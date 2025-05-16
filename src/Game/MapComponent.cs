using MicroEngineSDK;

namespace Game;

public class MapComponent : Component
{
    public override void Start()
    {
        GameObject.RenderInfo.Visible = true;
        GameObject.RenderInfo.ColorPalletIndex = 0;
        GameObject.RenderInfo.Symbol = (byte)'·';
        GameObject.Transform.Size = new Vector2Int { X = 8, Y = 8 };
    }
}
