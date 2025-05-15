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
        var asm = Assembly.LoadFrom(path);

        var types = asm.GetTypes()
            .Where(t => typeof(Component).IsAssignableFrom(t) && !t.IsAbstract);

        var entry = asm.GetTypes()
           .Single(x => typeof(IGameEntry).IsAssignableFrom(x) && !x.IsAbstract);

        GameEntry = (IGameEntry)Activator.CreateInstance(entry)!;

        foreach (var type in types)
        {
            _constructors.Add(() => (Component)Activator.CreateInstance(type)!);
        }
    }
}
