/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod
 * Copyright (C) 2004-2008 AlliedModders LLC.  All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#include "HalfLife2.h"
#include "sourcemod.h"
#include "sourcemm_api.h"
#include "UserMessages.h"
#include "PlayerManager.h"
#include "sm_stringutil.h"
#include "GameConfigs.h"
#include <compat_wrappers.h>

CHalfLife2 g_HL2;
ConVar *sv_lan = NULL;

namespace SourceHook
{
	template<>
	int HashFunction<datamap_t *>(datamap_t * const &k)
	{
		return reinterpret_cast<int>(k);
	}

	template<>
	int Compare<datamap_t *>(datamap_t * const &k1, datamap_t * const &k2)
	{
		return (k1-k2);
	}
}

CHalfLife2::CHalfLife2()
{
	m_pClasses = sm_trie_create();
}

CHalfLife2::~CHalfLife2()
{
	sm_trie_destroy(m_pClasses);

	List<DataTableInfo *>::iterator iter;
	DataTableInfo *pInfo;
	for (iter=m_Tables.begin(); iter!=m_Tables.end(); iter++)
	{
		pInfo = (*iter);
		delete pInfo;
	}

	m_Tables.clear();

	THash<datamap_t *, DataMapTrie>::iterator h_iter;
	for (h_iter=m_Maps.begin(); h_iter!=m_Maps.end(); h_iter++)
	{
		if (h_iter->val.trie)
		{
			sm_trie_destroy(h_iter->val.trie);
			h_iter->val.trie = NULL;
		}
	}

	m_Maps.clear();
}

#if SOURCE_ENGINE != SE_DARKMESSIAH
CSharedEdictChangeInfo *g_pSharedChangeInfo = NULL;
#endif

bool is_original_engine = false;

void CHalfLife2::OnSourceModStartup(bool late)
{
#if SOURCE_ENGINE != SE_DARKMESSIAH

	/* The Ship currently is the only known game to use an older version of the engine */
#if defined METAMOD_PLAPI_VERSION
	if (g_SMAPI->GetSourceEngineBuild() == SOURCE_ENGINE_ORIGINAL)
#else
	if (strcasecmp(g_SourceMod.GetGameFolderName(), "ship") == 0)
#endif
	{
		is_original_engine = true;
	}
	else if (g_pSharedChangeInfo == NULL)
	{
		g_pSharedChangeInfo = engine->GetSharedEdictChangeInfo();
	}
#endif
}

void CHalfLife2::OnSourceModAllInitialized()
{
	m_MsgTextMsg = g_UserMsgs.GetMessageIndex("TextMsg");
	m_HinTextMsg = g_UserMsgs.GetMessageIndex("HintText");
	m_SayTextMsg = g_UserMsgs.GetMessageIndex("SayText");
	m_VGUIMenu = g_UserMsgs.GetMessageIndex("VGUIMenu");
	g_ShareSys.AddInterface(NULL, this);
}

#if !defined METAMOD_PLAPI_VERSION
bool CHalfLife2::IsOriginalEngine()
{
	return is_original_engine;
}
#endif

#if SOURCE_ENGINE != SE_DARKMESSIAH
IChangeInfoAccessor *CBaseEdict::GetChangeAccessor()
{
	return engine->GetChangeAccessor( (const edict_t *)this );
}
#endif

bool UTIL_FindInSendTable(SendTable *pTable, 
						  const char *name,
						  sm_sendprop_info_t *info,
						  unsigned int offset)
{
	const char *pname;
	int props = pTable->GetNumProps();
	SendProp *prop;

	for (int i=0; i<props; i++)
	{
		prop = pTable->GetProp(i);
		pname = prop->GetName();
		if (pname && strcmp(name, pname) == 0)
		{
			info->prop = prop;
			info->actual_offset = offset + info->prop->GetOffset();
			return true;
		}
		if (prop->GetDataTable())
		{
			if (UTIL_FindInSendTable(prop->GetDataTable(), 
				name,
				info,
				offset + prop->GetOffset())
				)
			{
				return true;
			}
		}
	}

	return false;
}

typedescription_t *UTIL_FindInDataMap(datamap_t *pMap, const char *name)
{
	while (pMap)
	{
		for (int i=0; i<pMap->dataNumFields; i++)
		{
			if (pMap->dataDesc[i].fieldName == NULL)
			{
				continue;
			}
			if (strcmp(name, pMap->dataDesc[i].fieldName) == 0)
			{
				return &(pMap->dataDesc[i]);
			}
			if (pMap->dataDesc[i].td)
			{
				typedescription_t *_td;
				if ((_td=UTIL_FindInDataMap(pMap->dataDesc[i].td, name)) != NULL)
				{
					return _td;
				}
			}
		}
		pMap = pMap->baseMap;
	}

	return NULL; 
}

ServerClass *CHalfLife2::FindServerClass(const char *classname)
{
	DataTableInfo *pInfo = _FindServerClass(classname);

	if (!pInfo)
	{
		return NULL;
	}

	return pInfo->sc;
}

DataTableInfo *CHalfLife2::_FindServerClass(const char *classname)
{
	DataTableInfo *pInfo = NULL;

	if (!sm_trie_retrieve(m_pClasses, classname, (void **)&pInfo))
	{
		ServerClass *sc = gamedll->GetAllServerClasses();
		while (sc)
		{
			if (strcmp(classname, sc->GetName()) == 0)
			{
				pInfo = new DataTableInfo;
				pInfo->sc = sc;
				sm_trie_insert(m_pClasses, classname, pInfo);
				m_Tables.push_back(pInfo);
				break;
			}
			sc = sc->m_pNext;
		}
		if (!pInfo)
		{
			return NULL;
		}
	}

	return pInfo;
}

bool CHalfLife2::FindSendPropInfo(const char *classname, const char *offset, sm_sendprop_info_t *info)
{
	DataTableInfo *pInfo;
	sm_sendprop_info_t *prop;

	if ((pInfo = _FindServerClass(classname)) == NULL)
	{
		return false;
	}

	if ((prop = pInfo->lookup.retrieve(offset)) == NULL)
	{
		sm_sendprop_info_t temp_info;

		if (!UTIL_FindInSendTable(pInfo->sc->m_pTable, offset, &temp_info, 0))
		{
			return false;
		}

		pInfo->lookup.insert(offset, temp_info);
		*info = temp_info;
	}
	else
	{
		*info = *prop;
	}
	
	return true;
}

SendProp *CHalfLife2::FindInSendTable(const char *classname, const char *offset)
{
	sm_sendprop_info_t info;

	if (!FindSendPropInfo(classname, offset, &info))
	{
		return NULL;
	}

	return info.prop;
}

typedescription_t *CHalfLife2::FindInDataMap(datamap_t *pMap, const char *offset)
{
	typedescription_t *td = NULL;
	DataMapTrie &val = m_Maps[pMap];

	if (!val.trie)
	{
		val.trie = sm_trie_create();
	}
	if (!sm_trie_retrieve(val.trie, offset, (void **)&td))
	{
		if ((td = UTIL_FindInDataMap(pMap, offset)) != NULL)
		{
			sm_trie_insert(val.trie, offset, td);
		}
	}

	return td;
}

void CHalfLife2::SetEdictStateChanged(edict_t *pEdict, unsigned short offset)
{
#if SOURCE_ENGINE != SE_DARKMESSIAH
	if (g_pSharedChangeInfo != NULL)
	{
		if (offset)
		{
			pEdict->StateChanged(offset);
		}
		else
		{
			pEdict->StateChanged();
		}
	}
	else
#endif
	{
		pEdict->m_fStateFlags |= FL_EDICT_CHANGED;
	}
}

bool CHalfLife2::TextMsg(int client, int dest, const char *msg)
{
	bf_write *pBitBuf = NULL;
	cell_t players[] = {client};

	if (dest == HUD_PRINTTALK)
	{
		const char *chat_saytext = g_pGameConf->GetKeyValue("ChatSayText");

		/* Use SayText user message instead */
		if (chat_saytext != NULL && strcmp(chat_saytext, "yes") == 0)
		{
			char buffer[192];
			UTIL_Format(buffer, sizeof(buffer), "%s\1\n", msg);

			if ((pBitBuf = g_UserMsgs.StartMessage(m_SayTextMsg, players, 1, USERMSG_RELIABLE)) == NULL)
			{
				return false;
			}

			pBitBuf->WriteByte(0);
			pBitBuf->WriteString(buffer);
			pBitBuf->WriteByte(1);

			g_UserMsgs.EndMessage();

			return true;
		}
	}

	if ((pBitBuf = g_UserMsgs.StartMessage(m_MsgTextMsg, players, 1, USERMSG_RELIABLE)) == NULL)
	{
		return false;
	}

	pBitBuf->WriteByte(dest);
	pBitBuf->WriteString(msg);

	g_UserMsgs.EndMessage();

	return true;
}

bool CHalfLife2::HintTextMsg(int client, const char *msg)
{
	bf_write *pBitBuf = NULL;
	cell_t players[] = {client};

	if ((pBitBuf = g_UserMsgs.StartMessage(m_HinTextMsg, players, 1, USERMSG_RELIABLE)) == NULL)
	{
		return false;
	}

	const char *pre_byte = g_pGameConf->GetKeyValue("HintTextPreByte");
	if (pre_byte != NULL && strcmp(pre_byte, "yes") == 0)
	{
		pBitBuf->WriteByte(1);
	}
	pBitBuf->WriteString(msg);
	g_UserMsgs.EndMessage();

	return true;
}

bool CHalfLife2::ShowVGUIMenu(int client, const char *name, KeyValues *data, bool show)
{
	bf_write *pBitBuf = NULL;
	KeyValues *SubKey = NULL;
	int count = 0;
	cell_t players[] = {client};

	if ((pBitBuf = g_UserMsgs.StartMessage(m_VGUIMenu, players, 1, USERMSG_RELIABLE)) == NULL)
	{
		return false;
	}

	if (data)
	{
		SubKey = data->GetFirstSubKey();
		while (SubKey)
		{
			count++;
			SubKey = SubKey->GetNextKey();
		}
		SubKey = data->GetFirstSubKey();
	}

	pBitBuf->WriteString(name);
	pBitBuf->WriteByte((show) ? 1 : 0);
	pBitBuf->WriteByte(count);
	while (SubKey)
	{
		pBitBuf->WriteString(SubKey->GetName());
		pBitBuf->WriteString(SubKey->GetString());
		SubKey = SubKey->GetNextKey();
	}
	g_UserMsgs.EndMessage();

	return true;
}

void CHalfLife2::AddToFakeCliCmdQueue(int client, int userid, const char *cmd)
{
	DelayedFakeCliCmd *pFake;

	if (m_FreeCmds.empty())
	{
		pFake = new DelayedFakeCliCmd;
	} else {
		pFake = m_FreeCmds.front();
		m_FreeCmds.pop();
	}

	pFake->client = client;
	pFake->userid = userid;
	pFake->cmd.assign(cmd);

	m_CmdQueue.push(pFake);
}

void CHalfLife2::ProcessFakeCliCmdQueue()
{
	while (!m_CmdQueue.empty())
	{
		DelayedFakeCliCmd *pFake = m_CmdQueue.first();

		if (g_Players.GetClientOfUserId(pFake->userid) == pFake->client)
		{
			CPlayer *pPlayer = g_Players.GetPlayerByIndex(pFake->client);
			serverpluginhelpers->ClientCommand(pPlayer->GetEdict(), pFake->cmd.c_str());
		}

		m_CmdQueue.pop();
	}
}

bool CHalfLife2::IsLANServer()
{
	sv_lan = icvar->FindVar("sv_lan");

	if (!sv_lan)
	{
		return false;
	}

	return (sv_lan->GetInt() != 0);
}

bool CHalfLife2::KVLoadFromFile(KeyValues *kv, IBaseFileSystem *filesystem, const char *resourceName, const char *pathID)
{
#if defined METAMOD_PLAPI_VERSION
	if (g_SMAPI->GetSourceEngineBuild() == SOURCE_ENGINE_ORIGINAL)
#else
	if (strcasecmp(g_SourceMod.GetGameFolderName(), "ship") == 0)
#endif
	{
		Assert(filesystem);
#ifdef _MSC_VER
		Assert(_heapchk() == _HEAPOK);
#endif

		FileHandle_t f = filesystem->Open(resourceName, "rb", pathID);
		if (!f)
			return false;

		// load file into a null-terminated buffer
		int fileSize = filesystem->Size(f);
		char *buffer = (char *)MemAllocScratch(fileSize + 1);

		Assert(buffer);

		filesystem->Read(buffer, fileSize, f); // read into local buffer

		buffer[fileSize] = 0; // null terminate file as EOF

		filesystem->Close( f );	// close file after reading

		bool retOK = kv->LoadFromBuffer( resourceName, buffer, filesystem );

		MemFreeScratch();

		return retOK;
	}
	else
	{
		return kv->LoadFromFile(filesystem, resourceName, pathID);
	}
}

void CHalfLife2::PushCommandStack(const CCommand *cmd)
{
	CachedCommandInfo info;

	info.args = cmd;
#if SOURCE_ENGINE <= SE_DARKMESSIAH
	strncopy(info.cmd, cmd->Arg(0), sizeof(info.cmd));
#endif

	m_CommandStack.push(info);
}

const CCommand *CHalfLife2::PeekCommandStack()
{
	if (m_CommandStack.empty())
	{
		return NULL;
	}

	return m_CommandStack.front().args;
}

void CHalfLife2::PopCommandStack()
{
	m_CommandStack.pop();
}

const char *CHalfLife2::CurrentCommandName()
{
#if SOURCE_ENGINE >= SE_ORANGEBOX
	return m_CommandStack.front().args->Arg(0);
#else
	return m_CommandStack.front().cmd;
#endif
}

void CHalfLife2::AddDelayedKick(int client, int userid, const char *msg)
{
	DelayedKickInfo kick;

	kick.client = client;
	kick.userid = userid;
	UTIL_Format(kick.buffer, sizeof(kick.buffer), "%s", msg);

	m_DelayedKicks.push(kick);
}

void CHalfLife2::ProcessDelayedKicks()
{
	while (!m_DelayedKicks.empty())
	{
		DelayedKickInfo info = m_DelayedKicks.first();
		m_DelayedKicks.pop();

		CPlayer *player = g_Players.GetPlayerByIndex(info.client);
		if (player == NULL || player->GetUserId() != info.userid)
		{
			continue;
		}

		player->Kick(info.buffer);
	}
}

edict_t *CHalfLife2::EdictOfIndex(int index)
{
	return ::PEntityOfEntIndex(index);
}

int CHalfLife2::IndexOfEdict(edict_t *pEnt)
{
	return ::IndexOfEdict(pEnt);
}

edict_t *CHalfLife2::GetHandleEntity(CBaseHandle &hndl)
{
	if (!hndl.IsValid())
	{
		return NULL;
	}

	int index = hndl.GetEntryIndex();

	edict_t *pStoredEdict;
	CBaseEntity *pStoredEntity;

	pStoredEdict = GetEntity(index, &pStoredEntity);

	if (pStoredEdict == NULL || pStoredEntity == NULL)
	{
		return NULL;
	}

	IServerEntity *pSE = pStoredEdict->GetIServerEntity();

	if (pSE == NULL)
	{
		return NULL;
	}

	if (pSE->GetRefEHandle() != hndl)
	{
		return NULL;
	}

	return pStoredEdict;
}

void CHalfLife2::SetHandleEntity(CBaseHandle &hndl, edict_t *pEnt)
{
	IServerEntity *pEntOther = pEnt->GetIServerEntity();

	if (pEntOther == NULL)
	{
		return;
	}

	hndl.Set(pEntOther);
}

const char *CHalfLife2::GetCurrentMap()
{
	return STRING(gpGlobals->mapname);
}

void CHalfLife2::ServerCommand(const char *buffer)
{
	engine->ServerCommand(buffer);
}
