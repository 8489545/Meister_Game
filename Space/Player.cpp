#include "stdafx.h"
#include "Player.h"

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

	m_Player = m_Front;
	m_Player->SetParent(this);

	m_Player->SetPosition(1920 / 2, 900);

}

void Player::Release()
{
}

void Player::Update(float deltaTime, float Time)
{
	int i = 0;
}

void Player::Render()
{
	m_Player->Render();
}
