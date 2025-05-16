#pragma once

#include <string>
#include <memory>
#include <chrono>

#include "Common.h"
#include "ConsoleRenderer.h"
#include "NetRuntimeHost.h"
#include "InputSystem.h"
#include "Scene.h"

namespace MicroEngine
{
	class ENGINE_API Engine
	{
	public:
		Engine(std::wstring gameAssemblyPath);
		Engine(const Engine&) = delete;
		Engine(const Engine&&) = delete;

		void LoadNetRuntime();
		void Run();

		inline void SetActiveScene(Scene* scene) { _sceneToSwitch = scene; }
		inline InputSystem* GetInputSystem() const { return (InputSystem*)&_inputSys; }
		inline Scene* GetActiveScene() const 
		{
			if (_activeScene == nullptr && _sceneToSwitch != nullptr)
				return _sceneToSwitch;

			return _activeScene;
		}

	private:
		std::wstring _gameAssemblyPath;

		Scene* _sceneToSwitch;
		Scene* _activeScene;

		InputSystem _inputSys;
		std::unique_ptr<ConsoleRenderer> _renderer;
		NetRuntimeHost _runtimeHost;
	};

	void PostEngineShutdown();

	extern ENGINE_API std::unique_ptr<Engine> g_Engine;
	extern ENGINE_API std::vector<Scene*> g_SceneRepository;
}