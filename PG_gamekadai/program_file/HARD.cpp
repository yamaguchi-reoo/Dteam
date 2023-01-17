#include "HARD.h"
#include "DxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

HARD_DIF::HARD_DIF()
{
	cursol_x = 0;
	cursol_y = 0;
	if ((LoadDivGraph("images/Color.png", 4, 4, 1, 50, 50, block_image)) == -1)
	{
		throw "Images/Color.png";
	}

	srand((unsigned)time(NULL));
	for (int i = 0; i < HARD_SIZE; i++)
	{
		for (int j = 0; j < HARD_SIZE; j++)
		{
			hard_stage[i][j] = rand() % 4;
		}
	}
}


AbstractScene* HARD_DIF::Update()
{

	return this;
}

void HARD_DIF::Draw() const
{
	SetFontSize(10);
	for (int i = 0; i < HARD_SIZE; i++)
	{
		for (int j = 0; j < HARD_SIZE; j++)
		{
			DrawFormatString(10 * i, 10 * j, 0x00ff00, "%d", hard_stage[i][j]);
		}
	}
}