#include "stdafx.h"
#include "MiddleBoss.h"
#include"EnemyBullet.h"
#include"Laser.h"

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

	m_LeftDes2 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/leftDes2.png");
	m_RightDes2 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/rightDes2.png");
	m_MidDes2 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/midDes2.png");

	m_MidDes3 = Sprite::Create(L"Painting/Object/Enemy/MiddleBoss/midDes3.png");

	

	ObjMgr->AddObject(m_LeftDes1, "Effect");
	ObjMgr->AddObject(m_RightDes1, "Effect");
	ObjMgr->AddObject(m_MidDes1, "Effect");

	ObjMgr->AddObject(m_LeftDes2, "Effect");
	ObjMgr->AddObject(m_RightDes2, "Effect");
	ObjMgr->AddObject(m_MidDes2, "Effect");

	ObjMgr->AddObject(m_MidDes3, "Effect");

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

	ObjMgr->AddObject(m_MidDecor2, "Effect");
	ObjMgr->AddObject(m_MidCannon2, "Enemy");


	m_Phase = 1;
	m_Atk = 33;

	m_LeftDes1->m_Visible = false;
	m_RightDes1->m_Visible = false;
	m_MidDes1->m_Visible = false;

	m_LeftDes2->m_Visible = false;
	m_RightDes2->m_Visible = false;
	m_MidDes2->m_Visible = false;

	m_MidDes3->m_Visible = false;

	m_MidDecorRot = false;
	m_LeftCannon2Rot = false;
	m_RightCannon2Rot = false;
	m_MidCannon2Rot = false;

	m_MidDecor1Tick = new FireTick();
	m_LeftCannon1Tick = new FireTick();
	m_RightCannon1Tick = new FireTick();

	m_MidCannonTick = new FireTick();
	m_LeftCannon2Tick = new FireTick();
	m_RightCannon2Tick = new FireTick();

	m_MidCannon2Tick = new FireTick();
	m_LeftBigCannonTick = new FireTick();
	m_RightBigCannonTick = new FireTick();

	GameMgr::GetInst()->m_ScrollingStop = true;
}


MiddleBoss::~MiddleBoss()
{
}

void MiddleBoss::Update(float deltaTime, float Time)
{
	if (m_Phase == 1)
		Phase1();
	if(m_Phase == 2)
		Phase2();
	if(m_Phase == 3)
		Phase3();

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
		m_LeftCannon1->m_HP = 15000.f;
		m_RightCannon1->m_HP = 15000.f;
		m_MidDecor1->m_HP = 20000.f;

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

		if (m_LeftCannon1->m_HP <= 0 && m_LeftDes1->m_Visible == false)
		{
			GameMgr::GetInst()->m_AcqExp += 50;
			GameMgr::GetInst()->SpawnItem(m_LeftCannon1->m_Position);
			m_LeftCannon1->SetDestroy(true);
			m_LeftDes1->m_Visible = true;
		}
		if (m_RightCannon1->m_HP <= 0 && m_RightDes1->m_Visible == false)
		{
			GameMgr::GetInst()->m_AcqExp += 50;
			GameMgr::GetInst()->SpawnItem(m_RightCannon1->m_Position);
			m_RightCannon1->SetDestroy(true);
			m_RightDes1->m_Visible = true;
		}
		if (m_MidDecor1->m_HP <= 0 && m_MidDes1->m_Visible == false)
		{
			GameMgr::GetInst()->m_AcqExp += 100;
			GameMgr::GetInst()->SpawnItem(m_MidDecor1->m_Position);
			m_MidDecor1->SetDestroy(true);
			m_MidDes1->m_Visible = true;
		}

		if(m_LeftCannon1->m_HP <= 0 && m_RightCannon1->m_HP <= 0 && m_MidDecor1->m_HP <= 0)
		{
			m_Phase = 2;
		}
	}
}

void MiddleBoss::Phase2()
{
	if (m_Position.y <= 100)
	{
		m_LeftCannon2->m_HP = 20000.f;
		m_RightCannon2->m_HP = 20000.f;
		m_MidCannon->m_HP = 25000.f;
		m_RightDecor->m_HP = 30000.f;
		m_LeftDecor->m_HP = 30000.f;

		m_Position.y += 100 * dt;
	}
	else
	{
		m_MidCannonTick->m_FireDelay = 1.0f;
		m_MidCannonTick->m_LastFireTick += dt;

		m_LeftCannon2Tick->m_FireDelay = 0.2f;
		m_LeftCannon2Tick->m_LastFireTick += dt;

		m_RightCannon2Tick->m_FireDelay = 0.2f;
		m_RightCannon2Tick->m_LastFireTick += dt;

		Vec2 A = m_MidCannon->m_Position;
		Vec2 B = GameMgr::GetInst()->m_PlayerPos;
		Vec2 C;

		C = A - B;
		D3DXVec2Normalize(&C, &C);

		float angle = acos(C.x) * -1;

		m_MidCannon->m_Rotation = angle + D3DXToRadian(90);


		if (!m_LeftCannon2Rot)
		{
			m_LeftCannon2->m_Rotation -= D3DXToRadian(60) * dt;

			if (m_LeftCannon2->m_Rotation <= D3DXToRadian(-30))
				m_LeftCannon2Rot = true;

		}
		else if (m_LeftCannon2Rot)
		{
			m_LeftCannon2->m_Rotation += D3DXToRadian(60) * dt;

			if (m_LeftCannon2->m_Rotation >= D3DXToRadian(30))
				m_LeftCannon2Rot = false;
		}

		if (!m_RightCannon2Rot)
		{
			m_RightCannon2->m_Rotation += D3DXToRadian(60) * dt;

			if (m_RightCannon2->m_Rotation >= D3DXToRadian(30))
				m_RightCannon2Rot = true;

		}
		else if (m_RightCannon2Rot)
		{
			m_RightCannon2->m_Rotation -= D3DXToRadian(60) * dt;

			if (m_RightCannon2->m_Rotation <= D3DXToRadian(-30))
				m_RightCannon2Rot = false;
		}

		if (m_MidCannonTick->m_FireDelay <= m_MidCannonTick->m_LastFireTick && m_MidCannon->m_HP >= 0)
		{
			ObjMgr->AddObject(new EnemyBullet(m_MidCannon->m_Position, m_Atk, 700, 0, false, 0, true, L"BigBullet"), "EnemyBullet");
			m_MidCannonTick->m_LastFireTick = 0.f;
		}
		if (m_LeftCannon2Tick->m_FireDelay <= m_LeftCannon2Tick->m_LastFireTick && m_LeftCannon2->m_HP >= 0)
		{
			ObjMgr->AddObject(new EnemyBullet(m_LeftCannon2->m_Position, m_Atk, 500, D3DXToDegree(m_LeftCannon2->m_Rotation) - 180, false, 0, false), "EnemyBullet");
			m_LeftCannon2Tick->m_LastFireTick = 0.f;
		}
		if (m_RightCannon2Tick->m_FireDelay <= m_RightCannon2Tick->m_LastFireTick && m_RightCannon2->m_HP >= 0)
		{
			ObjMgr->AddObject(new EnemyBullet(m_RightCannon2->m_Position, m_Atk, 500, D3DXToDegree(m_RightCannon2->m_Rotation) - 180, false, 0, false), "EnemyBullet");
			m_RightCannon2Tick->m_LastFireTick = 0.f;
		}
		if (m_LeftCannon2->m_HP <= 0 && m_LeftCannon2->m_Destroy == false)
		{
			GameMgr::GetInst()->m_AcqExp += 50;
			GameMgr::GetInst()->SpawnItem(m_LeftCannon2->m_Position);
			m_LeftCannon2->SetDestroy(true);
		}
		if (m_RightCannon2->m_HP <= 0 && m_RightCannon2->m_Destroy == false)
		{
			GameMgr::GetInst()->m_AcqExp += 50;
			GameMgr::GetInst()->SpawnItem(m_RightCannon2->m_Position);
			m_RightCannon2->SetDestroy(true);
		}
		if (m_MidCannon->m_HP <= 0 && m_MidDes2->m_Visible == false)
		{
			GameMgr::GetInst()->m_AcqExp += 100;
			GameMgr::GetInst()->SpawnItem(m_MidCannon->m_Position);
			m_MidCannon->SetDestroy(true);
			m_MidDes2->m_Visible = true;
		}
		if (m_LeftDecor->m_HP <= 0 && m_LeftDes2->m_Visible == false)
		{
			m_LeftDecor->SetDestroy(true);
			m_LeftDes2->m_Visible = true;
		}
		if (m_RightDecor->m_HP <= 0 && m_RightDes2->m_Visible == false)
		{
			m_RightDecor->SetDestroy(true);
			m_RightDes2->m_Visible = true;
		}

		if (m_LeftCannon2->m_HP <= 0 && m_RightCannon2->m_HP <= 0 && m_MidCannon->m_HP <= 0 && m_LeftDecor->m_HP <= 0 && m_RightDecor->m_HP <= 0)
		{
			m_Phase = 3;
		}
	}
}

void MiddleBoss::Phase3()
{
	if (m_Position.y <= 450)
	{
		m_MidCannon2->m_HP = 20000.f;
		m_LeftBigCannon->m_HP = 20000.f;
		m_RightBigCannon->m_HP = 20000.f;

		m_Position.y += 150 * dt;
	}
	else
	{
		m_MidCannon2Tick->m_FireDelay = 0.1f;
		m_MidCannon2Tick->m_LastFireTick += dt;

		m_LeftBigCannonTick->m_FireDelay = 10.f;
		m_LeftBigCannonTick->m_LastFireTick += dt;

		m_RightBigCannonTick->m_FireDelay = 10.f;
		m_RightBigCannonTick->m_LastFireTick += dt;


		if (!m_MidCannon2Rot)
		{
			m_MidCannon2->m_Rotation -= D3DXToRadian(100) * dt;

			if (m_MidCannon2->m_Rotation <= D3DXToRadian(-30))
				m_MidCannon2Rot = true;

		}
		else if (m_MidCannon2Rot)
		{
			m_MidCannon2->m_Rotation += D3DXToRadian(100) * dt;

			if (m_MidCannon2->m_Rotation >= D3DXToRadian(30))
				m_MidCannon2Rot = false;
		}

		if (m_MidCannon2Tick->m_FireDelay <= m_MidCannon2Tick->m_LastFireTick && m_MidCannon2->m_HP >= 0)
		{
			ObjMgr->AddObject(new EnemyBullet(m_MidCannon2->m_Position, m_Atk, 500, D3DXToDegree(m_MidCannon2->m_Rotation) - 180, false, 0, false), "EnemyBullet");
			m_MidCannon2Tick->m_LastFireTick = 0.f;
		}
		if (m_LeftBigCannonTick->m_FireDelay <= m_LeftBigCannonTick->m_LastFireTick && m_LeftBigCannon->m_HP >= 0)
		{
			ObjMgr->AddObject(new Laser(m_LeftBigCannon->m_Position, 3, m_Atk, 1, 0.5), "Laser");
			m_LeftBigCannonTick->m_LastFireTick = 0.f;
		}
		if (m_RightBigCannonTick->m_FireDelay <= m_RightBigCannonTick->m_LastFireTick && m_RightBigCannon->m_HP >= 0)
		{
			ObjMgr->AddObject(new Laser(m_RightBigCannon->m_Position, 3, m_Atk, 1, 0.5), "Laser");
			m_RightBigCannonTick->m_LastFireTick = 0.f;
		}

		if (m_MidCannon2->m_HP <= 0 && !m_MidDes3->m_Visible)
		{
			GameMgr::GetInst()->m_AcqExp += 100;
			GameMgr::GetInst()->SpawnItem(m_MidCannon2->m_Position);
			m_MidCannon2->SetDestroy(true);
			m_MidDes3->m_Visible = true;
		}
		if (m_LeftBigCannon->m_HP <= 0 && !m_LeftBigCannon->m_Destroy)
		{
			GameMgr::GetInst()->m_AcqExp += 200;
			GameMgr::GetInst()->SpawnItem(m_MidCannon2->m_Position);
			m_LeftBigCannon->SetDestroy(true);
		}
		if (m_RightBigCannon->m_HP <= 0 && !m_RightBigCannon->m_Destroy)
		{
			GameMgr::GetInst()->m_AcqExp += 200;
			GameMgr::GetInst()->SpawnItem(m_RightBigCannon->m_Position);
			m_RightBigCannon->SetDestroy(true);
		}
	}
}

void MiddleBoss::Destroy()
{
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

	m_LeftDes2->SetPosition(m_Position.x - 178, m_Position.y + 215);
	m_RightDes2->SetPosition(m_Position.x + 115, m_Position.y + 215);
	m_MidDes2->SetPosition(m_Position.x - 21, m_Position.y + 120);

	m_MidDes3->SetPosition(m_Position.x - 21, m_Position.y + -260);
}
