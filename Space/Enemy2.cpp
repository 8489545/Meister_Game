#include "stdafx.h"
#include "Enemy2.h"
#include"EnemyBullet.h"
#include"Item.h"

Enemy2::Enemy2(Vec2 Pos)
{
	m_Enemy = Sprite::Create(L"Painting/Object/Enemy/Enemy2.png");
	m_Enemy->SetParent(this);

	m_Position = Pos;

	m_Speed = 400.f;
	m_HP = 700.f;
	m_Atk = 45.f;

	m_LastFireTick = 0.f;
	m_FireDelay = 1.0f;

	m_RandomPosition = Vec2((rand() % 600) + 660, (rand() % 700));

	m_MoveWaitingTime = 3.f;
	m_LastMoveTime = 0.f;
	m_NowTime = 0.f;
	m_HoldingTime = 10.f;
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
	m_NowTime += dt;

	if (m_Position.y <= 100)
	{
		m_Position.y += 300.f * dt;
	}
	else if (m_LastMoveTime >= m_MoveWaitingTime)
	{
		Move();
	}

	if (m_LastFireTick >= m_FireDelay && m_Tag != "Bullet")
	{
		ObjMgr->AddObject(new EnemyBullet(Vec2(m_Position.x, m_Position.y + 60), m_Atk, 400, 0, true, 50, true), "EnemyBullet");
		m_LastFireTick = 0.f;
	}

	if (m_NowTime >= m_HoldingTime && m_Tag != "Bullet")
	{
		if (m_Enemy->B > 0 && m_Enemy->G > 0)
		{
			m_Enemy->B -= 5;
			m_Enemy->G -= 5;
		}
		if (m_Enemy->B == 0 && m_Enemy->G == 0)
			m_Position.y += m_Speed * 3 * dt;

		if (m_Position.y >= 1200)
			SetDestroy(true);
	}

	if (m_Tag == "Bullet")
	{
		m_Rotation = D3DXToRadian(180);
		m_Position.y -= m_Speed * 6 * dt;

		if (m_Position.y <= -100)
			SetDestroy(true);
	}

	ObjMgr->CollisionCheak(this, "Enemy");
	ObjMgr->CollisionCheak(this, "CatchBox");

	if (m_HP <= 0)
	{
		if ((rand() % 30) == 0)
			ObjMgr->AddObject(new Item(m_Position), "ITEM");

		GameMgr::GetInst()->m_AcqExp += 20;
		GameMgr::GetInst()->m_Score += 50;
		ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Big/", 1, 9, 5, m_Position), "Effect");
		SetDestroy(true);
	}
}

void Enemy2::Render()
{
	m_Enemy->Render();
}

void Enemy2::OnCollision(Object* other)
{
	if (other->m_Tag == "CatchBox" && m_Enemy->B == 0 && m_Enemy->G == 0)
	{
		if (INPUT->GetKey(VK_SPACE) == KeyState::DOWN)
		{
			m_Tag = "Bullet";
			m_Atk = m_Atk * 10;
		}
	}
	if (other->m_Tag == "Enemy" && m_Tag == "Bullet")
	{
		other->m_HP -= m_Atk;
		ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Big/", 1, 9, 5, m_Position), "Effect");
		SetDestroy(true);
	}
}
