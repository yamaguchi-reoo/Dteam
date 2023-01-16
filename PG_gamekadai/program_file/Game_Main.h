#pragma once
#include"AbstractScene.h"
#include"COLOR.h"
#include"SELECT.h"



class GameMain:public AbstractScene
{
private:
	//������Game_Main�Ŏg���ϐ���

	int time;
	int cursol_x, cursol_y;
	COLOR* color;
	DIFFICULTY select;


public:
	//�R���X�g���N�^
	GameMain();
	GameMain(DIFFICULTY);
	~GameMain() {};


	//������Game_Main�Ŏg���֐���
	//���̊֐��Œl�̍X�V���s��
	AbstractScene* Update() override;
	//���̊֐��ŕ`������ׂď���
	void Draw() const override;
};

