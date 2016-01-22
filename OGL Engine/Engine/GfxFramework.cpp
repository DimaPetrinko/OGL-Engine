#include "stdafx.h"
#include <Windows.h>
#include <GL\glut.h>

#include "GfxFramework.h"


GfxFramework::GfxFramework()
{
}


GfxFramework::~GfxFramework()
{
}

bool GfxFramework::InitWindow(const char *_title, int _width, int _height) 
{
	glutInitWindowSize(_width, _height);
	glutInitWindowPosition(100, -100);
	return glutCreateWindow(_title);
}
