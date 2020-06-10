#include "stdafx.h"
#include "Player.h"
#include"DirectBullet.h"
#include"SpreadBullet.h"
#include"Shield.h"
#include"Bomb.h"
#include"Enemy2.h"
#include"Item.h"
#include"Laser.h"

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

	m_ColBox = Sprite::Create(L"Painting/Object/Player/ColiderBox.png");
	m_ColBox->m_Visible = false;

	m_CatchBox = Sprite::Create(L"Painting/Object/Player/CatchBox.png");

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
	m_DirectBasicAtk = 100.f;
	m_SpreadBasicAtk = m_DirectBasicAtk * 0.66f;
	m_Speed = 300.f;
	m_RPMIncrease = 0.f;

	m_FSkillCooldown = 0.f;
	m_SSkillCooldown = 0.f;

	m_FSkillMAXCooldown = 10.f;
	m_SSkillMAXCooldown = 25.f;
	m_CatchBox->m_Visible = false;
	m_Layer = 1;
	m_InvinTick = 0.f;

	GameMgr::GetInst()->m_PlayerShotType = SHOTTYPE::DIRECT;

	ObjMgr->AddObject(m_ColBox, "PlayerBox");
	ObjMgr->AddObject(m_CatchBox, "CatchBox");
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
	ColCheak();
	Invincibility();
	m_ColBox->m_Position = m_Position;
	m_CatchBox->SetPosition(m_Position.x,m_Position.y - m_Size.y / 2);
	if (INPUT->GetKey(VK_F1) == KeyState::DOWN)
		m_Exp += 50;
	if (INPUT->GetKey('S') == KeyState::DOWN)
		ObjMgr->AddObject(new Item(Vec2(1920 / 2, 300)), "ITEM");
	if (INPUT->GetKey('A') == KeyState::DOWN)
	{
		ObjMgr->AddObject(new Enemy2(Vec2(1920 / 2, -100)), "Enemy");
	}
}

void Player::Render()
{
	m_Player->Render();

}

void Player::OnCollision(Object* other)
{
	if (!m_PlayerInvincibility)
	{
		if (other->m_Tag == "EnemyBullet")
		{
			RECT rc;
			if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision))
			{
				float randx = (rand() % (int)m_Size.x) + m_Position.x - m_Size.x / 2;
				float randy = (rand() % (int)m_Size.y) + m_Position.y - m_Size.y / 2;
				m_HP -= other->m_Atk;
				ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
				other->SetDestroy(true);
				if (!m_PlayerInvincibility)
					m_PlayerInvincibility = true;
			}
		}
		if (other->m_Tag == "Laser")
		{
			RECT rc;
			if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision) && other->m_State == 2)
			{
				float randx = (rand() % (int)m_Size.x) + m_Position.x - m_Size.x / 2;
				float randy = (rand() % (int)m_Size.y) + m_Position.y - m_Size.y / 2;
				m_HP -= other->m_Atk;
				ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, Vec2(randx, randy)), "Effect");
				if(!m_PlayerInvincibility)
					m_PlayerInvincibility = true;
			}
		}
		if (other->m_Tag == "Enemy")
		{
			RECT rc;
			if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision) && other->m_State == 2)
			{
				m_HP -= other->m_Atk;
				ObjMgr->AddObject(new EffectMgr(L"Painting/Object/Effect/Explosion/", 1, 9, 5, m_Position), "Effect");
				other->SetDestroy(true);
				if (!m_PlayerInvincibility)
					m_PlayerInvincibility = true;
			}
		}
	}

	if (other->m_Tag == "ITEM")
	{
		if (other->m_State == 0)
		{
			if (m_HP + m_MAXHP * 0.2f >= m_MAXHP)
			{
				m_HP = m_MAXHP;
			}
			else
			{
				m_HP += m_MAXHP * 0.2f;
			}
			other->SetDestroy(true);
		}
		if (other->m_State == 1)
		{
			m_FSkillCooldown = 0.f;
			m_SSkillCooldown = 0.f;
			other->SetDestroy(true);
		}
		if (other->m_State == 2)
		{
			GameMgr::GetInst()->m_AcqExp += m_MAXExp - m_Exp;
			other->SetDestroy(true);
		}
	}
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
	if ((INPUT->GetKey(VK_SPACE) == KeyState::PRESS && (m_NowTick - m_LastFireTick) > m_FireDelay) && GameMgr::GetInst()->m_PlayerShotType == SHOTTYPE::DIRECT)
	{
		ObjMgr->AddObject(new DirectBullet(Vec2(m_Position.x - 30, m_Position.y - 20), 1000), "Bullet");
		ObjMgr->AddObject(new DirectBullet(Vec2(m_Position.x + 27, m_Position.y - 20), 1000), "Bullet");
		m_LastFireTick = m_NowTick;
	}
	if ((INPUT->GetKey(VK_SPACE) == KeyState::PRESS && (m_NowTick - m_LastFireTick) > m_FireDelay) && GameMgr::GetInst()->m_PlayerShotType == SHOTTYPE::SPREAD)
	{
		ObjMgr->AddObject(new SpreadBullet(Vec2(m_Position.x, m_Position.y - 50), 700,20,m_Atk), "Bullet");
		ObjMgr->AddObject(new SpreadBullet(Vec2(m_Position.x, m_Position.y - 50), 700,0, m_Atk), "Bullet");
		ObjMgr->AddObject(new SpreadBullet(Vec2(m_Position.x, m_Position.y - 50), 700,-20, m_Atk), "Bullet");
		m_LastFireTick = m_NowTick;
	}
}

void Player::ChangeFireMode()
{
	if (GameMgr::GetInst()->m_PlayerShotType == SHOTTYPE::DIRECT)
	{
		m_RPM = 400.f + m_RPMIncrease;
		m_Atk = m_DirectBasicAtk + m_AtkIncrease;
	}
	else if (GameMgr::GetInst()->m_PlayerShotType == SHOTTYPE::SPREAD)
	{
		m_RPM = 250.f + (m_RPMIncrease * 0.375f);
		m_Atk = m_SpreadBasicAtk + (m_AtkIncrease * 0.333f);
		
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
	GameMgr::GetInst()->m_PlayerPos = m_Position;

	if (GameMgr::GetInst()->m_AcqExp > 0)
	{
		GameMgr::GetInst()->m_AcqExp -= 1;
		m_Exp += 1;
	}
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
		ObjMgr->AddObject(new Shield(m_Position), "Shield");
		m_FSkillCooldown = m_FSkillMAXCooldown;
	}
	else if (m_FSkillCooldown > 0.f && INPUT->GetKey('X') == KeyState::DOWN)
	{
		ObjMgr->AddObject(new EffectMgr(L"Painting/UI/CooldownText/", 1, 8, 5, Vec2(1920 / 2,1080 / 2)), "Effect");
	}
	if (m_SSkillCooldown <= 0.f && INPUT->GetKey('Z') == KeyState::DOWN && m_SecendSkillAcq)
	{
		ObjMgr->AddObject(new Bomb(),"Bomb");
		m_SSkillCooldown = m_SSkillMAXCooldown;
	}
	else if (m_SSkillCooldown > 0.f && INPUT->GetKey('Z') == KeyState::DOWN)
	{
		ObjMgr->AddObject(new EffectMgr(L"Painting/UI/CooldownText/", 1, 8, 5, Vec2(1920 / 2, 1080 / 2)), "Effect");
	}
}

void Player::ColCheak()
{
	ObjMgr->CollisionCheak(this, "EnemyBullet");
	ObjMgr->CollisionCheak(this, "Enemy");
	ObjMgr->CollisionCheak(this, "ITEM");
	ObjMgr->CollisionCheak(this, "Laser");
}

void Player::Invincibility()
{
	const float InvinTime = 1.f;

	if (m_PlayerInvincibility)
	{
		m_InvinTick += dt;

		if (m_InvinTick > InvinTime)
		{
			m_InvinTick = 0.f;
			m_PlayerInvincibility = false;
		}
	}
}

void Player::LevelUP()
{
	if (m_Level == 5)
	{
		m_Exp = 0;
	}
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
