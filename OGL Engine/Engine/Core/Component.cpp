#include "stdafx.h"
#include "Headers\Component.h"
#include <iostream>

const char *Component::defaultName = "NewComponent";

Component::Component()
{
	name = defaultName;
	enabled = true;
	gameObject = &GameObject();
}

Component::Component(const GameObject* _gameObject)
{
	gameObject = _gameObject;
	name = defaultName;
	enabled = true;
}

Component::~Component()
{
	std::cout << "I've been destroyed. My name is " << this->name << std::endl;
}