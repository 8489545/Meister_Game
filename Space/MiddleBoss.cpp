#include "stdafx.h"
#include "MiddleBoss.h"

//Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/")


MiddleBoss::MiddleBoss()
{
	m_Body = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/Body.png");
	m_Body->SetParent(this);
	
	m_Body->SetPosition(1920 / 2, 100);

	m_LeftBigCannon = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/BigCannon.png");
	m_RightBigCannon = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/BigCannon.png");
}


MiddleBoss::~MiddleBoss()
{
}

void MiddleBoss::Update(float deltaTime, float Time)
{
	SetObjectsPosition();
}

void MiddleBoss::Render()
{
	m_LeftBigCannon->Render();
	m_RightBigCannon->Render();

	m_Body->Render();
}

void MiddleBoss::SetObjectsPosition()
{
}
