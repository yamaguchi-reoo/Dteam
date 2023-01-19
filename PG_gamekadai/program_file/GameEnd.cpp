#include "GameEnd.h"
#include "DxLib.h"

GameEnd::GameEnd()
{

	EndImg = LoadGraph("images/endimg1.png",FALSE);
	
}


AbstractScene* GameEnd::Update()
{
	if (++endtime < 800) { endy = 450 - endtime / 1; }

	//タイムの加算処理＆終了
	if (endtime > 900){ exit(0); }

	return this;
}


void GameEnd::Draw() const
{
	DrawGraph(0, 0, EndImg, TRUE);

	SetFontSize(30);
	DrawString(450, 400 + endy, "        タイトル   ", 0x000000);
	DrawString(450, 430 + endy, "　　  「いろつき」 ", 0x000000);
	DrawString(450, 500 + endy, "         制作者    ", 0x000000);
	DrawString(450, 560 + endy, "☆2-4　崎間　　竜也", 0x233B6C);
	DrawString(450, 590 + endy, "　2-4　佐久本　盛杏", 0x00FA9A);
	DrawString(450, 620 + endy, "　2-3　與那原　廉  ", 0xFFA500);
	DrawString(450, 650 + endy, "　1-4　山口　　麗王", 0x00008B);
	DrawString(450, 680 + endy, "　1-3　比屋根　綾寄", 0x8A2BE2);
	DrawString(450, 710 + endy, "　1-3　宮城　　直希", 0xe3acae);
	DrawString(450, 770 + endy, "    使用ソフトウェア ",0x000000);
	DrawString(450, 800 + endy, "　Visual Studio2022", 0x800080);
	DrawString(450, 835 + endy, "　Power Point", 0xff7f50);
	DrawString(450, 1000 + endy, " Thank you for playing!!", 0x000000);

}
