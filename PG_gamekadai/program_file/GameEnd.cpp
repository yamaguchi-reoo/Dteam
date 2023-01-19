#include "GameEnd.h"
#include "DxLib.h"

GameEnd::GameEnd()
{

	EndImg = LoadGraph("images/endimg1.png",FALSE);
	
}


AbstractScene* GameEnd::Update()
{
	if (++endtime < 600) { endy = 550 - endtime / 1; }

	//�^�C���̉��Z�������I��
	if (endtime > 600){ exit(0); }

	return this;
}


void GameEnd::Draw() const
{
	DrawGraph(0, 0, EndImg, TRUE);

	SetFontSize(30);
	DrawString(450, 170 + endy, "        �^�C�g��   ", 0x000000);
	DrawString(450, 200 + endy, "�@�@  �u���날���v ", 0x000000);
	DrawString(450, 230 + endy, "         �����    ", 0x000000);
	DrawString(450, 260 + endy, "��2-4�@��ԁ@�@����", 0x233B6C);
	DrawString(450, 290 + endy, "�@2-4�@���v�{�@����", 0x00FA9A);
	DrawString(450, 320 + endy, "�@2-3�@�o�ߌ��@��  ", 0xFFA500);
	DrawString(450, 350 + endy, "�@1-4�@�R���@�@�퉤", 0x00008B);
	DrawString(450, 380 + endy, "�@1-3�@�䉮���@����", 0x8A2BE2);
	DrawString(450, 410 + endy, "�@1-3�@�{��@�@����", 0xe3acae);
	DrawString(450, 440 + endy, "        �f�ޗ��p   ", 0x000000);
	DrawString(450, 480 + endy, "�@BG�@�@�@�@�w�w�w�w", 0x000000);
	DrawString(450, 510 + endy, "�@SE�@�@�@�@�w�w�w�w�w�w�w�w",0x000000);
	DrawString(450, 600 + endy, " Thank you for playing!!", 0x000000);

}
