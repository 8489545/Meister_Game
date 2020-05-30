#pragma once
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
public:
	MiddleBoss();
	~MiddleBoss();

	int m_Phase;

	void Update(float deltaTime, float Time);
	void Render();

	void Phase1();


	void SetObjectsPosition();
};

