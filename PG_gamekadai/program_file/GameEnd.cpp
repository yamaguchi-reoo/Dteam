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

	//タイムの加算処理＆終了
	if (endtime > 900){ exit(1); }

	return this;
}


void GameEnd::Draw() const
{
	DrawGraph(0, 0, EndImg, TRUE);

	SetFontSize(24);
	DrawString(450, 170 + endy, "        タイトル　　　", 0xFFFFFF);
	DrawString(450, 200 + endy, "　　      「」          ", 0xFFFFFF);
	DrawString(450, 230 + endy, "         制作者     ", 0xFFFFFF);
	DrawString(450, 260 + endy, "  2-    　　　　", 0xFFFFFF);
	DrawString(450, 290 + endy, "　2-　 Naoki　Miyagi", 0xFFFFFF);
	DrawString(450, 310 + endy, "　2-　 Naoki　Miyagi", 0xFFFFFF);
	DrawString(450, 340 + endy, "　1-4　山口　  麗王", 0xFFFFFF);
	DrawString(450, 370 + endy, "　1-3　比屋根　綾寄", 0xFFFFFF);
	DrawString(450, 400 + endy, "　1-3　宮城　　直希", 0xFFFFFF);
	DrawString(450, 430 + endy, "素材利用", 0xFFFFFF);
	DrawString(450, 470 + endy, "　BGM　　　 　ＸＸＸＸ", 0xFFFFFF);
	DrawString(450, 485 + endy, "　SE　　　　　ＸＸＸＸＸＸＸＸ", 0xFFFFFF);

}
