/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod MySQL Extension
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

#include "MyDatabase.h"
#include "smsdk_ext.h"
#include "MyBasicResults.h"
#include "MyStatement.h"

//@TODO: Fix Me
DBType GetOurType(/*enum_field_types type*/)
{
	//@TODO: Fix Me
	/*
	switch (type)
	{
	case MYSQL_TYPE_DOUBLE:
	case MYSQL_TYPE_FLOAT:
		{
			return DBType_Float;
		}
	case MYSQL_TYPE_TINY:
	case MYSQL_TYPE_SHORT:
	case MYSQL_TYPE_LONG:
	case MYSQL_TYPE_INT24:
	case MYSQL_TYPE_YEAR:
	case MYSQL_TYPE_BIT:
		{
			return DBType_Integer;
		}
	case MYSQL_TYPE_LONGLONG:
	case MYSQL_TYPE_DATE:
	case MYSQL_TYPE_TIME:
	case MYSQL_TYPE_DATETIME:
	case MYSQL_TYPE_TIMESTAMP:
	case MYSQL_TYPE_NEWDATE:
	case MYSQL_TYPE_VAR_STRING:
	case MYSQL_TYPE_VARCHAR:
	case MYSQL_TYPE_STRING:
	case MYSQL_TYPE_NEWDECIMAL:
	case MYSQL_TYPE_DECIMAL:
	case MYSQL_TYPE_ENUM:
	case MYSQL_TYPE_SET:
		{
			return DBType_String;
		}

	case MYSQL_TYPE_TINY_BLOB:
	case MYSQL_TYPE_MEDIUM_BLOB:
	case MYSQL_TYPE_LONG_BLOB:
	case MYSQL_TYPE_BLOB:
	case MYSQL_TYPE_GEOMETRY:
		{
			return DBType_Blob;
		}
	default:
		{
			return DBType_String;
		}
	}
	*/
	return DBType_Unknown;
}

MyDatabase::MyDatabase(PGconn *pgsql, const DatabaseInfo *info, bool persistent)
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

MyDatabase::~MyDatabase()
{
	//@TODO: Fix me
	//mysql_close(m_mysql);
	m_pgsql = NULL;

	m_pRefLock->DestroyThis();
	if (m_pFullLock)
	{
		m_pFullLock->DestroyThis();
	}
}

void MyDatabase::IncReferenceCount()
{
	m_pRefLock->Lock();
	m_refcount++;
	m_pRefLock->Unlock();
}

bool MyDatabase::Close()
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
		g_MyDriver.RemoveFromList(this, true);
	}

	/* Finally, free our resource(s) */
	delete this;

	return true;
}

const DatabaseInfo &MyDatabase::GetInfo()
{
	return m_Info;
}

unsigned int MyDatabase::GetInsertID()
{
	//@TODO: Fix me
	//return (unsigned int)mysql_insert_id(m_mysql);
	return 0;
}

unsigned int MyDatabase::GetAffectedRows()
{
	//@TODO: Fix me
	//return (unsigned int)mysql_affected_rows(m_mysql);
	return 0;
}

const char *MyDatabase::GetError(int *errCode)
{
	if (errCode)
	{
		//@TODO: Fix me
		//*errCode = mysql_errno(m_mysql);
	}

	//@TODO: Fix me
	//return mysql_error(m_mysql);
	return "";
}

bool MyDatabase::QuoteString(const char *str, char buffer[], size_t maxlength, size_t *newSize)
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

	//@TODO: Fix me
	//needed = mysql_real_escape_string(m_mysql, buffer, str, size);
	if (newSize)
	{
		*newSize = (size_t)needed;
	}

	return true;
}

bool MyDatabase::DoSimpleQuery(const char *query)
{
	IQuery *pQuery = DoQuery(query);
	if (!pQuery)
	{
		return false;
	}
	pQuery->Destroy();
	return true;
}

IQuery *MyDatabase::DoQuery(const char *query)
{
	//@TODO: Fix me
	if (TRUE /*mysql_real_query(m_mysql, query, strlen(query)) != 0*/ )
	{
		return NULL;
	}

	//@TODO: Fix me
	//MYSQL_RES *res = NULL;
	//if (mysql_field_count(m_mysql))
	//{
	//	res = mysql_store_result(m_mysql);
	//	if (!res)
	//	{
	//		return NULL;
	//	}
	//}

	//@TODO: Fix me
	//return new MyQuery(this, res);
	return NULL;
}

bool MyDatabase::DoSimpleQueryEx(const char *query, size_t len)
{
	IQuery *pQuery = DoQueryEx(query, len);
	if (!pQuery)
	{
		return false;
	}
	pQuery->Destroy();
	return true;
}

IQuery *MyDatabase::DoQueryEx(const char *query, size_t len)
{
	//@TODO: Fix me
	if ( TRUE /*mysql_real_query(m_mysql, query, len) != 0*/ )
	{
		return NULL;
	}

	//@TODO: Fix me
	//MYSQL_RES *res = NULL;
	//if (mysql_field_count(m_mysql))
	//{
	//	res = mysql_store_result(m_mysql);
	//	if (!res)
	//	{
	//		return NULL;
	//	}
	//}

	//@TODO: Fix me
	//return new MyQuery(this, res);
	return NULL;
}

IPreparedQuery *MyDatabase::PrepareQuery(const char *query, char *error, size_t maxlength, int *errCode)
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

bool MyDatabase::LockForFullAtomicOperation()
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

void MyDatabase::UnlockFromFullAtomicOperation()
{
	if (m_pFullLock)
	{
		m_pFullLock->Unlock();
	}
}

IDBDriver *MyDatabase::GetDriver()
{
	return &g_MyDriver;
}
