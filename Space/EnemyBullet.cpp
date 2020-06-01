#include "stdafx.h"
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(Vec2 Pos, float atk, float speed, float angle, bool isrand, int randrange, bool playerguidance)
{
	m_Bullet = Sprite::Create(L"Painting/Object/Bullet/EnemyBullet.png");
	m_Bullet->SetParent(this);

	if (isrand)
	{
		int randx = (rand() % randrange);
		int randy = (rand() % randrange);

		int sign = rand() % 3;

		switch (sign)
		{
		case 0:
			break;
		case 1:
			randx *= -1;
			break;
		case 2:
			randy *= 1;
			break;
		case 3:
			randx *= -1;
			randy *= -1;
			break;
		default:
			break;
		}


		Vec2 RandPos(randx, randy);
		ArrivePos = GameMgr::GetInst()->m_PlayerPos + RandPos;
	}
	if (!isrand && playerguidance)
	{
		ArrivePos = GameMgr::GetInst()->m_PlayerPos;
	}

	m_Position = Pos;
	StartPos = Pos;
	m_Speed = speed;
	m_Atk = atk;
	m_Rotation = D3DXToRadian(angle - 90);
	if (!playerguidance)
	{
		m_Rotation = D3DXToRadian(angle - 90);
		m_Speed = speed;
		ArrivePos = Vec2(cos(m_Rotation), sin(m_Rotation));
	}

	Dire = ArrivePos - StartPos;

	D3DXVec2Normalize(&Dire, &Dire);
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Update(float deltaTime, float Time)
{
	ObjMgr->CollisionCheak(this, "Player");
	ObjMgr->CollisionCheak(this, "Shield");
	ObjMgr->CollisionCheak(this, "Bomb");
	ObjMgr->CollisionCheak(this, "ColBox");

	if (!m_PlayerGuidance)
	{
		Dire = ArrivePos - StartPos;

		D3DXVec2Normalize(&Dire, &ArrivePos);
	}

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
	if (other->m_Tag == "Shield")
	{
		SetDestroy(this);
	}
	if (other->m_Tag == "Bomb")
	{
		SetDestroy(this);
	}
}
