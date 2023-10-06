#include "SceneMain.h"
#include <DxLib.h>
#include "Player.h"

#include <cassert>

namespace
{

}

SceneMain::SceneMain()
{
	//グラフィックのロード
	m_playerHandle = LoadGraph("data/Player.png");
	assert(m_playerHandle != -1);

	//プレイヤーのメモリ確保
	m_pPlayer = new Player;
	m_pPlayer->SetHandle(m_playerHandle);   //Playerにグラフィックのハンドルを渡す
}

SceneMain::~SceneMain()
{
	//メモリからグラフィックを削除
	DeleteGraph(m_playerHandle);

	//メモリの解放
	delete m_pPlayer;
	m_pPlayer = nullptr;
}

void SceneMain::Init()
{
	assert(m_pPlayer);   // m_pPlayer == nullptrの場合止まる

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
