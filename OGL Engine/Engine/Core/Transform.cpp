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
	rotation = rotation * _rotation;
}
//-----------------------------------------------------------------------------------------