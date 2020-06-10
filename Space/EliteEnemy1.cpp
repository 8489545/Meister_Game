#include "stdafx.h"
#include "EliteEnemy1.h"
#include"EnemyBullet.h"
#include"Item.h"

EliteEnemy1::EliteEnemy1(Vec2 Pos)
{
	m_Enemy = Sprite::Create(L"Painting/Object/Enemy/EliteEnemy1.png");
	m_Enemy->SetParent(this);

	m_Position = Pos;

	m_Speed = 500.f;
	m_Atk = 34.f;
	m_HP = 1500.f;
	
	m_LastFireTick = 0.f;
	m_NowTime = 0.f;
	m_FireDelay = 0.5f;

	m_RandomPosition = Vec2((rand() % 400) + 660, (rand() % 300));
	m_MoveWaitingTime = 7.f;
	m_LastMoveTime = 4.f;

	m_NumShotFired = 0.f;
}

EliteEnemy1::~EliteEnemy1()
{
}

void EliteEnemy1::Move()
{
	Vec2 A, B, Dire;
	const int EPSILON = 10;

	A = m_Position;
	B = m_RandomPosition;

	Dire = B - A;

	D3DXVec2Normalize(&Dire, &Dire);

	if (abs(m_Position.x - m_RandomPosition.x) > EPSILON&& abs(m_Position.y - m_RandomPosition.y) > EPSILON)
	{
		Translate(Dire.x * m_Speed * dt, Dire.y * m_Speed * dt);
	}
	else
	{
		m_RandomPosition = Vec2((rand() % 400) + 660, (rand() % 300));
		m_LastMoveTime = 0.f;
	}
}

void EliteEnemy1::Shot()
{
	if (m_NumShotFired % 2 == 1)
	{
		ObjMgr->AddObject(new EnemyBullet(Vec2(m_Position.x, m_Position.y + 60), m_Atk, 600, 0 + 180,	false, 50, false, L"BigBullet"), "EnemyBullet");
		ObjMgr->AddObject(new EnemyBullet(Vec2(m_Position.x, m_Position.y + 60), m_Atk, 600, -40 + 180, false, 50, false, L"BigBullet"), "EnemyBullet");
		ObjMgr->AddObject(new EnemyBullet(Vec2(m_Position.x, m_Position.y + 60), m_Atk, 600, 40 + 180, false, 50, false, L"BigBullet"), "EnemyBullet");
	}
	if (m_NumShotFired % 2 == 0)
	{
		ObjMgr->AddObject(new EnemyBullet(Vec2(m_Position.x, m_Position.y + 60), m_Atk, 600, 20 + 180, false, 50, false, L"BigBullet"), "EnemyBullet");
		ObjMgr->AddObject(new EnemyBullet(Vec2(m_Position.x, m_Position.y + 60), m_Atk, 600, -20 + 180, false, 50, false, L"BigBullet"), "EnemyBullet");
		ObjMgr->AddObject(new EnemyBullet(Vec2(m_Position.x, m_Position.y + 60), m_Atk, 600, 60 + 180, false, 50, false, L"BigBullet"), "EnemyBullet");
		ObjMgr->AddObject(new EnemyBullet(Vec2(m_Position.x, m_Position.y + 60), m_Atk, 600, -60 + 180, false, 50, false, L"BigBullet"), "EnemyBullet");	}

	m_NumShotFired++;
}

void EliteEnemy1::Update(float deltaTime, float Time)
{
	m_LastFireTick += dt;
	m_NowTime += dt;
	m_LastMoveTime += dt;
	
	if (m_Position.y <= 100)
	{
		m_Position.y += 300.f * dt;
	}
	 if (m_LastMoveTime >= m_MoveWaitingTime)
	{
		Move();
	}

	if (m_LastFireTick >= m_FireDelay && m_Tag != "Bullet")
	{
		Shot();
		m_LastFireTick = 0.f;
	}

	if (m_HP <= 0)
	{
		if ((rand() % 10) == 0)
			ObjMgr->AddObject(new Item(m_Position), "ITEM");
		GameMgr::GetInst()->m_AcqExp += 50;
		ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Big/", 1, 9, 5, m_Position), "Effect");
		SetDestroy(true);
	}
}

void EliteEnemy1::Render()
{
	m_Enemy->Render();
}

void EliteEnemy1::OnCollision(Object* other)
{
}
