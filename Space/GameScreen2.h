#pragma once
class GameScreen2 : public Scene
{
	Sprite* m_GameScreen1;
	Sprite* m_GameScreen2;

	Sprite* m_RBox;
	Sprite* m_LBox;
public:
	GameScreen2();
	~GameScreen2();

	bool m_isFinalBoss;

	float m_NowTime;
	float m_EnemySpawnTime;
	int m_PercentOfEliteEnemySpawn;
	int m_RandEnemySpawn;
	int m_EnemySpawnNum;

	void Init();
	void Release();

	void EnemySpawn();

	void Update(float deltaTime, float Time);
	void Render();
};

