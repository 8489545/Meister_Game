#pragma once
class Enemy2 : public Object
{
	Sprite* m_Enemy;
public:
	Enemy2(Vec2 Pos);
	~Enemy2();

	float m_Speed;
	float m_Atk;

	float m_LastFireTick;
	float m_FireDelay;
	float m_NowTime;
	float m_HoldingTime;

	Vec2 m_RandomPosition;
	float m_MoveWaitingTime;
	float m_LastMoveTime;

	void Move();
	void Shot();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

