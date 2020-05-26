#include "stdafx.h"
#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Init()
{
	m_DirectFire = Sprite::Create(L"Painting/UI/Direct.png");
	m_SpreadFire = Sprite::Create(L"Painting/UI/Spread.png");

	m_UIFirstLock = Sprite::Create(L"Painting/UI/LockedSkill.png");
	m_UISecendLock = Sprite::Create(L"Painting/UI/LockedSkill.png");

	m_UIFirstSkill = Sprite::Create(L"Painting/UI/BombSkill.png");
	m_UISecendSkill = Sprite::Create(L"Painting/UI/ShieldSkill.png");

	m_DirectFire->m_Layer = 2;
	m_SpreadFire->m_Layer = 2;

	m_DirectFire->SetPosition(300, 900);
	m_SpreadFire->SetPosition(300, 900);

	m_UIFirstLock->SetPosition(1500, 900);
	m_UISecendLock->SetPosition(1650, 900);

	m_UIFirstSkill->SetPosition(1500, 900);
	m_UISecendSkill->SetPosition(1650, 900);

	m_UIFire = m_DirectFire;
	m_UIFire->SetPosition(300, 900);

	m_UIText = new TextMgr();
	m_UIText->Init(32, true, false, "Arial");
	m_UIText->SetColor(255, 255, 255, 255);

	ObjMgr->AddObject(m_UIFirstSkill, "UI");
	ObjMgr->AddObject(m_UISecendSkill, "UI");
	ObjMgr->AddObject(m_UIFirstLock, "UI");
	ObjMgr->AddObject(m_UISecendLock, "UI");
}

void UI::Release()
{
}

void UI::Update()
{
}

void UI::Render()
{
	m_UIFire->Render();
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_UIText->print("HP : " + std::to_string(GameMgr::GetInst()->m_PlayerStatus.m_HP) + " \n" + 
					"ATK : " + std::to_string(GameMgr::GetInst()->m_PlayerStatus.m_Atk) + " \n" +
					"LEVEL : " + std::to_string(GameMgr::GetInst()->m_PlayerStatus.m_Level) + " \n" + 
					"RPM : " + std::to_string(GameMgr::GetInst()->m_PlayerStatus.m_RPM) + " \n" +
					"SPEED : " + std::to_string(GameMgr::GetInst()->m_PlayerStatus.m_Speed) + " \n", 0, 0);
	Renderer::GetInst()->GetSprite()->End();
}

void UI::ChangeFireMode()
{
	if (m_UIFire == m_DirectFire)
	{
		m_UIFire = m_SpreadFire;
	}
	else if (m_UIFire == m_SpreadFire)
	{
		m_UIFire = m_DirectFire;
	}
}

void UI::UnlockedFirstSkill()
{
	m_UIFirstLock->SetDestroy(true);
}

void UI::UnlockedSecendSkill()
{
	m_UISecendSkill->SetDestroy(true);
}
