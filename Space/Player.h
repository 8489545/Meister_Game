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

	Sprite* m_ColBox;
	Sprite* m_CatchBox;
public:
	Player();
	~Player();

	int m_Level;
	int m_Exp;
	int m_HP;
	float m_Speed;
	float m_RPM;

	int m_MAXHP;
	int m_MAXExp;
	float m_RPMIncrease;
	int m_AtkIncrease;

	bool m_FirstSkillAcq;
	bool m_SecendSkillAcq;

	float m_FSkillCooldown;
	float m_SSkillCooldown;
	float m_FSkillMAXCooldown;
	float m_SSkillMAXCooldown;

	bool m_willLevelUPReward;

	float m_FireDelay;
	float m_LastFireTick;
	float m_NowTick;

	void Init();
	void Release();

	void Update(float delatTime, float Time);
	void Render();
	void OnCollision(Object* other);

	void Move();
	void Shot();
	void ChangeFireMode();
	void DeliveringInformation();
	void Skill();
	void ColCheak();

	void LevelUP();
};

