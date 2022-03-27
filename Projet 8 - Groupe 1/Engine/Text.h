#pragma once

#include "HudElement.h"

class Text : public HudElement
{
	public :
		#pragma region PublicMethods
			Text();
			~Text();
			void InitFont();
			virtual void Update() override;
			void DrawTextOnScreen();
			void SetText(string strText);
			void SetTextColor(D3DXCOLOR color);
			//TODO : Set Font
			//TODO : Set Font Size
		#pragma endregion


	private:
		#pragma region PrivateVariables
			//Text
			ID3DXFont* _Font = 0; 					//Font variable*
			string _strText;
			std::wstring _wstrTextToDisplay;
			//Color
			D3DCOLOR _colorText = D3DXCOLOR(255, 240, 0, 1);
		#pragma endregion
};

