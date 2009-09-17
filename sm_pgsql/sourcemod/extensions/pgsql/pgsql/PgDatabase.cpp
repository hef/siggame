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

#include "PgDatabase.h"
#include "smsdk_ext.h"
#include "PgBasicResults.h"
#include "PgStatement.h"

DBType GetOurType(Oid type)
{
	switch (type)
	{
	// DB Float types
	case PG_TYPE_FLOAT:
	case PG_TYPE_DOUBLE:
		{
			return DBType_Float;
		}
	// DB integer types
	case PG_TYPE_INT8:
	case PG_TYPE_SHORT:
	case PG_TYPE_INT:
	case PG_TYPE_BOOL:
		{
			return DBType_Integer;
		}
	// DB Blobs.
	case PG_TYPE_BYTEAOID:
	case PG_TYPE_TEXTOID:
		{
			return DBType_Blob;
		}
	// DB String types
	case PG_TYPE_ABSTIMEOID:
	case PG_TYPE_RELTIMEOID:
	case PG_TYPE_TINTERVALOID:
	case PG_TYPE_TIMEOID:
	case PG_TYPE_TIMESTAMPOID:
	case PG_TYPE_TIMESTAMPTZOID:
	case PG_TYPE_TIMETZOID:
	case PG_TYPE_DATEOID:
	case PG_TYPE_NAMEOID:
	case PG_TYPE_MACADDROID:
	case PG_TYPE_INETOID:
	case PG_TYPE_CIDROID:
	case PG_TYPE_BPCHAROID:
	case PG_TYPE_VARCHAROID:
	default:
		{
			return DBType_String;
		}
	}
	return DBType_Unknown;
}

PgDatabase::PgDatabase(PGconn *pgsql, const DatabaseInfo *info, bool persistent)
: m_pgsql(pgsql), m_refcount(1), m_pFullLock(NULL), m_bPersistent(persistent)
{
	m_Host.assign(info->host);
	m_Database.assign(info->database);
	m_User.assign(info->user);
	m_Pass.assign(info->pass);

	m_Info.database = m_Database.c_str();
	m_Info.host = m_Host.c_str();
	m_Info.user = m_User.c_str();
	m_Info.pass = m_Pass.c_str();
	m_Info.driver = NULL;
	m_Info.maxTimeout = info->maxTimeout;
	m_Info.port = info->port;

	m_pRefLock = threader->MakeMutex();
}

PgDatabase::~PgDatabase()
{
	PQfinish(m_pgsql);
	m_pgsql = NULL;

	m_pRefLock->DestroyThis();
	if (m_pFullLock)
	{
		m_pFullLock->DestroyThis();
	}
}

void PgDatabase::IncReferenceCount()
{
	m_pRefLock->Lock();
	m_refcount++;
	m_pRefLock->Unlock();
}

bool PgDatabase::Close()
{
	m_pRefLock->Lock();
	if (m_refcount > 1)
	{
		m_refcount--;
		m_pRefLock->Unlock();
		return false;
	}
	m_pRefLock->Unlock();

	/* Remove us from the search list */
	if (m_bPersistent)
	{
		g_PgDriver.RemoveFromList(this, true);
	}

	/* Finally, free our resource(s) */
	delete this;

	return true;
}

const DatabaseInfo &PgDatabase::GetInfo()
{
	return m_Info;
}

unsigned int PgDatabase::GetInsertID()
{
	//@TODO: Figure out how to make this work in postgres..
	// postgress stores this information with the result set, not the DB.
	//@TODO: Fix me
	//return (unsigned int)mysql_insert_id(m_mysql);
	return 0;
}

unsigned int PgDatabase::GetAffectedRows()
{
	//@TODO: Figure out how to make this work in postgres..
	// postgress stores this information with the result set, not the DB.
	//@TODO: Fix me
	//return (unsigned int)mysql_affected_rows(m_mysql);
	return 0;
}

const char *PgDatabase::GetError(int *errCode)
{
	// Pg doesn't actually store error codes, or reference by error code.
	if (errCode)
	{
		return PQerrorMessage(m_pgsql);
	}

	return "";
}

bool PgDatabase::QuoteString(const char *str, char buffer[], size_t maxlength, size_t *newSize)
{
	unsigned long size = static_cast<unsigned long>(strlen(str));
	unsigned long needed = size * 2 + 1;

	if (maxlength < needed)
	{
		if (newSize)
		{
			*newSize = (size_t)needed;
		}
		return false;
	}
	// 5th param is an error flag, but it's only used for multibyte encoding issues.
	needed = PQescapeStringConn(m_pgsql, buffer, str, size, NULL);
	if (newSize)
	{
		*newSize = (size_t)needed;
	}

	return true;
}

bool PgDatabase::DoSimpleQuery(const char *query)
{
	IQuery *pQuery = DoQuery(query);
	if (!pQuery)
	{
		return false;
	}
	pQuery->Destroy();
	return true;
}

IQuery *PgDatabase::DoQuery(const char *query)
{
	PGresult *res = PQexec(m_pgsql, query);
	if(!res)
	{
		return NULL;
	}
	return new PgQuery(this, res);
}

bool PgDatabase::DoSimpleQueryEx(const char *query, size_t len)
{
	IQuery *pQuery = DoQueryEx(query, len);
	if (!pQuery)
	{
		return false;
	}
	pQuery->Destroy();
	return true;
}

IQuery *PgDatabase::DoQueryEx(const char *query, size_t len)
{
	PGresult *res = PQexec(m_pgsql, query);
	if(!res)
	{
		return NULL;
	}
	return new PgQuery(this, res);
}

IPreparedQuery *PgDatabase::PrepareQuery(const char *query, char *error, size_t maxlength, int *errCode)
{
	//@TODO: Fix me
	//MYSQL_STMT *stmt = mysql_stmt_init(m_mysql);
	//if (!stmt)
	//{
	//	if (error)
	//	{
	//		strncopy(error, GetError(errCode), maxlength);
	//	} else if (errCode) {
	//		*errCode = mysql_errno(m_mysql);
	//	}
	//	return NULL;
	//}

	//@TODO: Fix me
	//if (mysql_stmt_prepare(stmt, query, strlen(query)) != 0)
	//{
	//	if (error)
	//	{
	//		strncopy(error, mysql_stmt_error(stmt), maxlength);
	//	}
	//	if (errCode)
	//	{
	//		*errCode = mysql_stmt_errno(stmt);
	//	}
	//	mysql_stmt_close(stmt);
	//	return NULL;
	//}

	//@TODO: Fix me
	//return new MyStatement(this, stmt);
	return NULL;
}

bool PgDatabase::LockForFullAtomicOperation()
{
	if (!m_pFullLock)
	{
		m_pFullLock = threader->MakeMutex();
		if (!m_pFullLock)
		{
			return false;
		}
	}

	m_pFullLock->Lock();

	return true;
}

void PgDatabase::UnlockFromFullAtomicOperation()
{
	if (m_pFullLock)
	{
		m_pFullLock->Unlock();
	}
}

IDBDriver *PgDatabase::GetDriver()
{
	return &g_PgDriver;
}
