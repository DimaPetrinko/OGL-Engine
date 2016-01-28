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
#include "Headers\SphereRenderer.h"

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
SphereRenderer newBR;
//---

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	
	//test
	go.renderer->Render();
	newBR.Render();
	//---

	glutSwapBuffers();
}

void Idle()
{
	//test
	anotherGo.transform->Rotate(Maths::Quaternion(anotherGo.transform->Up(), 1));
	go.transform->Rotate(Maths::Quaternion(go.transform->Up(), 1));
	glutPostRedisplay();
	//---
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
	anotherGo.SetRenderer(new SphereRenderer(&anotherGo, Maths::Vector3(0.5, 0.7, 1)));
	SphereRenderer *newBRp = (SphereRenderer*)anotherGo.GetComponent("SphereRenderer");

	newBR = *newBRp;
	delete newBRp;
	newBR.gameObject->transform->position = Maths::Vector3(2, 1, 1);
	newBR.gameObject->transform->rotation = Maths::Quaternion(Maths::Vector3(0, 0, 1), 45);
	newBR.gameObject->transform->scale = Maths::Vector3(3,3,0.5);
	newBR.drawGizmos = true;
	go.transform->rotation = Maths::Quaternion(Maths::Vector3(1, 0, 0), 30);
	go.renderer->drawGizmos = true;
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