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
	
	FireTick* m_LCannon1Tick;
	FireTick* m_LCannon2Tick;
	FireTick* m_LCannon3Tick;
	FireTick* m_MidCannonTick;
	FireTick* m_RCannon1Tick;
	FireTick* m_RCannon2Tick;
	FireTick* m_RCannon3Tick;

	int m_Phase;
	int m_RandomPattern;

	float m_WarningTick;
	float m_PatternChangeTick;
	float m_MoveTime;
	float m_Speed;

	bool m_isPatternProgress;

	Vec2 m_RandPos;
	
	void Start();
	void AppearMove();
	void Pattern1();
	void Pattern2();
	void Pattern3();
	void Collision();
	void End();

	void SetCannonRot();

	void Update(float deltatime,float Time);
	void Render();
	void OnCollision(Object* other);

	float GetVec2Angle(Vec2 A, Vec2 B);
	void Shot(FireTick *fire, Vec2 Pos, float atk, float speed, float angle, bool isrand, int randrange, bool playerguidance,std::wstring filename = L"EnemyBullet");
	void SetObjectsPosition();
};

