#if _WIN32
#include <Windows.h>
#else
#include <dlfcn.h> 
#endif

#include <iostream>
#include <assert.h>
#include <filesystem>

#include "NetRuntimeHost.h"

using std::filesystem::path;

namespace MicroEngine
{
	constexpr const char_t* ENGINE_API = L"MicroEngineSDK.EngineAPI, MicroEngineSDK";
	constexpr const char_t* ENGINE_API_INITIALIZE = L"Initialize";
	constexpr const char_t* ENGINE_API_TICK = L"Tick";

	static void* LoadLibraryInternal(const char_t* path)
	{
#if _WIN32
		return LoadLibraryW((LPCWSTR)path);
#else
		return load_library(path);
#endif
	}

	static void* GetFunction(void* library, const char* functionName)
	{
#if _WIN32
		return GetProcAddress((HMODULE)library, functionName);
#else
		return get_export(library, functionName);
#endif
	}

	bool NetRuntimeHost::Load(std::wstring assemblyPath)
	{
		if (!LoadHostFXR())
			return false;

		path configPath(L"..\\..\\net9.0\\MicroEngineSDK.runtimeconfig.json");

		// temp hardcoded
		auto loadDelegate = GetLoadAssemblyDelegate(configPath.c_str());
		
		auto hr = loadDelegate(
			assemblyPath.c_str(), 
			ENGINE_API,
			ENGINE_API_INITIALIZE,
			UNMANAGEDCALLERSONLY_METHOD,
			nullptr, // reserved
			(void**)&_engineApi_Init);

		assert(hr == 0 && _engineApi_Init != nullptr);

		hr = loadDelegate(
			assemblyPath.c_str(),
			ENGINE_API,
			ENGINE_API_TICK,
			UNMANAGEDCALLERSONLY_METHOD,
			nullptr, // reserved
			(void**)&_engineApi_Tick);

		assert(hr == 0 && _engineApi_Tick != nullptr);

		path gameDll = configPath.parent_path() / "Game.dll";
		std::wstring pathString = gameDll.generic_wstring();
		_engineApi_Init((void*)(pathString.c_str()), pathString.length());
	}

	bool NetRuntimeHost::LoadHostFXR()
	{
		char_t buffer[255];
		size_t buffer_size = sizeof(buffer) / sizeof(char_t);
		int rc = get_hostfxr_path(buffer, &buffer_size, nullptr);
		if (rc != 0)
			return false;

		void* lib = LoadLibraryInternal(buffer);
		_initFxr = (HostFxrInitDelegate)GetFunction(lib, "hostfxr_initialize_for_runtime_config");
		_getDelegate = (HostFxrGetRuntimeDelegate)GetFunction(lib, "hostfxr_get_runtime_delegate");
		_closeFxr = (HostFxrCloseDelegate)GetFunction(lib, "hostfxr_close");

		return (_initFxr && _getDelegate && _closeFxr);
	}

	LoadAssemblyAndGetFunctionPointerDelegate NetRuntimeHost::GetLoadAssemblyDelegate(const char_t* config_path) const
	{
		void* load_assembly_and_get_function_pointer = nullptr;
		hostfxr_handle cxt = nullptr;
		int rc = _initFxr(config_path, nullptr, &cxt);
		if (rc != 0 || cxt == nullptr)
		{
			std::cerr << "Init failed: " << std::hex << std::showbase << rc << std::endl;
			_closeFxr(cxt);
			return nullptr;
		}

		// Get the load assembly function pointer
		rc = _getDelegate(
			cxt,
			hdt_load_assembly_and_get_function_pointer,
			&load_assembly_and_get_function_pointer);

		if (rc != 0 || load_assembly_and_get_function_pointer == nullptr)
			std::cerr << "Get delegate failed: " << std::hex << std::showbase << rc << std::endl;

		_closeFxr(cxt);
		return (LoadAssemblyAndGetFunctionPointerDelegate)load_assembly_and_get_function_pointer;
	}

}