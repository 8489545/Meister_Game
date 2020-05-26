#pragma once
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

	int m_Level;
	int m_Exp;
	int m_HP;
	float m_Speed;
	int m_Atk;
	float m_RPM;

	bool m_FirstSkillAcq;
	bool m_SecendSkillAcq;

	float m_FireDelay;
	float m_LastFireTick;
	float m_NowTick;

	void Init();
	void Release();

	void Update(float delatTime, float Time);
	void Render();

	void Move();
	void Shot();
	void ChangeFireMode();
	void DeliveringInformation();
};

