#pragma once

#include <string>
class ID3DXFont;

struct Log
{
	public:
		Log(string strToPrint, float fDuration)
		{
			_strToPrint = strToPrint;
			_fDuration = fDuration;
			_fCreationTime = Timer::s_inst->GetSystemTimeEx();
		}
		string GetText() {return _strToPrint;}
		bool bShouldBeDestroy() 
		{
			if (Timer::s_inst->GetSystemTimeEx() > _fCreationTime + _fDuration)
			{
				return true;
			}
			return false;
		}
	private:
		string _strToPrint;
		float _fDuration;
		float _fCreationTime;
};

class Debug
{
	public:
		#pragma region PublicVariable
			static Debug* s_inst;
		#pragma endregion

		#pragma region PublicFunctions
			Debug(LPDIRECT3DDEVICE9* d3ddev);
			void Init();
			void ScreenLog(const char charToLog[], float fDuration = -1);
			void ScreenLog(char charToLog[], float fDuration = -1);
			void ScreenLog(string* strToLog, float fDuration = -1);
			void UpdateScreenLogs();
		#pragma endregion

	private:
		#pragma region PrivateVariables
			LPDIRECT3DDEVICE9* _d3ddev;    // the pointer to the device class
			//Font variable
			ID3DXFont* _Font = 0;
			std::wstring _wstrToLog;
			list<Log*> _lstLogs;
			float _fDefaultDuration = 3.0f;
			D3DCOLOR _DefaultColor = D3DXCOLOR(255,240,0,1);
		#pragma endregion

};

static void ConsoleLog(string s)
{
	s += "\n";
	wstring temp(s.begin(), s.end());
	LPCWSTR lpcwstr = temp.c_str();
	OutputDebugStringW(lpcwstr);
}

