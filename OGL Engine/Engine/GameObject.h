#pragma once
#define GAMEOBJECT_H

#include <vector>
#include "Component.h"
//#include "Transform.h"

class Component;
class Transform;

class GameObject
{
public:
	const char *name;
	const char *tag;
	std::vector<Component> components;
	const Transform &transform;

private:
	static const char *defaultName;

public:
	GameObject();
	~GameObject();
};

