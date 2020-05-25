#pragma once
class SpreadBullet : public Object
{
	Sprite* m_Bullet;
public:
	SpreadBullet(Vec2 Pos, float Speed,float Angle);
	~SpreadBullet();

	Vec2 m_StartPos, m_ArrivePos, m_Dire;

	float m_Speed;

	void Update(float delatTime, float Time);
	void Render();
};
