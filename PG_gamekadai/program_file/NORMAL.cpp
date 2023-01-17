#include "NORMAL.h"
#include "DxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

NORMAL_DIF::NORMAL_DIF()
{
	cursol_x = 0;
	cursol_y = 0;

	if ((LoadDivGraph("images/Color.png", 4, 4, 1, 50, 50, block_image)) == -1)
	{
		throw "Images/Color.png";
	}

	srand((unsigned)time(NULL));
	for (int i = 0; i < NORMAL_SIZE; i++)
	{
		for (int j = 0; j < NORMAL_SIZE; j++)
		{
			normal_stage[i][j] = rand() % 4;
		}
	}
}

AbstractScene* NORMAL_DIF::Update()
{

	return this;
}

void NORMAL_DIF::Draw() const
{
	SetFontSize(10);
	for (int i = 0; i < NORMAL_SIZE; i++)
	{
		for (int j = 0; j < NORMAL_SIZE; j++)
		{
			DrawFormatString(10 * i, 10 * j, 0x00ff00, "%d", normal_stage[i][j]);
		}
	}
}