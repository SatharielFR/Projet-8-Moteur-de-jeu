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
		#pragma endregion

		#pragma region Accessors
			void SetTextureSize(int nbNewSize) { _nbTextureSize = nbNewSize; }
			int GetTextureSize() { return _nbTextureSize; }
			void SetSpriteColor(D3DXCOLOR* color);
			virtual void SetWidth(float nbWidth) override;
			virtual void SetHeight(float nbHeight) override;
			virtual void SetScale(float fScale) override;
		#pragma endregion


	private :
		#pragma region PrivateVariables
			int _nbTextureSize = 1024;
			ID3DXSprite* _sprite;
			D3DXCOLOR* _colorSprite;
			LPDIRECT3DTEXTURE9 _text;
		#pragma endregion

};

