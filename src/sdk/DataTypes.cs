using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace MicroEngineSDK;

[StructLayout(LayoutKind.Sequential)]
public struct Vector2Int
{
    public int X;
    public int Y;
}

[StructLayout(LayoutKind.Sequential)]
struct ConsoleTransformData
{
    public Vector2Int Position;
    public Vector2Int Size;
    public int Rotation;
};

[StructLayout(LayoutKind.Sequential)]
struct RenderInfoData
{
    public byte ColorPalleteIndex;
    public byte Symbol;
    public bool Visible;
};