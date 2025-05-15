using System.Runtime.InteropServices;

namespace MicroEngineSDK;

public static class EngineAPINative
{
    public const string ENGINE_PATH = "MicroEngine";
}

// scene
public static class SceneAPINative
{

    [DllImport(EngineAPINative.ENGINE_PATH)]
    public static extern IntPtr CreateScene(string name, int id);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    public static extern string GetSceneName(IntPtr scene);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    public static extern int GetSceneId(IntPtr scene);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    public static extern void SetActiveScene(IntPtr scene);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    public static extern IntPtr CreateGameObject(IntPtr scene, string name);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    public static extern void AddGameObjectToScene(IntPtr scene, IntPtr go);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    public static extern IntPtr CreateGameObjectForCurrentScene(string name);
}

// gameobject
public static class GameObjectAPINative
{
    [DllImport(EngineAPINative.ENGINE_PATH)]
    public static extern IntPtr GetTransform(IntPtr gameObject);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    public static extern IntPtr GetRenderInfo(IntPtr gameObject);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    public static extern string GetGameObjectName(IntPtr gameObject);
}