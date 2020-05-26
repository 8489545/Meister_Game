#include "stdafx.h"
#include "GameMgr.h"
#include "Player.h"
#include "UI.h"

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
	m_PlayerShotType = SHOTTYPE::DIRECT;
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

void GameMgr::UnlockSkill()
{
	if (m_FirstSkill)
		UI::GetInst()->UnlockedFirstSkill();
	if (m_SecendSkill)
		UI::GetInst()->UnlockedSecendSkill();
}
