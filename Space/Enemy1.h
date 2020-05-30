#pragma once
class Enemy1 : public Object
{
	Sprite* m_Enemy;
public:
	Enemy1(Vec2 Pos);
	~Enemy1();

	float m_Speed;
	float m_FireDelay;
	float m_LastFireTime;
	float m_HP;
	float m_HoldingTime;
	float m_NowTime;
	float m_RandYPos;
	float m_RandXPos;
	float m_RandSniffling;
	float m_Distance;

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

