#pragma once


class Timer
{
	public :
		#pragma region PublicVariable
			static float s_initTime;
			static bool s_isPerformanceTimer;
			static float s_frequency;
			static LONGLONG s_performTime;
		#pragma endregion


		#pragma region PublicFunctions
			Timer(float initTime, bool isPerformanceTimer, float frequency, LONGLONG performTime);
			void InitSystemTime();
			float GetSystemTimeEx();
		#pragma endregion

	private:
};

