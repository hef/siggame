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
#include <stdlib.h>
#include "PgBasicResults.h"

//@TODO: Fix Me
PgBasicResults::PgBasicResults(PGresult *res)
: m_pRes(res)
{
	Update();
}

PgBasicResults::~PgBasicResults()
{
}

void PgBasicResults::Update()
{
	if (m_pRes)
	{
		m_ColCount = (unsigned int)PQnfields(m_pRes);
		m_RowCount = (unsigned int)PQntuples(m_pRes);
		m_CurRow = 0;
		//@TODO: Fix Me
		//m_Row = NULL;
	}
}

unsigned int PgBasicResults::GetRowCount()
{
	return m_RowCount;
}

unsigned int PgBasicResults::GetFieldCount()
{
	return m_ColCount;
}

bool PgBasicResults::FieldNameToNum(const char *name, unsigned int *columnId)
{
	unsigned int total = GetFieldCount();

	for (unsigned int i=0; i<total; i++)
	{
		if (strcmp(FieldNumToName(i), name) == 0)
		{
			*columnId = i;
			return true;
		}
	}

	return false;
}

const char *PgBasicResults::FieldNumToName(unsigned int colId)
{
	if (colId >= GetFieldCount())
	{
		return NULL;
	}
	return PQfname(m_pRes, colId);;
}

bool PgBasicResults::MoreRows()
{
	return (m_CurRow < m_RowCount);
}

IResultRow *PgBasicResults::FetchRow()
{
	if (m_CurRow >= m_RowCount)
	{
		/* Put us one after so we know to block CurrentRow() */
		m_CurRow = m_RowCount + 1;
		return NULL;
	}
	
	// solution for Pg:
	// Pg's only value retrieval is in a single row/col.
	// thers is no get-row functionality.
	// However, we know what row we're currently looking at (m_CurRow)
	// and the result to this function is 'this'.  so just implement the
	// appropriate IResultRow implementations in this class to use m_CurRow &
	// the supplied column parameter to find the row/col value we're looking for.
	//@TODO: Fix me
	//m_Row = mysql_fetch_row(m_pRes);
	//m_Lengths = mysql_fetch_lengths(m_pRes);
	// side note: Pg defines PQgetlength(res, row, col) which tells you how large a value is.
	// so, with Pg, we don't actually need to copy the length data, m_Lengths is useless then.

	m_CurRow++;
	return this;
}

IResultRow *PgBasicResults::CurrentRow()
{
	if (!m_pRes
		|| !m_CurRow
		|| m_CurRow > m_RowCount)
	{
		return NULL;
	}
	
	return this;
}

bool PgBasicResults::Rewind()
{
	m_CurRow = 0;
	return true;
}

DBType PgBasicResults::GetFieldType(unsigned int field)
{
	if (field >= m_ColCount)
	{
		return DBType_Unknown;
	}

	//@TODO: Fix me
	//MYSQL_FIELD *fld = mysql_fetch_field_direct(m_pRes, field);
	if ( TRUE /*!fld*/ )
	{
		return DBType_Unknown;
	}

	//@TODO: Fix Me
	//return GetOurType(/*fld->type*/);
	return DBType_Unknown;
}

DBType PgBasicResults::GetFieldDataType(unsigned int field)
{
	DBType type = GetFieldType(field);
	if (type == DBType_Blob)
	{
		return DBType_Blob;
	} else {
		return DBType_String;
	}
}

bool PgBasicResults::IsNull(unsigned int columnId)
{
	if (columnId >= m_ColCount)
	{
		return true;
	}

	//@TODO: Fix Me
	return FALSE; //(m_Row[columnId] == NULL);
}

DBResult PgBasicResults::GetString(unsigned int columnId, const char **pString, size_t *length)
{
	if (columnId >= m_ColCount)
	{
		return DBVal_Error;
	} 
	//@TODO: Fix Me
	else if (FALSE /*m_Row[columnId] == NULL*/) 
	{
		*pString = "";
		if (length)
		{
			*length = 0;
		}
		return DBVal_Null;
	}

	//@TODO: Fix Me
	//*pString = m_Row[columnId];

	//@TODO: see if this can actually work this way.. I don't think we populate m_Lengths
	if (length)
	{
		*length = (size_t)m_Lengths[columnId];
	}

	return DBVal_Data;
}

DBResult PgBasicResults::CopyString(unsigned int columnId, 
									char *buffer, 
									size_t maxlength, 
									size_t *written)
{
	DBResult res;
	const char *str;
	if ((res=GetString(columnId, &str, NULL)) == DBVal_Error)
	{
		return DBVal_Error;
	}

	size_t wr = strncopy(buffer, str, maxlength);
	if (written)
	{
		*written = wr;
	}

	return res;
}

size_t PgBasicResults::GetDataSize(unsigned int columnId)
{
	//@TODO: see if this can actually work this way.. I don't think we populate m_Lengths
	if (columnId >= m_ColCount)
	{
		return 0;
	}

	return (size_t)m_Lengths[columnId];
}

DBResult PgBasicResults::GetFloat(unsigned int col, float *fval)
{
	if (col >= m_ColCount)
	{
		return DBVal_Error;
	} 
	//@TODO: Fix Me
	else if (FALSE /*m_Row[col] == NULL*/) 
	{
		*fval = 0.0f;
		return DBVal_Null;
	}

	//@TODO: Fix Me
	//*fval = (float)atof(m_Row[col]);

	return DBVal_Data;
}

DBResult PgBasicResults::GetInt(unsigned int col, int *val)
{
	if (col >= m_ColCount)
	{
		return DBVal_Error;
	}
	//@TODO: Fix Me
	else if (FALSE /*m_Row[col] == NULL*/) 
	{
		*val = 0;
		return DBVal_Null;
	}

	//@TODO: Fix Me
	//*val = atoi(m_Row[col]);

	return DBVal_Data;
}

DBResult PgBasicResults::GetBlob(unsigned int col, const void **pData, size_t *length)
{
	if (col >= m_ColCount)
	{
		return DBVal_Error;
	} 
	//@TODO: Fix Me
	else if (FALSE /*m_Row[col] == NULL*/) 
	{
		*pData = NULL;
		if (length)
		{
			*length = 0;
		}
		return DBVal_Null;
	}

	//@TODO: Fix Me
	//*pData = m_Row[col];

	if (length)
	{
		*length = (size_t)m_Lengths[col];
	}

	return DBVal_Data;
}

DBResult PgBasicResults::CopyBlob(unsigned int columnId, void *buffer, size_t maxlength, size_t *written)
{
	const void *addr;
	size_t length;
	DBResult res;

	if ((res=GetBlob(columnId, &addr, &length)) == DBVal_Error)
	{
		return DBVal_Error;
	}

	if (addr == NULL)
	{
		return DBVal_Null;
	}

	if (length > maxlength)
	{
		length = maxlength;
	}

	memcpy(buffer, addr, length);
	if (written)
	{
		*written = length;
	}

	return res;
}

//@TODO: Fix Me
PgQuery::PgQuery(PgDatabase *db, PGresult *results)
: m_pParent(db), m_rs(results)
{
	m_pParent->IncReferenceCount();
}

IResultSet *PgQuery::GetResultSet()
{
	if (m_rs.m_pRes == NULL)
	{
		return NULL;
	}

	return &m_rs;
}

bool PgQuery::FetchMoreResults()
{
	// Postgres never has partial result sets.
	return false;
}

void PgQuery::Destroy()
{
	/* :TODO: All this rot should be moved into the destructor,
	 * and the Update() function needs to not be so stupid.
	 * ... there is no virtualized destructor.  -Lyfe
	 */
	PQclear(m_rs.m_pRes);

	/* Tell our parent we're done */
	// huh?  -Lyfe
	m_pParent->Close();

	/* Self destruct */
	delete this;
}
