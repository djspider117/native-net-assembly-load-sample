#include "EngineAPI.h"
#include "ConsoleRenderer.h"
#include "GameObject.h"
#include "Engine.h"

Scene* CreateScene(const char* name, int id)
{
	Scene* rv = new Scene(std::string(name), id);
	g_SceneRepository.push_back(rv);
	return rv;
}
void SetActiveScene(Scene* scene)
{
	g_Engine->SetActiveScene(scene);
}

const char* GetSceneName(Scene* scene) 
{
	return scene->GetName().c_str();
}
int GetSceneId(Scene* s) 
{
	return s->GetId();
}

GameObject* CreateGameObject(Scene* scene, const char* name)
{
	if (scene == nullptr)
		return nullptr;

	return new GameObject(std::string(name));
}

void AddGameObjectToScene(Scene* scene, GameObject* go)
{
	scene->AddGameObject(go);
}

void* CreateGameObjectForCurrentScene(const char* name)
{
	return CreateGameObject(g_Engine->GetActiveScene(), name);
}

ConsoleTransform* GetTransform(GameObject* go)
{
	return go->GetTransformAsPtr();
}

RenderInfo* GetRenderInfo(GameObject* go)
{
	return go->GetRenderInfoAsPtr();
}

const char* GetGameObjectName(GameObject* go)
{
	return go->GetName().c_str();
}

int GetCurrentFrameKeyPressed()
{
	return (int)(g_Engine->GetInputSystem()->GetCurrentFrameKeyPressed());
}

int GetLastFrameKeyPressed()
{
	return (int)(g_Engine->GetInputSystem()->GetLastFrameKeyPressed());
}
