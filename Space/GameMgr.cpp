#include "stdafx.h"
#include "GameMgr.h"
#include "Player.h"
#include "UI.h"
#include"Item.h"
#include"MiddleBoss.h"

GameMgr::GameMgr()
{
}

GameMgr::~GameMgr()
{
}

void GameMgr::Init()
{
	m_CreatePlayer = false;
	m_FirstSkill = false;
	m_SecendSkill = false;
	m_ScrollingStop = false;
	m_FirstSkillCooldown = 0;
	m_SecendSkillCooldown = 0;
	m_PlayerShotType = SHOTTYPE::DIRECT;
	m_AcqExp = 0;

	SetPlayerStatus(0, 0, 0, 0, 0, 0);
}

void GameMgr::Release()
{
}

void GameMgr::CreatePlayer()
{
	ObjMgr->AddObject(new Player, "Player");
	m_CreatePlayer = true;
}

void GameMgr::CreateUI()
{
	UI::GetInst()->Init();
}

void GameMgr::ChangeFireMode()
{
	UI::GetInst()->ChangeFireMode();
}

void GameMgr::SetPlayerStatus(int level, int exp, int hp, float speed, int atk, float rpm)
{
	m_PlayerStatus = { level,exp,hp,speed,atk,rpm };
}

void GameMgr::SetLimit(float xmax, float xmin, float ymax, float ymin)
{
	XMAX = xmax;
	XMIN = xmin;
	YMAX = ymax;
	YMIN = ymin;
}

void GameMgr::SpawnItem(Vec2 Pos)
{
	ObjMgr->AddObject(new Item(Pos), "ITEM");
}

void GameMgr::SpawnMiddleBoss()
{
	ObjMgr->AddObject(new MiddleBoss(), "MiddleBoss");
}

void GameMgr::UnlockSkill()
{
	if (m_FirstSkill)
		UI::GetInst()->UnlockedFirstSkill();
	if (m_SecendSkill)
		UI::GetInst()->UnlockedSecendSkill();
}
