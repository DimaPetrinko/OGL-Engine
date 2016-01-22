#pragma once
#define TRANSFORM_H

#include "Component.h"
//#include "GameObject.h"

class GameObject;

class Transform : public Component
{
public:
	struct Vector2
	{
		float x, y;

		Vector2();
		Vector2(float _x, float _y);

		static float GetMagnitude(Vector2 vector);

		float GetMagnitude();

		static Vector2 Normilize(Vector2 vector);

		Vector2 Normilize();
	};

	struct Vector3
	{
		float x, y, z;

		Vector3();
		Vector3(float _x, float _y, float _z);

		static float GetMagnitude(Vector3 vector);

		float GetMagnitude();

		static Vector3 Normilize(Vector3 vector);

		Vector3 Normilize();
	};

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	Transform();
	Transform(const GameObject _gameObject, Vector3 _position, Vector3 _rotation, Vector3 _scale);
	~Transform();
};

