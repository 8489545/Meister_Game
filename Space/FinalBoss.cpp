#include "stdafx.h"
#include "FinalBoss.h"
#include "EnemyBullet.h"

//200% > 150%

FinalBoss::FinalBoss()
{
	m_Body = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/Body.png");
	m_Body->SetParent(this);

	m_BodyCol = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/BodyCol.png");
	m_LWingCol = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/WingCol.png");
	m_RWingCol = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/WingCol.png");
	m_TailWingCol = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/TailWingCol.png");

	m_LProp1 = new Animation();
	m_LProp2 = new Animation();
	m_LProp3 = new Animation();

	m_RProp1 = new Animation();
	m_RProp2 = new Animation();
	m_RProp3 = new Animation();

	m_LProp1->Init(1, true);
	m_LProp2->Init(1, true);
	m_LProp3->Init(1, true);

	m_RProp1->Init(1, true);
	m_RProp2->Init(1, true);
	m_RProp3->Init(1, true);

	m_LProp1->AddContinueFrame(L"Painting/Object/Enemy/FinalBoss/Animation/", 1, 8);
	m_LProp2->AddContinueFrame(L"Painting/Object/Enemy/FinalBoss/Animation/", 1, 8);
	m_LProp3->AddContinueFrame(L"Painting/Object/Enemy/FinalBoss/Animation/", 1, 8);

	m_RProp1->AddContinueFrame(L"Painting/Object/Enemy/FinalBoss/Animation/", 1, 8);
	m_RProp2->AddContinueFrame(L"Painting/Object/Enemy/FinalBoss/Animation/", 1, 8);
	m_RProp3->AddContinueFrame(L"Painting/Object/Enemy/FinalBoss/Animation/", 1, 8);

	m_LCannon1 = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/Cannon.png");
	m_LCannon2 = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/Cannon.png");
	m_LCannon3 = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/Cannon.png");
	m_MidCannon = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/Cannon.png");
	m_RCannon1 = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/Cannon.png");
	m_RCannon2 = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/Cannon.png");
	m_RCannon3 = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/Cannon.png");

	m_Warning = Sprite::Create(L"Painting/Object/Enemy/FinalBoss/Warning.png");
	m_Warning->SetPosition(1920 / 2, -300);

	m_BodyCol->m_Visible = false;
	m_LWingCol->m_Visible = false;
	m_RWingCol->m_Visible = false;
	m_TailWingCol->m_Visible = false;

	ObjMgr->AddObject(m_Warning, "UI");

	ObjMgr->AddObject(m_LProp1, "Decor");
	ObjMgr->AddObject(m_LProp2, "Decor");
	ObjMgr->AddObject(m_LProp3, "Decor");

	ObjMgr->AddObject(m_RProp1, "Decor");
	ObjMgr->AddObject(m_RProp2, "Decor");
	ObjMgr->AddObject(m_RProp3, "Decor");

	ObjMgr->AddObject(m_LCannon1, "Decor");
	ObjMgr->AddObject(m_LCannon2, "Decor");
	ObjMgr->AddObject(m_LCannon3, "Decor");
	ObjMgr->AddObject(m_MidCannon, "Decor");
	ObjMgr->AddObject(m_RCannon1, "Decor");
	ObjMgr->AddObject(m_RCannon2, "Decor");
	ObjMgr->AddObject(m_RCannon3, "Decor");


	m_LProp1->m_Layer = 1;
	m_LProp2->m_Layer = 1;
	m_LProp3->m_Layer = 1;

	m_RProp1->m_Layer = 1;
	m_RProp2->m_Layer = 1;
	m_RProp3->m_Layer = 1;

	m_LCannon1->m_Layer = 1;
	m_LCannon2->m_Layer = 1;
	m_LCannon3->m_Layer = 1;
	m_MidCannon->m_Layer = 1;
	m_RCannon1->m_Layer = 1;
	m_RCannon2->m_Layer = 1;
	m_RCannon3->m_Layer = 1;

	ObjMgr->AddObject(m_BodyCol, "BossCol");
	ObjMgr->AddObject(m_LWingCol, "BossCol");
	ObjMgr->AddObject(m_RWingCol, "BossCol");
	ObjMgr->AddObject(m_TailWingCol, "BossCol");

	SetPosition(1920 / 2, -500);

	m_LCannon1Tick = new FireTick();
	m_LCannon2Tick = new FireTick();
	m_LCannon3Tick = new FireTick();
	m_MidCannonTick = new FireTick();
	m_RCannon1Tick = new FireTick();
	m_RCannon2Tick = new FireTick();
	m_RCannon3Tick = new FireTick();

	m_LCannon1Tick->m_LastFireTick = 0.f;
	m_LCannon1Tick->m_FireDelay = 1.0f;

	m_LCannon2Tick->m_LastFireTick = 0.f;
	m_LCannon2Tick->m_FireDelay = 1.0f;

	m_LCannon3Tick->m_LastFireTick = 0.f;
	m_LCannon3Tick->m_FireDelay = 1.0f;

	m_MidCannonTick->m_LastFireTick = 0.f;
	m_MidCannonTick->m_FireDelay = 0.1f;

	m_RCannon1Tick->m_LastFireTick = 0.f;
	m_RCannon1Tick->m_FireDelay = 1.0f;

	m_RCannon2Tick->m_LastFireTick = 0.f;
	m_RCannon2Tick->m_FireDelay = 1.0f;

	m_RCannon3Tick->m_LastFireTick = 0.f;
	m_RCannon3Tick->m_FireDelay = 1.0f;

	m_WarningTick = 0.f;
	m_Phase = 0;
	m_RandomPattern = 0;
	m_isPatternProgress = false;
	m_PatternChangeTick = 0.f;
	m_MoveTime = 0.f;
	m_Speed = 400.f;
	m_RandPos = Vec2((rand() % 900) + 360, (rand() % 500));
	m_Atk = 40.f;

	m_HP = 1000000;
}

FinalBoss::~FinalBoss()
{
}

void FinalBoss::Start()
{
	if (m_Warning->m_Position.y <= 1080 / 2)
	{
		m_Warning->m_Position.y += 600 * dt;
	}
	else
	{
		m_WarningTick += dt;

		if (m_WarningTick >= 3.f)
		{
			m_Warning->m_Position.y += 600 * dt;

			if (m_Warning->m_Position.y >= 1300)
			{
				m_WarningTick = 0.f;
				m_Warning->SetDestroy(true);
				GameMgr::GetInst()->m_ScrollingStop = true;
				m_Phase = 1;
			}
		}
	}
}

void FinalBoss::AppearMove()
{
	if (m_Position.y <= 300)
		m_Position.y += 300 * dt;
	else
		m_Phase = 2;
}

void FinalBoss::Pattern1()
{
	m_LCannon1Tick->m_FireDelay = 1.0f;
	m_LCannon2Tick->m_FireDelay = 1.0f;
	m_LCannon3Tick->m_FireDelay = 1.0f;
	m_RCannon1Tick->m_FireDelay = 1.0f;
	m_RCannon2Tick->m_FireDelay = 1.0f;
	m_RCannon3Tick->m_FireDelay = 1.0f;

	SetCannonRot();
	Shot(m_LCannon1Tick, m_LCannon1->m_Position, m_Atk, 800, 0, false, 0, true, L"BigBullet");
	Shot(m_LCannon2Tick, m_LCannon2->m_Position, m_Atk, 800, 0, false, 0, true, L"BigBullet");
	Shot(m_LCannon3Tick, m_LCannon3->m_Position, m_Atk, 800, 0, false, 0, true, L"BigBullet");
	Shot(m_RCannon1Tick, m_RCannon1->m_Position, m_Atk, 800, 0, false, 0, true, L"BigBullet");
	Shot(m_RCannon2Tick, m_RCannon2->m_Position, m_Atk, 800, 0, false, 0, true, L"BigBullet");
	Shot(m_RCannon3Tick, m_RCannon3->m_Position, m_Atk, 800, 0, false, 0, true, L"BigBullet");
}

void FinalBoss::Pattern2()
{
	m_LCannon1->m_Rotation += D3DXToRadian(200) * dt;
	m_LCannon2->m_Rotation += D3DXToRadian(150) * dt;
	m_LCannon3->m_Rotation += D3DXToRadian(100) * dt;
	m_RCannon1->m_Rotation += D3DXToRadian(100) * dt;
	m_RCannon2->m_Rotation += D3DXToRadian(150) * dt;
	m_RCannon3->m_Rotation += D3DXToRadian(200) * dt;

	m_LCannon1Tick->m_FireDelay = 0.2;
	m_RCannon1Tick->m_FireDelay = 0.2;
	m_LCannon2Tick->m_FireDelay = 0.2;
	m_RCannon2Tick->m_FireDelay = 0.2;
	m_LCannon3Tick->m_FireDelay = 0.2;
	m_RCannon3Tick->m_FireDelay = 0.2;

	Shot(m_LCannon1Tick, m_LCannon1->m_Position, m_Atk, 500, D3DXToDegree(m_LCannon1->m_Rotation), false, 0, false);
	Shot(m_LCannon2Tick, m_LCannon2->m_Position, m_Atk, 500, D3DXToDegree(m_LCannon2->m_Rotation), false, 0, false);
	Shot(m_LCannon3Tick, m_LCannon3->m_Position, m_Atk, 500, D3DXToDegree(m_LCannon3->m_Rotation), false, 0, false);
	Shot(m_RCannon1Tick, m_RCannon1->m_Position, m_Atk, 500, D3DXToDegree(m_RCannon1->m_Rotation), false, 0, false);
	Shot(m_RCannon2Tick, m_RCannon2->m_Position, m_Atk, 500, D3DXToDegree(m_RCannon2->m_Rotation), false, 0, false);
	Shot(m_RCannon3Tick, m_RCannon3->m_Position, m_Atk, 500, D3DXToDegree(m_RCannon3->m_Rotation), false, 0, false);
}

void FinalBoss::Pattern3()
{
	SetCannonRot();
	m_LCannon1Tick->m_FireDelay = 0.5f;
	m_RCannon1Tick->m_FireDelay = 0.5f;
	m_LCannon2Tick->m_FireDelay = 0.5f;
	m_RCannon2Tick->m_FireDelay = 0.5f;
	m_LCannon3Tick->m_FireDelay = 0.5f;
	m_RCannon3Tick->m_FireDelay = 0.5f;

	Shot(m_LCannon1Tick, m_LCannon1->m_Position, m_Atk, 300, 0, true, 500, true);
	Shot(m_LCannon2Tick, m_LCannon2->m_Position, m_Atk, 300, 0, true, 500, true);
	Shot(m_LCannon3Tick, m_LCannon3->m_Position, m_Atk, 300, 0, true, 500, true);
	Shot(m_RCannon1Tick, m_RCannon1->m_Position, m_Atk, 300, 0, true, 500, true);
	Shot(m_RCannon2Tick, m_RCannon2->m_Position, m_Atk, 300, 0, true, 500, true);
	Shot(m_RCannon3Tick, m_RCannon3->m_Position, m_Atk, 300, 0, true, 500, true);
}

void FinalBoss::Collision()
{
	m_Body->B = 0;
	m_Body->G = 0; 
}

void FinalBoss::End()
{

}

void FinalBoss::SetCannonRot()
{
	Vec2 B = GameMgr::GetInst()->m_PlayerPos;


	m_LCannon1->m_Rotation = GetVec2Angle(m_LCannon1->m_Position, B) + D3DXToRadian(90);
	m_LCannon2->m_Rotation = GetVec2Angle(m_LCannon2->m_Position, B) + D3DXToRadian(90);
	m_LCannon3->m_Rotation = GetVec2Angle(m_LCannon3->m_Position, B) + D3DXToRadian(90);
	m_RCannon1->m_Rotation = GetVec2Angle(m_RCannon1->m_Position, B) + D3DXToRadian(90);
	m_RCannon2->m_Rotation = GetVec2Angle(m_RCannon2->m_Position, B) + D3DXToRadian(90);
	m_RCannon3->m_Rotation = GetVec2Angle(m_RCannon3->m_Position, B) + D3DXToRadian(90);
}

void FinalBoss::Update(float deltatime, float Time)
{
	if(m_Body->B < 255)
		m_Body->B += 85;
	if (m_Body->G < 255)
		m_Body->G += 85;

	if (m_Phase == 0)
		Start();
	if (m_Phase == 1)
		AppearMove();

	if (m_Phase == 2)
	{
		m_LCannon1Tick->m_LastFireTick += dt;
		m_LCannon2Tick->m_LastFireTick += dt;
		m_LCannon3Tick->m_LastFireTick += dt;
		m_MidCannonTick->m_LastFireTick += dt;
		m_RCannon1Tick->m_LastFireTick += dt;
		m_RCannon2Tick->m_LastFireTick += dt;
		m_RCannon3Tick->m_LastFireTick += dt;

		m_MoveTime += dt;

		if (m_MoveTime >= 3.f)
		{
			Vec2 A, B, Dire;
			const int EPSILON = 40;

			A = m_Position;
			B = m_RandPos;

			Dire = B - A;

			D3DXVec2Normalize(&Dire, &Dire);

			if (abs(m_Position.x - m_RandPos.x) > EPSILON&& abs(m_Position.y - m_RandPos.y) > EPSILON)
			{
				Translate(Dire.x * m_Speed * dt, Dire.y * m_Speed * dt);
			}
			else
			{
				m_RandPos = Vec2((rand() % 900) + 360, (rand() % 500));
				m_MoveTime = 0.f;
			}
		}

		m_MidCannon->m_Rotation += D3DXToRadian(150) * dt;

		if (m_MidCannonTick->m_FireDelay <= m_MidCannonTick->m_LastFireTick && m_HP >= 0)
		{
			ObjMgr->AddObject(new EnemyBullet(m_MidCannon->m_Position, m_Atk, 500, D3DXToDegree(m_MidCannon->m_Rotation), false, 0, false), "EnemyBullet");
			m_MidCannonTick->m_LastFireTick = 0.f;
		}

		if (!m_isPatternProgress)
		{
			m_RandomPattern = (rand() % 3) + 1;
			m_PatternChangeTick = 30.f;
			m_isPatternProgress = true;
		}
		if (m_isPatternProgress)
		{
			m_PatternChangeTick -= dt;
			if (m_PatternChangeTick >= 0)
			{
				if (m_RandomPattern == 1)
				{
					Pattern1();
				}
				if (m_RandomPattern == 2)
				{
					Pattern2();
				}
				if (m_RandomPattern == 3)
				{
					Pattern3();
				}
			}
			if (m_PatternChangeTick < 0)
			{
				m_isPatternProgress = false;
			}
		}

		if (m_HP <= 0)
			m_Phase = 3;
	}

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
			m_HP -= other->m_Atk * 2;
			ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
			Collision();
			other->SetDestroy(true);
		}
		if (IntersectRect(&rc, &m_LWingCol->m_Collision, &other->m_Collision))
		{
			float randx = (rand() % (int)m_LWingCol->m_Size.x) + m_LWingCol->m_Position.x - m_LWingCol->m_Size.x / 2;
			float randy = (rand() % (int)m_LWingCol->m_Size.y) + m_LWingCol->m_Position.y - m_LWingCol->m_Size.y / 2;
			m_HP -= other->m_Atk;
			ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
			Collision();
			other->SetDestroy(true);
		}
		if (IntersectRect(&rc, &m_RWingCol->m_Collision, &other->m_Collision))
		{
			float randx = (rand() % (int)m_RWingCol->m_Size.x) + m_RWingCol->m_Position.x - m_RWingCol->m_Size.x / 2;
			float randy = (rand() % (int)m_RWingCol->m_Size.y) + m_RWingCol->m_Position.y - m_RWingCol->m_Size.y / 2;
			m_HP -= other->m_Atk;
			ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
			Collision();
			other->SetDestroy(true);
		}
		if (IntersectRect(&rc, &m_TailWingCol->m_Collision, &other->m_Collision))
		{
			float randx = (rand() % (int)m_TailWingCol->m_Size.x) + m_TailWingCol->m_Position.x - m_TailWingCol->m_Size.x / 2;
			float randy = (rand() % (int)m_TailWingCol->m_Size.y) + m_TailWingCol->m_Position.y - m_TailWingCol->m_Size.y / 2;
			ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
			m_HP -= other->m_Atk;
			Collision();
			other->SetDestroy(true);
		}

		if (IntersectRect(&rc, &m_TailWingCol->m_Collision, &other->m_Collision))
		{
			float randx = (rand() % (int)m_TailWingCol->m_Size.x) + m_TailWingCol->m_Position.x - m_TailWingCol->m_Size.x / 2;
			float randy = (rand() % (int)m_TailWingCol->m_Size.y) + m_TailWingCol->m_Position.y - m_TailWingCol->m_Size.y / 2;
			m_HP -= other->m_Atk;
			ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
			Collision();
			other->SetDestroy(true);
		}
	}
}

float FinalBoss::GetVec2Angle(Vec2 A, Vec2 B)
{
	Vec2 C;
	
	C = B - A;
	D3DXVec2Normalize(&C, &C);

	float Angle;

	Vec2 UA;
	Vec2 UB;

	D3DXVec2Normalize(&UA, &A);
	D3DXVec2Normalize(&UB, &B);

	if (D3DXVec2CCW(&UA, &UB) >= 0.f)
		return acos(C.x);
	else if (D3DXVec2CCW(&UA, &UB) < 0.f)
		return -acos(C.x);
}

void FinalBoss::Shot(FireTick *fire, Vec2 Pos, float atk, float speed, float angle, bool isrand, int randrange, bool playerguidance, std::wstring filename)
{

	if (fire->m_FireDelay <= fire->m_LastFireTick)
	{
		ObjMgr->AddObject(new EnemyBullet(Pos, atk, speed, angle, isrand, randrange, playerguidance,filename), "EnemyBullet");
		fire->m_LastFireTick = 0.f;
	}
}

void FinalBoss::SetObjectsPosition()
{
	m_BodyCol->SetPosition(m_Position.x, m_Position.y - 50);
	m_LWingCol->SetPosition(m_Position.x - 350, m_Position.y - 70);
	m_RWingCol->SetPosition(m_Position.x + 350, m_Position.y - 70);
	m_TailWingCol->SetPosition(m_Position.x, m_Position.y + 230);

	m_LProp1->SetPosition(m_Position.x - 495, m_Position.y  - 180);
	m_LProp2->SetPosition(m_Position.x - 355, m_Position.y  - 180);
	m_LProp3->SetPosition(m_Position.x - 205, m_Position.y  - 180);

	m_RProp1->SetPosition(m_Position.x + 495 + 15, m_Position.y  - 180);
	m_RProp2->SetPosition(m_Position.x + 355 + 15, m_Position.y  - 180);
	m_RProp3->SetPosition(m_Position.x + 205 + 15, m_Position.y  - 180);

	m_LCannon1->SetPosition(m_Position.x - 425,m_Position.y - 75);
	m_LCannon2->SetPosition(m_Position.x - 280,m_Position.y - 75);
	m_LCannon3->SetPosition(m_Position.x - 135,m_Position.y - 75);
	m_MidCannon->SetPosition(m_Position.x + 15,m_Position.y - 100);
	m_RCannon1->SetPosition(m_Position.x + 425 + 20,m_Position.y - 75);
	m_RCannon2->SetPosition(m_Position.x + 280 + 20,m_Position.y - 75);
	m_RCannon3->SetPosition(m_Position.x + 135 + 20,m_Position.y - 75);
}
