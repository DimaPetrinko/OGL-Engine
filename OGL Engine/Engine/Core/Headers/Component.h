#pragma once
#define COMPONENT_H

#include "GameObject.h"

class GameObject;

class Component
{
public:	
	const char *name;
	bool enabled;
	const GameObject *gameObject;

private:
	static const char *defaultName;

public:
	Component();
	Component(const GameObject *_gameobject);
	virtual ~Component();
};

