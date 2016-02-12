#pragma once

static class Time
{
public:
	static double deltaTime;
private:
	static double prevTime;
public:
	Time();
	~Time();

	static void UpdateDeltaTime();
};

