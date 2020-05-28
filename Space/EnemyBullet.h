#pragma once
class EnemyBullet : public Object
{
	Sprite* m_Bullet;
public:
	EnemyBullet(Vec2 Pos, float atk,float speed);
	~EnemyBullet();

	Vec2 StartPos, ArrivePos, Dire;
	float m_Speed;

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

