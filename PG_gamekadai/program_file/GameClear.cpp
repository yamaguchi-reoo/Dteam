#include "GameClear.h"
#include"DxLib.h"
#include"SELECT.h"
#include<stdio.h>
#include"title.h"
#include"CONTROLER.h"

GameClear::GameClear()
{ 
	// �Q�[���N���A�摜�ǂݍ���
	gameclear_img = LoadGraph("images/gameclear01.png",FALSE);
	
	count = 0;
	blink = 60;

	// �t�H���g�ύX
	font = CreateFontToHandle("Terminal", 18, 3);
}

void GameClear::Draw() const
{
	DrawGraph(0, 0, gameclear_img, TRUE);
	
	// �����̓_��
	if (count & blink) 
	{
		// ���b�Z�[�W�ݒ�
		DrawStringToHandle(480, 650, " ---- �a�{�^���Ń��j���[��ʂ� ---- ", 0xffffff, font);
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
