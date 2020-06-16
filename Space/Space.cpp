#include"stdafx.h"
#include"MainScene.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#if _DEBUG
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "wt", stdout);

#endif
	App::GetInst()->Init(1920, 1080, 0);
	GameMgr::GetInst()->Init();
	GameMgr::GetInst()->RankInit();
	SceneDirector::GetInst()->ChangeScene(new MainScene());
	App::GetInst()->Run();
	return 0;
}