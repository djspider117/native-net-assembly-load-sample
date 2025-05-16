#pragma once

#include "Common.h"
#include "EngineObjects.h"
#include "Scene.h"

using namespace MicroEngine;

extern "C"
{
	ENGINE_API Scene* CreateScene(const char* name, int id);
	ENGINE_API void SetActiveScene(Scene* scene);
	ENGINE_API GameObject* CreateGameObject(Scene*, const char* name);
	ENGINE_API const char* GetSceneName(Scene*);
	ENGINE_API int GetSceneId(Scene*);
	ENGINE_API void AddGameObjectToScene(Scene*, GameObject*);
	ENGINE_API void* CreateGameObjectForCurrentScene(const char* name);
	ENGINE_API ConsoleTransform* GetTransform(GameObject*);
	ENGINE_API RenderInfo* GetRenderInfo(GameObject*);
	ENGINE_API const char* GetGameObjectName(GameObject* gameObject);
	ENGINE_API int GetCurrentFrameKeyPressed();
	ENGINE_API int GetLastFrameKeyPressed();
}