#pragma once
#include "Component.h"
#include "Transform.h"

class Component;

class Renderer : public Component
{
public:
	Maths::Vector3 color;
	bool drawGizmos;
	bool lit;

public:
	Renderer();
	Renderer(GameObject *_gameObject);
	virtual ~Renderer();

	virtual void Render();

private:

};