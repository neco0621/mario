#include "Player.h"
#include "game.h"
#include <DxLib.h>
#include <cmath>

namespace
{
	//�ړ����x
	constexpr float kSpeed = 3.0f;

	//�L�����N�^�[�̃T�C�Y
	constexpr int kWidth = 32;
	constexpr int kHeight = 32;

	//�L�����N�^�[�̃A�j���[�V����
	constexpr int kUseFrame[] = { 0,1,2,1 };
	//�L�����N�^�[�P�R�}�̃t���[����
	constexpr int kAnimFrameNum = 8;
	//�A�j���[�V�����P�T�C�N���̃t���[����
	constexpr int kAnimFrameCycle = _countof(kUseFrame) * kAnimFrameNum;
}

Player::Player() :
	m_handle(-1),
	m_pos(Game::kScreenWidth / 2, Game::kScreenHeight / 2),
	m_dir(kDirDown)
{
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
	//�p�b�h�̏\���L�[���g�p���ăv���C���[���ړ�������
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	bool isMove = false;   //�ړ������ǂ���
	//�ړ��ʂ����悤�ɂ���
	Vec2 move{ 0.0f, 0.0f };

	if (pad & PAD_INPUT_UP)
	{
		//m_pos.y -= kSpeed;
		move.y -= kSpeed;
		m_dir = kDirUp;
		isMove = true;
	}
	if (pad & PAD_INPUT_DOWN)
	{
		//m_pos.y += kSpeed;
		move.y += kSpeed;
		m_dir = kDirDown;
		isMove = true;
	}
	if (pad & PAD_INPUT_LEFT)
	{
		//m_pos.x -= kSpeed;
		move.x -= kSpeed;
		m_dir = kDirLeft;
		isMove = true;
	}
	if (pad & PAD_INPUT_RIGHT)
	{
		//m_pos.x += kSpeed;
		move.x += kSpeed;
		m_dir = kDirRight;
		isMove = true;
	}

	//�΂߈ړ��̏ꍇ�ł����������ňړ�����悤�ɂ���
	//�x�N�g���̐��K�����s�����߂Ƀx�N�g���̒��������߂�
	float moveLength = move.length();

	//moveLength(�x�N�g���̒���)��0.0�ɂȂ�\��������	
	if (moveLength > 0.0f)
	{
		//�΂߈ړ��̏ꍇ�����������ňړ�����悤�ɂ���
		//�x�N�g���̐��K��
		move.normalize();
		//�x�N�g���̒�����kSpeed�ɂ���
		//move.x *= kSpeed;
		//move.y *= kSpeed;
		move *= kSpeed;

		//���W�ƃx�N�g���̑����Z
		//m_pos.x += move.x;
		//m_pos.y += move.y;
		m_pos += move;
	}
}

void Player::Draw()
{
	int animFrame = m_warkAnimFrame / kAnimFrameNum;

	int srcX = kUseFrame[animFrame] * kWidth;
	int srcY = kHeight * m_dir;

	DrawRectGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		srcX, srcY, kWidth, kHeight, m_handle, true);
}
