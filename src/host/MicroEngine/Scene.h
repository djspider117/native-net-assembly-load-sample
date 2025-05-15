#pragma once

#include <vector>
#include "EngineObjects.h"

namespace MicroEngine
{
	class Scene
	{
	public:
		Scene(std::string name, int id);

		void Update();
		GameObject* CreateGameObject(const std::string& name);
		void AddGameObject(GameObject* go);

		inline const std::vector<GameObject*>& GetGameObjects() const { return _gameObjects; }
		inline const std::string& GetName() const { return _name; }
		inline int GetId() const { return _id; }

	private:
		std::vector<GameObject*> _gameObjects;
		std::string _name;
		int _id;
	};

}