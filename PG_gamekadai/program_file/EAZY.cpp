#include "EAZY.h"
#include "DxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include "CONTROLER.h"
#include <time.h>
#include"GAME_OVER.h"
#include"GameClear.h"

EAZY_DIF::EAZY_DIF()
{
	cursol_x = CURSOL_X;
	cursol_y = CURSOL_Y;
	stand_count = 0;
	cursol_count_x = 0;
	cursol_count_y = 0;
	game_count = 0;
	time_limit = 60;
	stand = false;
	pose = false;

	if ((LoadDivGraph("images/Color.png", 5, 5, 1, IMAGE_SIZE, IMAGE_SIZE, block_image)) == -1)
	{
		throw "Images/Color.png";
	}
	if ((frame_image = LoadGraph("images/FrameImage.png")) == -1)
	{
		throw "images/FrameImage.png";
	}
	if ((cursol_image = LoadGraph("images/CursorImage.png")) == -1)
	{
		throw "images/CursorImage.png";
	}


	srand((unsigned)time(NULL));

	for (int i = 0; i < EAZY_SIZE; i++)
	{
		for (int j = 0; j < EAZY_SIZE; j++)
		{
			eazy_stage[i][j] = rand() % 4 + 1;
		}
	}

	for (int i = 0; i < EAZY_SIZE; i++)
	{
		for (int j = 0; j < EAZY_SIZE; j++)
		{
			player_stage[i][j] = 0;
			answer_stage[i][j] = false;
		}
	}
}

AbstractScene* EAZY_DIF::Update()
{
	

	if (!stand)
	{
		Standby();
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
	{
		if (ClearJudge())
		{
			return new GameClear();
		}
	}
	else
	{
		game_count++;
	}

	if (game_count % 60 == 0)
	{
		time_limit--;
		if (time_limit <= 0)
		{
			return new GAME_OVER();
		}
	}


	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN) || PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_DOWN))
	{
		if (cursol_count_y < EAZY_SIZE - 1)
		{
			++cursol_count_y;
		}
		else
		{
			cursol_count_y = 0;
		}
		WaitTimer(120);
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP) /*|| PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_UP)*/)
	{
		if (cursol_count_y > 0)
		{
			--cursol_count_y;
		}
		else
		{
			cursol_count_y = EAZY_SIZE - 1;
		}
		WaitTimer(120);
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_RIGHT) /*|| PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT)*/)
	{
		if (cursol_count_x < EAZY_SIZE - 1)
		{
			++cursol_count_x;
		}
		else
		{
			cursol_count_x = 0;
		}
		WaitTimer(120);
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_LEFT) /*|| PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT)*/)
	{
		if (cursol_count_x > 0)
		{
			--cursol_count_x;
		}
		else
		{
			cursol_count_x = EAZY_SIZE - 1;
		}
		WaitTimer(120);
	}


	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		player_stage[cursol_count_y][cursol_count_x] = 2;
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		player_stage[cursol_count_y][cursol_count_x] = 1;
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_Y))
	{
		player_stage[cursol_count_y][cursol_count_x] = 4;
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_X))
	{
		player_stage[cursol_count_y][cursol_count_x] = 3;
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


bool EAZY_DIF::ClearJudge()
{
	int i;
	for (i = 0; i < EAZY_SIZE; i++)
	{
		for (int j = 0; j < EAZY_SIZE; j++)
		{
			if (player_stage[i][j] == eazy_stage[i][j])
			{
				answer_stage[i][j] = true;
				point += 25;
			}
		}
	}
	if (i >= EAZY_SIZE)
	{
		return true;
	}

	return false;
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
				switch (player_stage[i][j])
				{
				case 0:
					DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[0], TRUE);
					break;
				case 1:
					DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[1], TRUE);
					break;
				case 2:
					DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[2], TRUE);
					break;
				case 3:
					DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[3], TRUE);
					break;
				case 4:
					DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[4], TRUE);
					break;
				default:
					break;
				}
			}
		}

		DrawGraph(300 + (101 * cursol_count_x), 200 + (101 * cursol_count_y), cursol_image, TRUE);
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
					DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[0], TRUE);
					break;
				case 1:
					DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[1], TRUE);
					break;
				case 2:
					DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[2], TRUE);
					break;
				case 3:
					DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[3], TRUE);
					break;
				case 4:
					DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[4], TRUE);
					break;
				default:
					break;
				}
			}
		}
	}
	DrawGraph(300, 200, frame_image,TRUE);
	DrawFormatString(0, 0, 0xffff00, "%3d",time_limit);
}