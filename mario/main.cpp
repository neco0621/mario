#include "Application.h"
#include <DxLib.h>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Application& application = Application::GetInstance();

	//�_���ȗ�
	//��
	//Application application2 = Application::GetInstance();

	//���͕\�������`���ɂ͂Q���̃X�N���[��������܂�
	//����������Ńt���b�v(����ւ���)���s�����Ƃ�
	// ��ʂ̂�������Ȃ����Ă��܂�
	// SetDrawScreen���̊֐���DXLib_Init()�̌�łȂ���
	// �L���ł͂Ȃ����ߒ��ӂ��Ă�������
	if (!application.Init())
	{
		return -1;
	}
	application.Run();

	return 0;				// �\�t�g�̏I�� 
}