
class TransformComponent : public Component
{
	public :

		TransformComponent();
		virtual void Begin() override;
	//protected :

		Transform* m_transform;
};

