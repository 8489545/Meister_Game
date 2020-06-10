#include "stdafx.h"
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(Vec2 Pos, float atk, float speed, float angle /* degree */, bool isrand, int randrange, bool playerguidance, std::wstring filename)
{
	m_Bullet = Sprite::Create(L"Painting/Object/Bullet/"+ filename + L".png");
	m_Bullet->SetParent(this);

	m_Position = Pos;
	StartPos = Pos;
	m_Speed = speed;
	m_Atk = atk;
	m_PlayerGuidance = playerguidance;

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

		Dire = ArrivePos - StartPos;

		D3DXVec2Normalize(&Dire, &ArrivePos);
	}
	if (!isrand && playerguidance)
	{
		ArrivePos = GameMgr::GetInst()->m_PlayerPos;

		Dire = ArrivePos - StartPos;

		D3DXVec2Normalize(&Dire, &ArrivePos);
	}

	if (!playerguidance)
	{
		m_Rotation = D3DXToRadian(angle - 90);
		ArrivePos = Vec2(cos(m_Rotation), sin(m_Rotation));
	}
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

	if (m_PlayerGuidance)
	{
		Dire = ArrivePos - StartPos;
		D3DXVec2Normalize(&Dire, &Dire);
		Translate(Dire.x * m_Speed * dt, Dire.y * m_Speed * dt);
	}
	if(!m_PlayerGuidance)
	{
		Dire = ArrivePos - StartPos;
		D3DXVec2Normalize(&Dire, &ArrivePos);
		Translate(Dire.x * m_Speed * dt, Dire.y * m_Speed * dt);
	}

	if (m_Position.x >= GameMgr::GetInst()->XMAX + 100)
		SetDestroy(true);
	if (m_Position.x <= GameMgr::GetInst()->XMIN - 100)
		SetDestroy(true);
	if (m_Position.y >= GameMgr::GetInst()->YMAX + 100)
		SetDestroy(true);
	if (m_Position.y <= GameMgr::GetInst()->YMIN - 100)
		SetDestroy(true);
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
