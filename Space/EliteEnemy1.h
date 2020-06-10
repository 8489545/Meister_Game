#pragma once
class EliteEnemy1 : public Object
{
	Sprite* m_Enemy;
public:
	EliteEnemy1(Vec2 Pos);
	~EliteEnemy1();

	float m_Atk;
	float m_LastFireTick;
	float m_NowTime;
	float m_Speed;
	float m_FireDelay;

	Vec2 m_RandomPosition;
	float m_MoveWaitingTime;
	float m_LastMoveTime;

	int m_NumShotFired;

	void Move();
	void Shot();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

