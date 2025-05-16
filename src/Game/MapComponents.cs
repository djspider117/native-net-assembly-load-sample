using MicroEngineSDK;

namespace Game;

public class MapComponent : Component
{
    public override void Start()
    {
        GameObject.RenderInfo.Visible = true;
        GameObject.RenderInfo.Symbol = (byte)'.';
        GameObject.Transform.Size = new Vector2Int { X = 20, Y = 10 };
    }
}


public class LeftWallComponent : Component
{
    public override void Start()
    {
        GameObject.RenderInfo.Visible = true;
        GameObject.RenderInfo.Symbol = (byte)'|';
        GameObject.Transform.Position = new Vector2Int { X = 0, Y = 0 };
        GameObject.Transform.Size = new Vector2Int { X = 1, Y = 10 };
    }
}

public class RightWallComponent : Component
{
    public override void Start()
    {
        GameObject.RenderInfo.Visible = true;
        GameObject.RenderInfo.Symbol = (byte)'|';
        GameObject.Transform.Position = new Vector2Int { X = 19, Y = 0 };
        GameObject.Transform.Size = new Vector2Int { X = 1, Y = 10 };
    }
}

public class TopWallComponent : Component
{
    public override void Start()
    {
        GameObject.RenderInfo.Visible = true;
        GameObject.RenderInfo.Symbol = (byte)'=';
        GameObject.Transform.Position = new Vector2Int { X = 0, Y = 0 };
        GameObject.Transform.Size = new Vector2Int { X = 20, Y = 1 };
    }
}

public class BottomWallComponent : Component
{
    public override void Start()
    {
        GameObject.RenderInfo.Visible = true;
        GameObject.RenderInfo.Symbol = (byte)'=';
        GameObject.Transform.Position = new Vector2Int { X = 0, Y = 9 };
        GameObject.Transform.Size = new Vector2Int { X = 20, Y = 1 };
    }
}
