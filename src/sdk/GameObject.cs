namespace MicroEngineSDK;

public class GameObject : NativeObjectWrapper
{
    public string Name => GameObjectAPINative.GetGameObjectName(NativeObject);

    public GameObject(string name)
        : base(SceneAPINative.CreateGameObjectForCurrentScene(name))
    {
        // TODO: request a new gameobject ptr from the engine
    }

    public GameObject(string name, IntPtr ptr)
        : base(ptr)
    {
    }

    public T? GetComponent<T>() where T : Component
    {
        // TODO
        return null;
    }

    public T AddComponent<T>() where T : Component
    {
        // TODO
        return null;
    }
}

class RenderInfo : NativeObjectWrapper
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