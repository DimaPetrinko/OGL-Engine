#pragma once
#include "Maths.h"

class Window
{
public:
	static const char *defaultTitle;
	const char *title;
	Maths::Vector2 resolution;
	bool fullscreen;

public:
	Window();
	Window(const char *_title, Maths::Vector2 _resolution, bool _fullscreen);
	~Window();
};

