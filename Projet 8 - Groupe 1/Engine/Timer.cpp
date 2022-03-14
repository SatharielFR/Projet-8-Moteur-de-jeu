#include "pch.h"
#include "framework.h"


Timer::Timer(float initTime, bool isPerformanceTimer, float frequency, LONGLONG performTime)
{
    initTime = s_initTime;
    isPerformanceTimer = s_isPerformanceTimer;
    frequency = s_frequency;
    performTime = s_performTime;
}

void Timer::InitSystemTime()
{
	s_initTime = timeGetTime() / 1000.0f;
	s_isPerformanceTimer = false;
    s_frequency = 0.0f;
    LARGE_INTEGER frequency;
    memset(&frequency, 0, sizeof(LARGE_INTEGER));
    if (QueryPerformanceFrequency(&frequency) && frequency.QuadPart)
    {
        s_isPerformanceTimer = true;
        s_frequency = (float)frequency.QuadPart;
        LARGE_INTEGER counter;
        QueryPerformanceCounter(&counter);
        s_performTime = counter.QuadPart;
    }
}

float Timer::GetSystemTimeEx()
{
    // Performance
    if (s_isPerformanceTimer)
    {
        LARGE_INTEGER counter;
        QueryPerformanceCounter(&counter);
        return (float)(counter.QuadPart - s_performTime) / s_frequency;
    }

    // Classic
    return timeGetTime() / 1000.0f - s_initTime;
}