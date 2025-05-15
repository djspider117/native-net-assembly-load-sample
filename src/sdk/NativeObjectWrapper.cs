namespace MicroEngineSDK;

public class NativeObjectWrapper
{
    internal IntPtr NativeObject { get; private set; }
    internal NativeObjectWrapper(IntPtr ptr)
    {
        NativeObject = ptr;
    }
}
