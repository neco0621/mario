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
	//���ꂾ�����Ƃ܂���������ւ���O�̃V�[�����Ǘ��ł��Ȃ�
	// ��
	//scene_ = nextScene;


	if (scene_ != nullptr)
	{
		//�O�̃V�[������������
		//������Ă���
		delete scene_;
	}
	scene_ = nextScene;
}
