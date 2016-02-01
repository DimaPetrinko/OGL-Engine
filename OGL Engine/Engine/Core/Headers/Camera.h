#pragma once
#include "Component.h"
#include "GfxFramework.h"
class Camera :
	public Component
{
private:
	Maths::Vector3 prevPos;

public:
	Camera();
	Camera(GameObject* _gameObject);
	~Camera();

	void SetViewport();
};