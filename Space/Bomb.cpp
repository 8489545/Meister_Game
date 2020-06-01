#include "stdafx.h"
#include "Bomb.h"
#include"SpreadBullet.h"

Bomb::Bomb()
{
	m_Bomb = Sprite::Create(L"Painting/Object/Skill/GunShip.png");
	m_Bomb->SetParent(this);

	m_Shadow = Sprite::Create(L"Painting/Object/Skill/Shadow.png");

	SetPosition(1920 / 2, 1100);

	m_FireDelay = 0.2f;
	m_LastFireTime = 0.f;
	m_Atk = GameMgr::GetInst()->m_PlayerStatus.m_Atk;
}

Bomb::~Bomb()
{
}

void Bomb::Update(float delatTime, float Time)
{
	m_Shadow->SetPosition(m_Position.x + 50, m_Position.y + 50);
	m_LastFireTime += dt;
	m_Position.y -= 200 * dt;
	
	if (m_Position.y <= -500)
		SetDestroy(true);

	if (m_LastFireTime >= m_FireDelay)
	{
		ObjMgr->AddObject(new SpreadBullet(Vec2(m_Position.x - 70, m_Position.y - 130), 700, 0, m_Atk), "Bullet");
		ObjMgr->AddObject(new SpreadBullet(Vec2(m_Position.x - 70, m_Position.y - 130), 700, 20, m_Atk), "Bullet");
		ObjMgr->AddObject(new SpreadBullet(Vec2(m_Position.x - 70, m_Position.y - 130), 700, -20, m_Atk), "Bullet");

		ObjMgr->AddObject(new SpreadBullet(Vec2(m_Position.x + 70, m_Position.y - 130), 700, 0, m_Atk), "Bullet");
		ObjMgr->AddObject(new SpreadBullet(Vec2(m_Position.x + 70, m_Position.y - 130), 700, 20, m_Atk), "Bullet");
		ObjMgr->AddObject(new SpreadBullet(Vec2(m_Position.x + 70, m_Position.y - 130), 700, -20, m_Atk), "Bullet");
		m_LastFireTime = 0.f;
	}
}

void Bomb::Render()
{
	m_Shadow->Render();
	m_Bomb->Render();
}
