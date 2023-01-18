#pragma once
#include"AbstractScene.h"
#include"SELECT.h"

#define EAZY_SIZE 3
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
	bool answer_stage[EAZY_SIZE][EAZY_SIZE];
	int frame_image;
	int cursol_image;
	int cursol_count_x ,cursol_count_y;
	int standby_count;
	int game_count;
	int time_limit;
	int standby_limit;
	int point;
	bool stand;
	bool pose;
	EAZY_DIF* eazy;

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

	int Get_E_Stage(int i, int j)
	{
		return eazy_stage[i][j];
	}
	int Get_P_Stage(int i, int j)
	{
		return player_stage[i][j];
	}
	int Get_Point() { return point; }
};

