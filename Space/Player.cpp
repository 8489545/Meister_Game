#include "stdafx.h"
#include "Player.h"
#include"DirectBullet.h"
#include"SpreadBullet.h"

Player::Player()
{
	Init();
}

Player::~Player()
{
}

void Player::Init()
{
	m_Front = Sprite::Create(L"Painting/Object/Player/Front.png");
	m_Front->SetParent(this);
	
	m_Left = Sprite::Create(L"Painting/Object/Player/Left.png");
	m_Left->SetParent(this);

	m_Right = Sprite::Create(L"Painting/Object/Player/Right.png");
	m_Right->SetParent(this);

	m_Propel = Sprite::Create(L"Painting/Object/Player/Propel.png");
	m_Propel->SetParent(this);

	m_LPropel = Sprite::Create(L"Painting/Object/Player/LeftPropel.png");
	m_LPropel->SetParent(this);

	m_RPropel = Sprite::Create(L"Painting/Object/Player/RightPropel.png");
	m_RPropel->SetParent(this);

	m_Player = m_Front;
	m_Player->SetParent(this);

	SetPosition(1920 / 2, 900);

	m_FirstSkillAcq = false;
	m_SecendSkillAcq = false;

	m_HP = 100;
	m_Exp = 0;
	m_Level = 1;
	m_Atk = 60;
	m_Speed = 300.f;

	GameMgr::GetInst()->m_PlayerShotType = SHOTTYPE::DIRECT;
}

void Player::Release()
{
}

void Player::Update(float deltaTime, float Time)
{
	m_NowTick += deltaTime;
	DeliveringInformation();
	ChangeFireMode();
	Move();
	Shot();
}

void Player::Render()
{
	m_Player->Render();
}

void Player::Move()
{
	if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS && m_Position.x >= GameMgr::GetInst()->XMIN)
	{
		m_Position.x -= m_Speed * dt;
		m_Player = m_Left;

		if (INPUT->GetKey(VK_UP) == KeyState::PRESS && m_Position.y >= GameMgr::GetInst()->YMIN)
		{
			m_Position.y -= m_Speed * dt;
			m_Player = m_LPropel;
		}
	}
	else if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS && m_Position.x <= GameMgr::GetInst()->XMAX)
	{
		m_Position.x += m_Speed * dt;
		m_Player = m_Right;

		if (INPUT->GetKey(VK_UP) == KeyState::PRESS && m_Position.y >= GameMgr::GetInst()->YMIN)
		{
			m_Position.y -= m_Speed * dt;
			m_Player = m_RPropel;
		}
	}
	else if (INPUT->GetKey(VK_UP) == KeyState::PRESS && m_Position.y >= GameMgr::GetInst()->YMIN)
	{
		m_Position.y -= m_Speed * dt;
		m_Player = m_Propel;
	}
	else
	{
		m_Player = m_Front;
	}

	if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS && m_Position.y <= GameMgr::GetInst()->YMAX)
	{
		m_Position.y += m_Speed * dt;
	}
}

void Player::Shot()
{
	if (GameMgr::GetInst()->m_PlayerShotType == SHOTTYPE::SPREAD)
		printf("Spread\n");
	if ((INPUT->GetKey(VK_SPACE) == KeyState::PRESS && (m_NowTick - m_LastFireTick) > m_FireDelay) && GameMgr::GetInst()->m_PlayerShotType == SHOTTYPE::DIRECT)
	{
		ObjMgr->AddObject(new DirectBullet(Vec2(m_Position.x - 30, m_Position.y - 20), 1000), "Bullet");
		ObjMgr->AddObject(new DirectBullet(Vec2(m_Position.x + 27, m_Position.y - 20), 1000), "Bullet");
		m_LastFireTick = m_NowTick;
	}
	if ((INPUT->GetKey(VK_SPACE) == KeyState::PRESS && (m_NowTick - m_LastFireTick) > m_FireDelay) && GameMgr::GetInst()->m_PlayerShotType == SHOTTYPE::SPREAD)
	{
		ObjMgr->AddObject(new SpreadBullet(Vec2(m_Position.x, m_Position.y - 50), 700,20), "Bullet");
		ObjMgr->AddObject(new SpreadBullet(Vec2(m_Position.x, m_Position.y - 50), 700,0), "Bullet");
		ObjMgr->AddObject(new SpreadBullet(Vec2(m_Position.x, m_Position.y - 50), 700,-20), "Bullet");
		m_LastFireTick = m_NowTick;
	}
}

void Player::ChangeFireMode()
{
	if (GameMgr::GetInst()->m_PlayerShotType == SHOTTYPE::DIRECT)
	{
		m_RPM = 400.f;
	}
	else if (GameMgr::GetInst()->m_PlayerShotType == SHOTTYPE::SPREAD)
	{
		m_RPM = 250.f;
	}
	m_FireDelay = (60.f / m_RPM);
	if (INPUT->GetKey('B') == KeyState::DOWN)
	{
		if (GameMgr::GetInst()->m_PlayerShotType == SHOTTYPE::DIRECT)
		{
			GameMgr::GetInst()->m_PlayerShotType = SHOTTYPE::SPREAD;
		}
		else if (GameMgr::GetInst()->m_PlayerShotType == SHOTTYPE::SPREAD)
		{
			GameMgr::GetInst()->m_PlayerShotType = SHOTTYPE::DIRECT;
		}
		GameMgr::GetInst()->ChangeFireMode();
	}
}

void Player::DeliveringInformation()
{
	GameMgr::GetInst()->m_FirstSkill = m_FirstSkillAcq;
	GameMgr::GetInst()->m_SecendSkill = m_SecendSkillAcq;
	GameMgr::GetInst()->SetPlayerStatus(m_Level, m_Exp, m_HP, m_Speed, m_Atk, m_RPM);
}
