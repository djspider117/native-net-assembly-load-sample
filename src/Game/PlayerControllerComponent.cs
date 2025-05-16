using MicroEngineSDK;

namespace Game;

public class PlayerControllerComponent : Component
{
    public override void Start()
    {
        GameObject.RenderInfo.Visible = true;
        GameObject.RenderInfo.ColorPalletIndex = 1;
        GameObject.RenderInfo.Symbol = (byte)'#';
    }

    public override void Update()
    {
        var mx = 8;
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

        if (x < 0)
            x = 0;

        if (y < 0)
            y = 0;

        if (x > mx)
            x = mx;

        if (y > my)
            y = my;

        t.Position = new Vector2Int { X = x, Y = y };
    }
}
