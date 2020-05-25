#include "stdafx.h"
#include "DirectBullet.h"

DirectBullet::DirectBullet(Vec2 Pos, float Speed)
{
	m_Bullet = Sprite::Create(L"Painting/Object/Bullet/Direct.png");
	m_Bullet->SetParent(this);

	m_Position = Pos;
	m_Speed = Speed;
}

DirectBullet::~DirectBullet()
{
}

void DirectBullet::Update(float delatTime, float Time)
{
	m_Position.y -= m_Speed * dt;

	if (m_Position.y <= -100.f)
	{
      	SetDestroy(true);
	}
}

void DirectBullet::Render()
{
	m_Bullet->Render();
}
