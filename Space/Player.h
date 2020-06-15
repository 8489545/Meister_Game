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
	float m_Speed;
	float m_RPM;

	int m_MAXHP;
	int m_MAXExp;
	int m_AtkIncrease;
	float m_RPMIncrease;

	int m_DirectBasicAtk;
	int m_SpreadBasicAtk;

	bool m_FirstSkillAcq;
	bool m_SecendSkillAcq;

	float m_FSkillCooldown;
	float m_SSkillCooldown;
	float m_FSkillMAXCooldown;
	float m_SSkillMAXCooldown;

	bool m_willLevelUPReward;
	bool m_PlayerInvincibility;

	bool m_CheatPlayerInvin;

	float m_FireDelay;
	float m_LastFireTick;
	float m_NowTick;
	float m_InvinTick;

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
	void Invincibility();
	void Cheat();

	void LevelUP();
};

