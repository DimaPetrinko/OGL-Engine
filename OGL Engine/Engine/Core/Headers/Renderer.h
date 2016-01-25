#pragma once
#include "Component.h"
#include "Transform.h"

class Component;

class Renderer : public Component
{
public:
	Transform::Vector3 color;

public:
	Renderer();
	Renderer(GameObject *_gameObject);
	virtual ~Renderer();

	virtual void Render();

private:

};