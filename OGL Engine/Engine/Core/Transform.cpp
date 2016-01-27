#include "stdafx.h"
#include "Headers\Transform.h"

//Transform-----------------------------------------------------------------------------------
Transform::Transform()
{
	name = "Transform";
	position = Maths::Vector3();
	rotation = Maths::Quaternion();
	scale = Maths::Vector3();
}

Transform::Transform(const GameObject *_gameobject, Maths::Vector3 _position, Maths::Quaternion _rotation, Maths::Vector3 _scale) : Component(_gameobject)
{
	name = "Transform";
	position = _position;
	rotation = _rotation;
	scale = _scale;
}

Transform::~Transform()
{
}

void Transform::Translate(Maths::Vector3 _translation)
{	
	position.x += _translation.x;
	position.y += _translation.y;
	position.z += _translation.z;
}

void Transform::Rotate(Maths::Quaternion _rotation)
{
	rotation = _rotation * rotation;
}

Maths::Vector3 Transform::Up()
{
	Maths::Vector3 vUp = Maths::Vector3(0, 1, 0);
	return rotation * vUp;
}

Maths::Vector3 Transform::Right()
{
	Maths::Vector3 vRight = Maths::Vector3(1, 0, 0);
	return rotation * vRight;
}

Maths::Vector3 Transform::Forward()
{
	Maths::Vector3 vForward = Maths::Vector3(0, 0, 1);
	return rotation * vForward;
}
//-----------------------------------------------------------------------------------------