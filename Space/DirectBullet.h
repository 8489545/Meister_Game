#pragma once
class DirectBullet : public Object
{
	Sprite* m_Bullet;
public:
	DirectBullet(Vec2 Pos,float Speed);
	~DirectBullet();

	float m_Speed;

	void Update(float delatTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

