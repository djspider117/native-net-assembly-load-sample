namespace MicroEngineSDK;

public static class Engine
{
    public static void SetActiveScene(Scene scene)
    {
        SceneAPINative.SetActiveScene(scene.NativeObject);
    }
}
