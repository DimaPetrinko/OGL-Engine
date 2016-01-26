#include "stdafx.h"
#include <Windows.h>
#include <GL\glut.h>
#include <iostream>

#include "Headers\GfxFramework.h"


GfxFramework::GfxFramework()
{
}


GfxFramework::~GfxFramework()
{
}

int GfxFramework::InitWindow(const char *_title, int _width, int _height, bool _fullscreen) 
{

	if (_fullscreen)
	{ 
		glutFullScreen();
	}
	else
	{
		glutInitWindowSize(_width, _height);
		glutInitWindowPosition(0, 0);
	}

	std::cout << "Initialized new window: " << _title << " " << _width << "x" << _height << " fullscreen " << _fullscreen << std::endl;
	return glutCreateWindow(_title);
}

void GfxFramework::DrawCube(Transform::Vector3 color, Transform::Vector3 position, Transform::Vector3 rotation, Transform::Vector3 scale)
{
	glPushMatrix();

	//Translate
	glTranslatef(position.x, position.y, position.z);

	//Rotate
	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	//Scale
	glScalef(scale.x, scale.y, scale.z);

	//Color
	glColor3f(color.x, color.y, color.z);

	//Draw
	glutSolidCube(1);

	glPopMatrix();
}
