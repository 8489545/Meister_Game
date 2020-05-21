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

	SetPosition(1920 / 2, 900);

	m_Speed = 300.f;

}

void Player::Release()
{
}

void Player::Update(float deltaTime, float Time)
{
	Move();
}

void Player::Render()
{
	m_Player->Render();
}

void Player::Move()
{
	if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS)
	{
		m_Position.x += m_Speed * dt;
		m_Player = m_Right;
	}
	else if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS)
	{
		m_Position.x -= m_Speed * dt;
		m_Player = m_Left;
	}
	else
	{
		m_Player = m_Front;
	}
}
