using System.Runtime.InteropServices;

namespace MicroEngineSDK;

public class Input
{

    public static bool IsKeyDown(VirtualKey vk)
    {
        var tvk = (VirtualKey)GetCurrentFrameKeyPressed();
        return tvk == vk;
    }

    public static bool WasKeyDown(VirtualKey vk)
    {
        var tvk = (VirtualKey)GetLastFrameKeyPressed();
        return tvk == vk;
    }

    [DllImport(EngineAPINative.ENGINE_PATH)]
    internal static extern int GetCurrentFrameKeyPressed();

    [DllImport(EngineAPINative.ENGINE_PATH)]
    internal static extern int GetLastFrameKeyPressed();
}

public enum VirtualKey
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
