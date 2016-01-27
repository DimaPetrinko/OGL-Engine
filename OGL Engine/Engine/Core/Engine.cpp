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

#include "Headers\Component.h"
#include "Headers\Transform.h"
#include "Headers\Window.h"
#include "Headers\BoxRenderer.h"

#pragma comment(lib,"DevIL.lib")
#pragma comment(lib,"ilut.lib")
#pragma comment(lib,"ilu.lib")

void Reshape(int w, int h) {
	if (h == 0) h = 1;
	float ratio = w / (float)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 0.1, 100);
	glTranslated(0, 0, -10);
	//gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);	
}

//test
GameObject go = GameObject("Test Cube");
GameObject anotherGo = GameObject("Another Test Cube");
BoxRenderer newBR;

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	
	go.renderer->Render();
	newBR.Render();

	glutSwapBuffers();
}

void Idle()
{
	go.transform->Rotate(Maths::Quaternion(Maths::Vector3(1,1,0),1));
	glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y)
{
	//test
	switch (key)
	{
	case'w':
		glTranslatef(0, -.1, 0);
		break;
	case's':
		glTranslatef(0, .1, 0);
		break;
	case'a':
		glTranslatef(.1, 0, 0);
		break;
	case'd':
		glTranslatef(-.1, 0, 0);
		break;
	default:
		break;
	}
	//---
}

int main()
{
	Window window = Window("Engine", Maths::Vector2(1920, 1080), false);
	glutIdleFunc(Idle);
	//DevILInit();

	//test
	go.SetRenderer(new BoxRenderer(&go, Maths::Vector3(2, 0.3, 0.6)));
	anotherGo.SetRenderer(new BoxRenderer(&anotherGo, Maths::Vector3(0, 0.3, 0.8)));
	BoxRenderer *newBRp = (BoxRenderer*)anotherGo.GetComponent("BoxRenderer");

	newBR = *newBRp;
	delete newBRp;
	newBR.gameObject->transform->position = Maths::Vector3(2, 1, 1);
	newBR.gameObject->transform->rotation = Maths::Quaternion(Maths::Vector3(0, 1, 0), 45);
	newBR.gameObject->transform->scale = Maths::Vector3(2, 2, 2);

	Maths::Quaternion q1 = Maths::Quaternion(Maths::Vector3(0,1,0), 45);
	Maths::Quaternion q2 = Maths::Quaternion(Maths::Vector3(0,1,0), 5);
	Maths::Quaternion q3 = q1 * q2;
	Maths::Quaternion* q3p = Maths::Quaternion::ToEuler(q3);
	//----

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