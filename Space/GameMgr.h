#pragma once
class GameMgr : public Singleton<GameMgr>
{
public:
	GameMgr();
	~GameMgr();

	float XMAX, XMIN, YMAX, YMIN;

	bool m_CreatePlayer;

	void Init();
	void Release();

	void CreatePlayer();

	void SetLimit(float xmax,float xmin,float ymax,float ymin);
};

