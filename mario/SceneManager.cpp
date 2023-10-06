#include "SceneManager.h"
#include "Scene.h"

SceneManager::~SceneManager()
{
	delete scene_;
}

void SceneManager::Update(Input& input)
{
	scene_->Update(input);
}

void SceneManager::Draw()
{
	scene_->Draw();
}

void SceneManager::ChangeScene(Scene* nextScene)
{
	//これだけだとまずい→入れ替える前のシーンが管理できない
	// ↓
	//scene_ = nextScene;


	if (scene_ != nullptr)
	{
		//前のシーンがあったら
		//解放しておく
		delete scene_;
	}
	scene_ = nextScene;
}
