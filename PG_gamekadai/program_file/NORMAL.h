#pragma once
#include"AbstractScene.h"
#include"COLOR.h"
#include"SELECT.h"

#define NORMAL_SIZE 4


class NORMAL_DIF :public AbstractScene
{
private:
	//������Game_Main�Ŏg���ϐ���

	int block_image[4];
	int cursol_x, cursol_y;
	int normal_stage[6][6];


public:
	//�R���X�g���N�^
	NORMAL_DIF();
	~NORMAL_DIF() {};


	//������Game_Main�Ŏg���֐���
	//���̊֐��Œl�̍X�V���s��
	AbstractScene* Update() override;
	//���̊֐��ŕ`������ׂď���
	void Draw() const override;
};

