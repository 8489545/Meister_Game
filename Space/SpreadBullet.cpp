#include "stdafx.h"
#include "SpreadBullet.h"

SpreadBullet::SpreadBullet(Vec2 Pos, float Speed, float Angle,float atk)
{
	m_Bullet = Sprite::Create(L"Painting/Object/Bullet/Spread.png");
	m_Bullet->SetParent(this);

	m_Position = Pos;
	m_Rotation = D3DXToRadian(Angle - 90);
	m_Speed = Speed;

	m_Layer = 0;
	m_StartPos = m_Position;
	m_ArrivePos = Vec2(cos(m_Rotation), sin(m_Rotation));

	m_Atk = atk;
}

SpreadBullet::~SpreadBullet()
{
}

void SpreadBullet::AimHack()
{
	Vec2 A, B, C;

	A = m_Position;

	for (auto& iter : ObjMgr->m_Objects)
	{
		if (iter->m_Tag == "Enemy")
		{
			B = iter->m_Position;
		}
	}

	if (B.x <= -1000)
		B = Vec2(1920 / 2, -100);

	C = B - A;

	D3DXVec2Normalize(&C, &C);

	Vec2 UA;
	Vec2 UB;

	D3DXVec2Normalize(&UA, &A);
	D3DXVec2Normalize(&UB, &B);

	D3DXVec2CCW(&UA, &UB);
	m_Rotation = -acos(C.x) + D3DXToRadian(90);
	Translate(C.x * m_Speed * dt, C.y * m_Speed * dt);
}

void SpreadBullet::Update(float delatTime, float Time)
{
	m_Dire = m_ArrivePos - m_StartPos;

	D3DXVec2Normalize(&m_Dire, &m_ArrivePos);

	Translate(m_Dire.x * m_Speed * dt, m_Dire.y * m_Speed * dt);

	//AimHack();

	if (m_Position.y <= -100.f)
	{
		SetDestroy(true);
	}
	ObjMgr->CollisionCheak(this, "Enemy");
}

void SpreadBullet::Render()
{
	m_Bullet->Render();
}

void SpreadBullet::OnCollision(Object* other)
{
	if (other->m_Tag == "Enemy")
	{
		other->m_HP -= m_Atk;

		float randx = (rand() % (int)other->m_Size.x) + other->m_Position.x - other->m_Size.x / 2;
		float randy = (rand() % (int)other->m_Size.y) + other->m_Position.y - other->m_Size.y / 2;
		ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
		SetDestroy(true);
	}
}
