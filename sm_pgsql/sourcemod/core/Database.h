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

#ifndef _INCLUDE_DATABASE_MANAGER_H_
#define _INCLUDE_DATABASE_MANAGER_H_

#include <IDBDriver.h>
#include "sm_globals.h"
#include <sh_vector.h>
#include <sh_string.h>
#include <sh_list.h>
#include <ITextParsers.h>
#include "sm_memtable.h"
#include <IThreader.h>
#include "sm_simple_prioqueue.h"
#include "PluginSys.h"

using namespace SourceHook;

struct ConfDbInfo
{
	ConfDbInfo() : name(-1), driver(-1), host(-1), user(-1), pass(-1), 
		database(-1), realDriver(NULL)
	{
	}
	int name;
	int driver;
	int host;
	int user;
	int pass;
	int database;
	IDBDriver *realDriver;
	DatabaseInfo info;
};

class DBManager : 
	public IDBManager,
	public SMGlobalClass,
	public IHandleTypeDispatch,
	public ITextListener_SMC,
	public IThread,
	public IThreadWorkerCallbacks,
	public IPluginsListener
{
public:
	DBManager();
public:
	const char *GetInterfaceName();
	unsigned int GetInterfaceVersion();
public: //SMGlobalClass
	void OnSourceModAllInitialized();
	void OnSourceModLevelChange(const char *mapName);
	void OnSourceModIdentityDropped(IdentityToken_t *pToken);
	void OnSourceModShutdown();
public: //IHandleTypeDispatch
	void OnHandleDestroy(HandleType_t type, void *object);
public: //IDBManager
	void AddDriver(IDBDriver *pDrivera);
	void RemoveDriver(IDBDriver *pDriver);
	const DatabaseInfo *FindDatabaseConf(const char *name);
	bool Connect(const char *name, IDBDriver **pdr, IDatabase **pdb, bool persistent, char *error, size_t maxlength);
	unsigned int GetDriverCount();
	IDBDriver *GetDriver(unsigned int index);
	Handle_t CreateHandle(DBHandleType type, void *ptr, IdentityToken_t *pToken);
	HandleError ReadHandle(Handle_t hndl, DBHandleType type, void **ptr);
	HandleError ReleaseHandle(Handle_t hndl, DBHandleType type, IdentityToken_t *token);
	void AddDependency(IExtension *myself, IDBDriver *driver);
public: //ITextListener_SMC
	void ReadSMC_ParseStart();
	SMCResult ReadSMC_NewSection(const SMCStates *states, const char *name);
	SMCResult ReadSMC_KeyValue(const SMCStates *states, const char *key, const char *value);
	SMCResult ReadSMC_LeavingSection(const SMCStates *states);
	void ReadSMC_ParseEnd(bool halted, bool failed);
public: //IThread
	void RunThread(IThreadHandle *pThread);
	void OnTerminate(IThreadHandle *pThread, bool cancel);
public: //IThreadWorkerCallbacks
	void OnWorkerStart(IThreadWorker *pWorker);
	void OnWorkerStop(IThreadWorker *pWorker);
public: //IPluginsListener
	void OnPluginUnloaded(IPlugin *plugin);
public:
	ConfDbInfo *GetDatabaseConf(const char *name);
	IDBDriver *FindOrLoadDriver(const char *name);
	IDBDriver *GetDefaultDriver();
	const char *GetDefaultDriverName();
	bool AddToThreadQueue(IDBThreadOperation *op, PrioQueueLevel prio);
	void LockConfig();
	void UnlockConfig();
	void RunFrame();
	inline HandleType_t GetDatabaseType()
	{
		return m_DatabaseType;
	}
private:
	void KillWorkerThread();
private:
	CVector<IDBDriver *> m_drivers;

	/* Threading stuff */
	PrioQueue<IDBThreadOperation *> m_OpQueue;
	Queue<IDBThreadOperation *> m_ThinkQueue;
	CVector<bool> m_drSafety;			/* which drivers are safe? */
	IThreadWorker *m_pWorker;			/* Worker thread object */
	IMutex *m_pConfigLock;				/* Configuration lock */
	IMutex *m_pQueueLock;				/* Queue safety lock */
	IMutex *m_pThinkLock;				/* Think-queue lock */

	List<ConfDbInfo> m_confs;
	HandleType_t m_DriverType;
	HandleType_t m_DatabaseType;
	String m_DefDriver;
	BaseStringTable m_StrTab;
	char m_Filename[PLATFORM_MAX_PATH];
	unsigned int m_ParseLevel;
	unsigned int m_ParseState;
	IDBDriver *m_pDefault;
};

extern DBManager g_DBMan;

#endif //_INCLUDE_DATABASE_MANAGER_H_
