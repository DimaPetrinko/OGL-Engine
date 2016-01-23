#pragma once
#define GAMEOBJECT_H

#include <vector>
#include <memory>
#include "Component.h"
//#include "Transform.h"

class Component;
class Transform;

class GameObject
{
public:
	const char *name;
	const char *tag;
	bool enabled;
	std::vector<Component> components;
	//const Transform &transform;

private:
	static const char *defaultName;

public:
	GameObject();
	~GameObject();

	void AddComponent(Component &_component);
	Component GetComponent(const char *_name);
};

