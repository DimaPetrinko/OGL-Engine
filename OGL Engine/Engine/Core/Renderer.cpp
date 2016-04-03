#include "stdafx.h"
#include "Headers\Renderer.h"
#include "Headers\GfxFramework.h"

Renderer::Renderer() : Component()
{
	name = "Renderer";
	color.x = 0.8;
	color.y = 0.8;
	color.z = 0.8;
}

Renderer::Renderer(GameObject* _gameObject) : Component(_gameObject) 
{
	name = "Renderer";
	color.x = 0.8;
	color.y = 0.8;
	color.z = 0.8;
	lit = true;
}

Renderer::~Renderer() 
{

}

void Renderer::Render() 
{
	if (drawGizmos)
	{
		GfxFramework::DrawGizmos(gameObject->transform->position, gameObject->transform->rotation, gameObject->transform->scale);
	}
}