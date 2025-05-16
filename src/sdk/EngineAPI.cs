using System.Runtime.InteropServices;

namespace MicroEngineSDK;

internal class EngineAPI
{

    [UnmanagedCallersOnly(EntryPoint = nameof(Initialize))]
    internal static void Initialize(IntPtr ga_cstr, int len)
    {
        var gameDll = Marshal.PtrToStringAuto(ga_cstr, len)!;
        Console.WriteLine("Initializing EngineAPI");
        Console.WriteLine($"Loading {gameDll}");

        ComponentRegistry.RegisterFromAssembly(gameDll);

        Console.WriteLine("Starting game...");
        ComponentRegistry.GameEntry?.Run();
    }

    [UnmanagedCallersOnly(EntryPoint = nameof(Tick))]
    internal static void Tick()
    {
        Engine.RunStart();
        Engine.RunUpdate();
    }
}
