#pragma once
#include"AbstractScene.h"
class HELP : public AbstractScene
{
private:
	int help_image;
	//�����Ƀ^�C�g���Ŏg���ϐ���

public:
	//�����Ƀ^�C�g���Ŏg���֐���

	//�R���X�g���N�^
	//���̊֐��̒��ŏ�Ő錾�����ϐ�������������
	HELP();

	~HELP() {

	};

	//���̊֐��ɕ`��̂��ׂĂ������i�`��ȊO�͏����Ȃ��j
	void Draw() const override;

	//���̊֐����Œl�̍X�V������
	AbstractScene* Update() override;



};

