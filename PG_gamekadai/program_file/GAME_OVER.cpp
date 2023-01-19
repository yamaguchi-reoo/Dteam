#include "GAME_OVER.h"
#include"dxlib.h"
#include"AbstractScene.h"
#include"title.h"
#include"CONTROLER.h"
#include<math.h>

GAME_OVER::GAME_OVER()
{
	// �Q�[���I�[�o�[�摜�ǂݍ���
	gameoverimg = LoadGraph("images/gameover.png",FALSE);

	count = 0;
	blink = 60;
}

AbstractScene* GAME_OVER::Update() 
{
	++count; // �J�E���g���Z

	// B�{�^���Ń��j���[�֑J��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return new TITLE();
	}
	return this;
}

void GAME_OVER::Draw() const
{
	DrawGraph(0, 0, gameoverimg, TRUE);

	// �����̓_��
	if (count & blink) 
	{
		// ���b�Z�[�W�ݒ�
		SetFontSize(16);
		DrawString(500, 650, " ---- B�{�^���Ń��j���[��ʂ� ---- ", 0xffffff, 0x000000);
	}
	

}



