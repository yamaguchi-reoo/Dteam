#pragma once
#include"AbstractScene.h"








class TITLE:public AbstractScene
{private:
	//�����Ƀ^�C�g���Ŏg���ϐ���
	int titleimage;//�^�C�g���ϐ�
	int titlearrow;//�^�C�g���J�[�\��
	int cursor_x, cursor_y;
	int cursorstate;
	int cursorend;
	int cursor_no;
	
public:
	//�����Ƀ^�C�g���Ŏg���֐���

	//�R���X�g���N�^
	//���̊֐��̒��ŏ�Ő錾�����ϐ�������������
	TITLE();

	~TITLE() {};

	//���̊֐��ɕ`��̂��ׂĂ������i�`��ȊO�͏����Ȃ��j
	void Draw() const override;

	//���̊֐����Œl�̍X�V������
	AbstractScene* Update() override;
};

