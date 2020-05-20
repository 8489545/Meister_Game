#include "stdafx.h"
#include "MainScene.h"
#include"GameScreen.h"

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

void MainScene::Init()
{
	m_Text = new TextMgr();
	m_Text->Init(32, true, false, "Arial");
	m_Text->SetColor(255, 255, 255, 255);

	m_BG = Sprite::Create(L"Painting/MainScreen/Main.png");
	m_BG->SetPosition(1920 / 2, 1080 / 2);

	m_Title = Sprite::Create(L"Painting/MainScreen/Title.png");
	m_Title->SetPosition(500, 300);

	m_Start = Sprite::Create(L"Painting/MainScreen/Start.png");
	m_Start->SetPosition(1629, 427);

	m_Ranking = Sprite::Create(L"Painting/MainScreen/Ranking.png");
	m_Ranking->SetPosition(1629, 627);

	m_Exit = Sprite::Create(L"Painting/MainScreen/Exit.png");
	m_Exit->SetPosition(1629,827);
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{

	if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Start) && INPUT->GetButtonDown())
	{
		SceneDirector::GetInst()->ChangeScene(new GameScreen());
		INPUT->ButtonDown(false);
	}
	else if (CollisionMgr::GetInst()->MouseWithBoxSize(m_Exit) && INPUT->GetButtonDown())
	{
		INPUT->ButtonDown(false);
		exit(0);
	}
	
}

void MainScene::Render()
{
	m_BG->Render();
	m_Title->Render();
	m_Start->Render();
	m_Ranking->Render();
	m_Exit->Render();


	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + " " + std::to_string(INPUT->GetMousePos().y) + " \n" +
		std::to_string(dt) + " " +std::to_string(gt) , 0, 0);
	Renderer::GetInst()->GetSprite()->End();
}
