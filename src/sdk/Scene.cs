namespace MicroEngineSDK;

public class Scene : NativeObjectWrapper
{
    private List<GameObject> _gameObjects = [];

    public int Id => SceneAPINative.GetSceneId(NativeObject);
    public string Name => SceneAPINative.GetSceneName(NativeObject);


    internal Scene(nint ptr) : base(ptr)
    {
    }

    public Scene(string name, int id) : base(SceneAPINative.CreateScene(name, id))
    {
    }

    public void AddGameObject(GameObject go)
    {
        _gameObjects.Add(go);
        SceneAPINative.AddGameObjectToScene(NativeObject, go.NativeObject);
    }
}
