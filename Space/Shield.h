#pragma once
class Shield : public Object
{
	Sprite* m_Shield;
public:
	Shield(Vec2 Pos);
	~Shield();

	float m_NowTime;

	void Update(float deltaTime, float Time);
	void Render();
};

