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
	m_willLevelUPReward = false;

	m_MAXHP = 100;
	m_MAXExp = 100;
	m_HP = m_MAXHP;
	m_Exp = 0;
	m_Level = 1;
	m_Atk = 60;
	m_Speed = 300.f;
	m_RPMIncrease = 0.f;

	m_FSkillCooldown = 0.f;
	m_SSkillCooldown = 0.f;

	m_FSkillMAXCooldown = 10.f;
	m_SSkillMAXCooldown = 25.f;

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
	LevelUP();
	Skill();
	if (INPUT->GetKey(VK_F1) == KeyState::DOWN)
		m_Exp += 70;
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
		m_RPM = 400.f + m_RPMIncrease;
		m_Atk = 100 + m_AtkIncrease;
	}
	else if (GameMgr::GetInst()->m_PlayerShotType == SHOTTYPE::SPREAD)
	{
		m_RPM = 250.f + (m_RPMIncrease * 0.375f);
		m_Atk = 60 + (m_AtkIncrease * 0.333f);
		
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
	GameMgr::GetInst()->m_FirstSkillCooldown = m_FSkillCooldown;
	GameMgr::GetInst()->m_FirstSkillMaxCooldown = m_FSkillMAXCooldown;
	GameMgr::GetInst()->m_SecendSkillCooldown = m_SSkillCooldown;
	GameMgr::GetInst()->m_SecendSkillMaxCooldown = m_SSkillMAXCooldown;
}

void Player::Skill()
{
	if (m_FSkillCooldown > 0)
	{
		m_FSkillCooldown -= dt;

		if (m_FSkillCooldown < 0)
			m_FSkillCooldown = 0.f;
	}
	if (m_SSkillCooldown > 0)
	{
		m_SSkillCooldown -= dt;

		if (m_SSkillCooldown < 0)
			m_SSkillCooldown = 0.f;
	}

	if (m_FSkillCooldown <= 0.f && INPUT->GetKey('X') == KeyState::DOWN && m_FirstSkillAcq)
	{
		m_FSkillCooldown = m_FSkillMAXCooldown;
	}
	if (m_SSkillCooldown <= 0.f && INPUT->GetKey('Z') == KeyState::DOWN && m_SecendSkillAcq)
	{
		m_SSkillCooldown = m_SSkillMAXCooldown;
	}
}

void Player::LevelUP()
{
	if (m_Exp >= m_MAXExp && m_Level < 5)
	{
		m_willLevelUPReward = true;
	}
	if (m_willLevelUPReward)
	{
		m_Level += 1;
		ObjMgr->AddObject(new EffectMgr(L"Painting/UI/LevelUP/", 1, 5, 5, m_Position), "Effect");

		switch (m_Level)
		{
		case 2:
			m_MAXHP += m_MAXHP * 0.2;
			m_AtkIncrease += m_Atk * 0.2;
			m_RPMIncrease += m_RPM * 0.2;
			m_HP = m_MAXHP;
			m_MAXExp = 200;
			m_Exp = 0;
			break;
		case 3:
			m_MAXHP += m_MAXHP * 0.2;
			m_AtkIncrease += m_Atk * 0.2;
			m_RPMIncrease += m_RPM * 0.2;
			m_HP = m_MAXHP;
			m_FirstSkillAcq = true;
			m_MAXExp = 300;
			m_Exp = 0;
			break;
		case 4:
			m_MAXHP += m_MAXHP * 0.2;
			m_AtkIncrease += m_Atk * 0.2;
			m_RPMIncrease += m_RPM * 0.2;
			m_HP = m_MAXHP;
			m_MAXExp = 400;
			m_Exp = 0;
			break;
		case 5:
			m_MAXHP += m_MAXHP * 0.2;
			m_AtkIncrease += m_Atk * 0.2;
			m_RPMIncrease += m_RPM * 0.2;
			m_HP = m_MAXHP;
			m_SecendSkillAcq = true;
			m_MAXExp = 500;
			m_Exp = 0;
			break;
		default:
			break;
		}

		m_willLevelUPReward = false;
	}
}
