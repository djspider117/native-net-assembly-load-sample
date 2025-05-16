#pragma once

#include <string>
#include <vector>

#include "Component.h"

namespace MicroEngine
{
	struct Vector2Int
	{
		int X;
		int Y;
	};

	struct ConsoleTransform
	{
		Vector2Int Position{ 0,0 };
		Vector2Int Size{ 1, 1 };
		int Rotation{ 0 };
	};

	struct RenderInfo
	{
		char ColorPalleteIndex;
		char Symbol;
		bool Visible;
	};
}