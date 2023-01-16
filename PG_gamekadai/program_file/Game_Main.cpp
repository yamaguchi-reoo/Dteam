#include "Game_Main.h"
#include "DxLib.h"
#include <stdio.h>

GameMain::GameMain()
{
	color = nullptr;
	time = 0;
}

AbstractScene* GameMain::Update()
{
	return this;
}

void GameMain::Draw() const
{
	DrawString(0, 0, "MTHOR", 0xffff00);
}
