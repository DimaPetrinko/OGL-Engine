#include "stdafx.h"
#include "Headers\GameObject.h"
#include "Headers\Transform.h"

#include <memory>
#include <iostream>

const char *GameObject::defaultName = "NewGameObject";

GameObject::GameObject()// : transform(Transform(this,Transform::Vector3(), Transform::Vector3(), Transform::Vector3()))
{
	name = defaultName;
	enabled = true;
	transform = new Transform(this, Transform::Vector3(), Transform::Vector3(), Transform::Vector3(1, 1, 1));
	AddComponent(transform);
}

GameObject::GameObject(const char *_name) : GameObject::GameObject()
{
	name = _name;
}

//GameObject::GameObject(const char *_name, Transform::Vector3 _position, Transform::Vector3 _rotation, Transform::Vector3 _scale) : GameObject(_name)
//{
//	transform->position = _position;
//	transform->rotation = _rotation;
//	transform->scale = _scale;
//}

GameObject::~GameObject()
{
	if (transform != nullptr) { delete transform; }
	//if (renderer != nullptr) { delete renderer; }
}

void GameObject::SetRenderer(Renderer *_renderer)
{
	renderer = _renderer;
	AddComponent((Component*)renderer);
}

void GameObject::AddComponent(Component *_component)
{
	components.push_back(_component);
}

Component *GameObject::GetComponent(const char *_name)
{
	for each (Component* c in components)
	{
		if (c->name == _name)
		{
			return c;
		}
	}
}