#include "stdafx.h"
#include "Enemy2.h"
#include"EnemyBullet.h"

Enemy2::Enemy2(Vec2 Pos)
{
	m_Enemy = Sprite::Create(L"Painting/Object/Enemy/Enemy2.png");
	m_Enemy->SetParent(this);

	m_Position = Pos;

	m_Speed = 400.f;
	m_HP = 450.f;
	m_Atk = 50.f;

	m_LastFireTick = 0.f;
	m_FireDelay = 0.5f;

	m_RandomPosition = Vec2((rand() % 600) + 660, (rand() % 700));

	m_MoveWaitingTime = 2.f;
	m_LastMoveTime = 0.f;
}

Enemy2::~Enemy2()
{
}

void Enemy2::Move()
{
	Vec2 A, B,Dire;
	const int EPSILON = 10;

	A = m_Position;
	B = m_RandomPosition;

	Dire = B - A;

	D3DXVec2Normalize(&Dire, &Dire);

	if (abs(m_Position.x - m_RandomPosition.x) > EPSILON && abs(m_Position.y - m_RandomPosition.y) > EPSILON)
	{
		Translate(Dire.x * m_Speed * dt, Dire.y * m_Speed * dt);
	}
	else
	{
		m_RandomPosition = Vec2((rand() % 600) + 660, (rand() % 700));
		m_LastMoveTime = 0.f;
	}
}

void Enemy2::Shot()
{
}

void Enemy2::Update(float deltaTime, float Time)
{
	m_LastMoveTime += dt;
	m_LastFireTick += dt;

	if (m_Position.y <= 100)
	{
		m_Position.y += 300.f * dt;
	}
	else if (m_LastMoveTime >= m_MoveWaitingTime)
	{
		Move();
	}

	if (m_LastFireTick >= m_FireDelay)
	{
		ObjMgr->AddObject(new EnemyBullet(Vec2(m_Position.x, m_Position.y + 60), m_Atk, 400, 0, true, 50, true), "EnemyBullet");
		m_LastFireTick = 0.f;
	}
}

void Enemy2::Render()
{
	m_Enemy->Render();
}

void Enemy2::OnCollision(Object* other)
{
}
