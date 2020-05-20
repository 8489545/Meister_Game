#include "stdafx.h"
#include "GameScreen.h"

void GameScreen::Init()
{
	m_RBox = Sprite::Create(L"Painting/GameScreen/BlackBox.png");
	m_RBox->SetPosition(660 / 2, 1080 / 2);

	m_LBox = Sprite::Create(L"Painting/GameScreen/BlackBox.png");
	m_LBox->SetPosition(3180 / 2, 1080 / 2);
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
