#pragma once
#include "Renderer.h"
class SphereRenderer :
	public Renderer
{
public:
	SphereRenderer();
	SphereRenderer(GameObject *_gameObject);
	SphereRenderer(GameObject *_gameObject, Maths::Vector3 _color);
	~SphereRenderer();

	void Render() override;
};

