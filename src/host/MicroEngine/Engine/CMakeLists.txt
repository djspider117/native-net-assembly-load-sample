
add_library (Engine SHARED "Engine.h" "Engine.cpp" "ConsoleRenderer.h" "NetRuntimeHost.h" "EngineObjects.h" "InputSystem.h" "InputSystem.cpp" "Scene.h" "ConsoleRenderer.cpp" "NetRuntimeHost.cpp" "Scene.cpp" "EngineAPI.h" "EngineAPI.cpp" "FrameBuffer.h" "FrameBuffer.cpp" "GameObject.h" "Component.h" "GameObject.cpp" "Common.h")
target_link_libraries(Engine PRIVATE "${DOTNET_LIB}")
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(Engine PRIVATE ENGINE_EXPORTS)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Engine PROPERTY CXX_STANDARD 20)
endif()
