#include <thread>
#include "Engine.h"
#include "ConsoleRenderer.h"

namespace EngineConfig
{
	constexpr long long FrameSleepTimeMs = 33;
}

namespace MicroEngine
{
	std::unique_ptr<Engine> g_Engine = std::make_unique<Engine>(L"MicroEngineSDK.dll");

	Engine::Engine(std::wstring gameAssemblyPath) :
		_gameAssemblyPath(gameAssemblyPath),
		_inputSys(),
		_activeScene(nullptr),
		_sceneToSwitch(nullptr),
		_renderer(std::make_unique<ConsoleRenderer>(8, 8))
	{

	}
	void Engine::LoadNetRuntime()
	{
		_runtimeHost.Load(_gameAssemblyPath);
	}

	void Engine::Run()
	{
		bool shouldRun = true;
		do
		{
			if (_sceneToSwitch != nullptr)
			{
				_activeScene = _sceneToSwitch;
				_sceneToSwitch = nullptr;
			}

			_inputSys.Update();
			if (_activeScene != nullptr)
			{
				_runtimeHost.GetEngineTickDelegate()();
				_activeScene->Update();
				_renderer->RenderScene(_activeScene);
			}

			_renderer->Present();
			shouldRun = _inputSys.GetCurrentFrameKeyPressed() != VirtualKey::Esc;
			std::this_thread::sleep_for(std::chrono::milliseconds(EngineConfig::FrameSleepTimeMs));
		} while (shouldRun);
	}
	void PostEngineShutdown()
	{
		for(Scene* item : g_SceneRepository)
		{
			delete item;
		}
	}
}