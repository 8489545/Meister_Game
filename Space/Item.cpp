#include "stdafx.h"
#include "Item.h"

Item::Item(Vec2 Pos)
{
	m_Heal = Sprite::Create(L"Painting/Object/Item/Heal.png");
	m_Heal->SetParent(this);

	m_Cooldown = Sprite::Create(L"Painting/Object/Item/Cooldown.png");
	m_Cooldown->SetParent(this);

	m_LevelUp = Sprite::Create(L"Painting/Object/Item/LevelUp.png");
	m_LevelUp->SetParent(this);
	
	int randitem = rand() % 3;

	printf("%d", randitem);

	if(randitem == 0)
		m_Item = m_Heal;
	else if (randitem == 1)
		m_Item = m_Cooldown;
	else if (randitem == 2)
		m_Item = m_LevelUp;

	m_Item->SetParent(this);

	m_Position = Pos;
}

Item::~Item()
{
}

void Item::Update(float deltaTime, float Time)
{
	m_Position.y += 200 * dt;
}

void Item::Render()
{
	m_Item->Render();
}

void Item::OnCollision(Object* other)
{
}
