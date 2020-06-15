#include "stdafx.h"
#include "GameScreen2.h"

GameScreen2::GameScreen2()
{
}

GameScreen2::~GameScreen2()
{
}

void GameScreen2::Init()
{
	m_GameScreen1 = Sprite::Create(L"Painting/GameScreen/Stage2.png");
	m_GameScreen1->SetPosition(1920 / 2, 1080 / 2);
	m_GameScreen2 = Sprite::Create(L"Painting/GameScreen/Stage2.png");
	m_GameScreen2->SetPosition(1920 / 2, m_GameScreen1->m_Position.y - 5500);

	m_RBox = Sprite::Create(L"Painting/GameScreen/BlackBox.png");
	m_RBox->SetPosition(660 / 2, 1080 / 2);

	m_LBox = Sprite::Create(L"Painting/GameScreen/BlackBox.png");
	m_LBox->SetPosition(3180 / 2, 1080 / 2);

	ObjMgr->AddObject(m_RBox, "Obj");
	ObjMgr->AddObject(m_LBox, "Obj");

	m_RBox->m_Layer = 1;
	m_LBox->m_Layer = 1;

	GameMgr::GetInst()->CreatePlayer();
	GameMgr::GetInst()->CreateUI();

	m_NowTime = 0.f;
	m_EnemySpawnTime = 5.f;
	m_PercentOfEliteEnemySpawn = 40;
	m_RandEnemySpawn = 0;
	m_isFinalBoss = false;
}

void GameScreen2::Release()
{
}

void GameScreen2::EnemySpawn()
{
	m_EnemySpawnTime -= dt;
	if (m_NowTime <= 180.f)
	{
		if (m_EnemySpawnTime <= 0.f)
		{

			if (m_NowTime <= 60.f)
			{
				m_EnemySpawnNum = rand() % 5 + 1;
				m_RandEnemySpawn = rand() % 100;
				if (m_RandEnemySpawn <= m_PercentOfEliteEnemySpawn)
				{
					int RandX = (rand() % 600) + 660;
					GameMgr::GetInst()->SpawnEliteEnemy1(Vec2(RandX, -100));
				}
				for (int i = 0; i < m_EnemySpawnNum; i++)
				{
					int RandX = (rand() % 600) + 660;
					GameMgr::GetInst()->SpawnEnemy2(Vec2(RandX, -100));
				}
			}
			if (m_NowTime > 60.f && m_NowTime <= 120.f)
			{
				m_EnemySpawnNum = rand() % 4 + 1;
				m_RandEnemySpawn = rand() % 100;
				m_PercentOfEliteEnemySpawn = 60;
				if (m_RandEnemySpawn <= m_PercentOfEliteEnemySpawn)
				{
					int RandX = (rand() % 600) + 660;
					GameMgr::GetInst()->SpawnEliteEnemy2(Vec2(RandX, -100));
				}
				for (int i = 0; i < m_EnemySpawnNum; i++)
				{
					int RandX = (rand() % 600) + 660;
					GameMgr::GetInst()->SpawnEnemy1(Vec2(RandX, -100));
					GameMgr::GetInst()->SpawnEnemy2(Vec2(RandX, -100));
				}
			}
			if (m_NowTime > 120.f && m_NowTime <= 180.f)
			{
				m_EnemySpawnNum = rand() % 7 + 1;
				m_RandEnemySpawn = rand() % 100;
				m_PercentOfEliteEnemySpawn = 90;
				if (m_RandEnemySpawn <= m_PercentOfEliteEnemySpawn)
				{
					int RandX = (rand() % 600) + 660;
					GameMgr::GetInst()->SpawnEliteEnemy1(Vec2(RandX, -100));
					GameMgr::GetInst()->SpawnEliteEnemy2(Vec2(RandX, -100));
				}
				for (int i = 0; i < m_EnemySpawnNum; i++)
				{
					int RandX = (rand() % 600) + 660;
					GameMgr::GetInst()->SpawnEnemy1(Vec2(RandX, -100));
					GameMgr::GetInst()->SpawnEnemy2(Vec2(RandX, -100));
				}
			}
			m_EnemySpawnTime = 10.f;
		}
	}
	if (m_NowTime > 180.f && !m_isFinalBoss)
	{
		GameMgr::GetInst()->SpawnFinalBoss();
		m_isFinalBoss = true;
	}
}

void GameScreen2::Update(float deltaTime, float Time)
{
	m_NowTime += dt;
	if (!GameMgr::GetInst()->m_ScrollingStop)
	{
		m_GameScreen1->m_Position.y += 500 * dt;
		m_GameScreen2->m_Position.y += 500 * dt;
	}

	if (m_GameScreen1->m_Position.y >= 1080 + (m_GameScreen1->m_Size.y / 2) && !GameMgr::GetInst()->m_ScrollingStop)
	{
		m_GameScreen1->m_Position.y = m_GameScreen2->m_Position.y - 5450;
	}
	if (m_GameScreen2->m_Position.y >= 1080 + (m_GameScreen2->m_Size.y / 2) && !GameMgr::GetInst()->m_ScrollingStop)
	{
		m_GameScreen2->m_Position.y = m_GameScreen1->m_Position.y - 5450;
	}
	EnemySpawn();

	if (GameMgr::GetInst()->m_FinalBossClear)
	{
		GameMgr::GetInst()->m_Score += GameMgr::GetInst()->m_PlayerStatus.m_HP * 1000;
		GameMgr::GetInst()->ReleasePlayer();
		if (GameMgr::GetInst()->m_CreateUI)
			GameMgr::GetInst()->ReleaseUI();
		//SceneDirector::GetInst()->ChangeScene(new GameScreen2());
	}
}

void GameScreen2::Render()
{
	m_GameScreen1->Render();
	m_GameScreen2->Render();
}
