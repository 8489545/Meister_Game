#include "stdafx.h"
#include "Laser.h"

Laser::Laser(Vec2 Pos, float laserDuration, float atk, float appearTime,float sizeSpeed)
{
	m_Laser = Sprite::Create(L"Painting/Object/Bullet/Laser/Laser.png");
	m_Laser->SetParent(this);
	
	m_Laser->A = 128;
	m_Laser->R = 0;
	m_Laser->G = 0;
	m_Laser->B = 0;

	m_Position = Pos;

	m_LaserDuration = laserDuration;
	m_Atk = atk;
	m_LaserAppearTime = appearTime;
	m_SizeSpeed = sizeSpeed;

	m_LaserAppeared = false;
}

Laser::~Laser()
{
}

void Laser::Update(float deltaTime, float Time)
{
	m_NowTime += dt;
	if (!m_LaserAppeared)
	{
		if (m_NowTime >= m_LaserAppearTime)
		{
			m_LaserAppeared = true;
		}
	}
	else if (m_LaserAppeared)
	{
		m_Scale.x += m_SizeSpeed * dt;
		m_Laser->A = 255;
		m_Laser->R = 255;
		m_Laser->G = 255;
		m_Laser->B = 255;
		if (m_NowTime >= m_LaserDuration)
		{
			SetDestroy(this);
		}
	}
}

void Laser::Render()
{
	m_Laser->Render();
}

void Laser::OnCollision(Object* other)
{
}
