#pragma once

#include "Transform.h"

static class GfxFramework
{
public:
	GfxFramework();
	~GfxFramework();

	static int InitWindow(const char *_title, int _width, int _height, bool _fullscreen);
	static void DrawCube(Transform::Vector3 color, Transform::Vector3 position, Transform::Vector3 rotation, Transform::Vector3 scale);
};

