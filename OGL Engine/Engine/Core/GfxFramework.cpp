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

int GfxFramework::InitWindow(const char *_title, Maths::Vector2 _resolution, bool _fullscreen)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	if (_fullscreen)
	{ 
		glutFullScreen();
	}
	else
	{
		glutInitWindowSize((int)_resolution.x, (int)_resolution.y);
		glutInitWindowPosition(0, 0);
	}

	std::cout << "Initialized new window: " << _title << " " << _resolution.x << "x" << _resolution.y << " fullscreen " << _fullscreen << std::endl;
	return glutCreateWindow(_title);
}

void GfxFramework::DrawCube(Maths::Vector3 color, Maths::Vector3 position, Maths::Vector3 rotation, Maths::Vector3 scale)
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
