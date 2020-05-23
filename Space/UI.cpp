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
