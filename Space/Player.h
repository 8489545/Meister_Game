#pragma once
enum class SHOTTYPE
{
	DIRECT,
	SPREAD,
	NONE
};
class Player : public Object
{
	Sprite* m_Player;

	Sprite* m_Front;
	Sprite* m_Left;
	Sprite* m_Right;
	Sprite* m_Propel;
	Sprite* m_LPropel;
	Sprite* m_RPropel;
public:
	Player();
	~Player();

	SHOTTYPE m_ShotType;

	float m_Speed;
	float m_RPM;
	float m_FireDelay;

	float m_LastFireTick;
	float m_NowTick;

	void Init();
	void Release();

	void Update(float delatTime, float Time);
	void Render();

	void Move();
	void Shot();
};

