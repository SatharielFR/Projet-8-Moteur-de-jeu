#pragma once

class Sprite : public HudElement
{
	public:
		#pragma region PublicFunctions
			Sprite();
			~Sprite();
			void Update();
			void SetTexture(string strTextureName);
			void DrawSprite();
			void SetScale(float fScale);
			void SetPosition(int x, int y);
			void SetSpriteColor(D3DXCOLOR* color);
		#pragma endregion

	private :
		#pragma region PrivateVariables
			Transform _transform;
			ID3DXSprite* _sprite;
			D3DXCOLOR* _colorSprite;
			LPDIRECT3DTEXTURE9 _text;
		#pragma endregion

};

