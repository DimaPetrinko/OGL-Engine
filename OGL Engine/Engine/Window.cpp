#include "stdafx.h"
#include "Window.h"
#include "GfxFramework.h"

const char *Window::defaultTitle = "NewWindow";;

Window::Window()
{
	title = defaultTitle;
	width = 600;
	height = 400;
	GfxFramework::InitWindow(title, width, height);
}

Window::Window(const char *_title, int _width, int _height) 
{
	title = _title;
	width = _width;
	height = _height;
	GfxFramework::InitWindow(title, width, height);
}

Window::~Window()
{
}
