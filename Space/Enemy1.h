#pragma once
class Enemy1 : public Object
{
	Sprite* m_Enemy;
public:
	Enemy1(Vec2 Pos);
	~Enemy1();

	void Update(float deltaTime, float Time);
	void Render();
};

