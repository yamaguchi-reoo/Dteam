#include "EAZY.h"
#include "DxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

EAZY_DIF::EAZY_DIF()
{
	cursol_x = 0;
	cursol_y = 0;
	stand_count = 0;
	stand = false;

	if ((LoadDivGraph("images/Color.png", 4, 4, 1, 50, 50, block_image)) == -1)
	{
		throw "Images/Color.png";
	}
	if ((frame_image = LoadGraph("images/FrameImage.png")) == -1)
	{
		throw "images/FrameImage.png";
	}
	if ((cursol_image = LoadGraph("iamges/CursorImage.png")) == -1)
	{
		throw "images/CursorImage.png";
	}


	srand((unsigned)time(NULL));

	for (int i = 0; i < EAZY_SIZE; i++)
	{
		for (int j = 0; j < EAZY_SIZE; j++)
		{
			eazy_stage[i][j] = rand() % 4;
		}
	}
}

AbstractScene* EAZY_DIF::Update()
{
	if (!stand)
	{
		Standby();
	}
	return this;
}


void EAZY_DIF::Standby()
{

	if (stand_count++ > 300)
	{
		stand = true;
	}
}

void EAZY_DIF::Draw() const
{
	DrawBox(0, 0, 1280, 720, 0xffffff, TRUE);
	if (stand)
	{
		SetFontSize(10);
		for (int i = 0; i < EAZY_SIZE; i++)
		{
			for (int j = 0; j < EAZY_SIZE; j++)
			{
				DrawFormatString(10 * i, 10 * j, 0x00ff00, "%d", eazy_stage[i][j]);
			}
		}
	}
	else
	{

		SetFontSize(20);
		DrawString(400, 600, "Šo‚¦‚ë", 0xff00ff);

		for (int i = 0; i < EAZY_SIZE; i++)
		{
			for (int j = 0; j < EAZY_SIZE; j++)
			{
				switch (eazy_stage[i][j])
				{
				case 0:
					DrawGraph((300 + j) + (50 * j), (200 + i) + (50 * i), block_image[0], TRUE);
					DrawGraph((300 + j) + (50 * j), (200 + i) + (50 * i), cursol_image, TRUE);
					break;
				case 1:
					DrawGraph((300 + j) + (50 * j), (200 + i) + (50 * i), block_image[1], TRUE);
					break;
				case 2:
					DrawGraph((300 + j) + (50 * j), (200 + i) + (50 * i), block_image[2], TRUE);
					break;
				case 3:
					DrawGraph((300 + j) + (50 * j), (200 + i) + (50 * i), block_image[3], TRUE);
					break;
				default:
					break;
				}
			}
		}
	}
	DrawGraph(300, 200, frame_image,TRUE);
}