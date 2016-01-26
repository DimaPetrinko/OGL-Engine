#pragma once
#define TRANSFORM_H

#include "Component.h"
#include "Maths.h"
//#include "GameObject.h"

class GameObject;

class Transform : public Component
{
public:
	//struct Vector2
	//{
	//	float x, y;
	//
	//	Vector2();
	//	Vector2(float _x, float _y);
	//
	//	static Vector2 up;
	//	static Vector2 right;
	//
	//	static float GetMagnitude(Vector2 vector);
	//
	//	float GetMagnitude();
	//
	//	static Vector2 Normilize(Vector2 vector);
	//
	//	Vector2 Normilize();
	//};
	//
	//struct Vector3
	//{
	//	float x, y, z;
	//
	//	Vector3();
	//	Vector3(float _x, float _y, float _z);
	//
	//	static Vector3 up;
	//	static Vector3 right;
	//	static Vector3 forward;
	//
	//	static float GetMagnitude(Vector3 vector);
	//
	//	float GetMagnitude();
	//
	//	static Vector3 Normilize(Vector3 vector);
	//
	//	Vector3 Normilize();
	//};

	Maths::Vector3 up;
	Maths::Vector3 right;
	Maths::Vector3 forward;

	Maths::Vector3 position;
	Maths::Vector3 rotation;
	Maths::Vector3 scale;

	Transform();
	Transform(const GameObject *_gameObject, Maths::Vector3 _position, Maths::Vector3 _rotation, Maths::Vector3 _scale);
	~Transform();

	void Translate(Maths::Vector3 _translation);

	void Rotate(Maths::Vector3 _rotation);
};

