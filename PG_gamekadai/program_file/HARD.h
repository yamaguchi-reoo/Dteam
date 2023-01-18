#pragma once
#include"AbstractScene.h"
#include"SELECT.h"

#define HARD_SIZE 5
#define CURSOL_X 300
#define CURSOL_Y 200



class HARD_DIF :public AbstractScene
{
private:
	//������Game_Main�Ŏg���ϐ���

	int block_image[4];
	int cursol_x, cursol_y;
	int hard_stage[HARD_SIZE][HARD_SIZE];
	int player_stage[HARD_SIZE][HARD_SIZE];
	bool answer_stage[HARD_SIZE][HARD_SIZE];
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

public:
	//�R���X�g���N�^
	HARD_DIF();
	~HARD_DIF() {};

	//������Game_Main�Ŏg���֐���
	//���̊֐��Œl�̍X�V���s��
	AbstractScene* Update() override;
	//���̊֐��ŕ`������ׂď���
	void Draw() const override;

	void Standby();
	bool ClearJudge();

	int Get_H_Stage(int i,int j)
	{
		return hard_stage[i][j];
	}
	int Get_P_Stage(int i, int j)
	{
		return player_stage[i][j];
	}
	int Get_Point() { return point; }
};

