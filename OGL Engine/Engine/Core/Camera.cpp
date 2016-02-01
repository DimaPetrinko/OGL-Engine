#include "stdafx.h"
#include "Headers\Camera.h"

Camera::Camera() : Component()
{
	name = "Camera";
	prevPos = Maths::Vector3();
}

Camera::Camera(GameObject* _gameObject) : Component(_gameObject)
{
	name = "Camera";
	prevPos = Maths::Vector3();
}

Camera::~Camera()
{
}

void Camera::SetViewport()
{
	GfxFramework::SetViewport(gameObject->transform->position - prevPos, gameObject->transform->rotation);
	prevPos = gameObject->transform->position;
}