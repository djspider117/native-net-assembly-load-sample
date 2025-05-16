using System.Runtime.InteropServices;

namespace MicroEngineSDK;

public static class Engine
{
    private static List<Component> _unstarted = [];
    private static List<Component> _started = [];

    public static void RegisterInstantiatedComponent(Component component)
    {
        _unstarted.Add(component);
    }

    public static void RunStart()
    {
        foreach (var item in _unstarted)
        {
            item.Start();
            _started.Add(item);
        }
        _unstarted.Clear();
    }

    public static void RunUpdate()
    {
        foreach (var item in _started)
        {
            item.Update();
        }
    }

    public static void SetActiveScene(Scene scene)
    {
        SetActiveScene(scene.NativeObject);
    }

    [DllImport(EngineAPINative.ENGINE_PATH)]
    private static extern void SetActiveScene(IntPtr scene);
}
