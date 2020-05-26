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

	m_DirectFire->SetPosition(300, 900);
	m_SpreadFire->SetPosition(300, 900);

	m_UIFire = m_DirectFire;
	m_UIFire->SetPosition(300, 900);

	m_UIText = new TextMgr();
	m_UIText->Init(32, true, false, "Arial");
	m_UIText->SetColor(255, 255, 255, 255);
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
