#include "stdafx.h"
#include "Headers\BoxRenderer.h"
#include "Headers\GfxFramework.h"


BoxRenderer::BoxRenderer() : Renderer()
{
	name = "BoxRenderer";
}

BoxRenderer::BoxRenderer(GameObject *_gameObject) : Renderer(_gameObject)
{
	name = "BoxRenderer";
}

BoxRenderer::BoxRenderer(GameObject *_gameObject, Transform::Vector3 _color) : BoxRenderer::BoxRenderer(_gameObject)
{
	color = _color;
}

BoxRenderer::~BoxRenderer()
{
}

void BoxRenderer::Render() 
{
	Renderer::Render();
	GfxFramework::DrawCube(color, gameObject->transform->position, gameObject->transform->rotation, gameObject->transform->scale);
}