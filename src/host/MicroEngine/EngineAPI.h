#pragma once

#include "EngineObjects.h"
#include "Scene.h"

using namespace MicroEngine;

extern "C"
{
	Scene* CreateScene(const char* name, int id);
	void SetActiveScene(Scene* scene);
	GameObject* CreateGameObject(Scene*, const char* name);

	const char* GetSceneName(Scene*);
	int GetSceneId(Scene*);

	void AddGameObjectToScene(Scene*, GameObject*);
	void* CreateGameObjectForCurrentScene(const char* name);

	ConsoleTransform* GetTransform(GameObject*);
	RenderInfo* GetRenderInfo(GameObject*);
	const char* GetGameObjectName(GameObject* gameObject);
}