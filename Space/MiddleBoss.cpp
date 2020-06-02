#include "stdafx.h"
#include "MiddleBoss.h"
#include"EnemyBullet.h"

//Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/")


MiddleBoss::MiddleBoss()
{
	m_Body = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/Body.png");
	m_Body->SetParent(this);
	m_Layer = -1;
	
	SetPosition(1920 / 2, -500);

	m_LeftCannon1 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/Cannon.png");
	m_RightCannon1 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/Cannon.png");

	m_MidCannon = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/Cannon.png");
	m_MidDecor1 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/MidDecor1.png");

	m_LeftDecor = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/leftDecor.png");
	m_RightDecor = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/rightDecor.png");

	m_LeftCannon2 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/Cannon.png");
	m_RightCannon2 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/Cannon.png");

	m_LeftBigCannon = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/BigCannon.png");
	m_RightBigCannon = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/BigCannon.png");

	m_MidDecor2 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/MidDecor2.png");
	m_MidCannon2 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/Cannon.png");

	m_LeftDes1 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/leftDes1.png");
	m_RightDes1= Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/rightDes1.png");
	m_MidDes1 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/midDes1.png");
	

	ObjMgr->AddObject(m_LeftDes1, "Effect");
	ObjMgr->AddObject(m_RightDes1, "Effect");
	ObjMgr->AddObject(m_MidDes1, "Effect");

	ObjMgr->AddObject(m_LeftCannon1, "Enemy");
	ObjMgr->AddObject(m_RightCannon1, "Enemy");

	ObjMgr->AddObject(m_MidCannon, "Enemy");
	ObjMgr->AddObject(m_MidDecor1, "Enemy");

	ObjMgr->AddObject(m_LeftDecor, "Enemy");
	ObjMgr->AddObject(m_RightDecor, "Enemy");

	ObjMgr->AddObject(m_LeftCannon2, "Enemy");
	ObjMgr->AddObject(m_RightCannon2, "Enemy");

	ObjMgr->AddObject(m_LeftBigCannon, "Enemy");
	ObjMgr->AddObject(m_RightBigCannon, "Enemy");

	ObjMgr->AddObject(m_MidDecor2, "Enemy");
	ObjMgr->AddObject(m_MidCannon2, "Enemy");


	m_Phase = 1;
	m_Atk = 33;

	m_LeftDes1->m_Visible = false;
	m_RightDes1->m_Visible = false;
	m_MidDes1->m_Visible = false;

	m_MidDecorRot = false;

	m_LeftCannon1->m_HP = 15000.f;
	m_RightCannon1->m_HP = 15000.f;
	m_MidDecor1->m_HP = 35000.f;

	m_MidDecor1Tick = new FireTick();
	m_LeftCannon1Tick = new FireTick();
	m_RightCannon1Tick = new FireTick();
}


MiddleBoss::~MiddleBoss()
{
}

void MiddleBoss::Update(float deltaTime, float Time)
{
	if (m_Phase == 1)
	{
		Phase1();
	}
	SetObjectsPosition();
}

void MiddleBoss::Render()
{
	m_Body->Render();
}

void MiddleBoss::Phase1()
{
	if (m_Position.y <= -250)
	{
		m_Position.y += 100 * dt;
	}
	else
	{
		m_MidDecor1Tick->m_FireDelay = 0.1f;
		m_MidDecor1Tick->m_LastFireTick += dt;

		m_LeftCannon1Tick->m_FireDelay = 2.0f;
		m_LeftCannon1Tick->m_LastFireTick += dt;

		m_RightCannon1Tick->m_FireDelay = 2.0f;
		m_RightCannon1Tick->m_LastFireTick += dt;

		Vec2 A = m_LeftCannon1->m_Position;
		Vec2 A2 = m_RightCannon1->m_Position;
		Vec2 B = GameMgr::GetInst()->m_PlayerPos;
		Vec2 C;
		Vec2 C2;

		C = A - B;
		C2 = A2 - B;
		D3DXVec2Normalize(&C, &C);
		D3DXVec2Normalize(&C2, &C2);

		float angle = acos(C.x) * -1;
		float angle2 = acos(C2.x) * -1;

		m_LeftCannon1->m_Rotation = angle + D3DXToRadian(90);
		m_RightCannon1->m_Rotation = angle2 + D3DXToRadian(90);


		if (!m_MidDecorRot)
		{
			m_MidDecor1->m_Rotation -= D3DXToRadian(60) * dt;

			if (m_MidDecor1->m_Rotation <= D3DXToRadian(-30))
				m_MidDecorRot = true;

		}
		else if (m_MidDecorRot)
		{
			m_MidDecor1->m_Rotation += D3DXToRadian(60) * dt;

			if (m_MidDecor1->m_Rotation >= D3DXToRadian(30))
				m_MidDecorRot = false;
		}

		if (m_MidDecor1Tick->m_FireDelay <= m_MidDecor1Tick->m_LastFireTick && m_MidDecor1->m_HP >= 0)
		{
			ObjMgr->AddObject(new EnemyBullet(m_MidDecor1->m_Position, m_Atk, 500, D3DXToDegree(m_MidDecor1->m_Rotation) - 180, false, 0, false), "EnemyBullet");
			m_MidDecor1Tick->m_LastFireTick = 0.f;
		}
		if (m_LeftCannon1Tick->m_FireDelay <= m_LeftCannon1Tick->m_LastFireTick && m_LeftCannon1->m_HP >= 0)
		{
			ObjMgr->AddObject(new EnemyBullet(m_LeftCannon1->m_Position, m_Atk, 700, 0, false, 0, true,L"BigBullet"), "EnemyBullet");
			m_LeftCannon1Tick->m_LastFireTick = 0.f;
		}
		if (m_RightCannon1Tick->m_FireDelay <= m_RightCannon1Tick->m_LastFireTick && m_RightCannon1->m_HP >= 0)
		{
			ObjMgr->AddObject(new EnemyBullet(m_RightCannon1->m_Position, m_Atk, 700, 0, false, 0, true, L"BigBullet"), "EnemyBullet");
			m_RightCannon1Tick->m_LastFireTick = 0.f;
		}

		if (m_LeftCannon1->m_HP <= 0)
		{
			GameMgr::GetInst()->SpawnItem(m_LeftCannon1->m_Position);
			m_LeftCannon1->SetDestroy(true);
			m_LeftDes1->m_Visible = true;
		}
		if (m_RightCannon1->m_HP <= 0)
		{
			GameMgr::GetInst()->SpawnItem(m_RightCannon1->m_Position);
			m_RightCannon1->SetDestroy(true);
			m_RightDes1->m_Visible = true;
		}
		if (m_MidDecor1->m_HP <= 0)
		{
			GameMgr::GetInst()->SpawnItem(m_MidDecor1->m_Position);
			m_MidDecor1->SetDestroy(true);
			m_MidDes1->m_Visible = true;
		}
	}
}	  

void MiddleBoss::SetObjectsPosition()
{
	m_LeftCannon1->SetPosition(m_Position.x - 100, m_Position.y + 400);
	m_RightCannon1->SetPosition(m_Position.x + 50, m_Position.y + 400);

	m_MidDecor1->SetPosition(m_Position.x - 20, m_Position.y + 320);
	m_MidCannon->SetPosition(m_Position.x - 20, m_Position.y + 180);

	m_LeftDecor->SetPosition(m_Position.x - 180, m_Position.y + 210);
	m_RightDecor->SetPosition(m_Position.x + 130, m_Position.y + 210);

	m_LeftCannon2->SetPosition(m_Position.x - 150, m_Position.y - 20);
	m_RightCannon2->SetPosition(m_Position.x + 110, m_Position.y - 20);

	m_LeftBigCannon->SetPosition(m_Position.x - 150, m_Position.y - 130);
	m_RightBigCannon->SetPosition(m_Position.x + 125, m_Position.y - 130);

	m_MidDecor2->SetPosition(m_Position.x - 25, m_Position.y - 156);
	m_MidCannon2->SetPosition(m_Position.x - 20, m_Position.y - 280);

	m_LeftDes1->SetPosition(m_Position.x - 90, m_Position.y + 415);
	m_RightDes1->SetPosition(m_Position.x + 50, m_Position.y + 420);
	m_MidDes1->SetPosition(m_Position.x - 21, m_Position.y + 320);
}
