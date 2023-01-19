#include "HARD.h"
#include "DxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include "CONTROLER.h"
#include <time.h>
#include"GAME_OVER.h"
#include"GameClear.h"
#include"RESULT.h"

HARD_DIF::HARD_DIF()
{
	standby_count = 0;
	cursol_count_x = 0;
	cursol_count_y = 0;
	game_count = 0;
	time_limit = 60;
	standby_limit = 10;
	stand = false;
	pose = false;
	point = 0;

	Hflame_x = 425;
	Hflame_y = 150;

	if ((LoadDivGraph("images/Color1.png", 4, 4, 1, IMAGE_SIZE, IMAGE_SIZE, block_image)) == -1)
	{
		throw "Images/Color.png";
	}
	if ((frame_image = LoadGraph("images/FrameImage3.png")) == -1)
	{
		throw "images/FrameImage.png";
	}
	if ((cursol_image = LoadGraph("images/CursorImage.png")) == -1)
	{
		throw "images/CursorImage.png";
	}

	if ((mozi_image = LoadGraph("images/mozi.png")) == -1);
	if ((kakunin_image = LoadGraph("images/kakunin.png")) == -1);


	srand((unsigned)time(NULL));

	for (int i = 0; i < HARD_SIZE; i++)
	{
		for (int j = 0; j < HARD_SIZE; j++)
		{
			hard_stage[i][j] = rand() % 3 + 1;
		}
	}

	for (int i = 0; i < HARD_SIZE; i++)
	{
		for (int j = 0; j < HARD_SIZE; j++)
		{
			player_stage[i][j] = 0;
			answer_stage[i][j] = false;
		}
	}
}

AbstractScene* HARD_DIF::Update()
{
	//画面が止まっているか
	if (!pose)
	{
		//記憶時間は終わっているか
		if (!stand)
		{
			Standby();
			if (standby_count++ % 60 == 0)
			{
				standby_limit--;
			}
		}
		else
		{
			//STARTぼたんで画面をポーズ
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
			{
				pose = true;
			}
			else
			{
				game_count++;
			}

			//ゲーム時間を数える
			if (game_count % 60 == 0)
			{
				time_limit--;
				if (time_limit <= 0)
				{
					return new GAME_OVER();
				}
			}

			//カーソル移動

			//十字キー　下
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN) /*|| PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_DOWN)*/)
			{
				if (cursol_count_y < HARD_SIZE - 1)
				{
					++cursol_count_y;
				}
				else
				{
					cursol_count_y = 0;
				}
				WaitTimer(120);
			}

			//十字キー　上
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP) /*|| PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_UP)*/)
			{
				if (cursol_count_y > 0)
				{
					--cursol_count_y;
				}
				else
				{
					cursol_count_y = HARD_SIZE - 1;
				}
				WaitTimer(120);
			}

			//十字キー　右
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_RIGHT) /*|| PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT)*/)
			{
				if (cursol_count_x < HARD_SIZE - 1)
				{
					++cursol_count_x;
				}
				else
				{
					cursol_count_x = 0;
				}
				WaitTimer(120);
			}

			//十字キー　左
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_LEFT) /*|| PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_LEFT)*/)
			{
				if (cursol_count_x > 0)
				{
					--cursol_count_x;
				}
				else
				{
					cursol_count_x = HARD_SIZE - 1;
				}
				WaitTimer(120);
			}


			//各ボタンを押して色を配列に
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
			{
				player_stage[cursol_count_y][cursol_count_x] = 2;	//緑
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
			{
				player_stage[cursol_count_y][cursol_count_x] = 1;	//赤
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_Y))
			{
				player_stage[cursol_count_y][cursol_count_x] = 4;	//黄色
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_X))
			{
				player_stage[cursol_count_y][cursol_count_x] = 3;   //青
			}
		}
	}
	else
	{
		//ポーズ中にAボタンでクリア判定をし、リザルトへ
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
		{
			if (ClearJudge())
			{
				return new RESULT(this);
			}
			else {}
		}
		//Bボタンでポーズ解除
		else if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
		{
			pose = false;
		}
		else;
	}
	return this;
}


void HARD_DIF::Standby()
{
	//記憶時間をはかり、終わらせる処理
	if (standby_limit <= 0)
	{
		stand = true;
	}
}


bool HARD_DIF::ClearJudge()
{
	int i;
	for (i = 0; i < HARD_SIZE; i++)
	{
		for (int j = 0; j < HARD_SIZE; j++)
		{
			//採点をする
			if (player_stage[i][j] == hard_stage[i][j])
			{
				answer_stage[i][j] = true;
				point += 100 / (HARD_SIZE * HARD_SIZE);
			}
		}
	}
	if (i >= HARD_SIZE)
	{
		return true;
	}

	return false;
}


void HARD_DIF::Draw() const
{
	//画面を止めているか
	if (!pose)
	{
		DrawBox(0, 0, 1280, 720, 0xffffff, TRUE);
		//記憶時間かどうか
		if (stand)
		{
			SetFontSize(10);
			for (int i = 0; i < HARD_SIZE; i++)
			{
				for (int j = 0; j < HARD_SIZE; j++)
				{
					//プレイヤーの描画
					switch (player_stage[i][j])
					{
					case 0:
						DrawGraph((Hflame_x + j) + (IMAGE_SIZE * j), (Hflame_y + i) + (IMAGE_SIZE * i), block_image[0], TRUE);//白
						break;
					case 1:
						DrawGraph((Hflame_x + j) + (IMAGE_SIZE * j), (Hflame_y + i) + (IMAGE_SIZE * i), block_image[1], TRUE);//赤
						break;
					case 2:
						DrawGraph((Hflame_x + j) + (IMAGE_SIZE * j), (Hflame_y + i) + (IMAGE_SIZE * i), block_image[2], TRUE);//緑
						break;
					case 3:
						DrawGraph((Hflame_x + j) + (IMAGE_SIZE * j), (Hflame_y + i) + (IMAGE_SIZE * i), block_image[3], TRUE);//青
						break;
					case 4:
						DrawGraph((Hflame_x + j) + (IMAGE_SIZE * j), (Hflame_y + i) + (IMAGE_SIZE * i), block_image[4], TRUE);//黄色
							break;
					default:
						break;
					}
				}
			}
			DrawGraph(Hflame_x, Hflame_y, frame_image, TRUE);
			SetFontSize(20);
			DrawFormatString(0, 0, 0xffff00, "%3d", time_limit);
			DrawGraph(Hflame_x + (101 * cursol_count_x), Hflame_y + (101 * cursol_count_y), cursol_image, TRUE);
		}
		//記憶時間中
		else
		{

			DrawGraph(425, 10, mozi_image, TRUE);

			for (int i = 0; i < HARD_SIZE; i++)
			{
				for (int j = 0; j < HARD_SIZE; j++)
				{
					//お手本描画
					switch (hard_stage[i][j])
					{
					case 0:
						DrawGraph((Hflame_x + j) + (IMAGE_SIZE * j), (Hflame_y + i) + (IMAGE_SIZE * i), block_image[0], TRUE);//白
						break;
					case 1:
						DrawGraph((Hflame_x + j) + (IMAGE_SIZE * j), (Hflame_y + i) + (IMAGE_SIZE * i), block_image[1], TRUE);//赤
						break;
					case 2:
						DrawGraph((Hflame_x + j) + (IMAGE_SIZE * j), (Hflame_y + i) + (IMAGE_SIZE * i), block_image[2], TRUE);//緑
						break;
					case 3:
						DrawGraph((Hflame_x + j) + (IMAGE_SIZE * j), (Hflame_y + i) + (IMAGE_SIZE * i), block_image[3], TRUE);//青
						break;
					case 4:
						DrawGraph((Hflame_x + j) + (IMAGE_SIZE * j), (Hflame_y + i) + (IMAGE_SIZE * i), block_image[4], TRUE);//黄色
						break;
					default:
						break;
					}
				}
			}
			DrawGraph(Hflame_x, Hflame_y, frame_image, TRUE);
			SetFontSize(20);
			DrawFormatString(0, 0, 0xffff00, "%3d", standby_limit);
		}
	}
	//ポーズ中
	else
	{
		DrawGraph(0, 0, kakunin_image, TRUE);//確認画面の表示
	}
}