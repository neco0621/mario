#include "Input.h"
#include <DxLib.h>

void Input::Update()
{
	//�O�̃t���[���̏�����
	lastKeyState_ = keyState_;
	//���݂̓�������擾
	GetHitKeyStateAll(keyState_.data());
}

bool Input::IsTriggered(const char* command) const
{
	return !lastKeyState_[KEY_INPUT_RETURN] && keyState_[KEY_INPUT_RETURN];
}