#pragma once
class Timer
{
	public :

		float s_initTime;
		bool s_isPerformanceTimer;
		float s_frequency;
		LONGLONG s_performTime;

		Timer();
		void InitSystemTime();
		float GetSystemTimeEx();
};

