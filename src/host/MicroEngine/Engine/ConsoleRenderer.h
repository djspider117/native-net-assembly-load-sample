#pragma once

#include "Common.h"
#include "Scene.h"
#include <memory>
#include "FrameBuffer.h"

namespace MicroEngine
{
	class ENGINE_API ConsoleRenderer
	{
	public:
		ConsoleRenderer(char w, char h);

		void RenderScene(const Scene* scene);
		void Present();

	private:
		std::unique_ptr<FrameBuffer> _frameBuffer;
	};
}