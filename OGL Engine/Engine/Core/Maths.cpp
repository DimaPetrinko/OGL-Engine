#include "stdafx.h"
#include "Headers\Maths.h"
#include <iostream>


//Vector2-----------------------------------------------------------------------------------
Maths::Vector2::Vector2() { x = 0.0f; y = 0.0f; }

Maths::Vector2::Vector2(float _x, float _y) { x = _x; y = _y; }

Maths::Vector2 Maths::Vector2::up = Maths::Vector2(0, 1); //worldspace

Maths::Vector2 Maths::Vector2::right = Maths::Vector2(1, 0); //worldspace

float Maths::Vector2::GetMagnitude(Vector2 vector) // returns magnitude of given vector
{
	float mag = sqrt((vector.x*vector.x) + (vector.y*vector.y));
	return mag;
}

float Maths::Vector2::GetMagnitude() //return self magnitude
{
	return GetMagnitude(*this);
}

Maths::Vector2 Maths::Vector2::Normilize(Vector2 vector)
{
	float mag = vector.GetMagnitude();
	Vector2 normalized = Vector2((vector.x / mag), (vector.y / mag));
	return normalized;
}

Maths::Vector2 Maths::Vector2::Normilize()
{
	return Normilize(*this);
}
//-----------------------------------------------------------------------------------------

//Vector3-----------------------------------------------------------------------------------
Maths::Vector3::Vector3() { x = 0.0f; y = 0.0f; z = 0.0; }

Maths::Vector3::Vector3(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }

Maths::Vector3 Maths::Vector3::up = Maths::Vector3(0, 1, 0); //worldspace

Maths::Vector3 Maths::Vector3::right = Maths::Vector3(1, 0, 0); //worldspace

Maths::Vector3 Maths::Vector3::forward = Maths::Vector3(0, 0, 1); //worldspace

float Maths::Vector3::GetMagnitude(Vector3 vector) // returns magnitude of given vector
{
	float mag = sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));
	return mag;
}

float Maths::Vector3::GetMagnitude() //return self magnitude
{
	return GetMagnitude(*this);
}

Maths::Vector3 Maths::Vector3::Normilize(Vector3 vector)
{
	float mag = vector.GetMagnitude();
	Vector3 normalized = Vector3((vector.x / mag), (vector.y / mag), (vector.z / mag));
	return normalized;
}

Maths::Vector3 Maths::Vector3::Normilize()
{
	return Normilize(*this);
}
//-----------------------------------------------------------------------------------------

//Matrix3----------------------------------------------------------------------------------
Maths::Matrix3::Matrix3(const float *_arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrixArr[i][j] = _arr[i][j];
		}
	}
}

Maths::Matrix3::Matrix3()
{
	float *_arr[3][3] = 
	{
		{0,0,0},
		{0,0,0},
		{0,0,0}	
	};
	Maths::Matrix3::Matrix3(_arr);
}

Maths::Matrix3 Maths::Matrix3::operator* (const Matrix3 &A)
{
	Matrix3 _mat = Matrix3();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_mat.matrixArr[i][j] = A.matrixArr[i][j];
		}
	}
	return _mat;
}
//-----------------------------------------------------------------------------------------

Maths::Maths()
{
}


Maths::~Maths()
{
}
