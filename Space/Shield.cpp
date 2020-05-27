#include "stdafx.h"
#include "Shield.h"

Shield::Shield(Vec2 Pos)
{
	m_Shield = Sprite::Create(L"Painting/Object/Skill/Shield.png");
	m_Shield->SetParent(this);

	m_Position = Pos;
}

Shield::~Shield()
{
}

void Shield::Update(float deltaTime, float Time)
{
	m_Position = GameMgr::GetInst()->m_PlayerPos;
	m_NowTime += dt;

	if (m_NowTime >= 3.f)
	{
		SetDestroy(true);
	}
}

void Shield::Render()
{
	m_Shield->Render();
}
