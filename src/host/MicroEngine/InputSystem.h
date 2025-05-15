#pragma once

namespace MicroEngine
{
	enum class VirtualKey
	{
		None,
		Esc,
		ArrowUp,
		ArrowDown,
		ArrowLeft,
		ArrowRight,
		Q,
		W,
		R
	};

	class InputSystem
	{
	public:
		void Update();

		const VirtualKey GetCurrentFrameKeyPressed() const { return _currentKeyPressed; }
		const VirtualKey GetLastFrameKeyPressed() const { return _lastKeyPressed; }

	private:
		VirtualKey _currentKeyPressed;
		VirtualKey _lastKeyPressed;
	};
}