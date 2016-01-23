#include "stdafx.h"
#include "GameObject.h"
#include "Transform.h"

const char *GameObject::defaultName = "NewGameObject";

GameObject::GameObject()// : transform(Transform(*this,Transform::Vector3(), Transform::Vector3(), Transform::Vector3()))
{
	name = defaultName;
	enabled = true;
	AddComponent((Component&)Transform(*this, Transform::Vector3(), Transform::Vector3(), Transform::Vector3())/*transform*/);
}


GameObject::~GameObject()
{
}

void GameObject::AddComponent(Component &_component) 
{
	components.push_back(_component);
}

Component GameObject::GetComponent(const char *_name)
{
	for each (Component c in components)
	{
		if (c.name == _name)
		{
			return c;
		}
	}
}
