#pragma once
#include"AbstractScene.h"
#include"SELECT.h"

#define NORMAL_SIZE 4
#define CURSOL_X 300
#define CURSOL_Y 200



class NORMAL_DIF :public AbstractScene
{
private:
	//������Game_Main�Ŏg���ϐ���

	int block_image[4];
	int cursol_x, cursol_y;
	int normal_stage[NORMAL_SIZE][NORMAL_SIZE];
	int player_stage[NORMAL_SIZE][NORMAL_SIZE];
	bool answer_stage[NORMAL_SIZE][NORMAL_SIZE];
	int frame_image;
	int cursol_image;
	int cursol_count_x, cursol_count_y;
	int standby_count;
	int game_count;
	int time_limit;
	int standby_limit;
	int point;
	bool stand;
	bool pose;

	int Nflame_x;
	int Nflame_y;

	int mozi_image;
	int kakunin_image;

public:
	//�R���X�g���N�^
	NORMAL_DIF();
	~NORMAL_DIF() {};

	//������Game_Main�Ŏg���֐���
	//���̊֐��Œl�̍X�V���s��
	AbstractScene* Update() override;
	//���̊֐��ŕ`������ׂď���
	void Draw() const override;

	void Standby();
	bool ClearJudge();


	//�ϐ��̒��g���Q�b�g����֐�
	int Get_N_Stage(int i, int j)
	{
		return normal_stage[i][j];
	}
	int Get_P_Stage(int i, int j)
	{
		return player_stage[i][j];
	}

	int Get_Point() { return point; }
};

