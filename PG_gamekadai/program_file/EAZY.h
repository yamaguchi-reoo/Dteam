#pragma once
#include"AbstractScene.h"
#include"SELECT.h"

#define EAZY_SIZE 2
#define CURSOL_X 300
#define CURSOL_Y 200



class EAZY_DIF :public AbstractScene
{
private:
	//������Game_Main�Ŏg���ϐ���

	int block_image[4];
	int cursol_x, cursol_y;
	int eazy_stage[EAZY_SIZE][EAZY_SIZE];
	int player_stage[EAZY_SIZE][EAZY_SIZE];
	int frame_image;
	int cursol_image;
	int cursol_count_x ,cursol_count_y;
	int stand_count;
	bool stand;
	bool pose;

public:
	//�R���X�g���N�^
	EAZY_DIF();
	~EAZY_DIF() {};

	//������Game_Main�Ŏg���֐���
	//���̊֐��Œl�̍X�V���s��
	AbstractScene* Update() override;
	//���̊֐��ŕ`������ׂď���
	void Draw() const override;

	void Standby();
	bool ClearJudge();
};

