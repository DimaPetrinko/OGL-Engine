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
	gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
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

	glPushMatrix();

	go.renderer->Render();
	newBR.Render();

	glPopMatrix();

	glutSwapBuffers();
}

void Idle()
{
	go.transform->Translate(Transform::Vector3(.01, .01, 0));
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
{	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	Window window = Window("Engine", 1280, 720, false);
	/*glutInitWindowSize(1346, 680);
	glutInitWindowPosition(10, 0);
	glutCreateWindow("3DGL");*/
	glutIdleFunc(Idle);
	//DevILInit();

	//test
	go.SetRenderer(new BoxRenderer(&go, Transform::Vector3(2, 0.3, 0.6)));
	anotherGo.SetRenderer(new BoxRenderer(&anotherGo, Transform::Vector3(0, 0.3, 0.8)));
	BoxRenderer *newBRp = (BoxRenderer*)anotherGo.GetComponent("BoxRenderer");

	newBR = *newBRp;
	delete newBRp;
	newBR.gameObject->transform->position = Transform::Vector3(2, 1, 1);
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