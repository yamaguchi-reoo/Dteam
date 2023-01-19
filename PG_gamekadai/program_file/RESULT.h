#pragma once
#include "AbstractScene.h"
#include "EAZY.h"
#include "NORMAL.h"
#include "HARD.h"
class RESULT : public AbstractScene
{
private:
	EAZY_DIF* easy;			//�C�[�W�[������
	NORMAL_DIF* normal;		//�m�[�}��������
	HARD_DIF* hard;			//�n�[�h������

	int point;				//�_��
	int h_stage[HARD_SIZE][HARD_SIZE];			//�n�[�h�X�e�[�W�ϐ�
	int h_p_stage[HARD_SIZE][HARD_SIZE];		//�n�[�h�̃v���C���[�̉�
	int n_stage[NORMAL_SIZE][NORMAL_SIZE];		//�m�[�}���X�e�[�W�ϐ�
	int n_p_stage[NORMAL_SIZE][NORMAL_SIZE];	//�m�[�}���̃v���C���[�̉�
	int e_stage[EAZY_SIZE][EAZY_SIZE];			//�C�[�W�[�X�e�[�W�ϐ�
	int e_p_stage[EAZY_SIZE][EAZY_SIZE];		//�C�[�W�[�̃v���C���[�̉�
	int image[5];								//�u���b�N�摜
	int frame_image[3];							//�e��Փx�̌r��


	int zibun_image;
	int kotae_image;
	int botan_image;
public:
	//�e��Փx�̃R���X�g���N�^
	RESULT();
	RESULT(EAZY_DIF*);
	RESULT(NORMAL_DIF*);
	RESULT(HARD_DIF*);
	~RESULT() {};

	AbstractScene* Update() override;
	void Draw() const override;
};

