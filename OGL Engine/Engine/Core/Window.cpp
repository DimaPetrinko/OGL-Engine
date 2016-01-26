#include "stdafx.h"
#include "Headers\Window.h"
#include "Headers\GfxFramework.h"
#include <iostream>

const char *Window::defaultTitle = "NewWindow";;

Window::Window()
{
	title = defaultTitle;
	width = 600;
	height = 400;
	GfxFramework::InitWindow(title, width, height, false);
}

Window::Window(const char *_title, int _width, int _height, bool _fullscreen)
{
	title = _title;
	width = _width;
	height = _height;
	fullscreen = _fullscreen;
	GfxFramework::InitWindow(title, width, height, _fullscreen);
}

Window::~Window()
{
}
