#pragma once
#include "Scene.h"

#include <vector>

class Player;
class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	void Init();
	void End();
	void Update();
	void Draw();

private:
	//グラフィックハンドル
	int m_playerHandle;

	//プレイヤー
	Player* m_pPlayer;
};

