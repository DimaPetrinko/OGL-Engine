#include "stdafx.h"
#include "Headers\Time.h"
#include <chrono>

double Time::deltaTime = 0.16f;
double Time::prevTime = clock();
Time::Time()
{
}


Time::~Time()
{
}

void Time::UpdateDeltaTime()
{
	deltaTime = (clock() - prevTime) / CLOCKS_PER_SEC;
	float c = clock();
	float cps = CLOCKS_PER_SEC;
	prevTime = clock();
}
