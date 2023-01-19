#include "GAME_OVER.h"
#include"dxlib.h"
#include"AbstractScene.h"
#include"title.h"
#include"CONTROLER.h"
#include<math.h>

GAME_OVER::GAME_OVER()
{
	// ゲームオーバー画像読み込み
	gameoverimg = LoadGraph("images/gameover01.png",FALSE);

	count = 0;
	blink = 60;

	// フォント変更
	font = CreateFontToHandle("Terminal", 18, 3);
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
		DrawStringToHandle(480, 650, " ---- Ｂボタンでメニュー画面へ ---- ", 0xffffff, font);
	}
	

}



