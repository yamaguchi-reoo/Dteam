#include "GameClear.h"
#include"DxLib.h"
#include"SELECT.h"
#include<stdio.h>
#include"title.h"
#include"CONTROLER.h"

GameClear::GameClear()
{ 
	// ゲームクリア画像読み込み
	gameclearimg = LoadGraph("images/gameclear.png",FALSE);
}

void GameClear::Draw() const
{
	DrawGraph(0, 0, gameclearimg, TRUE);
	
	// メッセージ設定
	SetFontSize(16);
	DrawString(500, 650, " ---- Bボタンでメニュー画面へ ----", 0xffffff);
}

AbstractScene* GameClear::Update()
{
	// Bボタンでメニューへ遷移
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return new TITLE();
	}
	return this;
}
