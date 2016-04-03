#include "stdafx.h"
#include "Headers\SphereRenderer.h"
#include "Headers\GfxFramework.h"


SphereRenderer::SphereRenderer() : Renderer()
{
	name = "SphereRenderer";
}

SphereRenderer::SphereRenderer(GameObject *_gameObject) : Renderer(_gameObject)
{
	name = "SphereRenderer";
}

SphereRenderer::SphereRenderer(GameObject *_gameObject, Maths::Vector3 _color) : SphereRenderer::SphereRenderer(_gameObject)
{
	color = _color;
}

SphereRenderer::~SphereRenderer()
{
}

void SphereRenderer::Render()
{
	if (gameObject->enabled && enabled)
	{
		Renderer::Render();
		GfxFramework::DrawSphere(color, gameObject->transform->position, gameObject->transform->rotation, gameObject->transform->scale, lit);
	}
}
