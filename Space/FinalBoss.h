#pragma once
class FinalBoss : public Object
{
	Sprite* m_Body;

	Sprite* m_BodyCol;
	Sprite* m_LWingCol;
	Sprite* m_RWingCol;
	Sprite* m_TailWingCol;

	Animation* m_LProp1;
	Animation* m_LProp2;
	Animation* m_LProp3;
	Animation* m_RProp1;
	Animation* m_RProp2;
	Animation* m_RProp3;

	Sprite* m_LCannon1;
	Sprite* m_LCannon2;
	Sprite* m_LCannon3;

	Sprite* m_MidCannon;

	Sprite* m_RCannon1;
	Sprite* m_RCannon2;
	Sprite* m_RCannon3;

	Sprite* m_Warning;
public:
	FinalBoss();
	~FinalBoss();

	int m_Phase;
	int m_RandomPattern;

	float m_WarningTick;

	bool m_isPatternProgress;
	
	void Start();
	void AppearMove();
	void Collision();

	void Update(float deltatime,float Time);
	void Render();
	void OnCollision(Object* other);

	void SetObjectsPosition();
};

