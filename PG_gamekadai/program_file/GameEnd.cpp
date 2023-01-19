#include "GameEnd.h"
#include "DxLib.h"

GameEnd::GameEnd()
{

	EndImg = LoadGraph("images/endimg1.png",FALSE);
	
}


AbstractScene* GameEnd::Update()
{
	if (++endtime < 800) { endy = 450 - endtime / 1; }

	//�^�C���̉��Z�������I��
	if (endtime > 900){ exit(0); }

	return this;
}


void GameEnd::Draw() const
{
	DrawGraph(0, 0, EndImg, TRUE);

	SetFontSize(30);
	DrawString(450, 400 + endy, "        �^�C�g��   ", 0x000000);
	DrawString(450, 430 + endy, "�@�@  �u������v ", 0x000000);
	DrawString(450, 500 + endy, "         �����    ", 0x000000);
	DrawString(450, 560 + endy, "��2-4�@��ԁ@�@����", 0x233B6C);
	DrawString(450, 590 + endy, "�@2-4�@���v�{�@����", 0x00FA9A);
	DrawString(450, 620 + endy, "�@2-3�@�o�ߌ��@��  ", 0xFFA500);
	DrawString(450, 650 + endy, "�@1-4�@�R���@�@�퉤", 0x00008B);
	DrawString(450, 680 + endy, "�@1-3�@�䉮���@����", 0x8A2BE2);
	DrawString(450, 710 + endy, "�@1-3�@�{��@�@����", 0xe3acae);
	DrawString(450, 770 + endy, "    �g�p�\�t�g�E�F�A ",0x000000);
	DrawString(450, 800 + endy, "�@Visual Studio2022", 0x800080);
	DrawString(450, 835 + endy, "�@Power Point", 0xff7f50);
	DrawString(450, 1000 + endy, " Thank you for playing!!", 0x000000);

}
