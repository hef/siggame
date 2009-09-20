#ifndef _INCLUDE_SOURCEPAWN_JIT_RUNTIME_H_
#define _INCLUDE_SOURCEPAWN_JIT_RUNTIME_H_

#include <sp_vm_api.h>
#include "jit_shared.h"
#include "sp_vm_function.h"

class BaseContext;
class JitFunction;

class DebugInfo : public IPluginDebugInfo
{
public:
	DebugInfo(sp_plugin_t *plugin);
public:
	int LookupFile(ucell_t addr, const char **filename);
	int LookupFunction(ucell_t addr, const char **name);
	int LookupLine(ucell_t addr, uint32_t *line);
private:
	sp_plugin_t *m_pPlugin;
};

/* Jit wants fast access to this so we expose things as public */
class BaseRuntime : public SourcePawn::IPluginRuntime
{
public:
	BaseRuntime();
	~BaseRuntime();
public:
	virtual int CreateBlank(uint32_t heastk);
	virtual int CreateFromMemory(sp_file_hdr_t *hdr, uint8_t *base);
	virtual bool IsDebugging();
	virtual IPluginDebugInfo *GetDebugInfo();
	virtual int FindNativeByName(const char *name, uint32_t *index);
	virtual int GetNativeByIndex(uint32_t index, sp_native_t **native);
	virtual uint32_t GetNativesNum();
	virtual int FindPublicByName(const char *name, uint32_t *index);
	virtual int GetPublicByIndex(uint32_t index, sp_public_t **publicptr);
	virtual uint32_t GetPublicsNum();
	virtual int GetPubvarByIndex(uint32_t index, sp_pubvar_t **pubvar);
	virtual int FindPubvarByName(const char *name, uint32_t *index);
	virtual int GetPubvarAddrs(uint32_t index, cell_t *local_addr, cell_t **phys_addr);
	virtual uint32_t GetPubVarsNum();
	virtual IPluginFunction *GetFunctionByName(const char *public_name);
	virtual IPluginFunction *GetFunctionById(funcid_t func_id);
	virtual IPluginContext *GetDefaultContext();
	virtual int ApplyCompilationOptions(ICompilation *co);
	virtual void SetPauseState(bool paused);
	virtual bool IsPaused();
	virtual size_t GetMemUsage();
	JitFunction *GetJittedFunction(uint32_t idx);
	uint32_t AddJittedFunction(JitFunction *fn);
public:
	BaseContext *GetBaseContext();
private:
	sp_plugin_t m_plugin;
	unsigned int m_NumFuncs;
	unsigned int m_MaxFuncs;
	JitFunction **m_FuncCache;
public:
	DebugInfo m_Debug;
	sp_plugin_t *m_pPlugin;
	BaseContext *m_pCtx;
	CFunction **m_PubFuncs;
	JitFunction **m_PubJitFuncs;
	ICompilation *m_pCo;
	unsigned int m_CompSerial;
};

#endif //_INCLUDE_SOURCEPAWN_JIT_RUNTIME_H_
