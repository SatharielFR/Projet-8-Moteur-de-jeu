#pragma once

//namespace Interface 
//{

	#pragma region ForwardDeclarations
		class Sprite;
		class Button;
		class Text;
	#pragma endregion


	class HUD
	{
		public:
			#pragma region GlobalVariables
				LPDIRECT3DVERTEXBUFFER9 g_lpVBuffer;
				LPDIRECT3DTEXTURE9 g_lpTexture;
			#pragma endregion

			#pragma region methods
				HUD();
				void UpdateHUD(LPDIRECT3DDEVICE9 device);
				void InitializeHUD(LPDIRECT3DDEVICE9 device);
				void AddSprite(Sprite* spriteToAdd);
				void RemoveSprite(Sprite* spriteToAdd);
				void AddButton(Button* buttonToAdd);
				void RemoveButton(Button* buttonToAdd);
				void AddText(Text* textToAdd);
				void RemoveText(Text* textToAdd);
			#pragma endregion

		private :
			#pragma region PrivateVariables
				list<Sprite*> _lstSprites;
				list<Button*> _lstButtons;
				list<Text*> _lstTexts;
			#pragma endregion
	};

//}