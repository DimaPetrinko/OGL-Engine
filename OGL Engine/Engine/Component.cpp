#include "stdafx.h"
#include "Component.h"

const char *Component::defaultName = "NewComponent";

Component::Component() : gameObject(GameObject())
{
	name = defaultName;
}

Component::Component(GameObject _gameObject) : gameObject(_gameObject)
{
	name = defaultName;
}

Component::~Component()
{
}