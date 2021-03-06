#pragma once
class GameScreen : public Scene
{
	Sprite* m_GameScreen1;
	Sprite* m_GameScreen2;

	Sprite* m_Tutorials;

	Sprite* m_RBox;
	Sprite* m_LBox;
public:

	void Init();
	void Release();

	bool m_isStart;
	bool m_CompleteTutorials;
	bool m_isMiddleBoss;
	float m_NowTime;
	float m_EnemySpawnTime;
	int m_PercentOfEliteEnemySpawn;
	int m_RandEnemySpawn;
	int m_EnemySpawnNum;

	void EnemySpawn();
	void Update(float deltaTime, float time);
	void Render();
};

