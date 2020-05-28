#include "stdafx.h"
#include "Enemy1.h"
#include"EnemyBullet.h"

Enemy1::Enemy1(Vec2 Pos)
{
	m_Enemy = Sprite::Create(L"Painting/Object/Enemy/Enemy1.png");
	m_Enemy->SetParent(this);

	m_Position = Pos;

	m_HP = 500.f;
	m_Speed = 250.f;
	m_FireDelay = 1.5f;
	m_LastFireTime = 0.f;
	m_Atk = 30.f;
	m_HoldingTime = 7.f;
	m_NowTime = 0.f;
	m_Distance = 0.f;

	m_RandYPos = (rand() % 450) + 50;
	m_RandXPos = (rand() % 400);
	m_RandSniffling = (rand() % 3);
}

Enemy1::~Enemy1()
{
}

void Enemy1::Update(float deltaTime, float Time)
{
	m_LastFireTime += dt;
	m_NowTime += dt;
	if (m_Position.y < m_RandYPos)
	{
		m_Position.y += m_Speed * dt;
	}
	if(m_Position.y > m_RandYPos)
	{
		if (m_RandSniffling == 0)
		{
			if (m_Distance < m_RandXPos && m_Position.x > GameMgr::GetInst()->XMIN)
			{
				m_Position.x -= m_Speed / 2 * dt;
				m_Distance += m_Speed * dt;
			}
		}
		if (m_RandSniffling == 1)
		{
			if (m_Distance < m_RandXPos && m_Position.x < GameMgr::GetInst()->XMAX)
			{
				m_Position.x += m_Speed / 2 * dt;
				m_Distance += m_Speed * dt;
			}
		}
	}

	if (m_LastFireTime >= m_FireDelay && m_NowTime <= m_HoldingTime)
	{
		ObjMgr->AddObject(new EnemyBullet(Vec2(m_Position.x, m_Position.y + 60), m_Atk, 700), "EnemyBullet");
		m_LastFireTime = 0.f;
	}
	if (m_NowTime >= m_HoldingTime)
	{
		if (m_Enemy->B > 0 && m_Enemy->G > 0)
		{
			m_Enemy->B -= 5;
			m_Enemy->G -= 5;
		}
		if(m_Enemy->B == 0 && m_Enemy->G == 0)
			m_Position.y += m_Speed * 3 * dt;

		if (m_Position.y >= 1200)
			SetDestroy(true);
	}
}

void Enemy1::Render()
{
	m_Enemy->Render();
}
