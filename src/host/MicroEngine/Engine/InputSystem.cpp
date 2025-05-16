#include "InputSystem.h"

#include <conio.h>

namespace MicroEngine
{
    static VirtualKey ReadKey()
    {
#ifdef _WIN32
        if (_kbhit())
        {
            int ch = _getch();
            if (ch == 0 || ch == 224)
            {
                // Arrow keys
                int arrow = _getch();
                switch (arrow)
                {
                case 72: return VirtualKey::ArrowUp;
                case 80: return VirtualKey::ArrowDown;
                case 75: return VirtualKey::ArrowLeft;
                case 77: return VirtualKey::ArrowRight;
                default: return VirtualKey::None;
                }
            }
            else
            {
                switch (ch)
                {
                case 27: return VirtualKey::Esc;
                case 'q': case 'Q': return VirtualKey::Q;
                case 'w': case 'W': return VirtualKey::W;
                case 'r': case 'R': return VirtualKey::R;
                default: return VirtualKey::None;
                }
            }
        }
        return VirtualKey::None;

#else // Unix (Linux/macOS)

        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

        VirtualKey result = VirtualKey::None;
        unsigned char ch;
        if (read(STDIN_FILENO, &ch, 1) > 0)
        {
            if (ch == 27) // ESC or arrow key
            {
                unsigned char seq[2];
                if (read(STDIN_FILENO, &seq[0], 1) > 0 && read(STDIN_FILENO, &seq[1], 1) > 0)
                {
                    if (seq[0] == '[')
                    {
                        switch (seq[1])
                        {
                        case 'A': result = VirtualKey::ArrowUp; break;
                        case 'B': result = VirtualKey::ArrowDown; break;
                        case 'C': result = VirtualKey::ArrowRight; break;
                        case 'D': result = VirtualKey::ArrowLeft; break;
                        }
                    }
                }
                else
                {
                    result = VirtualKey::Esc;
                }
            }
            else
            {
                switch (ch)
                {
                case 'q': case 'Q': result = VirtualKey::Q; break;
                case 'w': case 'W': result = VirtualKey::W; break;
                case 'r': case 'R': result = VirtualKey::R; break;
                }
            }
        }

        fcntl(STDIN_FILENO, F_SETFL, flags); // Restore flags
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore terminal
        return result;

#endif
    }


	void InputSystem::Update()
	{
        _lastKeyPressed = _currentKeyPressed;
        _currentKeyPressed = ReadKey();
	}

}