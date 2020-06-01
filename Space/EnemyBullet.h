#pragma once
class EnemyBullet : public Object
{
	Sprite* m_Bullet;
public:
	EnemyBullet(Vec2 Pos, float atk,float speed,float angle,bool isrand,int randrange,bool playerguidance);
	~EnemyBullet();

	Vec2 StartPos, ArrivePos, Dire;
	float m_Speed;
	bool m_PlayerGuidance;

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

