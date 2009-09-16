/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod PgSQL Extension
 * Copyright (C) 2009 Lyfe & Saganaki.
 * Based on the SourceMod MySQL Extension -
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

#ifndef _INCLUDE_SM_PGSQL_DATABASE_H_
#define _INCLUDE_SM_PGSQL_DATABASE_H_

#include "PgDriver.h"
#include <IThreader.h>

class PgQuery;
class PgStatement;

class PgDatabase : public IDatabase
{
	friend class PgQuery;
	friend class PgStatement;
public:
	PgDatabase(PGconn *pgsql, const DatabaseInfo *info, bool persistent);
	~PgDatabase();
public: //IDatabase
	bool Close();
	const char *GetError(int *errorCode=NULL);
	bool DoSimpleQuery(const char *query);
	IQuery *DoQuery(const char *query);
	IPreparedQuery *PrepareQuery(const char *query, char *error, size_t maxlength, int *errCode=NULL);
	bool QuoteString(const char *str, char buffer[], size_t maxlen, size_t *newSize);
	unsigned int GetAffectedRows();
	unsigned int GetInsertID();
	bool LockForFullAtomicOperation();
	void UnlockFromFullAtomicOperation();
	void IncReferenceCount();
	IDBDriver *GetDriver();
	bool DoSimpleQueryEx(const char *query, size_t len);
	IQuery *DoQueryEx(const char *query, size_t len);
public:
	const DatabaseInfo &GetInfo();
private:
	PGconn *m_pgsql;
	unsigned int m_refcount;
	IMutex *m_pFullLock;
	IMutex *m_pRefLock;

	/* ---------- */
	DatabaseInfo m_Info;
	String m_Host;
	String m_Database;
	String m_User;
	String m_Pass;
	bool m_bPersistent;
};

//@TODO: Fix Me
DBType GetOurType(/*enum_field_types type*/);

#endif //_INCLUDE_SM_PGSQL_DATABASE_H_
