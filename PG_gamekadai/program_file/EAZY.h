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

	int block_image[4];							//�u���b�N�摜
	int eazy_stage[EAZY_SIZE][EAZY_SIZE];		//����{�摜
	int player_stage[EAZY_SIZE][EAZY_SIZE];		//�v���C���[�p�z��
	bool answer_stage[EAZY_SIZE][EAZY_SIZE];	//��
	int frame_image;							//�r��
	int cursol_image;							//�J�[�\��
	int cursol_count_x ,cursol_count_y;			//�J�[�\���ړ�
	int standby_count;							//�L�����ԁi�t���[���j
	int game_count;								//�Q�[�����ԁi�t���[���j
	int time_limit;								//�Q�[��������
	int standby_limit;							//�L��������
	int point;									//�_��
	bool stand;									//�L�����Ԃ��ǂ���
	bool pose;									//�|�[�Y�����ǂ���
	EAZY_DIF* eazy;								//�������g������

public:
	//�R���X�g���N�^
	EAZY_DIF();
	~EAZY_DIF() {};

	//������Game_Main�Ŏg���֐���
	//���̊֐��Œl�̍X�V���s��
	AbstractScene* Update() override;
	//���̊֐��ŕ`������ׂď���
	void Draw() const override;

	//�L�����Ԋ֐�
	void Standby();
	//�N���A����
	bool ClearJudge();


	//�ϐ��Q�b�g
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

