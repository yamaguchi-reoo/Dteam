#include "GameEnd.h"
#include "DxLib.h"

GameEnd::GameEnd()
{

	EndImg = LoadGraph("images/endimg1.png",FALSE);
	
}


AbstractScene* GameEnd::Update()
{
	if (++endtime < 600) { endy = 550 - endtime / 1; }

	//^CÌÁZI¹
	if (endtime > 600){ exit(0); }

	return this;
}


void GameEnd::Draw() const
{
	DrawGraph(0, 0, EndImg, TRUE);

	SetFontSize(30);
	DrawString(450, 170 + endy, "        ^Cg   ", 0x000000);
	DrawString(450, 200 + endy, "@@  u¢ë ¢v ", 0x000000);
	DrawString(450, 230 + endy, "         §ìÒ    ", 0x000000);
	DrawString(450, 260 + endy, "2-4@èÔ@@³ç", 0x233B6C);
	DrawString(450, 290 + endy, "@2-4@²v{@·Ç", 0x00FA9A);
	DrawString(450, 320 + endy, "@2-3@äoß´@õ  ", 0xFFA500);
	DrawString(450, 350 + endy, "@1-4@Rû@@í¤", 0x00008B);
	DrawString(450, 380 + endy, "@1-3@ä®ª@»ñ", 0x8A2BE2);
	DrawString(450, 410 + endy, "@1-3@{é@@¼ó", 0xe3acae);
	DrawString(450, 440 + endy, "        fÞp   ", 0x000000);
	DrawString(450, 480 + endy, "@BG@@@@wwww", 0x000000);
	DrawString(450, 510 + endy, "@SE@@@@wwwwwwww",0x000000);
	DrawString(450, 600 + endy, " Thank you for playing!!", 0x000000);

}
