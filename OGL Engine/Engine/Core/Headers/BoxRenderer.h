#pragma once
#include "Headers\Renderer.h"

class BoxRenderer :
	public Renderer
{
public:
	BoxRenderer();
	BoxRenderer(GameObject *_gameObject);
	BoxRenderer(GameObject *_gameObject, Transform::Vector3 _color);
	~BoxRenderer();

	void Render() override;
};

