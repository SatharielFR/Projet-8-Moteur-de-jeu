#pragma once

class RigidbodyComponent : public Component
{
	public :

		#pragma region PublicVariables
			static int s_type;
			D3DXVECTOR3 velocity;
			bool useGravity;
			float GravityStrengh;
			int radius;
		#pragma endregion

		#pragma region PublicFunctions
			RigidbodyComponent();
			virtual void Begin() override;
			virtual void Update() override;
			virtual int GetType() { return s_type; }
			void AddForce(D3DXVECTOR3 force);
		#pragma endregion
};

