$ErrorActionPreference = "Stop"

$preset = "win-x64-release"
$config = "Release"
$repoRoot = $PSScriptRoot
$srcDir = Join-Path $repoRoot "src"
$hostDir = Join-Path $srcDir "host"
$microEngineDir = Join-Path $hostDir "MicroEngine"

Write-Host "=== Step 1: Configuring native build with preset '$preset' ==="
Push-Location $microEngineDir
cmake --preset $preset
Pop-Location

$buildDir = Join-Path $microEngineDir "out/build/$preset"
$appOutputDir = Join-Path $buildDir "App"

Write-Host "=== Step 2: Building native engine and app ==="
cmake --build $buildDir --config $config

Write-Host "=== Step 3: Building .NET SDK and Game projects ==="

$slnPath = Join-Path $srcDir "MicroEngine.sln"
& msbuild $slnPath /p:Configuration=$config

Write-Host "=== Build complete! ==="
Write-Host "Executable: $appOutputDir\App.exe"