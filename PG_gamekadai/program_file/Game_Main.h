#pragma once
#include"AbstractScene.h"
class GameMain:public AbstractScene
{
private:
	//������Game_Main�Ŏg���ϐ���

public:
	//�R���X�g���N�^
	GameMain();
	~GameMain();


	//������Game_Main�Ŏg���֐���
	//���̊֐��Œl�̍X�V���s��
	AbstractScene* Update() override;
	//���̊֐��ŕ`������ׂď���
	void Draw() const override;
};

