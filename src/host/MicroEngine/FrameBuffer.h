#pragma once
#include <stdlib.h>
#include <cstring>

constexpr auto EMPTY_PIXEL = ' ';

namespace MicroEngine
{
	class FrameBuffer final
	{
	public:
		FrameBuffer(char w, char h);

		~FrameBuffer();

		FrameBuffer(const FrameBuffer&) = delete;
		FrameBuffer(const FrameBuffer&&) = delete;

		inline const char* GetFrameData() const { return _frame; }
		inline char GetWidth() const { return _width; }
		inline char GetHeight() const { return _height; }

		void SetPixel(char x, char y, char c);

		void Clear(char fill = EMPTY_PIXEL);

	private:

		char _width;
		char _height;
		char* _frame;
	};
}