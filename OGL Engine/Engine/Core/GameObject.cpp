#include "stdafx.h"
#include "GameObject.h"
#include "Transform.h"

#include <memory>
#include <iostream>

const char *GameObject::defaultName = "NewGameObject";

GameObject::GameObject()// : transform(Transform(*this,Transform::Vector3(), Transform::Vector3(), Transform::Vector3()))
{
	name = defaultName;
	enabled = true;
	AddComponent(&Transform(*this, Transform::Vector3(), Transform::Vector3(), Transform::Vector3())/*transform*/);
	//transform = (Transform*)components[0];
}


GameObject::~GameObject()
{
	std::cout << "I've been destroyed. My name is " << this->name << std::endl;
}

void GameObject::AddComponent(Component *_component)
{
	transform = (Transform*)_component;
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
