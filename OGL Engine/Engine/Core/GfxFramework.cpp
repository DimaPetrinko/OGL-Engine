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
