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
			void SetTextureSize(int nbNewSizeX, int nbNewSizeY) { _vec2TextureSize->x = nbNewSizeX; _vec2TextureSize->y = nbNewSizeY;}
			D3DXVECTOR2 GetTextureSize() { return *_vec2TextureSize; }
			void SetSpriteColor(D3DXCOLOR* color);
			virtual void SetWidth(float nbWidth) override;
			virtual void SetHeight(float nbHeight) override;
			virtual void SetScale(float fScale) override;
		#pragma endregion


	private :
		#pragma region PrivateVariables
			D3DXVECTOR2* _vec2TextureSize = new D3DXVECTOR2(1024,1024);
			ID3DXSprite* _sprite;
			D3DXCOLOR* _colorSprite;
			LPDIRECT3DTEXTURE9 _text;
		#pragma endregion

};

