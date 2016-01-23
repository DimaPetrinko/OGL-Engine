#include "stdafx.h"
#include "Component.h"
#include <iostream>

const char *Component::defaultName = "NewComponent";

Component::Component() : gameObject(GameObject())
{
	name = defaultName;
	enabled = true;
}

Component::Component(GameObject _gameObject) : gameObject(_gameObject)
{
	name = defaultName;
	enabled = true;
}

Component::~Component()
{
	std::cout << "I've been destroyed. My name is " << this->name << std::endl;
}