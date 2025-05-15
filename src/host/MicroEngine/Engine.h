#pragma once

#include <string>
#include <memory>

#include "ConsoleRenderer.h"
#include "NetRuntimeHost.h"
#include "InputSystem.h"
#include "Scene.h"

namespace MicroEngine
{
	class Engine
	{
	public:
		Engine(std::wstring gameAssemblyPath);
		Engine(const Engine&) = delete;
		Engine(const Engine&&) = delete;

		void LoadNetRuntime();
		void Run();

		inline void SetActiveScene(Scene* scene) { _sceneToSwitch = scene; }
		inline Scene* GetActiveScene() const { return _activeScene; }

	private:
		std::wstring _gameAssemblyPath;

		Scene* _sceneToSwitch;
		Scene* _activeScene;
		InputSystem _inputSys;
		std::unique_ptr<ConsoleRenderer> _renderer;
		NetRuntimeHost _runtimeHost;
	};

	void PostEngineShutdown();

	extern std::unique_ptr<Engine> g_Engine;
	extern std::vector<Scene*> g_SceneRepository;
}