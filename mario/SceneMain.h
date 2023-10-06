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
	//�O���t�B�b�N�n���h��
	int m_playerHandle;

	//�v���C���[
	Player* m_pPlayer;
};

