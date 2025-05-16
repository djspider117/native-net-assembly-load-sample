namespace MicroEngineSDK;

public abstract class Component
{
    public GameObject GameObject { get; set; } = null!;

    public virtual void Start() { }
    public virtual void Update() { }
}
