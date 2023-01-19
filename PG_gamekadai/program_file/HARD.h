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

	int block_image[4];							//�u���b�N�摜�p�ϐ�
	int hard_stage[HARD_SIZE][HARD_SIZE];		//����{�摜�p�ϐ�
	int player_stage[HARD_SIZE][HARD_SIZE];		//�v���C���[���͗p�ϐ�
	bool answer_stage[HARD_SIZE][HARD_SIZE];	//�̓_�p�z��
	int frame_image;							//�r���摜�p�ϐ�
	int cursol_image;							//�J�[�\���摜�p�ϐ�
	int cursol_count_x, cursol_count_y;			//�J�[�\���ړ��p�ϐ�
	int standby_count;							//�L�����ԗp�t���[����
	int game_count;								//�Q�[�����ԗp�t���[����
	int time_limit;								//�Q�[�������ԕϐ�
	int standby_limit;							//�L�������ԕϐ�
	int point;									//�_��
	bool stand;									//�L�����Ԃ��ǂ���
	bool pose;									//��ʂ��~�߂Ă��邩�ǂ���

public:
	//�R���X�g���N�^
	HARD_DIF();
	//�f�X�g���N�^
	~HARD_DIF() {};

	//������Game_Main�Ŏg���֐���
	//���̊֐��Œl�̍X�V���s��
	AbstractScene* Update() override;
	//���̊֐��ŕ`������ׂď���
	void Draw() const override;

	//�L�����ԗp�֐�
	void Standby();
	//�N���A����p�֐�
	bool ClearJudge();

	//�ϐ����Q�b�g����֐�����
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

