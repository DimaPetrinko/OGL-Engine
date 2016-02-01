#pragma once
#include "Component.h"
#include "GfxFramework.h"
class Camera :
	public Component
{
public:
	int fov;

private:
	Maths::Vector3 prevPos;
	Maths::Quaternion prevRot;

public:
	Camera();
	Camera(GameObject* _gameObject);
	Camera(GameObject* _gameObject, int fov);
	~Camera();

	void SetViewport(int _w, int _h);
	void Show();
};