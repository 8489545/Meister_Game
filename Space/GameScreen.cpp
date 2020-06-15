#include "stdafx.h"
#include "GameScreen.h"
#include"MiddleBoss.h"
#include"GameScreen2.h"

void GameScreen::Init()
{
	m_GameScreen1 = Sprite::Create(L"Painting/GameScreen/Stage1.png");
	m_GameScreen1->SetPosition(1920 / 2, 1080 / 2);
	m_GameScreen2 = Sprite::Create(L"Painting/GameScreen/Stage1.png");
	m_GameScreen2->SetPosition(1920 / 2, m_GameScreen1->m_Position.y - 1080);

	m_Tutorials = Sprite::Create(L"Painting/GameScreen/Tutorials.png");
	m_Tutorials->SetPosition(1920 / 2, 1080 / 2);

	m_RBox = Sprite::Create(L"Painting/GameScreen/BlackBox.png");
	m_RBox->SetPosition(660 / 2, 1080 / 2);

	m_LBox = Sprite::Create(L"Painting/GameScreen/BlackBox.png");
	m_LBox->SetPosition(3180 / 2, 1080 / 2);

	ObjMgr->AddObject(m_RBox, "Effect");
	ObjMgr->AddObject(m_LBox, "Effect");

	m_RBox->m_Layer = 1;
	m_LBox->m_Layer = 1;

	GameMgr::GetInst()->SetLimit(1260 - 114 / 2, 660 + 114 / 2, 1080 - 110 / 2, 0 + 110 / 2);

	ObjMgr->AddObject(m_Tutorials, "UI");

	m_isStart = false;
	m_CompleteTutorials = false;
	m_isMiddleBoss = false;

	m_NowTime = 0.f;
	m_EnemySpawnTime = 5.f;
	m_PercentOfEliteEnemySpawn = 30;
	m_RandEnemySpawn = 0;
}

void GameScreen::Release()
{
}

void GameScreen::EnemySpawn()
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
					GameMgr::GetInst()->SpawnEnemy1(Vec2(RandX, -100));
				}
			}
			if (m_NowTime > 60.f && m_NowTime <= 120.f)
			{
				m_EnemySpawnNum = rand() % 8 + 1;
				m_RandEnemySpawn = rand() % 100;
				m_PercentOfEliteEnemySpawn = 50;
				if (m_RandEnemySpawn <= m_PercentOfEliteEnemySpawn)
				{
					int RandX = (rand() % 600) + 660;
					GameMgr::GetInst()->SpawnEliteEnemy1(Vec2(RandX, -100));
				}
				for (int i = 0; i < m_EnemySpawnNum; i++)
				{
					int RandX = (rand() % 600) + 660;
					GameMgr::GetInst()->SpawnEnemy1(Vec2(RandX, -100));
				}
			}
			if (m_NowTime > 120.f && m_NowTime <= 180.f)
			{
				m_EnemySpawnNum = rand() % 5 + 1;
				m_RandEnemySpawn = rand() % 100;
				m_PercentOfEliteEnemySpawn = 80;
				if (m_RandEnemySpawn <= m_PercentOfEliteEnemySpawn)
				{
					int RandX = (rand() % 600) + 660;
					GameMgr::GetInst()->SpawnEliteEnemy1(Vec2(RandX, -100));
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
	if (m_NowTime > 180.f && !m_isMiddleBoss)
	{
		GameMgr::GetInst()->SpawnMiddleBoss();
		m_isMiddleBoss = true;
	}
}

void GameScreen::Update(float deltaTime, float time)
{
	m_NowTime += dt;
	if (!GameMgr::GetInst()->m_ScrollingStop)
	{
		m_GameScreen1->m_Position.y += 500 * dt;
		m_GameScreen2->m_Position.y += 500 * dt;
	}

	if (m_GameScreen1->m_Position.y >= 1080 + (m_GameScreen1->m_Size.y / 2) && !GameMgr::GetInst()->m_ScrollingStop)
	{
		m_GameScreen1->m_Position.y = m_GameScreen2->m_Position.y - 1080;
	}
	if (m_GameScreen2->m_Position.y >= 1080 + (m_GameScreen2->m_Size.y / 2) && !GameMgr::GetInst()->m_ScrollingStop)
	{
		m_GameScreen2->m_Position.y = m_GameScreen1->m_Position.y - 1080;
	}

	if (INPUT->GetButtonDown() && !m_CompleteTutorials)
	{
		m_CompleteTutorials = true;
		m_Tutorials->SetDestroy(true);
		GameMgr::GetInst()->CreatePlayer();
		GameMgr::GetInst()->CreateUI();
		m_isStart = true;
		INPUT->ButtonDown(false);
	}
	if (m_CompleteTutorials)
	{
		EnemySpawn();

		if (GameMgr::GetInst()->m_MiddleBossClear)
		{
			GameMgr::GetInst()->m_Score += GameMgr::GetInst()->m_PlayerStatus.m_HP * 500;
			GameMgr::GetInst()->ReleasePlayer();
			if (GameMgr::GetInst()->m_CreateUI)
				GameMgr::GetInst()->ReleaseUI();
			SceneDirector::GetInst()->ChangeScene(new GameScreen2());
		}
	}
	if (INPUT->GetKey(VK_F6) == KeyState::DOWN)
	{
		m_CompleteTutorials = true;
		m_Tutorials->SetDestroy(true);
		m_isStart = true;
		GameMgr::GetInst()->ReleasePlayer();
		if(GameMgr::GetInst()->m_CreateUI)
			GameMgr::GetInst()->ReleaseUI();
		SceneDirector::GetInst()->ChangeScene(new GameScreen2());
	}
}

void GameScreen::Render()
{
	m_GameScreen1->Render();
	m_GameScreen2->Render();
}
