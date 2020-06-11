#pragma once
class FinalBoss : public Object
{
	Sprite* m_Body;

	Sprite* m_BodyCol;
	Sprite* m_LWingCol;
	Sprite* m_RWingCol;
	Sprite* m_TailWingCol;

	Animation* m_LProp1;
	Animation* m_LProp2;
	Animation* m_LProp3;
	Animation* m_RProp1;
	Animation* m_RProp2;
	Animation* m_RProp3;
public:
	FinalBoss();
	~FinalBoss();

	void CollisionCheak();
	void Collision();

	void Update(float deltatime,float Time);
	void Render();
	void OnCollision(Object* other);

	void SetObjectsPosition();
};

