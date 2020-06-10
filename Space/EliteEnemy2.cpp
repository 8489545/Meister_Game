#include "stdafx.h"
#include "EliteEnemy2.h"
#include"EnemyBullet.h"
#include"Item.h"

EliteEnemy2::EliteEnemy2(Vec2 Pos)
{
	m_Enemy = Sprite::Create(L"Painting/Object/Enemy/EliteEnemy2.png");
	m_Enemy->SetParent(this);

	m_Position = Pos;

	m_Speed = 400.f;
	m_Atk = 20.f;
	m_HP = 1000.f;

	m_LastFireTick = 0.f;
	m_NowTime = 0.f;
	m_FireDelay = 0.3f;

	m_RandomPosition = Vec2((rand() % 400) + 660, (rand() % 300));
	m_MoveWaitingTime = 1.f;
	m_LastMoveTime = 0.f;

	m_NumShotFired = 0.f;
}

EliteEnemy2::~EliteEnemy2()
{
}

void EliteEnemy2::Move()
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

void EliteEnemy2::Update(float deltaTime, float Time)
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
		ObjMgr->AddObject(new EnemyBullet(Vec2(m_Position.x, m_Position.y + 60), m_Atk, 800, 0, false,0, true), "EnemyBullet");
		m_LastFireTick = 0.f;
	}

	if (m_HP <= 0)
	{
		if ((rand() % 5) == 0)
			ObjMgr->AddObject(new Item(m_Position), "ITEM");
		GameMgr::GetInst()->m_AcqExp += 50;
		ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Big/", 1, 9, 5, m_Position), "Effect");
		SetDestroy(true);
	}
}

void EliteEnemy2::Render()
{
	m_Enemy->Render();
}

void EliteEnemy2::OnCollision(Object* other)
{
}
