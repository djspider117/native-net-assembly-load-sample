using System.Diagnostics;
using System.Reflection;

namespace MicroEngineSDK;

public static class ComponentRegistry
{
    private static List<Func<Component>> _constructors = new();


    public static IGameEntry? GameEntry { get; private set; }

    public static void Register<T>() where T : Component, new()
    {
        _constructors.Add(() => new T());
    }

  
    public static void RegisterFromAssembly(string path)
    {
        var asm = Assembly.Load("Game");
       
        var types = asm.GetTypes()
            .Where(t => typeof(Component).IsAssignableFrom(t) && !t.IsAbstract);

        foreach (var type in types)
        {
            Debug.WriteLine($"Found componenet type: {type.Name}");
            _constructors.Add(() => (Component)Activator.CreateInstance(type)!);
        }

        var entry = asm.GetTypes()
           .FirstOrDefault(x => typeof(IGameEntry).IsAssignableFrom(x) && !x.IsAbstract);

        if (entry == null)
        {
            Debug.WriteLine($"Could not find entrypoint in {path}");
            return;
        }

        GameEntry = (IGameEntry)Activator.CreateInstance(entry)!;
    }
}
