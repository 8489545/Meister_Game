#include "stdafx.h"
#include "GameScreen.h"

void GameScreen::Init()
{
	m_GameScreen1 = Sprite::Create(L"Painting/GameScreen/Stage1.png");
	m_GameScreen1->SetPosition(1920 / 2, 1080 / 2);
	m_GameScreen2 = Sprite::Create(L"Painting/GameScreen/Stage1.png");
	m_GameScreen2->SetPosition(1920 / 2, m_GameScreen1->m_Position.y - 1080);

	m_RBox = Sprite::Create(L"Painting/GameScreen/BlackBox.png");
	m_RBox->SetPosition(660 / 2, 1080 / 2);

	m_LBox = Sprite::Create(L"Painting/GameScreen/BlackBox.png");
	m_LBox->SetPosition(3180 / 2, 1080 / 2);

	GameMgr::GetInst()->CreatePlayer();

	GameMgr::GetInst()->SetLimit(1260 - 114 / 2, 660 + 114 / 2, 1080 - 110 / 2, 0 + 110 / 2);
}

void GameScreen::Release()
{
}

void GameScreen::Update(float deltaTime, float time)
{
	m_GameScreen1->m_Position.y += 500 * dt;
	m_GameScreen2->m_Position.y += 500 * dt;

	if (m_GameScreen1->m_Position.y >= 1080 + (m_GameScreen1->m_Size.y / 2))
	{
		m_GameScreen1->m_Position.y = m_GameScreen2->m_Position.y - 1080;
	}
	if (m_GameScreen2->m_Position.y >= 1080 + (m_GameScreen2->m_Size.y / 2))
	{
		m_GameScreen2->m_Position.y = m_GameScreen1->m_Position.y - 1080;
	}
}

void GameScreen::Render()
{
	m_RBox->Render();
	m_LBox->Render();
	m_GameScreen1->Render();
	m_GameScreen2->Render();
}
