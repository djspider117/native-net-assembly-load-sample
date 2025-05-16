namespace MicroEngineSDK;

public class RenderInfo : NativeObjectWrapper
{
    public byte ColorPalletIndex
    {
        get
        {
            unsafe
            {
                return (*(RenderInfoData*)NativeObject).ColorPalleteIndex;
            }
        }
        set
        {
            unsafe
            {
                (*(RenderInfoData*)NativeObject).ColorPalleteIndex = value;
            }
        }
    }

    public byte Symbol
    {
        get
        {
            unsafe
            {
                return (*(RenderInfoData*)NativeObject).Symbol;
            }
        }
        set
        {
            unsafe
            {
                (*(RenderInfoData*)NativeObject).Symbol = value;
            }
        }
    }

    public bool Visible
    {
        get
        {
            unsafe
            {
                return (*(RenderInfoData*)NativeObject).Visible;
            }
        }
        set
        {
            unsafe
            {
                (*(RenderInfoData*)NativeObject).Visible = value;
            }
        }
    }

    internal RenderInfo(nint ptr) : base(ptr)
    {
    }
}
