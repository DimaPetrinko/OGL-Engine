#include "stdafx.h"
#include <Windows.h>
#include <GL\glut.h>

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
		glutInitWindowPosition(100, -100);
	}
	return glutCreateWindow(_title);
}

void GfxFramework::DrawCube(Transform::Vector3 color, Transform::Vector3 position, Transform::Vector3 rotation, Transform::Vector3 scale)
{
	//Translation
	glTranslatef(position.x, position.y, position.z);

	//Rotation
	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	//Scaling
	glScalef(scale.x, scale.y, scale.z);

	//Coloring
	glColor3f(color.x, color.y, color.z);

	//Drawing
	glutSolidCube(1);
	
	//Unoloring
	glColor3f(1,1,1);

	//Unscaling
	glScalef(scale.x, scale.y, scale.z);

	//Reverse rotation
	glRotatef(-rotation.x, 1, 0, 0);
	glRotatef(-rotation.y, 0, 1, 0);
	glRotatef(-rotation.z, 0, 0, 1);

	//Reverse translation
	glTranslatef(-position.x, -position.y, -position.z);
}
