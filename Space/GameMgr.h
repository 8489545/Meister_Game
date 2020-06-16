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
struct RankingPlayer
{
	int score;
	std::string name;
};
class GameMgr : public Singleton<GameMgr>
{
public:
	GameMgr();
	~GameMgr();

	struct stVECTORsort
	{
		bool operator() (const RankingPlayer* pObject1, const RankingPlayer* pObject2) const
		{
			if (pObject1->score < pObject2->score)
				return TRUE;

			return FALSE;
		}
	};

	float XMAX, XMIN, YMAX, YMIN;

	std::vector<RankingPlayer*> Ranks;

	bool m_CreatePlayer;
	bool m_CreateUI;
	SHOTTYPE m_PlayerShotType;

	PlayerStatus m_PlayerStatus;

	Vec2 m_PlayerPos;

	int m_AcqExp;

	bool m_FirstSkill;
	bool m_SecendSkill;

	bool m_ScrollingStop;

	bool m_MiddleBossClear;
	bool m_FinalBossClear;

	float m_FirstSkillCooldown;
	float m_SecendSkillCooldown;
	float m_FirstSkillMaxCooldown;
	float m_SecendSkillMaxCooldown;

	int m_Score;

	void Init();
	void RankInit();
	void Release();

	void CreatePlayer();
	void CreateUI();

	void ReleasePlayer();
	void ReleaseUI();
	void GameEnd();

	void SortRanking();

	void ChangeFireMode();

	void SetPlayerStatus(int level, int exp, int hp, float speed, int atk, float rpm);
	void SetLimit(float xmax,float xmin,float ymax,float ymin);
	void SpawnItem(Vec2 Pos);

	void SpawnMiddleBoss();
	void SpawnFinalBoss();

	void SpawnEnemy1(Vec2 Pos);
	void SpawnEnemy2(Vec2 Pos);
	void SpawnEliteEnemy1(Vec2 Pos);
	void SpawnEliteEnemy2(Vec2 Pos);

	void UnlockSkill();
};

