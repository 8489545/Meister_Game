#pragma once
class Bomb : public Object
{
	Sprite* m_Bomb;
	Sprite* m_Shadow;
public:
	Bomb();
	~Bomb();

	float m_FireDelay;
	float m_LastFireTime;

	void Update(float delatTime, float Time);
	void Render();
};

