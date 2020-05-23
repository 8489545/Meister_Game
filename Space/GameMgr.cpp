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

void GameMgr::SetLimit(float xmax, float xmin, float ymax, float ymin)
{
	XMAX = xmax;
	XMIN = xmin;
	YMAX = ymax;
	YMIN = ymin;
}
