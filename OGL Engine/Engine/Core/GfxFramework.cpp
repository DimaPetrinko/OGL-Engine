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

void GfxFramework::DrawGizmos(Maths::Vector3 position, Maths::Quaternion rotation, Maths::Vector3 scale)
{
	glPushMatrix();

	//Translate
	glTranslatef(position.x, position.y, position.z);

	//Rotate
	Maths::Quaternion *q = Maths::Quaternion::ToEuler(rotation);
	glRotatef(q->w, q->axis.x, q->axis.y, q->axis.z);
	delete(q);

	//Draw
	glLineWidth(5);

	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(scale.x, 0, 0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, scale.y, 0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, scale.z);
	glEnd();

	glColor3f(1, 1, 1);

	glLineWidth(1);

	glPopMatrix();
}

void GfxFramework::DrawCube(Maths::Vector3 color, Maths::Vector3 position, Maths::Quaternion rotation, Maths::Vector3 scale)
{
	glPushMatrix();

	//Translate
	glTranslatef(position.x, position.y, position.z);

	//Rotate
	Maths::Quaternion *q = Maths::Quaternion::ToEuler(rotation);
	/*std::cout << "w: " << q->w
		<< ", x: " << q->axis.x
		<< ", y: " << q->axis.y
		<< ", z: " << q->axis.z
		<< std::endl;*/
	
	glRotatef(q->w, q->axis.x, q->axis.y, q->axis.z);

	delete(q);
	/*glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.x, 1, 0, 0);	
	glRotatef(rotation.z, 0, 0, 1);*/

	//Scale
	glScalef(scale.x, scale.y, scale.z);

	//Color
	glColor3f(color.x, color.y, color.z);

	//Draw
	glutSolidCube(1);

	glPopMatrix();
}

void GfxFramework::DrawSphere(Maths::Vector3 color, Maths::Vector3 position, Maths::Quaternion rotation, Maths::Vector3 scale, bool lit)
{
	glPushMatrix();

	//Translate
	glTranslatef(position.x, position.y, position.z);

	//Rotate
	Maths::Quaternion *q = Maths::Quaternion::ToEuler(rotation);
	glRotatef(q->w, q->axis.x, q->axis.y, q->axis.z);
	delete(q);

	//Scale
	glScalef(scale.x, scale.y, scale.z);

	//Color
	glColor3f(color.x, color.y, color.z);

	//Draw
	if (!lit) glDisable(GL_LIGHTING);
	glutSolidSphere(0.5, scale.x * 10, scale.y * 10);
	if (!lit) glEnable(GL_LIGHTING);
	glPopMatrix();
}

void GfxFramework::SetViewport(int _w, int _h, int _fov)
{
	if (_h == 0) _h = 1;
	float ratio = _w / (float)_h;
	glViewport(0, 0, _w, _h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(_fov, ratio, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
}

void GfxFramework::Show(Maths::Vector3 position, Maths::Quaternion rotation)
{
	glTranslatef(-position.x, -position.y, -position.z);
	Maths::Quaternion *q = Maths::Quaternion::ToEuler(rotation);
	glRotatef(q->w, -q->axis.x, -q->axis.y, -q->axis.z);
	delete(q);
}