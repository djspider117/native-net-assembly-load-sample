namespace MicroEngineSDK;

public class ConsoleTransform : NativeObjectWrapper
{
    public Vector2Int Position
    {
        get
        {
            unsafe
            {
                return (*(ConsoleTransformData*)NativeObject).Position;
            }
        }
        set
        {
            unsafe
            {
                (*(ConsoleTransformData*)NativeObject).Position = value;
            }
        }
    }

    public Vector2Int Size
    {
        get
        {
            unsafe
            {
                return (*(ConsoleTransformData*)NativeObject).Size;
            }
        }
        set
        {
            unsafe
            {
                (*(ConsoleTransformData*)NativeObject).Size = value;
            }
        }
    }

    public int Rotation
    {
        get
        {
            unsafe
            {
                return (*(ConsoleTransformData*)NativeObject).Rotation;
            }
        }
        set
        {
            unsafe
            {
                (*(ConsoleTransformData*)NativeObject).Rotation = value;
            }
        }
    }

    internal ConsoleTransform(nint ptr) : base(ptr)
    {
    }
}