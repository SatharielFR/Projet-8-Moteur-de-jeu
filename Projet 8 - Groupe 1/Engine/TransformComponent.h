
class TransformComponent : public Component
{
	public :

		TransformComponent();
		virtual int GetType() { return _type; }
		virtual void Begin() override;
	//protected :

		static int _type;
		Transform* m_transform;
};

