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

	m_Position.y += m_Laser->m_Size.y / 2;

	m_LaserDuration = laserDuration;
	m_Atk = atk;
	m_LaserAppearTime = appearTime;
	m_SizeSpeed = sizeSpeed;

	m_LaserAppeared = false;

	printf("%f \n", m_Position.x);
}

Laser::~Laser()
{
}

void Laser::Update(float deltaTime, float Time)
{
	m_NowTime+=dt;
	if(!m_LaserAppeared)
	{
		m_State=1;
		if(m_NowTime>=m_LaserAppearTime)
		{
			m_LaserAppeared=true;
		}
	}
	else if(m_LaserAppeared)
	{
		m_State = 2;
		m_Scale.x += m_SizeSpeed * dt;
		if (m_Laser->A < 255)
		{
			m_Laser->A+=5;

			if (m_Laser->A + 5 > 255)
			{
				m_Laser->A = 255;
			}
		}
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
