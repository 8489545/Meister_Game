#include "stdafx.h"
#include "SpreadBullet.h"

SpreadBullet::SpreadBullet(Vec2 Pos, float Speed, float Angle)
{
	m_Bullet = Sprite::Create(L"Painting/Object/Bullet/Spread.png");
	m_Bullet->SetParent(this);

	m_Position = Pos;
	m_Rotation = D3DXToRadian(Angle - 90);
	m_Speed = Speed;

	m_StartPos = m_Position;
	m_ArrivePos = Vec2(cos(m_Rotation), sin(m_Rotation));

	m_Atk = GameMgr::GetInst()->m_PlayerStatus.m_Atk;
}

SpreadBullet::~SpreadBullet()
{
}

void SpreadBullet::Update(float delatTime, float Time)
{
	m_Dire = m_ArrivePos - m_StartPos;

	D3DXVec2Normalize(&m_Dire, &m_ArrivePos);

	Translate(m_Dire.x * m_Speed * dt, m_Dire.y * m_Speed * dt);

	if (m_Position.y <= -100.f)
	{
		SetDestroy(true);
	}
}

void SpreadBullet::Render()
{
	m_Bullet->Render();
}
