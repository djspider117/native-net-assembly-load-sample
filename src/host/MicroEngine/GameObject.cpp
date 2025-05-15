#include "GameObject.h"

namespace MicroEngine
{
	GameObject::GameObject(std::string name) : _name(name)
	{
		_components.reserve(5);
	}
}