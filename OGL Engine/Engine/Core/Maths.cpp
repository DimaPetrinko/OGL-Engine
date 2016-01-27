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

Maths::Vector3 Maths::Vector3::operator*(float _f) const
{
	return Maths::Vector3(x * _f, y * _f, z * _f);
}

Maths::Vector3 Maths::Vector3::operator+(const Maths::Vector3 &_v) const
{
	return Vector3(x + _v.x, y + _v.y, z + _v.z);
}

Maths::Vector3 Maths::Vector3::operator-(const Maths::Vector3 &_v) const
{
	return Vector3(x - _v.x, y - _v.y, z - _v.z);
}

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

float Maths::Vector3::Dot(const Maths::Vector3 &_v) const
{
	return (x * _v.x) + (y * _v.y) + (z * _v.z);
}

Maths::Vector3 Maths::Vector3::Cross(const Maths::Vector3 &_v) const
{
	return Vector3(y * _v.z - z * _v.y,
		z * _v.x - x * _v.z,
		x * _v.y - y * _v.x);
}
//-----------------------------------------------------------------------------------------

//Quaternion-------------------------------------------------------------------------------
Maths::Quaternion::Quaternion(float _w, const Maths::Vector3 &_axis) 
{
	w = _w;
	axis = _axis;
}

Maths::Quaternion::Quaternion() : Maths::Quaternion::Quaternion(1, Vector3())
{
}

Maths::Quaternion::Quaternion(const Vector3 &_axis, float _angle)
{
	ToQuaternion(_axis, _angle);
}

Maths::Quaternion Maths::Quaternion::operator*(const Maths::Quaternion& B) const
{
	Maths::Quaternion r;

	r.w = w * B.w - axis.Dot(B.axis);
	r.axis = axis * B.w + B.axis * w + axis.Cross(B.axis);

	return r;
}

void Maths::Quaternion::ToQuaternion(const Maths::Vector3 &_axis, float _angle)
{
	w = std::cos(_angle * DEG_TO_RAD / 2);
	axis.x = std::sin(_angle * DEG_TO_RAD / 2)* _axis.x;
	axis.y = std::sin(_angle * DEG_TO_RAD / 2)* _axis.y;
	axis.z = std::sin(_angle * DEG_TO_RAD / 2)* _axis.z;
}

Maths::Quaternion *Maths::Quaternion::ToEuler(const Maths::Quaternion &_q)
{
	Quaternion* _qp = new Quaternion();
	float _wOld = _q.w;
	_qp->w = 2 * std::acos(_q.w) * RAD_TO_DEG;
	if (_q.w <= 1 && _q.w >= -1)
	{
		_qp->axis.x = _q.axis.x / std::sin(std::acos(_q.w));
		_qp->axis.y = _q.axis.y / std::sin(std::acos(_q.w));
		_qp->axis.z = _q.axis.z / std::sin(std::acos(_q.w));
	}
	else
	{
		if (_q.w > 1) _qp->w = 1;
		else _qp->w = -1;
		_qp->axis.x = 0;
		_qp->axis.y = 0;
		_qp->axis.z = 0;
	}
	return _qp;
}
//-----------------------------------------------------------------------------------------

//Matrix3----------------------------------------------------------------------------------
//Maths::Matrix3::Matrix3(const float _arr[3][3])
//{
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			matrixArr[i][j] = _arr[i][j];
//		}
//	}
//}
//
//Maths::Matrix3::Matrix3()
//{
//	float *_arr[3][3] = 
//	{
//		{0,0,0},
//		{0,0,0},
//		{0,0,0}	
//	};
//	//Maths::Matrix3::Matrix3(_arr);
//}
//
//Maths::Matrix3 Maths::Matrix3::operator* (const Matrix3 &A)
//{
//	Matrix3 _mat = Matrix3();
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			_mat.matrixArr[i][j] = A.matrixArr[i][j];
//		}
//	}
//	return _mat;
//}
//-----------------------------------------------------------------------------------------

Maths::Maths()
{
}


Maths::~Maths()
{
}
