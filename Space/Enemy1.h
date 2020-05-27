#pragma once
class Enemy1 : public Object
{
public:
	Enemy1(Vec2 Pos);
	~Enemy1();

	void Update(float deltaTime, float Time);
	void Render();
};

