#include "stdafx.h"
#include "Headers\Renderer.h"

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
}

Renderer::~Renderer() 
{

}

void Renderer::Render() 
{

}