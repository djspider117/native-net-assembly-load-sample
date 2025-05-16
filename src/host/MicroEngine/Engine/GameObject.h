#pragma once

#include <vector>
#include <string>

#include "EngineObjects.h"

namespace MicroEngine
{
	class Component;

	class GameObject
	{
	public:
		GameObject(std::string name);

		template<typename T>
		T* AddComponent()
		{
			Component* comp = new T();
			comp->SetOwner(this);
			_components.push_back(comp);

			return comp;
		}

		template<typename T>
		T* GetComponent()
		{
			for (Component* c : _components)
			{
				if (auto casted = dynamic_cast<T*>(c))
					return casted;
			}

			return nullptr;
		}

		inline const std::string& GetName() const { return _name; }
		inline ConsoleTransform* GetTransformAsPtr() const { return (ConsoleTransform*)&_transform; }
		inline RenderInfo* GetRenderInfoAsPtr() const { return (RenderInfo*)&_renderInfo; }

		inline const RenderInfo& GetRenderInfo() const { return _renderInfo; }
		inline const ConsoleTransform& GetTransform() const { return _transform; }

	private:
		std::string _name;
		std::vector<Component*> _components;

		ConsoleTransform _transform{};
		RenderInfo _renderInfo{};
	};
}