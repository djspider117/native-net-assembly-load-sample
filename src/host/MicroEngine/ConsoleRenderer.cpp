#include "ConsoleRenderer.h"
#include "Scene.h"
#include "GameObject.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>

namespace MicroEngine
{
	ConsoleRenderer::ConsoleRenderer(char w, char h) 
	{
		_frameBuffer = std::make_unique<FrameBuffer>(w, h);
#ifdef _WIN32
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info{};
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);
#else
		std::cout << "\x1b[?25l"
#endif
	}

	void ConsoleRenderer::RenderScene(const Scene* scene)
	{
		for (auto& go : scene->GetGameObjects())
		{
			// TODO: update renderer components
		}
	}
	void ConsoleRenderer::Present()
	{
#ifdef _WIN32
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD origin = { 0, 0 };
		SetConsoleCursorPosition(hConsole, origin);
#else
		std::cout << "\x1b[H"; // ANSI escape code to move cursor to top-left
#endif
		const char* frame = _frameBuffer->GetFrameData();
		char width = _frameBuffer->GetWidth();
		char height = _frameBuffer->GetHeight();
		for (char y = 0; y < height; ++y)
		{
			for (char x = 0; x < width; ++x)
			{
				std::cout << frame[y * width + x];
			}
			std::cout << '\n';
		}
	}
}