#pragma once


class Input;
class SceneManager;
/// <summary>
/// �V�[�����N���X
/// �����ȃV�[���̊�ɂȂ�N���X
/// </summary>
class Scene
{
protected:
	//���������O����SceneManager��m���Ă��邱�Ƃɂ���
	SceneManager& manager_;
public:
	/// <summary>
	/// ��������SceneManager�̎Q�Ƃ��󂯎���Ă���
	/// </summary>
	/// <param name="manager">SCeneManeger�̎Q��</param>
	Scene(SceneManager& manager);

	/// <summary>
	/// �V�[���̍X�V
	/// </summary>
	/// <param name="input">���̓I�u�W�F�N�g</param>
	virtual void Update(Input& input) = 0;

	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	virtual void Draw() = 0;

};

