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

#include "PgDriver.h"
#include "PgDatabase.h"
#include "sdk/smsdk_ext.h"

PgDriver g_PgDriver;

PgDriver::PgDriver()
{
	m_PgHandle = BAD_HANDLE;
}

void CloseDBList(List<PgDatabase *> &l)
{
	List<PgDatabase *>::iterator iter;
	for (iter=l.begin(); iter!=l.end(); iter++)
	{
		PgDatabase *db = (*iter);
		while (!db->Close())
		{
			/* Spool until it closes  */
		}
	}
	l.clear();
}

void PgDriver::Shutdown()
{
	List<PgDatabase *>::iterator iter;
	CloseDBList(m_PermDbs);

	if (m_PgHandle != BAD_HANDLE)
	{
		dbi->ReleaseHandle(m_PgHandle, DBHandle_Driver, myself->GetIdentity());
		m_PgHandle = BAD_HANDLE;
	}
}

const char *PgDriver::GetIdentifier()
{
	return "pgsql";
}

Handle_t PgDriver::GetHandle()
{
	if (m_PgHandle == BAD_HANDLE)
	{
		m_PgHandle = dbi->CreateHandle(DBHandle_Driver, this, myself->GetIdentity());
	}

	return m_PgHandle;
}

IdentityToken_t *PgDriver::GetIdentity()
{
	return myself->GetIdentity();
}

const char *PgDriver::GetProductName()
{
	return "PgSQL";
}

PGconn *Connect(const DatabaseInfo *info, char *error, size_t maxlength)
{
	//@TODO: Fix me
	//MYSQL *mysql = mysql_init(NULL);
	PGconn *psql;
	// There is no pg init function.
	const char *host = NULL, *socket = NULL;
	char connect_string[1024];

	if (info->maxTimeout > 0)
	{
		//@TODO: Fix me
		//mysql_options(mysql, MYSQL_OPT_CONNECT_TIMEOUT, (const char *)&(info->maxTimeout));
	}

	/* Have MySQL automatically reconnect if it times out or loses connection.
	 * This will prevent "MySQL server has gone away" errors after a while.
	 */
	//@TODO: Fix me
	//my_bool my_true = true;
	//mysql_options(mysql, MYSQL_OPT_RECONNECT, (const char *)&my_true);

	if (info->host[0] == '/')
	{
		host = "localhost";
		socket = info->host;
	}
	else
	{
		host = info->host;
		socket = NULL;
	}
	snprintf(connect_string, sizeof(connect_string),
		"hostaddr = '%s' port = '%d' dbname = '%s' user = '%s' password = '%s'",
		host, info->port, info->database, info->user, info->pass);
	//@TODO: Add possibility to set connection options.
	psql = PQconnectdb(connect_string);
	if(!psql)
	{
		snprintf(error, maxlength, "Error connecting to database server: %s", PQerrorMessage(psql));
		PQfinish(psql);
		return NULL;
	}
	return psql;
}

bool CompareField(const char *str1, const char *str2)
{
	if ((str1 == NULL && str2 != NULL)
		|| (str1 != NULL && str2 == NULL))
	{
		return false;
	}

	if (str1 == NULL && str2 == NULL)
	{
		return true;
	}

	return (strcmp(str1, str2) == 0);
}

IDatabase *PgDriver::Connect(const DatabaseInfo *info, bool persistent, char *error, size_t maxlength)
{
	if (persistent)
	{
		/* Try to find a matching persistent connection */
		List<PgDatabase *>::iterator iter;
		for (iter=m_PermDbs.begin();
			 iter!=m_PermDbs.end();
			 iter++)
		{
			PgDatabase *db = (*iter);
			const DatabaseInfo &other = db->GetInfo();
			if (CompareField(info->host, other.host)
				&& CompareField(info->user, other.user)
				&& CompareField(info->pass, other.pass)
				&& CompareField(info->database, other.database)
				&& (info->port == other.port))
			{
				db->IncReferenceCount();
				return db;
			}
		}
	}

	//@TODO: Fix me
	//MYSQL *mysql = ::Connect(info, error, maxlength);
	//if (!mysql)
	//{
	//	return NULL;
	//}

	//@TODO: Fix me
	PgDatabase *db = new PgDatabase(NULL, info, persistent);

	if (persistent)
	{
		m_PermDbs.push_back(db);
	}
	
	return db;
}

void PgDriver::RemoveFromList(PgDatabase *pdb, bool persistent)
{
	if (persistent)
	{
		m_PermDbs.remove(pdb);
	}
}

bool PgDriver::IsThreadSafe()
{
	//@TODO: Fix me
	//return (mysql_thread_safe() != 0);
	return false;
}

bool PgDriver::InitializeThreadSafety()
{
	//@TODO: Fix me
	//return (mysql_thread_init() == 0);
	return false;
}

void PgDriver::ShutdownThreadSafety()
{
	//@TODO: Fix me
	//mysql_thread_end();
}

unsigned int strncopy(char *dest, const char *src, size_t count)
{
	if (!count)
	{
		return 0;
	}

	char *start = dest;
	while ((*src) && (--count))
	{
		*dest++ = *src++;
	}
	*dest = '\0';

	return (dest - start);
}
