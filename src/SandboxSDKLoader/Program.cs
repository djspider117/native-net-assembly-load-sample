using MicroEngineSDK;

namespace SandboxSDKLoader;

internal class Program
{
    static void Main(string[] args)
    {
        ComponentRegistry.RegisterFromAssembly(@"C:\Work\native-net-assembly-load-sample\src\host\MicroEngine\out\build\net9.0\Game.dll");
        ComponentRegistry.GameEntry?.Run();
    }
}
