#include "stdafx.h"
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(Vec2 Pos, float atk,float speed)
{
	m_Bullet = Sprite::Create(L"Painting/Object/Bullet/EnemyBullet.png");
	m_Bullet->SetParent(this);

	m_Position = Pos;
	StartPos = Pos;
	ArrivePos = GameMgr::GetInst()->m_PlayerPos;
	m_Speed = speed;
	m_Atk = atk;

	Dire = ArrivePos - StartPos;

	D3DXVec2Normalize(&Dire, &Dire);
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Update(float deltaTime, float Time)
{
	ObjMgr->CollisionCheak(this, "Player");
	Translate(Dire.x * m_Speed * dt, Dire.y * m_Speed * dt);

	if (m_Position.y >= 1200)
	{
		SetDestroy(true);
	}
}

void EnemyBullet::Render()
{
	m_Bullet->Render();
}

void EnemyBullet::OnCollision(Object* other)
{
}
