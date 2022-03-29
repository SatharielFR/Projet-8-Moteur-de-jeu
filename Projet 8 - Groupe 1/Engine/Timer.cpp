#include "pch.h"
#include "framework.h"

Timer* Timer::s_inst = nullptr;

Timer::Timer()
{   
    //Singleton
    if (s_inst)
    {
        delete(this);
    }
    else
    {
        s_inst = this;
    }
    InitSystemTime();
}

void Timer::InitSystemTime()
{
	m_initTime = timeGetTime() / 1000.0f;
	m_isPerformanceTimer = false;
    m_frequency = 0.0f;
    LARGE_INTEGER frequency;
    memset(&frequency, 0, sizeof(LARGE_INTEGER));
    if (QueryPerformanceFrequency(&frequency) && frequency.QuadPart)
    {
        m_isPerformanceTimer = true;
        m_frequency = (float)frequency.QuadPart;
        LARGE_INTEGER counter;
        QueryPerformanceCounter(&counter);
        m_performTime = counter.QuadPart;
    }
}

float Timer::GetSystemTimeEx()
{
    // Performance
    if (m_isPerformanceTimer)
    {
        LARGE_INTEGER counter;
        QueryPerformanceCounter(&counter);
        return (float)(counter.QuadPart - m_performTime) / m_frequency; //rounded to micro sec
    }
    else

    // Classic
    return timeGetTime() / 1000.0f - m_initTime; //rounded to mili sec
}

bool Timer::UpdateTime()
{
    // System time
    float newSysTime = GetSystemTimeEx();
    float elapsedSysTime = newSysTime - m_fSysTime;
    if (elapsedSysTime < 0.005f) // 200 fps max
        return false;
    m_fSysTime = newSysTime;
    //if (elapsedSysTime > 0.04f) // 25 fps min
    //    elapsedSysTime = 0.04f;
    // App time
    m_fElapsedTime = elapsedSysTime;
    m_fTime += m_fElapsedTime;

    return true;
}

float Timer::GetDeltaTime()
{
    return m_fElapsedTime;
}

void Timer::UpdateDeltaTime()
{
    //Update DeltaTime
//    m_fDeltaTime = GetSystemTimeEx() - m_fTimeLastFrame;
//    m_fTimeLastFrame = GetSystemTimeEx();
}
