#pragma once

#define PI 3.14159265359
#define RAD_TO_DEG 180/PI
#define DEG_TO_RAD PI/180

static class Maths
{
public:
	struct Vector2
	{
		float x, y;

		Vector2();
		Vector2(float _x, float _y);

		static Vector2 up;
		static Vector2 right;

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

		static Vector3 up;
		static Vector3 right;
		static Vector3 forward;

		Vector3 operator*(float _f) const;

		Vector3 operator+(const Vector3 &_v) const;

		Vector3 operator-(const Vector3 &_v) const;

		static float GetMagnitude(Vector3 vector);

		float GetMagnitude();

		static Vector3 Normilize(Vector3 vector);

		Vector3 Normilize();

		float Dot(const Vector3 &_v) const;
		Vector3 Cross(const Vector3 &_v) const;
	};

	struct Quaternion
	{
		float w;
		Vector3 axis;
		
		Quaternion(float _w, const Vector3 &_axis);
		Quaternion();
		Quaternion(const Vector3 &_axis, float _angle);

		Quaternion operator*(const Quaternion& B) const;

		void ToQuaternion(const Vector3 &_axis, float _angle);
		static Quaternion *ToEuler(const Quaternion &_q);
	};

public:
	Maths();
	~Maths();
};

