#pragma once
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

		static float GetMagnitude(Vector3 vector);

		float GetMagnitude();

		static Vector3 Normilize(Vector3 vector);

		Vector3 Normilize();
	};

	struct Matrix3
	{
		float matrixArr[3][3];

		Matrix3();
		Matrix3(const float _arr[3][3]);
		Matrix3 operator* (const Maths::Matrix3 &A);
	};

public:
	Maths();
	~Maths();
};

