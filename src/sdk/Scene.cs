using System.Runtime.InteropServices;

namespace MicroEngineSDK;

public class Scene : NativeObjectWrapper
{
    private List<GameObject> _gameObjects = [];

    public int Id => GetSceneId(NativeObject);
    public string Name => GetSceneName(NativeObject);


    internal Scene(nint ptr) : base(ptr)
    {
    }

    public Scene(string name, int id) : base(CreateScene(name, id))
    {
    }

    public void AddGameObject(GameObject go)
    {
        _gameObjects.Add(go);
        AddGameObjectToScene(NativeObject, go.NativeObject);
    }

    [DllImport(EngineAPINative.ENGINE_PATH)]
    internal static extern IntPtr CreateScene(string name, int id);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    internal static extern string GetSceneName(IntPtr scene);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    internal static extern int GetSceneId(IntPtr scene);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    internal static extern IntPtr CreateGameObject(IntPtr scene, string name);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    internal static extern void AddGameObjectToScene(IntPtr scene, IntPtr go);
}
