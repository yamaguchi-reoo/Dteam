#include "GameClear.h"
#include"DxLib.h"
#include<stdio.h>

GameClear::GameClear()
{

}

void GameClear::Draw() const
{
	SetFontSize(16);
	DrawString(150, 420, " ---- B�{�^���Ń��j���[��ʂ� ----", 0xffffff, 0x000000);
}

AbstractScene* GameClear::Update()
{
	return this;
}
