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
}

void GameScreen2::Release()
{
}

void GameScreen2::Update(float deltaTime, float Time)
{
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
}

void GameScreen2::Render()
{
	m_GameScreen1->Render();
	m_GameScreen2->Render();
}
