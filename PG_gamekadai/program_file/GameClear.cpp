#include "GameClear.h"
#include"DxLib.h"
#include"SELECT.h"
#include<stdio.h>
#include"title.h"
#include"CONTROLER.h"

GameClear::GameClear()
{ 
	// �Q�[���N���A�摜�ǂݍ���
	gameclearimg = LoadGraph("images/gameclear.png",FALSE);
	
	count = 0;
	blink = 60;
}

void GameClear::Draw() const
{
	DrawGraph(0, 0, gameclearimg, TRUE);
	
	// �����̓_��
	if (count & blink) {
		// ���b�Z�[�W�ݒ�
		SetFontSize(16);
		DrawString(500, 650 , " ---- B�{�^���Ń��j���[��ʂ� ----", 0xffffff);
	}
	
}

AbstractScene* GameClear::Update()
{
	++count; // �J�E���g���Z

	// B�{�^���Ń��j���[�֑J��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return new TITLE();
	}
	return this;
}
