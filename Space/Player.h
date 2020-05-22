#pragma once
class Player : public Object
{
	Sprite* m_Player;

	Sprite* m_Front;
	Sprite* m_Left;
	Sprite* m_Right;
	Sprite* m_Propel;
public:
	Player();
	~Player();

	float m_Speed;

	void Init();
	void Release();

	void Update(float delatTime, float Time);
	void Render();

	void Move();
};

