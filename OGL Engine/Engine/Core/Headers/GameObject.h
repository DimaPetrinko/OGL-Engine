#pragma once
#define GAMEOBJECT_H

#include <vector>
#include <algorithm>
#include <memory>
#include "Component.h"
//#include "Renderer.h"
//#include "Transform.h"

class Component;
class Transform;
class Renderer;

class GameObject
{
public:
	const char *name;
	const char *tag;
	bool enabled;
	std::vector<Component*> components;
	Transform *transform;
	Renderer *renderer;

	//const Transform &transform;

private:
	static const char *defaultName;

public:
	GameObject();
	GameObject(const char *_name);
	~GameObject();

	void SetRenderer(Renderer* _renderer);
	void AddComponent(Component *_component);
	Component *GetComponent(const char *_name);
};

