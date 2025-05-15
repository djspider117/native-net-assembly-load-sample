#pragma once
#include <vector>
#include <string>

namespace MicroEngine
{
    class GameObject;

    class Component
    {
    public:
        virtual void Update() {}
        virtual ~Component() = default;

        void SetOwner(GameObject* owner) { _owner = owner; }
        GameObject* GetOwner() const { return _owner; }

    protected:
        GameObject* _owner = nullptr;
    };
}