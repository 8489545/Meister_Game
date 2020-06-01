#include "stdafx.h"
#include "MiddleBoss.h"

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

	ObjMgr->AddObject(m_LeftCannon1, "MidBossObj");
	ObjMgr->AddObject(m_RightCannon1, "MidBossObj");

	ObjMgr->AddObject(m_MidCannon, "MidBossObj");
	ObjMgr->AddObject(m_MidDecor1, "MidBossObj");

	ObjMgr->AddObject(m_LeftDecor, "MidBossObj");
	ObjMgr->AddObject(m_RightDecor, "MidBossObj");

	ObjMgr->AddObject(m_LeftCannon2, "MidBossObj");
	ObjMgr->AddObject(m_RightCannon2, "MidBossObj");

	ObjMgr->AddObject(m_LeftBigCannon, "MidBossObj");
	ObjMgr->AddObject(m_RightBigCannon, "MidBossObj");

	ObjMgr->AddObject(m_MidDecor2, "MidBossObj");
	ObjMgr->AddObject(m_MidCannon2, "MidBossObj");


	m_Phase = 1;

	m_LeftDes1->m_Visible = false;
	m_RightDes1->m_Visible = false;
	m_MidDes1->m_Visible = false;

	m_MidDecorRot = false;

	m_LeftCannon1->m_HP = 7500.f;
	m_RightCannon1->m_HP = 7500.f;
	m_MidDecor1->m_HP = 20000.f;
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
		Vec2 MidCannonEnd;
		MidCannonEnd.x = m_MidDecor1->m_Position.x - 50 + cos(m_MidDecor1->m_Rotation) * m_MidDecor1->m_Size.x;
		MidCannonEnd.y = m_MidDecor1->m_Position.y + sin(m_MidDecor1->m_Rotation) * m_MidDecor1->m_Size.x;

		if (!m_MidDecorRot)
		{
			m_MidDecor1->m_Rotation -= D3DXToRadian(30) * dt;

			if (m_MidDecor1->m_Rotation <= D3DXToRadian(-90))
				m_MidDecorRot = true;

		}
		else if (m_MidDecorRot)
		{
			m_MidDecor1->m_Rotation += D3DXToRadian(30) * dt;

			if (m_MidDecor1->m_Rotation >= D3DXToRadian(90))
				m_MidDecorRot = false;
		}

		if (m_LeftCannon1->m_HP <= 0)
		{
			m_LeftCannon1->SetDestroy(true);
			m_LeftDes1->m_Visible = true;
		}
		if (m_RightCannon1->m_HP <= 0)
		{
			m_RightCannon1->SetDestroy(true);
			m_RightDes1->m_Visible = true;
		}
		if (m_MidDecor1->m_HP <= 0)
		{
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
