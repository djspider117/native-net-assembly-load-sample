namespace MicroEngineSDK;

public abstract class Component
{
    public GameObject? GameObject { get; set; }

    public virtual void Start() { }
    public virtual void Update() { }
}
