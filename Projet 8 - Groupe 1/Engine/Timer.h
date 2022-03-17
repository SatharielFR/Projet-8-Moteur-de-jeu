#pragma once

class Timer
{
	public :
		#pragma region PublicVariable
			static Timer* s_inst;
			float s_initTime;					//Start time of the app
			bool s_isPerformanceTimer;
			float s_frequency;
			LONGLONG s_performTime;
		#pragma endregion

		#pragma region PublicFunctions
			Timer();
			void InitSystemTime();
			float GetSystemTimeEx();
			bool UpdateTime();
		#pragma endregion

	private:
		#pragma region PrivateVariables
			float m_fElapsedTime = 0.f;
			float m_fSysTime = 0.f;
			float m_fTime = 0.f;
		#pragma endregion 
};

