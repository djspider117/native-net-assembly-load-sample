#include "FrameBuffer.h"

namespace MicroEngine
{
	FrameBuffer::FrameBuffer(char w, char h) :
		_width(w),
		_height(h)
	{
		_frame = (char*)malloc((size_t)(w * h));
		Clear();
	}

	FrameBuffer::~FrameBuffer()
	{
		free((void*)_frame);
	}

	void FrameBuffer::SetPixel(char x, char y, char c)
	{
		if (x >= 0 && x < _width && y >= 0 && y < _height)
			_frame[y * _width + x] = c;
	}
	
	void FrameBuffer::Clear(char fill)
	{
		std::memset(_frame, fill, (size_t)(_width * _height));
	}
}