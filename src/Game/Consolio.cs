using MicroEngineSDK;

namespace Game;

public class Consolio : IGameEntry
{
    public void Run()
    {
        var demoScene = new Scene("Demo Scene", 0);
        Engine.SetActiveScene(demoScene);

        var map = new GameObject("Map");
        map.AddComponent<MapComponent>();

        var player = new GameObject("Player");
        player.AddComponent<PlayerControllerComponent>();

        demoScene.AddGameObject(map);
        demoScene.AddGameObject(player);
    }
}
