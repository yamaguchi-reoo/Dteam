#include "Game_Main.h"
#include "DxLib.h"
#include <stdio.h>

GameMain::GameMain()
{
	color = nullptr;
	cursol_x = 0;
	cursol_y = 0;
	time = 0;

	for (int i = 0; i < 4; i++)
	{

	}
}

GameMain::GameMain(DIFFICULTY difficulty)
{
	select = difficulty;
	color = nullptr;
	cursol_x = 0;
	cursol_y = 0;
	time = 0;
}

AbstractScene* GameMain::Update()
{

	return this;
}

void GameMain::Draw() const
{
	switch (select)
	{
	case DIFFICULTY::EAZY:
		break;
	case DIFFICULTY::NORMAL:
		break;
	case DIFFICULTY::HARD:
		break;
	default:
		break;
	}
}
