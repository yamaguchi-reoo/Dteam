#include "RESULT.h"
#include"DxLib.h"
#include"CONTROLER.h"
#include"title.h"
#include"GameClear.h"
#include"GAME_OVER.h"

RESULT::RESULT()
{
	easy = nullptr;
	normal = nullptr;
	hard = nullptr;

	for (int i = 0; i < EAZY_SIZE; i++)
	{
		for (int j = 0; j < EAZY_SIZE; j++)
		{
			e_stage[i][j] = 0;
			e_p_stage[i][j] = 0;
		}
	}

	for (int i = 0; i < NORMAL_SIZE; i++)
	{
		for (int j = 0; j < NORMAL_SIZE; j++)
		{
			n_stage[i][j] = 0;
			n_p_stage[i][j] = 0;
		}
	}

	for (int i = 0; i < HARD_SIZE; i++)
	{
		for (int j = 0; j < HARD_SIZE; j++)
		{
			h_stage[i][j] = 0;
			h_p_stage[i][j] = 0;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		image[i] = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		frame_image[i] = 0;
	}


	point = 0;

}

RESULT::RESULT(EAZY_DIF* eazy_dif)
{
	easy = eazy_dif;
	normal = nullptr;
	hard = nullptr;

	for (int i = 0; i < EAZY_SIZE; i++)
	{
		for (int j = 0; j < EAZY_SIZE; j++)
		{
			e_stage[i][j] = easy->Get_E_Stage(i, j);
			e_p_stage[i][j] = easy->Get_P_Stage(i, j);
		}
	}

	for (int i = 0; i < NORMAL_SIZE; i++)
	{
		for (int j = 0; j < NORMAL_SIZE; j++)
		{
			n_stage[i][j] = 0;
			n_p_stage[i][j] = 0;
		}
	}

	for (int i = 0; i < HARD_SIZE; i++)
	{
		for (int j = 0; j < HARD_SIZE; j++)
		{
			h_stage[i][j] = 0;
			h_p_stage[i][j] = 0;
		}
	}

	point = easy->Get_Point();

	if ((LoadDivGraph("images/Color.png", 5, 5, 1, IMAGE_SIZE, IMAGE_SIZE, image)) == -1)
	{
		throw "Images/Color.png";
	}
	if ((frame_image[0] = LoadGraph("images/FrameImage1.png")) == -1)
	{
		throw "images/FrameImage.png";
	}

}

RESULT::RESULT(NORMAL_DIF* normal_dif)
{
	easy = nullptr;
	normal = normal_dif;
	hard = nullptr;

	for (int i = 0; i < EAZY_SIZE; i++)
	{
		for (int j = 0; j < EAZY_SIZE; j++)
		{
			e_stage[i][j] = 0;
			e_p_stage[i][j] = 0;
		}
	}

	for (int i = 0; i < NORMAL_SIZE; i++)
	{
		for (int j = 0; j < NORMAL_SIZE; j++)
		{
			n_stage[i][j] = normal->Get_N_Stage(i, j);
			n_p_stage[i][j] = normal->Get_P_Stage(i, j);
		}
	}

	for (int i = 0; i < HARD_SIZE; i++)
	{
		for (int j = 0; j < HARD_SIZE; j++)
		{
			h_stage[i][j] = 0;
			h_p_stage[i][j] = 0;
		}
	}

	point = normal->Get_Point();

	if ((LoadDivGraph("images/Color.png", 5, 5, 1, IMAGE_SIZE, IMAGE_SIZE, image)) == -1)
	{
		throw "Images/Color.png";
	}
	if ((frame_image[1] = LoadGraph("images/FrameImage2.png")) == -1)
	{
		throw "images/FrameImage.png";
	}

}

RESULT::RESULT(HARD_DIF* hard_dif)
{
	easy = nullptr;
	normal = nullptr;
	hard = hard_dif;

	for (int i = 0; i < EAZY_SIZE; i++)
	{
		for (int j = 0; j < EAZY_SIZE; j++)
		{
			e_stage[i][j] = 0;
			e_p_stage[i][j] = 0;
		}
	}

	for (int i = 0; i < NORMAL_SIZE; i++)
	{
		for (int j = 0; j < NORMAL_SIZE; j++)
		{
			n_stage[i][j] = 0;
			n_p_stage[i][j] = 0;
		}
	}

	for (int i = 0; i < HARD_SIZE; i++)
	{
		for (int j = 0; j < HARD_SIZE; j++)
		{
			h_stage[i][j] = hard->Get_H_Stage(i, j);
			h_p_stage[i][j] = hard->Get_P_Stage(i, j);
		}
	}

	point = hard->Get_Point();

	if ((LoadDivGraph("images/Color.png", 5, 5, 1, IMAGE_SIZE, IMAGE_SIZE, image)) == -1)
	{
		throw "Images/Color.png";
	}
	if ((frame_image[2] = LoadGraph("images/FrameImage3.png")) == -1)
	{
		throw "images/FrameImage.png";
	}
}


AbstractScene* RESULT::Update()
{

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		if (point >= 50)
		{
			return new GameClear();
		}
		else
		{
			return new GAME_OVER();
		}
	}
	return this;
}

void RESULT::Draw() const
{
	DrawLine(640, 0, 640, 720, 0xffffff, TRUE);
	if (easy != nullptr)
	{
		DrawGraph(70, 120, frame_image[0], TRUE);
		DrawGraph(710, 110, frame_image[0], TRUE);

		for (int i = 0; i < EAZY_SIZE; i++)
		{
			for (int j = 0; j < EAZY_SIZE; j++)
			{
				switch (e_p_stage[i][j])
				{
				case 0:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[0], TRUE);
					break;
				case 1:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[1], TRUE);
					break;
				case 2:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[2], TRUE);
					break;
				case 3:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[3], TRUE);
					break;
				case 4:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[4], TRUE);
					break;
				default:
					break;
				}


				switch (e_stage[i][j])
				{
				case 0:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[0], TRUE);
					break;
				case 1:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[1], TRUE);
					break;
				case 2:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[2], TRUE);
					break;
				case 3:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[3], TRUE);
					break;
				case 4:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[4], TRUE);
					break;
				default:
					break;
				}
			}
		}
	}
	else if (normal != nullptr)
	{
		DrawGraph(70, 120, frame_image[1], TRUE);
		DrawGraph(710, 120, frame_image[1], TRUE);


		for (int i = 0; i < NORMAL_SIZE; i++)
		{
			for (int j = 0; j < NORMAL_SIZE; j++)
			{
				switch (n_p_stage[i][j])
				{
				case 0:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[0], TRUE);
					break;
				case 1:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[1], TRUE);
					break;
				case 2:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[2], TRUE);
					break;
				case 3:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[3], TRUE);
					break;
				case 4:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[4], TRUE);
					break;
				default:
					break;
				}


				switch (n_stage[i][j])
				{
				case 0:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[0], TRUE);
					break;
				case 1:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[1], TRUE);
					break;
				case 2:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[2], TRUE);
					break;
				case 3:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[3], TRUE);
					break;
				case 4:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[4], TRUE);
					break;
				default:
					break;
				}
			}
		}
	}
	else
	{
		DrawGraph(70, 120, frame_image[2], TRUE);
		DrawGraph(710, 120, frame_image[2], TRUE);


		for (int i = 0; i < HARD_SIZE; i++)
		{
			for (int j = 0; j < HARD_SIZE; j++)
			{
				switch (h_p_stage[i][j])
				{
				case 0:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[0], TRUE);
					break;
				case 1:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[1], TRUE);
					break;
				case 2:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[2], TRUE);
					break;
				case 3:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[3], TRUE);
					break;
				case 4:
					DrawGraph((70 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[4], TRUE);
					break;
				default:
					break;
				}


				switch (h_stage[i][j])
				{
				case 0:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[0], TRUE);
					break;
				case 1:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[1], TRUE);
					break;
				case 2:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[2], TRUE);
					break;
				case 3:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[3], TRUE);
					break;
				case 4:
					DrawGraph((710 + j) + (IMAGE_SIZE * j), (110 + i) + (IMAGE_SIZE * i), image[4], TRUE);
					break;
				default:
					break;
				}
			}
		}
	}


	SetFontSize(30);
	DrawFormatString(100, 665, 0xff00ff, "Bƒ{ƒ^ƒ“‚ÅŽŸ‚Ì‰æ–Ê‚Ö");
	DrawFormatString(0, 0, 0xffffff, "%d", point);
}



