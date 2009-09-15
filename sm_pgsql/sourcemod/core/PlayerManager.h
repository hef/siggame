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

#ifndef _INCLUDE_SOURCEMOD_CPLAYERMANAGER_H_
#define _INCLUDE_SOURCEMOD_CPLAYERMANAGER_H_

#include "sm_globals.h"
#include <eiface.h>
#include "sourcemm_api.h"
#include <IForwardSys.h>
#include <IPlayerHelpers.h>
#include <IAdminSystem.h>
#include <sh_string.h>
#include <sh_list.h>
#include <sh_vector.h>
#include "ConVarManager.h"

using namespace SourceHook;

#define PLAYER_LIFE_UNKNOWN	0
#define PLAYER_LIFE_ALIVE	1
#define PLAYER_LIFE_DEAD	2

#define MIN_API_FOR_ADMINCALLS		7

union serial_t
{
	uint32_t   value;
	struct
	{
		uint8_t  index;
		uint32_t serial : 24;
	} bits;
};

class CPlayer : public IGamePlayer
{
	friend class PlayerManager;
public:
	CPlayer();
public:
	const char *GetName();
	const char *GetIPAddress();
	const char *GetAuthString();
	edict_t *GetEdict();
	bool IsInGame();
	bool WasCountedAsInGame();
	bool IsConnected();
	bool IsAuthorized();
	bool IsFakeClient();
	void SetAdminId(AdminId id, bool temporary);
	AdminId GetAdminId();
	void Kick(const char *str);
	IPlayerInfo *GetPlayerInfo();
	unsigned int GetLanguageId();
	int GetUserId();
	bool RunAdminCacheChecks();
	void NotifyPostAdminChecks();
	unsigned int GetSerial();
public:
	void DoBasicAdminChecks();
	bool IsInKickQueue();
	void MarkAsBeingKicked();
	int GetLifeState();
private:
	void Initialize(const char *name, const char *ip, edict_t *pEntity);
	void Connect();
	void Disconnect();
	void SetName(const char *name);
	void DumpAdmin(bool deleting);
	void Authorize(const char *auth);
	void Authorize_Post();
	void DoPostConnectAuthorization();
private:
	bool m_IsConnected;
	bool m_IsInGame;
	bool m_IsAuthorized;
	bool m_bIsInKickQueue;
	String m_Name;
	String m_Ip;
	String m_IpNoPort;
	String m_AuthID;
	AdminId m_Admin;
	bool m_TempAdmin;
	edict_t *m_pEdict;
	IPlayerInfo *m_Info;
	String m_LastPassword;
	bool m_bAdminCheckSignalled;
	int m_iIndex;
	unsigned int m_LangId;
	int m_UserId;
	bool m_bFakeClient;
	serial_t m_Serial;
};

class PlayerManager : 
	public SMGlobalClass,
	public IPlayerManager,
	public IConVarChangeListener
{
	friend class CPlayer;
public:
	PlayerManager();
	~PlayerManager();
public: //SMGlobalClass
	void OnSourceModAllInitialized();
	void OnSourceModShutdown();
	void OnSourceModLevelEnd();
	ConfigResult OnSourceModConfigChanged(const char *key, const char *value, ConfigSource source, char *error, size_t maxlength);
	void OnSourceModMaxPlayersChanged(int newvalue);
public:
	CPlayer *GetPlayerByIndex(int client) const;
	void RunAuthChecks();
	void ClearAdminId(AdminId id);
	void ClearAllAdmins();
public:
	bool OnClientConnect(edict_t *pEntity, const char *pszName, const char *pszAddress, char *reject, int maxrejectlen);
	bool OnClientConnect_Post(edict_t *pEntity, const char *pszName, const char *pszAddress, char *reject, int maxrejectlen);
	void OnClientPutInServer(edict_t *pEntity, char const *playername);
	void OnClientDisconnect(edict_t *pEntity);
	void OnClientDisconnect_Post(edict_t *pEntity);
#if SOURCE_ENGINE >= SE_ORANGEBOX
	void OnClientCommand(edict_t *pEntity, const CCommand &args);
#else
	void OnClientCommand(edict_t *pEntity);
#endif
	void OnClientSettingsChanged(edict_t *pEntity);
	//void OnClientSettingsChanged_Pre(edict_t *pEntity);
public: //IPlayerManager
	void AddClientListener(IClientListener *listener);
	void RemoveClientListener(IClientListener *listener);
	IGamePlayer *GetGamePlayer(int client);
	IGamePlayer *GetGamePlayer(edict_t *pEdict);
	int GetMaxClients();
	int GetNumPlayers();
	int GetClientOfUserId(int userid);
	bool IsServerActivated();
	int FilterCommandTarget(IGamePlayer *pAdmin, IGamePlayer *pTarget, int flags);
	int InternalFilterCommandTarget(CPlayer *pAdmin, CPlayer *pTarget, int flags);
	void RegisterCommandTargetProcessor(ICommandTargetProcessor *pHandler);
	void UnregisterCommandTargetProcessor(ICommandTargetProcessor *pHandler);
	void ProcessCommandTarget(cmd_target_info_t *info);
	int GetClientFromSerial(unsigned int serial);
public: // IConVarChangeListener
	void OnConVarChanged(ConVar *pConVar, const char *oldValue, float flOldValue);
public:
	inline int MaxClients()
	{
		return m_maxClients;
	}
	inline int NumPlayers()
	{
		return m_PlayerCount;
	}
	inline int ListenClient()
	{
		return m_ListenClient;
	}
	bool CheckSetAdmin(int index, CPlayer *pPlayer, AdminId id);
	bool CheckSetAdminName(int index, CPlayer *pPlayer, AdminId id);
	const char *GetPassInfoVar();
	void RecheckAnyAdmins();
	unsigned int GetReplyTo();
	unsigned int SetReplyTo(unsigned int reply);
	void MaxPlayersChanged(int newvalue = -1);
private:
	void OnServerActivate(edict_t *pEdictList, int edictCount, int clientMax);
	void InvalidatePlayer(CPlayer *pPlayer);
private:
	List<IClientListener *> m_hooks;
	IForward *m_clconnect;
	IForward *m_cldisconnect;
	IForward *m_cldisconnect_post;
	IForward *m_clputinserver;
	IForward *m_clcommand;
	IForward *m_clinfochanged;
	IForward *m_clauth;
	IForward *m_onActivate;
	IForward *m_onActivate2;
	CPlayer *m_Players;
	int *m_UserIdLookUp;
	int m_maxClients;
	int m_PlayerCount;
	bool m_FirstPass;
	unsigned int *m_AuthQueue;
	String m_PassInfoVar;
	bool m_QueryLang;
	bool m_bIsListenServer;
	int m_ListenClient;
};

#if SOURCE_ENGINE >= SE_ORANGEBOX
void CmdMaxplayersCallback(const CCommand &command);
#else
void CmdMaxplayersCallback();
#endif

extern void ClientConsolePrint(edict_t *e, const char *fmt, ...);

extern PlayerManager g_Players;
extern bool g_OnMapStarted;
extern const unsigned int *g_NumPlayersToAuth;

#endif //_INCLUDE_SOURCEMOD_CPLAYERMANAGER_H_
