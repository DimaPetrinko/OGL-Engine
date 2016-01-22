#pragma once
class Window
{
public:
	static const char *defaultTitle;
	const char *title;
	int width;
	int height;

public:
	Window();
	Window(const char *_title, int _width, int _height);
	~Window();
};

