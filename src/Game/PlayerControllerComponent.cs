using MicroEngineSDK;

namespace Game;

public class PlayerControllerComponent : Component
{
    public override void Start()
    {
        GameObject.RenderInfo.Visible = true;
        GameObject.RenderInfo.ColorPalletIndex = 1;
        GameObject.RenderInfo.Symbol = (byte)'O';
        GameObject.Transform.Position = new Vector2Int { X = 10, Y = 5 };
    }

    public override void Update()
    {
        var mx = 18;
        var my = 8;
        var t = GameObject.Transform;
        var x = t.Position.X;
        var y = t.Position.Y;

        if (Input.IsKeyDown(VirtualKey.ArrowUp))
            --y;

        if (Input.IsKeyDown(VirtualKey.ArrowLeft))
            --x;

        if (Input.IsKeyDown(VirtualKey.ArrowRight))
            ++x;

        if (Input.IsKeyDown(VirtualKey.ArrowDown))
            ++y;

        if (x < 1)
            x = 1;

        if (y < 1)
            y = 1;

        if (x > mx)
            x = mx;

        if (y > my)
            y = my;

        t.Position = new Vector2Int { X = x, Y = y };
    }
}
