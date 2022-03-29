#pragma once

class Timer
{
	public :
		#pragma region PublicVariable
			static Timer*	s_inst;
			float			m_initTime;					//Start time of the app
			bool			m_isPerformanceTimer;		
			float			m_frequency;
			LONGLONG		m_performTime;
		#pragma endregion

		#pragma region PublicFunctions
			Timer();
			void InitSystemTime();
			float GetSystemTimeEx();
			float GetDeltaTime();
			bool UpdateTime();
		#pragma endregion

	private:
		#pragma region PrivateVariables
			float m_fElapsedTime;
			float m_fSysTime;
			float m_fTime;
		#pragma endregion 
};

