#pragma once
class Laser : public Object
{
	Sprite* m_Warning;
	Sprite* m_Laser;
public:
	Laser(Vec2 Pos,float laserDuration,float atk,float appearTime,float sizeSpeed);
	~Laser();

	float m_LaserDuration;
	float m_LaserAppearTime;
	float m_NowTime;
	float m_SizeSettingTime;
	float m_SizeSpeed;

	bool m_LaserAppeared;

	void Update(float deltaTime,float Time);
	void Render();
	void OnCollision(Object* other);
};

