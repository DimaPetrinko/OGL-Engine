#pragma once

#include "Transform.h"

static class GfxFramework
{
public:
	GfxFramework();
	~GfxFramework();

	static int InitWindow(const char *_title, Maths::Vector2 _resolution, bool _fullscreen);
	static void DrawCube(Maths::Vector3 color, Maths::Vector3 position, Maths::Vector3 rotation, Maths::Vector3 scale);
};

