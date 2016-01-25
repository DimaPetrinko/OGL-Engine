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
	//transform.gameObject = this;
	AddComponent(/*&Transform(*this, Transform::Vector3(), Transform::Vector3(), Transform::Vector3())*/transform);
	//transform = (Transform*)components[0];
}

GameObject::GameObject(const char *_name) : GameObject::GameObject()
{
	name = _name;
}

GameObject::~GameObject()
{
	if (transform != nullptr) { delete transform; }
	//if (renderer != nullptr) { delete renderer; }
	std::cout << "I've been destroyed. My name is " << this->name << std::endl;
}

void GameObject::SetRenderer(Renderer* _renderer)
{
	renderer = _renderer;
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