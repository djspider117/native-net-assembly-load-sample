#include "Application.h"

namespace MicroEngine
{
	extern std::unique_ptr<Engine> g_Engine;

	Application::Application(int argc, char* argv[])
	{
		_cmdLineArgs.resize(argc);
		for (int i = 0; i < argc; i++)
		{
			_cmdLineArgs.push_back(argv[i]);
		}
	}

	void Application::Run()
	{
		g_Engine->LoadNetRuntime();
		g_Engine->Run();
	}
}