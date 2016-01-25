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
	Transform *transform;
	Renderer *renderer;

private:
	static const char *defaultName;
	std::vector<Component*> components;

public:
	GameObject();
	GameObject(const char *_name);
	//GameObject(const char *_name, Transform::Vector3 _position, Transform::Vector3 _rotation, Transform::Vector3 _scale);
	~GameObject();

	void SetRenderer(Renderer* _renderer);
	void AddComponent(Component *_component);
	Component *GetComponent(const char *_name);
};

