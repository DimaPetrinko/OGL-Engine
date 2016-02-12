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
#include "Headers\Camera.h"
#include "Headers\Time.h"

#pragma comment(lib,"DevIL.lib")
#pragma comment(lib,"ilut.lib")
#pragma comment(lib,"ilu.lib")

Camera* cam;

void Reshape(int w, int h) 
{
	cam->SetViewport(w, h);
}

//test
GameObject go = GameObject("Test Cube");
GameObject camera = GameObject("Camera");
GameObject anotherGo = GameObject("Another Test Cube");
SphereRenderer newBR;
//---

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	
	//test
	cam->Show();
	go.renderer->Render();
	newBR.Render();
	//---
	
	Time::UpdateDeltaTime();
	std::cout << Time::deltaTime << std::endl;

	glutSwapBuffers();
}

void Idle()
{
	//test
	anotherGo.transform->Rotate(Maths::Quaternion(anotherGo.transform->Up(), 60 * Time::deltaTime));
	go.transform->Rotate(Maths::Quaternion(go.transform->Up(), 60 * Time::deltaTime));
	glutPostRedisplay();
	//---
}

void Keyboard(unsigned char key, int x, int y)
{
	//test
	switch (key)
	{
	case'w':
		camera.transform->Translate(camera.transform->Forward() * -10 * Time::deltaTime);
		break;
	case's':
		camera.transform->Translate(camera.transform->Forward() * 10 * Time::deltaTime);
		break;
	case'a':
		camera.transform->Translate(camera.transform->Right() * -10 * Time::deltaTime);
		break;
	case'd':
		camera.transform->Translate(camera.transform->Right() * 10 * Time::deltaTime);
		break;
	case'e':
		camera.transform->Translate(camera.transform->Up() * 10 * Time::deltaTime);
		break;
	case'q':
		camera.transform->Translate(camera.transform->Up() * -10 * Time::deltaTime);
		break;
	default:
		break;
	}
	//---
}

int main()
{
	Window window = Window("Engine", Maths::Vector2(1366, 768), false);
	//DevILInit();

	//test
	go.SetRenderer(new BoxRenderer(&go, Maths::Vector3(2, 0.3, 0.6)));
	//go.transform->rotation = Maths::Quaternion(Maths::Vector3(1, 0, 0), 30);
	go.renderer->drawGizmos = true;

	anotherGo.SetRenderer(new SphereRenderer(&anotherGo, Maths::Vector3(0.5, 0.7, 1)));
	SphereRenderer *newBRp = (SphereRenderer*)anotherGo.GetComponent("SphereRenderer");
	newBR = *newBRp;
	delete newBRp;
	newBR.gameObject->transform->position = Maths::Vector3(2, 1, 1);
	newBR.gameObject->transform->rotation = Maths::Quaternion(Maths::Vector3(0, 0, 1), 45);
	newBR.gameObject->transform->scale = Maths::Vector3(3,3,0.5);
	newBR.drawGizmos = true;

	camera.AddComponent(new Camera(&camera,45));
	cam = (Camera*)camera.GetComponent("Camera");
	camera.transform->rotation = Maths::Quaternion(Maths::Vector3(1, 0, 0), 30);
	camera.transform->position = Maths::Vector3(0, 0, 2);	
	//----
	
	glutIdleFunc(Idle);
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