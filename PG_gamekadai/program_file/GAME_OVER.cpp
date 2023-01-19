#include "GAME_OVER.h"
#include"dxlib.h"
#include"AbstractScene.h"
#include"title.h"
#include"CONTROLER.h"
#include<math.h>

GAME_OVER::GAME_OVER()
{
	// ゲームオーバー画像読み込み
	gameoverimg = LoadGraph("images/gameover.png",FALSE);

	count = 0;
	blink = 60;
}

AbstractScene* GAME_OVER::Update() 
{
	++count; // カウント加算

	// Bボタンでメニューへ遷移
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return new TITLE();
	}
	return this;
}

void GAME_OVER::Draw() const
{
	DrawGraph(0, 0, gameoverimg, TRUE);

	// 文字の点滅
	if (count & blink) 
	{
		// メッセージ設定
		SetFontSize(16);
		DrawString(500, 650, " ---- Bボタンでメニュー画面へ ---- ", 0xffffff, 0x000000);
	}
	

}



