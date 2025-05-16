#pragma once

#include <string>
#include <nethost.h>
#include <coreclr_delegates.h>
#include <hostfxr.h>

namespace MicroEngine
{
	typedef hostfxr_initialize_for_runtime_config_fn HostFxrInitDelegate;
	typedef hostfxr_get_runtime_delegate_fn HostFxrGetRuntimeDelegate;
	typedef hostfxr_close_fn HostFxrCloseDelegate;
	typedef load_assembly_and_get_function_pointer_fn LoadAssemblyAndGetFunctionPointerDelegate;
	typedef void (CORECLR_DELEGATE_CALLTYPE* ManagedDelegate)();
	typedef void (CORECLR_DELEGATE_CALLTYPE* ManagedInitDelegate)(void*, int);

	class NetRuntimeHost
	{
	public:
		NetRuntimeHost() = default;
		NetRuntimeHost(const NetRuntimeHost&) = delete;
		NetRuntimeHost(const NetRuntimeHost&&) = delete;

		bool Load(std::wstring assemblyPath);

		inline const ManagedDelegate& GetEngineTickDelegate() const { return _engineApi_Tick; }

	private:
		bool LoadHostFXR();
		LoadAssemblyAndGetFunctionPointerDelegate GetLoadAssemblyDelegate(const char_t* config_path) const;

		HostFxrInitDelegate _initFxr = nullptr;
		HostFxrGetRuntimeDelegate _getDelegate = nullptr;
		HostFxrCloseDelegate _closeFxr = nullptr;

		ManagedInitDelegate _engineApi_Init = nullptr;
		ManagedDelegate _engineApi_Tick = nullptr;
	};
}