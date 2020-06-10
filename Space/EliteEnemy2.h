#pragma once
class EliteEnemy2 : public Object
{
	Sprite* m_Enemy;
public:
	EliteEnemy2(Vec2 Pos);
	~EliteEnemy2();

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

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

