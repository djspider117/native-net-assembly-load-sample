# CMakeList.txt : CMake project for MicroEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Get DOTNET_HOST_DIR from environment
if(NOT DEFINED ENV{DOTNET_HOST_DIR})
    message(FATAL_ERROR "Environment variable DOTNET_HOST_DIR is not set. For Windows: C:/Program Files/dotnet/packs/Microsoft.NETCore.App.Host.win-x64/9.0.5/runtimes/win-x64/native")
else()
    set(DOTNET_HOST_DIR "$ENV{DOTNET_HOST_DIR}")
endif()


project ("MicroEngine")

# Add header include
include_directories("${DOTNET_HOST_DIR}")

# Add static library (adjust as needed)
if(WIN32)
    set(DOTNET_LIB "${DOTNET_HOST_DIR}/nethost.lib")
elseif(UNIX)
    set(DOTNET_LIB "${DOTNET_HOST_DIR}/libnethost.so")
endif()
# Add source to this project's executable.
add_executable (MicroEngine "main.cpp"  "Application.h" "Application.cpp" "Engine.h" "Engine.cpp" "ConsoleRenderer.h" "NetRuntimeHost.h" "EngineObjects.h" "InputSystem.h" "InputSystem.cpp" "Scene.h" "ConsoleRenderer.cpp" "NetRuntimeHost.cpp" "Scene.cpp" "EngineAPI.h" "EngineAPI.cpp" "FrameBuffer.h" "FrameBuffer.cpp" "GameObject.h" "Component.h" "GameObject.cpp")
target_link_libraries(MicroEngine PRIVATE "${DOTNET_LIB}")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MicroEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
