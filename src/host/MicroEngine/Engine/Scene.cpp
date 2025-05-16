#include "Scene.h"
#include "GameObject.h"

#include <string>

namespace MicroEngine
{
	Scene::Scene(std::string name, int id) :
		_name(name),
		_id(id)
	{

	}

	GameObject* Scene::CreateGameObject(const std::string& name)
	{
		auto rv = new GameObject(name);
		_gameObjects.push_back(rv);
		return rv;
	}

	void Scene::AddGameObject(GameObject* go)
	{
		_gameObjects.push_back(go);
	}
}