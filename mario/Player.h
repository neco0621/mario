#pragma once
#include "Vec2.h"

class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

	//�����o�ϐ��ɃA�N�Z�X����
	void SetHandle(int handle) { m_handle = handle; }
	//�v���C���[�̌��݈ʒu���擾����
	Vec2 GetPos() const { return m_pos; }

public:
	//�����Ă����
	enum Dir
	{
		kDirDown,   //��
		kDirLeft,   //��
		kDirRight,   //�E
		kDirUp,     //��
	};

private:
	int m_handle;   //�O���t�B�b�N�̃n���h��
	//�\���ʒu
	Vec2 m_pos;
	//�����Ă������
	Dir m_dir;
	//�����A�j���[�V����
	int m_warkAnimFrame;
	int m_warkAnimCount;
};

