#pragma once
#define TRANSFORM_H

#include "Component.h"
#include "Maths.h"
//#include "GameObject.h"

class GameObject;

class Transform : public Component
{
public:
	Maths::Vector3 up; //self
	Maths::Vector3 right; //self
	Maths::Vector3 forward; //self

	Maths::Vector3 position;
	Maths::Quaternion rotation;
	Maths::Vector3 scale;

	Transform();
	Transform(const GameObject *_gameObject, Maths::Vector3 _position, Maths::Quaternion _rotation, Maths::Vector3 _scale);
	~Transform();

	void Translate(Maths::Vector3 _translation);

	void Rotate(Maths::Quaternion _rotation);
};

