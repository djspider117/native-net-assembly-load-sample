using System.Runtime.InteropServices;

namespace MicroEngineSDK;

public class GameObject : NativeObjectWrapper
{
    private Dictionary<Type, Component> _componentCache = [];

    public string Name => GetGameObjectName(NativeObject);
    public RenderInfo RenderInfo { get; private set; }
    public ConsoleTransform Transform { get; private set; }

    public GameObject(string name)
        : base(CreateGameObjectForCurrentScene(name))
    {
        RenderInfo = new(GetRenderInfo(NativeObject));
        Transform = new(GetTransform(NativeObject));
    }

    public GameObject(string name, IntPtr ptr)
        : base(ptr)
    {
        RenderInfo = new(GetRenderInfo(NativeObject));
        Transform = new(GetTransform(NativeObject));
    }

    public T? GetComponent<T>() where T : Component
    {
        var type = typeof(T);
        if (_componentCache.TryGetValue(type, out var component))
            return (T)component;

        return null;
    }

    public T AddComponent<T>() where T : Component, new()
    {
        var comp = new T { GameObject = this };
        _componentCache.Add(typeof(T), comp);
        Engine.RegisterInstantiatedComponent(comp);
        return comp;
    }

    #region Native API

    [DllImport(EngineAPINative.ENGINE_PATH)]
    internal static extern IntPtr GetTransform(IntPtr gameObject);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    internal static extern IntPtr GetRenderInfo(IntPtr gameObject);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    internal static extern string GetGameObjectName(IntPtr gameObject);

    [DllImport(EngineAPINative.ENGINE_PATH)]
    internal static extern IntPtr CreateGameObjectForCurrentScene(string name);

    #endregion
}