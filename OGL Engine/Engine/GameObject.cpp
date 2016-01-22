#include "stdafx.h"
#include "GameObject.h"
#include "Transform.h"

const char *GameObject::defaultName = "NewGameOgject";

GameObject::GameObject() : transform(Transform())
{
	name = defaultName;
	components.push_back(Component(*this));
}


GameObject::~GameObject()
{
}
