#include "GameEnd.h"
#include "DxLib.h"
#include <stdio.h>
#include<stdlib.h>


GameEnd::GameEnd()
{

	EndImg = LoadGraph("imges/End.png",FALSE);
	
}


AbstractScene* GameEnd::Update()
{
	if (++endtime < 600) { endy = 300 - endtime / 2; }

	//�^�C���̉��Z�������I��
	if (endtime > 900){ exit(0); }

	return this;
}


void GameEnd::Draw() const
{
	DrawGraph(0, 0, EndImg, TRUE);

	SetFontSize(24);
	DrawString(450, 170 + endy, "        �^�C�g���@�@�@", 0xFFFFFF);
	DrawString(450, 200 + endy, "�@�@      �u�v         ", 0xFFFFFF);
	DrawString(450, 230 + endy, "         �����    ", 0xFFFFFF);
	DrawString(450, 260 + endy, "��2-4�@�����@�@����", 0xFFFFFF);
	DrawString(450, 290 + endy, "�@2-4�@�����@�@����", 0xFFFFFF);
	DrawString(450, 320 + endy, "�@2-3�@�����@�@����", 0xFFFFFF);
	DrawString(450, 350 + endy, "�@1-4�@�R���@�@�퉤", 0xFFFFFF);
	DrawString(450, 380 + endy, "�@1-3�@�䉮���@����", 0xFFFFFF);
	DrawString(450, 410 + endy, "�@1-3�@�{��@�@����", 0xFFFFFF);
	DrawString(450, 440 + endy, "�f�ޗ��p", 0xFFFFFF);
	DrawString(450, 480 + endy, "�@BGM�@�@�@ �@�w�w�w�w", 0xFFFFFF);
	DrawString(450, 495 + endy, "�@SE�@�@�@�@�@�w�w�w�w�w�w�w�w", 0xFFFFFF);
	DrawString(450, 600 + endy, "Thank you for playing!!", 0xFFFFFF);


}
