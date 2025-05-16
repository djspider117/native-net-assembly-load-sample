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

        var lw = new GameObject("LeftWall");
        lw.AddComponent<LeftWallComponent>();

        var rw = new GameObject("RightWall");
        rw.AddComponent<RightWallComponent>();

        var tw = new GameObject("TopWall");
        tw.AddComponent<TopWallComponent>();

        var bw = new GameObject("BottomWall");
        bw.AddComponent<BottomWallComponent>();

        var player = new GameObject("Player");
        player.AddComponent<PlayerControllerComponent>();

        demoScene.AddGameObject(map);
        demoScene.AddGameObject(lw);
        demoScene.AddGameObject(rw);
        demoScene.AddGameObject(tw);
        demoScene.AddGameObject(bw);
        demoScene.AddGameObject(player);
    }
}