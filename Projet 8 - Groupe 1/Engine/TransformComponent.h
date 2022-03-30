
class TransformComponent : public Component
{
	public :

		TransformComponent();
		~TransformComponent();
		virtual int GetType() { return s_type; }
		virtual void Begin() override;
		static int s_type;
		Transform* m_transform;
};

