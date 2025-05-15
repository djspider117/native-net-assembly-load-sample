using MicroEngineSDK;

namespace Game;

public class Consolio : IGameEntry
{
    public void Run()
    {
        var demoScene = new Scene("Demo Scene", 0);

        var player = new GameObject("Player");
        
    }
}

public class PlayerComponent : Component
{
    public override void Update()
    {
        
    }
}
