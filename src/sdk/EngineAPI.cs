using System.Runtime.InteropServices;

namespace MicroEngineSDK;

internal class EngineAPI
{
    [UnmanagedCallersOnly(EntryPoint = nameof(Initialize))]
    internal static void Initialize()
    {
        ComponentRegistry.RegisterFromAssembly("GameLogic.dll");
        ComponentRegistry.GameEntry?.Run();
    }

    [UnmanagedCallersOnly(EntryPoint = nameof(Tick))]
    internal static void Tick()
    {
    }
}
