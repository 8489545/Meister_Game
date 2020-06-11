#include "stdafx.h"
#include "FinalBoss.h"

FinalBoss::FinalBoss()
{
	m_Body = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/Body.png");
	m_Body->SetParent(this);

	m_BodyCol = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/BodyCol.png");
	m_LWingCol = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/WingCol.png");
	m_RWingCol = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/WingCol.png");
	m_TailWingCol = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/TailWingCol.png");

	ObjMgr->AddObject(m_BodyCol, "BossCol");
	ObjMgr->AddObject(m_LWingCol, "BossCol");
	ObjMgr->AddObject(m_RWingCol, "BossCol");
	ObjMgr->AddObject(m_TailWingCol, "BossCol");

	SetPosition(1920 / 2, 1080 / 2);
}

FinalBoss::~FinalBoss()
{
}

void FinalBoss::CollisionCheak()
{
}

void FinalBoss::Update(float deltatime, float Time)
{
	SetObjectsPosition();

	ObjMgr->CollisionCheak(this,"Bullet");
}

void FinalBoss::Render()
{
	m_Body->Render();
}

void FinalBoss::OnCollision(Object* other)
{
	if (other->m_Tag == "Bullet")
	{
		RECT rc;
		if (IntersectRect(&rc, &m_BodyCol->m_Collision, &other->m_Collision))
		{
			float randx = (rand() % (int)m_BodyCol->m_Size.x) + m_BodyCol->m_Position.x - m_BodyCol->m_Size.x / 2;
			float randy = (rand() % (int)m_BodyCol->m_Size.y) + m_BodyCol->m_Position.y - m_BodyCol->m_Size.y / 2;
			m_HP -= other->m_Atk;
			ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
			other->SetDestroy(true);
		}
		if (IntersectRect(&rc, &m_LWingCol->m_Collision, &other->m_Collision))
		{
			float randx = (rand() % (int)m_LWingCol->m_Size.x) + m_LWingCol->m_Position.x - m_LWingCol->m_Size.x / 2;
			float randy = (rand() % (int)m_LWingCol->m_Size.y) + m_LWingCol->m_Position.y - m_LWingCol->m_Size.y / 2;
			m_HP -= other->m_Atk;
			ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
			other->SetDestroy(true);
		}
		if (IntersectRect(&rc, &m_RWingCol->m_Collision, &other->m_Collision))
		{
			float randx = (rand() % (int)m_RWingCol->m_Size.x) + m_RWingCol->m_Position.x - m_RWingCol->m_Size.x / 2;
			float randy = (rand() % (int)m_RWingCol->m_Size.y) + m_RWingCol->m_Position.y - m_RWingCol->m_Size.y / 2;
			m_HP -= other->m_Atk;
			ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
			other->SetDestroy(true);
		}
		if (IntersectRect(&rc, &m_TailWingCol->m_Collision, &other->m_Collision))
		{
			float randx = (rand() % (int)m_TailWingCol->m_Size.x) + m_TailWingCol->m_Position.x - m_TailWingCol->m_Size.x / 2;
			float randy = (rand() % (int)m_TailWingCol->m_Size.y) + m_TailWingCol->m_Position.y - m_TailWingCol->m_Size.y / 2;
			m_HP -= other->m_Atk;
			ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
			other->SetDestroy(true);
		}

		if (IntersectRect(&rc, &m_TailWingCol->m_Collision, &other->m_Collision))
		{
			float randx = (rand() % (int)m_TailWingCol->m_Size.x) + m_TailWingCol->m_Position.x - m_TailWingCol->m_Size.x / 2;
			float randy = (rand() % (int)m_TailWingCol->m_Size.y) + m_TailWingCol->m_Position.y - m_TailWingCol->m_Size.y / 2;
			m_HP -= other->m_Atk;
			ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
			other->SetDestroy(true);
		}
	}
}

void FinalBoss::SetObjectsPosition()
{
	m_BodyCol->SetPosition(m_Position.x, m_Position.y - 50);
	m_LWingCol->SetPosition(m_Position.x - 350, m_Position.y - 70);
	m_RWingCol->SetPosition(m_Position.x + 350, m_Position.y - 70);
	m_TailWingCol->SetPosition(m_Position.x, m_Position.y + 230);
}
