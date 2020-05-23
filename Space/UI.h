#pragma once
class UI : public Singleton<UI>
{
	Sprite* m_DirectFire;
	Sprite* m_SpreadFire;

	Sprite* m_UIFire;
public:
	UI();
	~UI();
	void Init();
	void Release();

	void Update();
	void Render();

	void ChangeFireMode();
};

