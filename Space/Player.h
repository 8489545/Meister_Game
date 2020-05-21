#pragma once
class Player : public Object
{
	Sprite* m_Player;

	Sprite* m_Front;
	Sprite* m_Left;
	Sprite* m_Right;
public:
	Player();
	~Player();

	void Init();
	void Release();

	void Update(float delatTime, float Time);
	void Render();
};

