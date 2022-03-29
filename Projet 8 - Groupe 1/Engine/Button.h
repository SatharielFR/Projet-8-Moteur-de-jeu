#pragma once

class Button : HudElement
{
	public:
		#pragma region PublicFunctions
			Button();
			~Button();
			void Update();
			//virtual void SetWidth(float fWidth) override;
			//virtual void SetHeight(float fWidth) override;
			//virtual void SetPosition(int x, int y) override;
		#pragma endregion

	private:
		#pragma region PrivateVariables
			Sprite* _spriteDefault;
			Sprite* _spriteHover;
			D3DXCOLOR* _colorDefault;
		#pragma endregion

		#pragma region PrivateFunctions
			void Hover();
			void OnClick();
			void DrawButton();
		#pragma endregion
};

