#pragma once
enum class SHOTTYPE
{
	DIRECT,
	SPREAD,
	NONE
};
struct PlayerStatus
{
public:
	int m_Level;
	int m_Exp;
	int m_HP;
	float m_Speed;
	int m_Atk;
	float m_RPM;
};
class GameMgr : public Singleton<GameMgr>
{
public:
	GameMgr();
	~GameMgr();

	float XMAX, XMIN, YMAX, YMIN;

	bool m_CreatePlayer;
	SHOTTYPE m_PlayerShotType;

	PlayerStatus m_PlayerStatus;

	bool m_FirstSkill;
	bool m_SecendSkill;

	void Init();
	void Release();

	void CreatePlayer();
	void CreateUI();

	void ChangeFireMode();

	void SetPlayerStatus(int level, int exp, int hp, float speed, int atk, float rpm);

	void SetLimit(float xmax,float xmin,float ymax,float ymin);

	void UnlockSkill();
};

