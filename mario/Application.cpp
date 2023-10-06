#include "Application.h"
#include <DxLib.h>
#include <assert.h>

void Application::Terminate()
{
	//DxLibの終了処理
	DxLib_End();
}

bool Application::Init()
{
	//ウィンドウモードにします
	ChangeWindowMode(true);
	SetWindowText(L"mario");
	if (DxLib_Init() == -1)
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}

void Application::Run()
{
	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();
		ScreenFlip();
	}
	Terminate();
}
