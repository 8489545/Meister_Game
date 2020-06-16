#pragma once
class RankScene : public Scene
{
public:
	RankScene();
	~RankScene();

	std::string name;

	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
};

