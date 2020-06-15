#pragma once
class SpreadBullet : public Object
{
	Sprite* m_Bullet;
public:
	SpreadBullet(Vec2 Pos, float Speed,float Angle,float atk);
	~SpreadBullet();

	Vec2 m_StartPos, m_ArrivePos, m_Dire;

	float m_Speed;

	void AimHack();
	void Update(float delatTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

