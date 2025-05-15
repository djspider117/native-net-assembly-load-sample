#include "EngineAPI.h"
#include "ConsoleRenderer.h"
#include "GameObject.h"
#include "Engine.h"

static Scene* CreateScene(const char* name, int id)
{
	Scene* rv = new Scene(std::string(name), id);
	g_SceneRepository.push_back(rv);
	return rv;
}

static void SetActiveScene(Scene* scene)
{
	g_Engine->SetActiveScene(scene);
}

static const char* GetSceneName(Scene* scene) 
{
	return scene->GetName().c_str();
}
static int GetSceneId(Scene* s) 
{
	return s->GetId();
}

static GameObject* CreateGameObject(Scene* scene, const char* name)
{
	if (scene == nullptr)
		return nullptr;

	return new GameObject(std::string(name));
}

static void AddGameObjectToScene(Scene* scene, GameObject* go)
{
	scene->AddGameObject(go);
}

static void* CreateGameObjectForCurrentScene(const char* name)
{
	return CreateGameObject(g_Engine->GetActiveScene(), name);
}

static ConsoleTransform* GetTransform(GameObject* go)
{
	return go->GetTransformAsPtr();
}

static RenderInfo* GetRenderInfo(GameObject* go)
{
	return go->GetRenderInfoAsPtr();
}

static const char* GetGameObjectName(GameObject* go)
{
	return go->GetName().c_str();
}
