#pragma once

#include <memory>
#include <vector>
#include <string>

#include "Engine.h"

namespace MicroEngine
{
	class Application
	{
	public:
		Application(int argc, char* argv[]);
		Application(const Application&) = delete;
		Application(const Application&&) = delete;

		void Run();

	private:
		std::vector<std::string> _cmdLineArgs;
	};
}
