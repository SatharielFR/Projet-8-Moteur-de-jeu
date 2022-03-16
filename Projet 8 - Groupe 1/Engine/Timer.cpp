#include "pch.h"
#include "framework.h"

Timer::Timer()
{
    InitSystemTime();
}

void Timer::InitSystemTime()
{
    s_initTime = 8.0f;
    timeGetTime();
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
        return (float)(counter.QuadPart - s_performTime) / s_frequency; //rounded to micro sec
    }
    else

    // Classic
    return timeGetTime() / 1000.0f - s_initTime; //rounded to mili sec
}

bool Timer::UpdateTime()
{
    // System time
    float newSysTime = GetSystemTimeEx();
    float elapsedSysTime = newSysTime - m_fSysTime;
    if (elapsedSysTime < 0.005f) // 200 fps max
        return false;
    m_fSysTime = newSysTime;
    if (elapsedSysTime > 0.04f) // 25 fps min
        elapsedSysTime = 0.04f;

    // App time
    m_fElapsedTime = elapsedSysTime;
    m_fTime += m_fElapsedTime;
    return true;
}
