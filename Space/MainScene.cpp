#include "stdafx.h"
#include "MainScene.h"

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
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
}

void MainScene::Render()
{
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + " " + std::to_string(INPUT->GetMousePos().y) + " \n" +
		std::to_string(dt) + " " +std::to_string(gt) , 0, 0);
	Renderer::GetInst()->GetSprite()->End();
}
