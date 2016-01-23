#pragma once
static class GfxFramework
{
public:
	GfxFramework();
	~GfxFramework();

	static int InitWindow(const char *_title, int _width, int _height, bool _fullscreen);
};

