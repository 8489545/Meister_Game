#include "stdafx.h"
#include "DirectBullet.h"

DirectBullet::DirectBullet(Vec2 Pos, float Speed)
{
	m_Bullet = Sprite::Create(L"Painting/Object/Bullet/Direct.png");
	m_Bullet->SetParent(this);

	m_Position = Pos;
	m_Speed = Speed;

	m_Atk = GameMgr::GetInst()->m_PlayerStatus.m_Atk;
}

DirectBullet::~DirectBullet()
{
}

void DirectBullet::Update(float delatTime, float Time)
{
	m_Position.y -= m_Speed * dt;

	if (m_Position.y <= -100.f)
	{
      	SetDestroy(true);
	}
	ObjMgr->CollisionCheak(this, "Enemy");
}

void DirectBullet::Render()
{
	m_Bullet->Render();
}

void DirectBullet::OnCollision(Object* other)
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
