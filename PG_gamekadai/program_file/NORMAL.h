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

	int block_image[4];                             //�u���b�N�摜�p�ϐ�
	int normal_stage[NORMAL_SIZE][NORMAL_SIZE];     //����{�p�z��
	int player_stage[NORMAL_SIZE][NORMAL_SIZE];     //�v���C���[�����ۂɓ��͂���ϐ�
	bool answer_stage[NORMAL_SIZE][NORMAL_SIZE];    //�𓚗p�ϐ�
	int frame_image;                                //�r���摜�p�ϐ�
	int cursol_image;                               //�J�[�\���摜�p�ϐ�
	int cursol_count_x, cursol_count_y;             //�J�[�\���p�ϐ�
	int standby_count;                              //����{�����鎞�Ԃ��t���[���P�ʂŐ�����ϐ�
	int game_count;                                 //�Q�[�����Ԃ��t���[���P�ʂŐ�����ϐ�
	int time_limit;                                 //�����Ԃ̃^�C�����~�b�g�p�ϐ�
	int standby_limit;                              //����{�p�̎����Ԃ̃^�C�����~�b�g�p�ϐ�
	int point;                                      //�_���p�ϐ�
	bool stand;                                     //�X�^���o�C���I���������ǂ����̕ϐ�
	bool pose;                                      //�Q�[�����~�߂Ă��邩�ǂ����̕ϐ�

	int Nflame_x;
	int Nflame_y;

	int mozi_image;
	int kakunin_image;
	int timeer_image;

public:
	//�R���X�g���N�^
	NORMAL_DIF();
	//�f�X�g���N�^
	~NORMAL_DIF() {};

	//������Game_Main�Ŏg���֐���
	//���̊֐��Œl�̍X�V���s��
	AbstractScene* Update() override;
	//���̊֐��ŕ`������ׂď���
	void Draw() const override;

	//�摜���o�����ʂ̊֐�
	void Standby();
	
	//�_���𐔂��ăN���A���ǂ������肷��ϐ�
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

