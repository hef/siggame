/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod BinTools Extension
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

#ifndef _INCLUDE_SOURCEMOD_CALLMAKER_H_
#define _INCLUDE_SOURCEMOD_CALLMAKER_H_


#include "CallWrapper.h"
#include "HookWrapper.h"

using namespace SourceMod;

class CallMaker : public IBinTools
{
public: //IBinTools
	ICallWrapper *CreateCall(void *address,
		CallConvention cv,
		const PassInfo *retInfo,
		const PassInfo paramInfo[],
		unsigned int numParams);
	ICallWrapper *CreateVCall(unsigned int vtblIdx,
		unsigned int vtblOffs,
		unsigned int thisOffs,
		const PassInfo *retInfo,
		const PassInfo paramInfo[],
		unsigned int numParams);
};

class CallMaker2 
#if defined HOOKING_ENABLED
	: public IBinTools2
#endif
{
public: //IBinTools2
	virtual ICallWrapper *CreateCall(void *address,
		const SourceHook::ProtoInfo *protoInfo);
	virtual ICallWrapper *CreateVirtualCall(const SourceHook::ProtoInfo *protoInfo,
		const SourceHook::MemFuncInfo *info);
#if defined HOOKING_ENABLED
	virtual IHookWrapper *CreateVirtualHook(SourceHook::ISourceHook *pSH, 
		const SourceHook::ProtoInfo *protoInfo, 
		const SourceHook::MemFuncInfo *info, 
		VIRTUAL_HOOK_PROTO f);
#endif
};

extern CallMaker2 g_CallMaker2;

SourceHook::ProtoInfo::CallConvention GetSHCallConvention(SourceMod::CallConvention cv);
SourceMod::CallConvention GetSMCallConvention(SourceHook::ProtoInfo::CallConvention cv);
SourceHook::PassInfo::PassType GetSHPassType(SourceMod::PassType type);
SourceMod::PassType GetSMPassType(int type);
void GetSMPassInfo(SourceMod::PassInfo *out, const SourceHook::PassInfo *in);



#endif //_INCLUDE_SOURCEMOD_CALLMAKER_H_
