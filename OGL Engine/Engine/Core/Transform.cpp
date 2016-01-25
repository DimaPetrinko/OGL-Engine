#include "stdafx.h"
#include "Headers\Transform.h"
#include <iostream>
#include <time.h>

//Vector2-----------------------------------------------------------------------------------
Transform::Vector2::Vector2() { x = 0.0f; y = 0.0f; }

Transform::Vector2::Vector2(float _x, float _y) { x = _x; y = _y; }

Transform::Vector2 Transform::Vector2::up = Transform::Vector2(0, 1); //worldspace

Transform::Vector2 Transform::Vector2::right = Transform::Vector2(1, 0); //worldspace

float Transform::Vector2::GetMagnitude(Vector2 vector) // returns magnitude of given vector
{
	float mag = sqrt((vector.x*vector.x) + (vector.y*vector.y));
	return mag;
}

float Transform::Vector2::GetMagnitude() //return self magnitude
{
	return GetMagnitude(*this);
}

Transform::Vector2 Transform::Vector2::Normilize(Vector2 vector)
{
	float mag = vector.GetMagnitude();
	Vector2 normalized = Vector2((vector.x / mag), (vector.y / mag));
	return normalized;
}

Transform::Vector2 Transform::Vector2::Normilize()
{
	return Normilize(*this);
}
//-----------------------------------------------------------------------------------------

//Vector3-----------------------------------------------------------------------------------
Transform::Vector3::Vector3() { x = 0.0f; y = 0.0f; z = 0.0; }

Transform::Vector3::Vector3(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }

Transform::Vector3 Transform::Vector3::up = Transform::Vector3(0, 1, 0); //worldspace

Transform::Vector3 Transform::Vector3::right = Transform::Vector3(1, 0, 0); //worldspace

Transform::Vector3 Transform::Vector3::forward = Transform::Vector3(0, 0, 1); //worldspace

float Transform::Vector3::GetMagnitude(Vector3 vector) // returns magnitude of given vector
{
	float mag = sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));
	return mag;
}

float Transform::Vector3::GetMagnitude() //return self magnitude
{
	return GetMagnitude(*this);
}

Transform::Vector3 Transform::Vector3::Normilize(Vector3 vector)
{
	float mag = vector.GetMagnitude();
	Vector3 normalized = Vector3((vector.x / mag), (vector.y / mag), (vector.z / mag));
	return normalized;
}

Transform::Vector3 Transform::Vector3::Normilize()
{
	return Normilize(*this);
}
//-----------------------------------------------------------------------------------------

//Transform-----------------------------------------------------------------------------------
Transform::Transform()
{
	name = "Transform";
	position = Vector3();
	rotation = Vector3();
	scale = Vector3();
}

Transform::Transform(const GameObject *_gameobject, Vector3 _position, Vector3 _rotation, Vector3 _scale) : Component(_gameobject)
{
	name = "Transform";
	position = _position;
	rotation = _rotation;
	scale = _scale;
}

Transform::~Transform()
{
	std::cout << "I've been destroyed. My name is " << this->name << std::endl;
}

Transform::Vector3 Transform::up = Transform::Vector3(0, 1, 0);

Transform::Vector3 Transform::right = Transform::Vector3(1, 0, 0);

Transform::Vector3 Transform::forward = Transform::Vector3(0, 0, 1);

void Transform::Translate(Transform::Vector3 _translation)
{
	position.x += _translation.x;
	position.y += _translation.y;
	position.z += _translation.z;
}
//-----------------------------------------------------------------------------------------