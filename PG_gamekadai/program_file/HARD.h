#pragma once
#include"AbstractScene.h"
#include"COLOR.h"
#include"SELECT.h"

#define HARD_SIZE 6

class HARD_DIF :public AbstractScene
{
private:
	//������Game_Main�Ŏg���ϐ���

	int block_image[4];
	int cursol_x, cursol_y;
	int hard_stage[HARD_SIZE][HARD_SIZE];


public:
	//�R���X�g���N�^
	HARD_DIF();
	~HARD_DIF() {};


	//������Game_Main�Ŏg���֐���
	//���̊֐��Œl�̍X�V���s��
	AbstractScene* Update() override;
	//���̊֐��ŕ`������ׂď���
	void Draw() const override;
};
