#pragma once

class RigidbodyComponent : public Component
{
	public :
		D3DXVECTOR3 velocity;
		bool useGravity;
		float GravityStrengh;

		RigidbodyComponent();
		virtual void Begin() override;
		virtual void Update() override;
		void AddForce(D3DXVECTOR3 force);
};

