#include "GameEnd.h"
#include "DxLib.h"

GameEnd::GameEnd()
{

	EndImg = LoadGraph("images/endimg1.png",FALSE);
	
}


AbstractScene* GameEnd::Update()
{
	if (++endtime < 600) { endy = 550 - endtime / 1; }

	//タイムの加算処理＆終了
	if (endtime > 600){ exit(0); }

	return this;
}


void GameEnd::Draw() const
{
	DrawGraph(0, 0, EndImg, TRUE);

	SetFontSize(30);
	DrawString(450, 170 + endy, "        タイトル   ", 0x000000);
	DrawString(450, 200 + endy, "　　  「いろあい」 ", 0x000000);
	DrawString(450, 230 + endy, "         制作者    ", 0x000000);
	DrawString(450, 260 + endy, "☆2-4　崎間　　竜也", 0x233B6C);
	DrawString(450, 290 + endy, "　2-4　佐久本　盛杏", 0x00FA9A);
	DrawString(450, 320 + endy, "　2-3　與那原　廉  ", 0xFFA500);
	DrawString(450, 350 + endy, "　1-4　山口　　麗王", 0x00008B);
	DrawString(450, 380 + endy, "　1-3　比屋根　綾寄", 0x8A2BE2);
	DrawString(450, 410 + endy, "　1-3　宮城　　直希", 0xe3acae);
	DrawString(450, 440 + endy, "        素材利用   ", 0x000000);
	DrawString(450, 480 + endy, "　BG　　　　ＸＸＸＸ", 0x000000);
	DrawString(450, 510 + endy, "　SE　　　　ＸＸＸＸＸＸＸＸ",0x000000);
	DrawString(450, 600 + endy, " Thank you for playing!!", 0x000000);

}
