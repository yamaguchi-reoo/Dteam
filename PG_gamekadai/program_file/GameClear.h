#pragma once
#include"CONTROLER.h"
#include"AbstractScene.h"
class GameClear:public AbstractScene
{
private:
	//�����ɃQ�[���N���A�Ŏg���ϐ���
public:
	//�����ɃQ�[���N���A�Ŏg���֐���

	//�R���X�g���N�^
	//���̒��ŏ�Ő錾�����ϐ�������������
	GameClear();
	//���̒��ō�������̂�����
	~GameClear();


	//������GameClear�Ŏg���ϐ��̒l�̍X�V������
	AbstractScene* Update() override;
	//������GameClear�̕`��̂��ׂĂ�����
	void Draw() const override;
};

