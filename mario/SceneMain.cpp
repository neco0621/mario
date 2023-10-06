#include "SceneMain.h"
#include <DxLib.h>
#include "Player.h"

#include <cassert>

namespace
{

}

SceneMain::SceneMain()
{
	//�O���t�B�b�N�̃��[�h
	m_playerHandle = LoadGraph("data/Player.png");
	assert(m_playerHandle != -1);

	//�v���C���[�̃������m��
	m_pPlayer = new Player;
	m_pPlayer->SetHandle(m_playerHandle);   //Player�ɃO���t�B�b�N�̃n���h����n��
}

SceneMain::~SceneMain()
{
	//����������O���t�B�b�N���폜
	DeleteGraph(m_playerHandle);

	//�������̉��
	delete m_pPlayer;
	m_pPlayer = nullptr;
}

void SceneMain::Init()
{
	assert(m_pPlayer);   // m_pPlayer == nullptr�̏ꍇ�~�܂�

	m_pPlayer->Init();
}

void SceneMain::End()
{
}

void SceneMain::Update()
{
	m_pPlayer->Update();
}

void SceneMain::Draw()
{
	m_pPlayer->Draw();
}
