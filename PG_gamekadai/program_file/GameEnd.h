#pragma once
#include"AbstractScene.h"
class GameEnd : AbstractScene
{
private:
	//������GAME�G���h�Ŏg���ϐ���
	int endy = 0;
	int endtime = 0;

	int EndImg;


public:
	//������GAME�G���h�Ŏg���֐���

	//�R���X�g���N�^
	//���̒��Ő錾�����ϐ�������������
	GameEnd();
	~GameEnd(){};

	//������GameEnd�Ŏg���ϐ��̒l���X�V����


	AbstractScene* Update() override;
	//�����ŕ`������ׂď���
	void Draw() const override;


};

