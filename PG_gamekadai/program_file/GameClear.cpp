#include "GameClear.h"
#include"DxLib.h"
#include"SELECT.h"
#include<stdio.h>
#include"title.h"
#include"CONTROLER.h"

GameClear::GameClear()
{ 
	// ゲームクリア画像読み込み
	gameclear_img = LoadGraph("images/gameclear01.png",FALSE);
	
	count = 0;
	blink = 60;

	// フォント変更
	font = CreateFontToHandle("Terminal", 18, 3);
}

void GameClear::Draw() const
{
	DrawGraph(0, 0, gameclear_img, TRUE);
	
	// 文字の点滅
	if (count & blink) 
	{
		// メッセージ設定
		DrawStringToHandle(480, 650, " ---- Ｂボタンでメニュー画面へ ---- ", 0xffffff, font);
	}
	
}

AbstractScene* GameClear::Update()
{
	++count; // カウント加算

	// Bボタンでメニューへ遷移
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return new TITLE();
	}
	return this;
}
