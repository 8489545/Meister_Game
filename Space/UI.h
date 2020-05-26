#pragma once
class UI : public Singleton<UI>
{
	Sprite* m_DirectFire;
	Sprite* m_SpreadFire;

	Sprite* m_UIFirstLock;
	Sprite* m_UISecendLock;

	Sprite* m_UIFirstSkill;
	Sprite* m_UISecendSkill;
	Sprite* m_UIFire;

	Sprite* m_UIFirstSkillCooldown;
	Sprite* m_UISecendSkillCooldown;

	TextMgr* m_UIText;
public:
	UI();
	~UI();
	void Init();
	void Release();

	float m_FSkillGage;
	float m_SSkillGage;

	void Update();
	void Render();

	void ChangeFireMode();
	void UnlockedFirstSkill();
	void UnlockedSecendSkill();
};

