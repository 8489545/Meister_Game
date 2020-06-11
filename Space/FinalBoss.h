#pragma once
class FinalBoss : public Object
{
	Sprite* m_Body;

	Sprite* m_BodyCol;
	Sprite* m_LWingCol;
	Sprite* m_RWingCol;
	Sprite* m_TailWingCol;
public:
	FinalBoss();
	~FinalBoss();

	void CollisionCheak();

	void Update(float deltatime,float Time);
	void Render();
	void OnCollision(Object* other);

	void SetObjectsPosition();
};

