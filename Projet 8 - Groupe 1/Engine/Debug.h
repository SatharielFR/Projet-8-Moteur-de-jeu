#pragma once

#include <string>
class ID3DXFont;

class Debug
{
	public:
		#pragma region PublicVariable
			static Debug* s_inst;
		#pragma endregion

		#pragma region PublicFunctions
			Debug(LPDIRECT3DDEVICE9* d3ddev);
			void Init();
			void ScreenLog(const char charToLog[]);
			void ScreenLog(char charToLog[]);
			void ScreenLog(string* strToLog);
		#pragma endregion

	private:
		#pragma region PrivateVariables
			LPDIRECT3DDEVICE9* _d3ddev;    // the pointer to the device class
			//Font variable
			ID3DXFont* _Font = 0;
			std::wstring _strToLog;
		#pragma endregion

};

static void ConsoleLog(string s)
{
	s += "\n";
	wstring temp(s.begin(), s.end());
	LPCWSTR lpcwstr = temp.c_str();
	OutputDebugStringW(lpcwstr);
}

