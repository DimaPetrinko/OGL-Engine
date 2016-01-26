#include "stdafx.h"
#include "Headers\Window.h"
#include "Headers\GfxFramework.h"
#include <iostream>

const char *Window::defaultTitle = "NewWindow";;

Window::Window()
{
	title = defaultTitle;
	resolution = Maths::Vector2(600, 400);
	GfxFramework::InitWindow(title, resolution, false);
}

Window::Window(const char *_title, Maths::Vector2 _resolution, bool _fullscreen)
{
	title = _title;
	resolution = _resolution;
	fullscreen = _fullscreen;
	GfxFramework::InitWindow(title, _resolution, _fullscreen);
}

Window::~Window()
{
}
