/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod Client Preferences Extension
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

#include "extension.h"
#include "cookie.h"
#include "menus.h"

cell_t RegClientPrefCookie(IPluginContext *pContext, const cell_t *params)
{
	if (g_ClientPrefs.Database == NULL && !g_ClientPrefs.databaseLoading)
	{
		return pContext->ThrowNativeError("Clientprefs is disabled due to a failed database connection");
	}

	char *name;
	pContext->LocalToString(params[1], &name);

	if (name[0] == '\0')
	{
		return pContext->ThrowNativeError("Cannot create preference cookie with no name");
	}

	char *desc;
	pContext->LocalToString(params[2], &desc);

	Cookie *pCookie = g_CookieManager.CreateCookie(name, desc, (CookieAccess)params[3]);

	if (!pCookie)
	{
		return BAD_HANDLE;
	}

	return handlesys->CreateHandle(g_CookieType, 
		pCookie, 
		pContext->GetIdentity(), 
		myself->GetIdentity(), 
		NULL);
}

cell_t FindClientPrefCookie(IPluginContext *pContext, const cell_t *params)
{
	if (g_ClientPrefs.Database == NULL && !g_ClientPrefs.databaseLoading)
	{
		return pContext->ThrowNativeError("Clientprefs is disabled due to a failed database connection");
	}

	char *name;
	pContext->LocalToString(params[1], &name);

	Cookie *pCookie = g_CookieManager.FindCookie(name);

	if (!pCookie)
	{
		return BAD_HANDLE;
	}

	return handlesys->CreateHandle(g_CookieType, 
		pCookie, 
		pContext->GetIdentity(), 
		myself->GetIdentity(), 
		NULL);
}

cell_t SetClientPrefCookie(IPluginContext *pContext, const cell_t *params)
{
	if (g_ClientPrefs.Database == NULL && !g_ClientPrefs.databaseLoading)
	{
		return pContext->ThrowNativeError("Clientprefs is disabled due to a failed database connection");
	}

	int client = params[1];

	if ((client < 1) || (client > playerhelpers->GetMaxClients()))
	{
		return pContext->ThrowNativeError("Client index %d is invalid", client);
	}

	Handle_t hndl = static_cast<Handle_t>(params[2]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();

	Cookie *pCookie;

	if ((err = handlesys->ReadHandle(hndl, g_CookieType, &sec, (void **)&pCookie))
	     != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid Cookie handle %x (error %d)", hndl, err);
	}

	char *value;
	pContext->LocalToString(params[3], &value);

	return g_CookieManager.SetCookieValue(pCookie, client, value);
}

cell_t GetClientPrefCookie(IPluginContext *pContext, const cell_t *params)
{
	if (g_ClientPrefs.Database == NULL && !g_ClientPrefs.databaseLoading)
	{
		return pContext->ThrowNativeError("Clientprefs is disabled due to a failed database connection");
	}

	int client = params[1];

	if ((client < 1) || (client > playerhelpers->GetMaxClients()))
	{
		return pContext->ThrowNativeError("Client index %d is invalid", client);
	}

	Handle_t hndl = static_cast<Handle_t>(params[2]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();

	Cookie *pCookie;

	if ((err = handlesys->ReadHandle(hndl, g_CookieType, &sec, (void **)&pCookie))
	     != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid Cookie handle %x (error %d)", hndl, err);
	}
	
	char *value = NULL;

	g_CookieManager.GetCookieValue(pCookie, client, &value);

	pContext->StringToLocal(params[3], params[4], value);

	return 1;
}

cell_t AreClientCookiesCached(IPluginContext *pContext, const cell_t *params)
{
	if (g_ClientPrefs.Database == NULL && !g_ClientPrefs.databaseLoading)
	{
		return pContext->ThrowNativeError("Clientprefs is disabled due to a failed database connection");
	}

	int client = params[1];

	if ((client < 1) || (client > playerhelpers->GetMaxClients()))
	{
		return pContext->ThrowNativeError("Client index %d is invalid", client);
	}

	return g_CookieManager.AreClientCookiesCached(client);
}

cell_t GetCookieAccess(IPluginContext *pContext, const cell_t *params)
{
	if (g_ClientPrefs.Database == NULL && !g_ClientPrefs.databaseLoading)
	{
		return pContext->ThrowNativeError("Clientprefs is disabled due to a failed database connection");
	}

	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();

	Cookie *pCookie;

	if ((err = handlesys->ReadHandle(hndl, g_CookieType, &sec, (void **)&pCookie))
	     != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid Cookie handle %x (error %d)", hndl, err);
	}

	return pCookie->access;
}

static cell_t GetCookieIterator(IPluginContext *pContext, const cell_t *params)
{
	if (g_ClientPrefs.Database == NULL && !g_ClientPrefs.databaseLoading)
	{
		return pContext->ThrowNativeError("Clientprefs is disabled due to a failed database connection");
	}

	SourceHook::List<Cookie *>::iterator *iter = new SourceHook::List<Cookie *>::iterator;
	*iter = g_CookieManager.cookieList.begin();

	Handle_t hndl = handlesys->CreateHandle(g_CookieIterator, iter, pContext->GetIdentity(), myself->GetIdentity(), NULL);
	if (hndl == BAD_HANDLE)
	{
		delete iter;
	}

	return hndl;
}

static cell_t ReadCookieIterator(IPluginContext *pContext, const cell_t *params)
{
	if (g_ClientPrefs.Database == NULL && !g_ClientPrefs.databaseLoading)
	{
		return pContext->ThrowNativeError("Clientprefs is disabled due to a failed database connection");
	}

	SourceHook::List<Cookie *>::iterator *iter;

	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;

	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();

	if ((err = handlesys->ReadHandle(hndl, g_CookieIterator, &sec, (void **)&iter))
	     != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid Cookie iterator handle %x (error %d)", hndl, err);
	}

	if (*iter == g_CookieManager.cookieList.end())
	{
		return 0;
	}

	Cookie *pCookie = (Cookie *)**iter;

	(*iter)++;

	pContext->StringToLocalUTF8(params[2], params[3], pCookie->name, NULL);
	pContext->StringToLocalUTF8(params[5], params[6], pCookie->description, NULL);

	cell_t *addr;
	pContext->LocalToPhysAddr(params[4], &addr);
	*addr = pCookie->access;

	return 1;
}

cell_t ShowSettingsMenu(IPluginContext *pContext, const cell_t *params)
{
	if (g_ClientPrefs.Database == NULL && !g_ClientPrefs.databaseLoading)
	{
		return pContext->ThrowNativeError("Clientprefs is disabled due to a failed database connection");
	}

	char message[256];
	Translate(message, sizeof(message), "%T:", 2, NULL, "Client Settings", &params[1]);

	g_CookieManager.clientMenu->SetDefaultTitle(message);
	g_CookieManager.clientMenu->Display(params[1], 0, NULL);

	return 0;
}

cell_t AddSettingsMenuItem(IPluginContext *pContext, const cell_t *params)
{
	if (g_ClientPrefs.Database == NULL && !g_ClientPrefs.databaseLoading)
	{
		return pContext->ThrowNativeError("Clientprefs is disabled due to a failed database connection");
	}

	char *display;
	pContext->LocalToString(params[3], &display);

	/* Register a callback */
	ItemHandler *pItem = new ItemHandler;
	pItem->isAutoMenu = false;
	pItem->forward = forwards->CreateForwardEx(NULL, ET_Ignore, 5, NULL, Param_Cell, Param_Cell, Param_Cell, Param_String, Param_Cell);

	pItem->forward->AddFunction(pContext, static_cast<funcid_t>(params[1]));

	char info[20];
	AutoMenuData *data = new AutoMenuData;
	data->datavalue = params[2];
	data->handler = pItem;
	UTIL_Format(info, sizeof(info), "%x", data);

	ItemDrawInfo draw(display, 0);

	g_CookieManager.clientMenu->AppendItem(info, draw);

	/* Track this in case the plugin unloads */

	IPlugin *pPlugin = plsys->FindPluginByContext(pContext->GetContext());
	SourceHook::List<char *> *pList = NULL;

	if (!pPlugin->GetProperty("SettingsMenuItems", (void **)&pList, false) || !pList)
	{
		pList = new SourceHook::List<char *>;
		pPlugin->SetProperty("SettingsMenuItems", pList);
	}

	char *copyarray = new char[strlen(display)+1];
	UTIL_Format(copyarray, strlen(display)+1, "%s", display);

	pList->push_back(copyarray);

	return 0;
}

cell_t AddSettingsPrefabMenuItem(IPluginContext *pContext, const cell_t *params)
{
	if (g_ClientPrefs.Database == NULL && !g_ClientPrefs.databaseLoading)
	{
		return pContext->ThrowNativeError("Clientprefs is disabled due to a failed database connection");
	}

	Handle_t hndl = static_cast<Handle_t>(params[1]);
	HandleError err;
	HandleSecurity sec;
 
	sec.pOwner = NULL;
	sec.pIdentity = myself->GetIdentity();

	Cookie *pCookie;

	if ((err = handlesys->ReadHandle(hndl, g_CookieType, &sec, (void **)&pCookie))
	     != HandleError_None)
	{
		return pContext->ThrowNativeError("Invalid Cookie handle %x (error %d)", hndl, err);
	}

	/* Register a callback */
	ItemHandler *pItem = new ItemHandler;
	pItem->isAutoMenu = true;
	pItem->autoMenuType = (CookieMenu)params[2];


	/* User passed a function id for a callback */
	if (params[4] != -1)
	{
		pItem->forward = forwards->CreateForwardEx(NULL, ET_Ignore, 5, NULL, Param_Cell, Param_Cell, Param_Cell, Param_String, Param_Cell); 
		pItem->forward->AddFunction(pContext, static_cast<funcid_t>(params[4]));
	}
	else
	{
		pItem->forward = NULL;
	}

	char *display;
	pContext->LocalToString(params[3], &display);

	ItemDrawInfo draw(display, 0);

	char info[20];
	AutoMenuData *data = new AutoMenuData;
	data->datavalue = params[5];
	data->pCookie = pCookie;
	data->type = (CookieMenu)params[2];
	data->handler = pItem;
	UTIL_Format(info, sizeof(info), "%x", data);

	g_CookieManager.clientMenu->AppendItem(info, draw);

	/* Track this in case the plugin unloads */

	IPlugin *pPlugin = plsys->FindPluginByContext(pContext->GetContext());
	SourceHook::List<char *> *pList = NULL;

	if (!pPlugin->GetProperty("SettingsMenuItems", (void **)&pList, false) || !pList)
	{
		pList = new SourceHook::List<char *>;
		pPlugin->SetProperty("SettingsMenuItems", pList);
	}

	char *copyarray = new char[strlen(display)+1];
	UTIL_Format(copyarray, strlen(display)+1, "%s", display);

	pList->push_back(copyarray);

	return 0;
}

sp_nativeinfo_t g_ClientPrefNatives[] = 
{
	{"RegClientCookie",				RegClientPrefCookie},
	{"FindClientCookie",			FindClientPrefCookie},
	{"SetClientCookie",				SetClientPrefCookie},
	{"GetClientCookie",				GetClientPrefCookie},
	{"AreClientCookiesCached",		AreClientCookiesCached},
	{"GetCookieAccess",				GetCookieAccess},
	{"ReadCookieIterator",			ReadCookieIterator},
	{"GetCookieIterator",			GetCookieIterator},
	{"ShowCookieMenu",				ShowSettingsMenu},
	{"SetCookieMenuItem",			AddSettingsMenuItem},
	{"SetCookiePrefabMenu",			AddSettingsPrefabMenuItem},
	{NULL,							NULL}
};
