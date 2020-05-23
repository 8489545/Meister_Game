#pragma once
enum class SHOTTYPE
{
	DIRECT,
	SPREAD,
	NONE
};
class GameMgr : public Singleton<GameMgr>
{
public:
	GameMgr();
	~GameMgr();

	float XMAX, XMIN, YMAX, YMIN;

	bool m_CreatePlayer;
	SHOTTYPE m_PlayerShotType;

	void Init();
	void Release();

	void CreatePlayer();
	void CreateUI();

	void ChangeFireMode();

	void SetLimit(float xmax,float xmin,float ymax,float ymin);
};

