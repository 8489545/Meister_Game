#pragma once
class GameMgr : public Singleton<GameMgr>
{
public:
	GameMgr();
	~GameMgr();


	bool m_CreatePlayer;

	void Init();
	void Release();

	void CreatePlayer();
};

