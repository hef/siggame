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

#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "sm_stringutil.h"
#include "sm_globals.h"
#include "sourcemod.h"
#include "PluginSys.h"
#include "HandleSys.h"
#include "LibrarySys.h"
#include "TimerSys.h"
#include "ForwardSys.h"
#include "Logger.h"
#include "ExtensionSys.h"

#if defined PLATFORM_WINDOWS
#include <windows.h>
#elif defined PLATFORM_LINUX
#include <limits.h>
#include <unistd.h>
#include <sys/times.h>
#endif

HandleType_t g_PlIter;
ConVar sm_datetime_format("sm_datetime_format", "%m/%d/%Y - %H:%M:%S", 0, "Default formatting time rules");
IForward *g_OnLogAction = NULL;

class CoreNativeHelpers : 
	public SMGlobalClass,
	public IHandleTypeDispatch
{
public:
	void OnSourceModAllInitialized()
	{
		HandleAccess hacc;
		g_HandleSys.InitAccessDefaults(NULL,  &hacc);
		hacc.access[HandleAccess_Clone] = HANDLE_RESTRICT_IDENTITY|HANDLE_RESTRICT_OWNER;

		g_PlIter = g_HandleSys.CreateType("PluginIterator", this, 0, NULL, NULL, g_pCoreIdent, NULL);

		g_OnLogAction = g_Forwards.CreateForward("OnLogAction", 
			ET_Hook, 
			5, 
			NULL,
			Param_Cell,
			Param_Cell,
			Param_Cell,
			Param_Cell,
			Param_String);
	}
	void OnHandleDestroy(HandleType_t type, void *object)
	{
		IPluginIterator *iter = (IPluginIterator *)object;
		iter->Release();
	}
	void OnSourceModShutdown()
	{
		g_Forwards.ReleaseForward(g_OnLogAction);
		g_HandleSys.RemoveType(g_PlIter, g_pCoreIdent);
	}
} g_CoreNativeHelpers;

void LogAction(Handle_t hndl, int type, int client, int target, const char *message)
{
	if (g_OnLogAction->GetFunctionCount())
	{
		cell_t result = 0;
		g_OnLogAction->PushCell(hndl);
		g_OnLogAction->PushCell(type);
		g_OnLogAction->PushCell(client);
		g_OnLogAction->PushCell(target);
		g_OnLogAction->PushString(message);
		g_OnLogAction->Execute(&result);

		if (result >= (ResultType)Pl_Handled)
		{
			return;
		}
	}

	const char *logtag = "SM";
	if (type == 2)
	{
		HandleError err;
		IPlugin *pPlugin = g_PluginSys.PluginFromHandle(hndl, &err);
		if (pPlugin)
		{
			logtag = pPlugin->GetFilename();
		}
	}

	g_Logger.LogMessage("[%s] %s", logtag, message);
}

static cell_t ThrowError(IPluginContext *pContext, const cell_t *params)
{
	char buffer[512];

	g_SourceMod.SetGlobalTarget(SOURCEMOD_SERVER_LANGUAGE);

	g_SourceMod.FormatString(buffer, sizeof(buffer), pContext, params, 1);

	if (pContext->GetLastNativeError() == SP_ERROR_NONE)
	{
		pContext->ThrowNativeErrorEx(SP_ERROR_ABORTED, "%s", buffer);
	}

	return 0;
}

static cell_t GetTime(IPluginContext *pContext, const cell_t *params)
{
	time_t t = GetAdjustedTime();
	cell_t *addr;
	pContext->LocalToPhysAddr(params[1], &addr);

	*(time_t *)addr = t;

	return static_cast<cell_t>(t);
}

#if defined SUBPLATFORM_SECURECRT
void _ignore_invalid_parameter(
						const wchar_t * expression,
						const wchar_t * function, 
						const wchar_t * file, 
						unsigned int line,
						uintptr_t pReserved
						)
{
	/* Wow we don't care, thanks Microsoft. */
}
#endif

static cell_t FormatTime(IPluginContext *pContext, const cell_t *params)
{
	char *format, *buffer;
	pContext->LocalToString(params[1], &buffer);
	pContext->LocalToStringNULL(params[3], &format);

	if (format == NULL)
	{
		format = const_cast<char *>(sm_datetime_format.GetString());
	}

#if defined SUBPLATFORM_SECURECRT
	_invalid_parameter_handler handler = _set_invalid_parameter_handler(_ignore_invalid_parameter);
#endif

	time_t t = (params[4] == -1) ? GetAdjustedTime() : (time_t)params[4];
	size_t written = strftime(buffer, params[2], format, localtime(&t));

#if defined SUBPLATFORM_SECURECRT
	_set_invalid_parameter_handler(handler);
#endif

	if (params[2] && format[0] != '\0' && !written)
	{
		pContext->ThrowNativeError("Invalid time format or buffer too small");
		return 0;
	}

	return 1;
}

static cell_t GetPluginIterator(IPluginContext *pContext, const cell_t *params)
{
	IPluginIterator *iter = g_PluginSys.GetPluginIterator();

	Handle_t hndl = g_HandleSys.CreateHandle(g_PlIter, iter, pContext->GetIdentity(), g_pCoreIdent, NULL);

	if (hndl == BAD_HANDLE)
	{
		iter->Release();
	}

	return hndl;
}

static cell_t MorePlugins(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = (Handle_t)params[1];
	HandleError err;
	IPluginIterator *pIter;

	HandleSecurity sec;
	sec.pIdentity = g_pCoreIdent;
	sec.pOwner = pContext->GetIdentity();

	if ((err=g_HandleSys.ReadHandle(hndl, g_PlIter, &sec, (void **)&pIter)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Could not read Handle %x (error %d)", hndl, err);
	}

	return pIter->MorePlugins() ? 1 : 0;
}

static cell_t ReadPlugin(IPluginContext *pContext, const cell_t *params)
{
	Handle_t hndl = (Handle_t)params[1];
	HandleError err;
	IPluginIterator *pIter;

	HandleSecurity sec;
	sec.pIdentity = g_pCoreIdent;
	sec.pOwner = pContext->GetIdentity();

	if ((err=g_HandleSys.ReadHandle(hndl, g_PlIter, &sec, (void **)&pIter)) != HandleError_None)
	{
		return pContext->ThrowNativeError("Could not read Handle %x (error %d)", hndl, err);
	}

	CPlugin *pPlugin = (CPlugin *)pIter->GetPlugin();
	if (!pPlugin)
	{
		return BAD_HANDLE;
	}

	pIter->NextPlugin();

	return pPlugin->GetMyHandle();
}

CPlugin *GetPluginFromHandle(IPluginContext *pContext, Handle_t hndl)
{
	if (hndl == BAD_HANDLE)
	{
		return g_PluginSys.GetPluginByCtx(pContext->GetContext());
	} else {
		HandleError err;
		CPlugin *pPlugin = (CPlugin *)g_PluginSys.PluginFromHandle(hndl, &err);
		if (!pPlugin)
		{
			pContext->ThrowNativeError("Could not read Handle %x (error %d)", hndl, err);
		}
		return pPlugin;
	}
}

static cell_t GetPluginStatus(IPluginContext *pContext, const cell_t *params)
{
	CPlugin *pPlugin = GetPluginFromHandle(pContext, params[1]);
	if (!pPlugin)
	{
		return 0;
	}

	return pPlugin->GetStatus();
}

static cell_t GetPluginFilename(IPluginContext *pContext, const cell_t *params)
{
	CPlugin *pPlugin = GetPluginFromHandle(pContext, params[1]);
	if (!pPlugin)
	{
		return 0;
	}

	pContext->StringToLocalUTF8(params[2], params[3], pPlugin->GetFilename(), NULL);

	return 1;
}

static cell_t IsPluginDebugging(IPluginContext *pContext, const cell_t *params)
{
	CPlugin *pPlugin = GetPluginFromHandle(pContext, params[1]);
	if (!pPlugin)
	{
		return 0;
	}

	return pPlugin->IsDebugging() ? 1 : 0;
}

/* Local to plugins only */
enum PluginInfo
{
	PlInfo_Name,			/**< Plugin name */
	PlInfo_Author,			/**< Plugin author */
	PlInfo_Description,		/**< Plugin description */
	PlInfo_Version,			/**< Plugin verison */
	PlInfo_URL,				/**< Plugin URL */
};

static cell_t GetPluginInfo(IPluginContext *pContext, const cell_t *params)
{
	CPlugin *pPlugin = GetPluginFromHandle(pContext, params[1]);
	if (!pPlugin)
	{
		return 0;
	}

	const sm_plugininfo_t *info = pPlugin->GetPublicInfo();

	if (!info)
	{
		return 0;
	}

	const char *str = NULL;

	switch ((PluginInfo)params[2])
	{
	case PlInfo_Name:
		{
			str = info->name;
			break;
		}
	case PlInfo_Author:
		{
			str = info->author;
			break;
		}
	case PlInfo_Description:
		{
			str = info->description;
			break;
		}
	case PlInfo_Version:
		{
			str = info->version;
			break;
		}
	case PlInfo_URL:
		{
			str = info->url;
			break;
		}
	}

	if (!str || str[0] == '\0')
	{
		return 0;
	}

	pContext->StringToLocalUTF8(params[3], params[4], str, NULL);

	return 1;
}

static cell_t SetFailState(IPluginContext *pContext, const cell_t *params)
{
	char *str;
	CPlugin *pPlugin;

	pContext->LocalToString(params[1], &str);
	pPlugin = g_PluginSys.GetPluginByCtx(pContext->GetContext());

	if (params[0] == 1)
	{
		pPlugin->SetErrorState(Plugin_Error, "%s", str);

		return pContext->ThrowNativeErrorEx(SP_ERROR_ABORTED, "%s", str);
	}
	else
	{
		char buffer[2048];

		g_SourceMod.FormatString(buffer, sizeof(buffer), pContext, params, 1);
		if (pContext->GetLastNativeError() != SP_ERROR_NONE)
		{
			pPlugin->SetErrorState(Plugin_Error, "%s", str);
			return pContext->ThrowNativeErrorEx(SP_ERROR_ABORTED, "Formatting error (%s)", str);
		}
		else
		{
			pPlugin->SetErrorState(Plugin_Error, "%s", buffer);
			return pContext->ThrowNativeErrorEx(SP_ERROR_ABORTED, "%s", buffer);
		}
	}

	return 0;
}

static cell_t GetSysTickCount(IPluginContext *pContext, const cell_t *params)
{
#if defined PLATFORM_WINDOWS
	return (cell_t)GetTickCount();
#elif defined PLATFORM_LINUX
	tms tm;
	clock_t ticks = times(&tm);
	long ticks_per_sec = sysconf(_SC_CLK_TCK);
	double fticks = (double)ticks / (double)ticks_per_sec;
	fticks *= 1000.0f;
	if (fticks > INT_MAX)
	{
		double r = (int)(fticks / INT_MAX) * (double)INT_MAX;
		fticks -= r;
	}
	return (cell_t)fticks;
#elif defined PLATFORM_APPLE
	assert(false);
	return 0;
#endif
}

static cell_t AutoExecConfig(IPluginContext *pContext, const cell_t *params)
{
	CPlugin *plugin = g_PluginSys.GetPluginByCtx(pContext->GetContext());

	char *cfg, *folder;
	pContext->LocalToString(params[2], &cfg);
	pContext->LocalToString(params[3], &folder);

	if (cfg[0] == '\0')
	{
		static char temp_str[255];
		static char temp_file[PLATFORM_MAX_PATH];
		char *ptr;

		g_LibSys.GetFileFromPath(temp_str, sizeof(temp_str), plugin->GetFilename());
		if ((ptr = strstr(temp_str, ".smx")) != NULL)
		{
			*ptr = '\0';
		}

		/* We have the raw filename! */
		UTIL_Format(temp_file, sizeof(temp_file), "plugin.%s", temp_str);
		cfg = temp_file;
	}

	plugin->AddConfig(params[1] ? true : false, cfg, folder);

	return 1;
}

static cell_t MarkNativeAsOptional(IPluginContext *pContext, const cell_t *params)
{
	char *name;
	uint32_t idx;
	sp_native_t *native;

	pContext->LocalToString(params[1], &name);
	if (pContext->FindNativeByName(name, &idx) != SP_ERROR_NONE)
	{
		/* Oops! This HAS to silently fail! */
		return 0;
	}

	pContext->GetNativeByIndex(idx, &native);

	native->flags |= SP_NTVFLAG_OPTIONAL;

	return 1;
}

static cell_t RegPluginLibrary(IPluginContext *pContext, const cell_t *params)
{
	char *name;
	CPlugin *pl = g_PluginSys.GetPluginByCtx(pContext->GetContext());

	pContext->LocalToString(params[1], &name);

	pl->AddLibrary(name);

	return 1;
}

static cell_t LibraryExists(IPluginContext *pContext, const cell_t *params)
{
	char *str;
	pContext->LocalToString(params[1], &str);

	if (g_PluginSys.LibraryExists(str))
	{
		return 1;
	}

	if (g_Extensions.LibraryExists(str))
	{
		return 1;
	}

	return 0;
}

static cell_t sm_LogAction(IPluginContext *pContext, const cell_t *params)
{
	char buffer[2048];
	g_SourceMod.SetGlobalTarget(SOURCEMOD_SERVER_LANGUAGE);
	g_SourceMod.FormatString(buffer, sizeof(buffer), pContext, params, 3);

	if (pContext->GetLastNativeError() != SP_ERROR_NONE)
	{
		return 0;
	}

	CPlugin *pPlugin = g_PluginSys.GetPluginByCtx(pContext->GetContext());

	LogAction(pPlugin->GetMyHandle(), 2, params[1], params[2], buffer);

	return 1;
}

static cell_t LogToFile(IPluginContext *pContext, const cell_t *params)
{
	char *file;
	pContext->LocalToString(params[1], &file);

	char path[PLATFORM_MAX_PATH];
	g_SourceMod.BuildPath(Path_Game, path, sizeof(path), "%s", file);

	FILE *fp = fopen(path, "at");
	if (!fp)
	{
		return pContext->ThrowNativeError("Could not open file \"%s\"", path);
	}

	char buffer[2048];
	g_SourceMod.SetGlobalTarget(SOURCEMOD_SERVER_LANGUAGE);
	g_SourceMod.FormatString(buffer, sizeof(buffer), pContext, params, 2);

	if (pContext->GetLastNativeError() != SP_ERROR_NONE)
	{
		fclose(fp);
		return 0;
	}

	CPlugin *pPlugin = g_PluginSys.GetPluginByCtx(pContext->GetContext());

	g_Logger.LogToOpenFile(fp, "[%s] %s", pPlugin->GetFilename(), buffer);

	fclose(fp);

	return 1;
}

static cell_t LogToFileEx(IPluginContext *pContext, const cell_t *params)
{
	char *file;
	pContext->LocalToString(params[1], &file);

	char path[PLATFORM_MAX_PATH];
	g_SourceMod.BuildPath(Path_Game, path, sizeof(path), "%s", file);

	FILE *fp = fopen(path, "at");
	if (!fp)
	{
		return pContext->ThrowNativeError("Could not open file \"%s\"", path);
	}

	char buffer[2048];
	g_SourceMod.SetGlobalTarget(SOURCEMOD_SERVER_LANGUAGE);
	g_SourceMod.FormatString(buffer, sizeof(buffer), pContext, params, 2);

	if (pContext->GetLastNativeError() != SP_ERROR_NONE)
	{
		fclose(fp);
		return 0;
	}

	g_Logger.LogToOpenFile(fp, "%s", buffer);

	fclose(fp);

	return 1;
}

static cell_t GetExtensionFileStatus(IPluginContext *pContext, const cell_t *params)
{
	char *str;
	pContext->LocalToString(params[1], &str);

	IExtension *pExtension = g_Extensions.FindExtensionByFile(str);
	
	if (!pExtension)
	{
		return -2;
	}
	
	if (!pExtension->IsLoaded())
	{
		return -1;
	}

	char *error;
	pContext->LocalToString(params[2], &error);
	if (!pExtension->IsRunning(error, params[3]))
	{
		return 0;
	}

	return 1;
}

static cell_t FindPluginByNumber(IPluginContext *pContext, const cell_t *params)
{
	CPlugin *pPlugin = g_PluginSys.GetPluginByOrder(params[1]);
	
	if (pPlugin == NULL)
	{
		return BAD_HANDLE;
	}

	return pPlugin->GetMyHandle();
}

static cell_t VerifyCoreVersion(IPluginContext *pContext, const cell_t *params)
{
	return 4;
}

REGISTER_NATIVES(coreNatives)
{
	{"AutoExecConfig",			AutoExecConfig},
	{"GetPluginFilename",		GetPluginFilename},
	{"GetPluginInfo",			GetPluginInfo},
	{"GetPluginIterator",		GetPluginIterator},
	{"GetPluginStatus",			GetPluginStatus},
	{"GetSysTickCount",			GetSysTickCount},
	{"GetTime",					GetTime},
	{"IsPluginDebugging",		IsPluginDebugging},
	{"MorePlugins",				MorePlugins},
	{"ReadPlugin",				ReadPlugin},
	{"ThrowError",				ThrowError},
	{"SetFailState",			SetFailState},
	{"FormatTime",				FormatTime},
	{"MarkNativeAsOptional",	MarkNativeAsOptional},
	{"RegPluginLibrary",		RegPluginLibrary},
	{"LibraryExists",			LibraryExists},
	{"LogAction",				sm_LogAction},
	{"LogToFile",				LogToFile},
	{"LogToFileEx",				LogToFileEx},
	{"GetExtensionFileStatus",	GetExtensionFileStatus},
	{"FindPluginByNumber",		FindPluginByNumber},
	{"VerifyCoreVersion",		VerifyCoreVersion},
	{NULL,						NULL},
};

