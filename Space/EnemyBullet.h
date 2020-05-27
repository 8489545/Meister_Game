#pragma once
class EnemyBullet : public Object
{
	Sprite* m_Bullet;
public:
	EnemyBullet(Vec2 Pos, float atk);
	~EnemyBullet();

	void Update(float deltaTime, float Time);
	void Render();
};

