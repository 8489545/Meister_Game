#pragma once
struct FireTick
{
	float m_FireDelay;
	float m_LastFireTick;
};
class MiddleBoss : public Object
{
	Sprite* m_Body;

	Sprite* m_LeftCannon1;
	Sprite* m_LeftCannon2;

	Sprite* m_RightCannon1;
	Sprite* m_RightCannon2;

	Sprite* m_LeftBigCannon;
	Sprite* m_RightBigCannon;

	Sprite* m_MidCannon;
	Sprite* m_MidCannon2;

	Sprite* m_MidDecor1;
	Sprite* m_MidDecor2;

	Sprite* m_LeftDecor;
	Sprite* m_RightDecor;

	Sprite* m_LeftDes1;
	Sprite* m_LeftDes2;
	Sprite* m_LeftDes3;

	Sprite* m_RightDes1;
	Sprite* m_RightDes2;
	Sprite* m_RightDes3;

	Sprite* m_MidDes1;
	Sprite* m_MidDes2;
	Sprite* m_MidDes3;

	Sprite* m_MidBossWarning;
	Sprite* m_MidBossClear;
public:
	MiddleBoss();
	~MiddleBoss();

	int m_Phase;

	float m_WarningTick;
	float m_EndTick;

	bool m_MidDecorRot;
	bool m_LeftCannon2Rot;
	bool m_RightCannon2Rot;
	bool m_MidCannon2Rot;

	bool m_isDestroy;

	FireTick* m_MidDecor1Tick;
	FireTick* m_LeftCannon1Tick;
	FireTick* m_RightCannon1Tick;

	FireTick* m_MidCannonTick;
	FireTick* m_LeftCannon2Tick;
	FireTick* m_RightCannon2Tick;

	FireTick* m_MidCannon2Tick;
	FireTick* m_LeftBigCannonTick;
	FireTick* m_RightBigCannonTick;

	FireTick* m_DestroyTick;

	void Update(float deltaTime, float Time);
	void Render();

	void Start();
	void End();

	void Phase1();
	void Phase2();
	void Phase3();

	void Destroy();


	void SetObjectsPosition();
};

