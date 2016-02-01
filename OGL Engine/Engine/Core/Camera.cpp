#include "stdafx.h"
#include "Headers\Camera.h"

Camera::Camera() : Component()
{
	name = "Camera";
	fov = 45;
	prevPos = Maths::Vector3();
	prevRot = Maths::Quaternion();
}

Camera::Camera(GameObject* _gameObject) : Component(_gameObject)
{
	name = "Camera";
	fov = 45;
	prevPos = Maths::Vector3();
	prevRot = Maths::Quaternion();
}

Camera::Camera(GameObject* _gameObject, int _fov) : Camera(_gameObject)
{
	fov = _fov;
}

Camera::~Camera()
{
}

void Camera::SetViewport(int _w, int _h)
{
	GfxFramework::SetViewport(_w, _h, fov);
}

void Camera::Show()
{
	GfxFramework::Show(gameObject->transform->position - prevPos, gameObject->transform->rotation * Maths::Quaternion::Inverse(prevRot));
	prevPos = gameObject->transform->position;
	prevRot = gameObject->transform->rotation;
}