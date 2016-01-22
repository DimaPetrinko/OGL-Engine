#pragma once
static class GfxFramework
{
public:
	GfxFramework();
	~GfxFramework();

	static bool InitWindow(const char *_title, int _width, int _height);
};

