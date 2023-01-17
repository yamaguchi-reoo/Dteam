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
	int eazy_stage[4][4];
	int normal_stage[6][6];
	int hard_stage[8][8];
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

