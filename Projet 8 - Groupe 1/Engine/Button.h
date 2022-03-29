#pragma once
#include <functional>

class Button : HudElement
{
	public:
		#pragma region PublicFunctions
			Button(Engine* engine);
			~Button();
			void Update();
			virtual void SetWidth(float fWidth) override;
			virtual void SetHeight(float fHeight) override;
			virtual void SetPosition(int x, int y) override;
			void SetDefaultColor(D3DXCOLOR* color);
			void SetHoverColor(D3DXCOLOR* color);
			void SetTexture(string a, string b);
			void SetTextureResolution(int x,int y);
			std::function<void()> m_OnClic;
		#pragma endregion

	private:
		#pragma region PrivateVariables
			Engine* _engine;
			Sprite* _spriteDefault;
			Sprite* _spriteHover;
			D3DXCOLOR* _colorDefault;
			D3DXCOLOR* _colorHover;
		#pragma endregion

		#pragma region PrivateFunctions
			bool IsMouseHover();
			void OnClick();
			void DrawButton();
		#pragma endregion
};

