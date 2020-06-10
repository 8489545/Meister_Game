#pragma once
class GameScreen2 : public Scene
{
	Sprite* m_GameScreen1;
	Sprite* m_GameScreen2;

	Sprite* m_RBox;
	Sprite* m_LBox;
public:
	GameScreen2();
	~GameScreen2();

	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
};

