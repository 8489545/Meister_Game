#include "stdafx.h"
#include "GameScreen.h"

void GameScreen::Init()
{
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
}

void GameScreen::Render()
{
	m_RBox->Render();
	m_LBox->Render();
}
