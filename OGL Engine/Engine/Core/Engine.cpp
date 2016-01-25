// Engine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <GL\glut.h>
#include <math.h>
#include <vector>
#include <IL/il.h>
#include <IL/ilut.h>
#include <iostream>

#include "Component.h"
#include "Transform.h"
#include "Window.h"

#pragma comment(lib,"DevIL.lib")
#pragma comment(lib,"ilut.lib")
#pragma comment(lib,"ilu.lib")

struct Vector2
{
	float x, y;

	Vector2() { x = 0.0f; y = 0.0f; }
	Vector2(float _x, float _y) { x = _x; y = _y; }

	static float GetMagnitude(Vector2 vector) // returns magnitude of given vector
	{
		float mag = sqrt((vector.x*vector.x) + (vector.y*vector.y));
		return mag;
	}

	float GetMagnitude() //return self magnitude
	{
		return GetMagnitude(*this);
	}

	static Vector2 Normilize(Vector2 vector) 
	{
		float mag = vector.GetMagnitude();
		Vector2 normalized = Vector2((vector.x / mag), (vector.y / mag));
		return normalized;
	}

	Vector2 Normilize()
	{
		return Normilize(*this);
	}
};

void Reshape(int w, int h) {
	if (h == 0) h = 1;
	float ratio = w / (float)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 0.1, 100);
	gluLookAt(0, 2, 1, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);

	//test
	glColor3d(0.2, 0.85, 0.67);
	glutSolidCube(1);

	glutSwapBuffers();
}

void Idle()
{

}

void Keyboard(unsigned char key, int x, int y)
{

}

GameObject go = GameObject();

int main()
{
	//Transform *t = (Transform*)go.GetComponent("Transform");
	//std::cout << t->name << std::endl;

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	Window window = Window("Engine", 1280, 720, false);
	/*glutInitWindowSize(1346, 680);
	glutInitWindowPosition(10, 0);
	glutCreateWindow("3DGL");*/
	glutIdleFunc(Idle);
	//DevILInit();
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	//glutPassiveMotionFunc(MouseRot);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glutMainLoop();
	return 0;
}