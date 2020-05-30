#pragma once
class Item : public Object
{
	Sprite* m_Heal;
	Sprite* m_Cooldown;
	Sprite* m_LevelUp;

	Sprite* m_Item;
public:
	Item(Vec2 Pos);
	~Item();

	void Update(float deltaTime, float Time);
	void Render();
	void OnCollision(Object* other);
};

