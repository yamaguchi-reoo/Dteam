#include "NORMAL.h"
#include "DxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include "CONTROLER.h"
#include <time.h>
#include"GAME_OVER.h"
#include"GameClear.h"
#include"RESULT.h"


NORMAL_DIF::NORMAL_DIF()
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

	Nflame_x=450;
	Nflame_y=200;


	if ((LoadDivGraph("images/Color.png", 5, 5, 1, IMAGE_SIZE, IMAGE_SIZE, block_image)) == -1)
	{
		throw "Images/block_image.png";
	}
	if ((frame_image = LoadGraph("images/FrameImage2.png")) == -1)
	{
		throw "images/FrameImage.png";
	}
	if ((cursol_image = LoadGraph("images/CursorImage.png")) == -1)
	{
		throw "images/CursorImage.png";
	}

	if ((mozi_image = LoadGraph("images/mozi.png")) == -1);
	if((kakunin_image=LoadGraph("images/kakunin.png"))==-1);

	srand((unsigned)time(NULL));

	for (int i = 0; i < NORMAL_SIZE; i++)
	{
		for (int j = 0; j < NORMAL_SIZE; j++)
		{
			normal_stage[i][j] = rand() % 4 + 1;
		}
	}

	for (int i = 0; i < NORMAL_SIZE; i++)
	{
		for (int j = 0; j < NORMAL_SIZE; j++)
		{
			player_stage[i][j] = 0;
			answer_stage[i][j] = false;
		}
	}
}

AbstractScene* NORMAL_DIF::Update()
{

	//画面をポーズしているか判定
	if (!pose)
	{
		//画像を覚える時間が終わっているかどうか判定
		if (!stand)
		{
			Standby();
			//時間をはかる
			if (standby_count++ % 60 == 0)
			{
				standby_limit--;
			}

		}
		else
		{
			//STARTボタンを押したらポーズする
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
			{
				pose = true;
			}
			else
			{
				game_count++;
			}

			//ゲームの時間をはかり、0以下になったらクリア判定をし、リザルトへ
			if (game_count % 60 == 0)
			{
				time_limit--;
				if (time_limit <= 0)
				{
					if (ClearJudge())
					{
						return new RESULT();
					}
				}
			}


			//カーソル移動

			//十字キー　下
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN) /*|| PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_DOWN)*/)
			{
				if (cursol_count_y < NORMAL_SIZE - 1)
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
					cursol_count_y = NORMAL_SIZE - 1;
				}
				WaitTimer(120);
			}
			//十字キー　右
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_RIGHT) /*|| PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_RIGHT)*/)
			{
				if (cursol_count_x < NORMAL_SIZE - 1)
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
					cursol_count_x = NORMAL_SIZE - 1;
				}
				WaitTimer(120);
			}

			//ボタンが押されたときに、色の変数を配列に入れる
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
			{
				player_stage[cursol_count_y][cursol_count_x] = 2;    //緑
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
			{
				player_stage[cursol_count_y][cursol_count_x] = 1;    //赤
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_Y))
			{
				player_stage[cursol_count_y][cursol_count_x] = 4;    //黄色
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_X))
			{
				player_stage[cursol_count_y][cursol_count_x] = 3;    //青
			}
		}
	}
	//ポーズ中
	else
	{
		//Aボタンを押したらクリア判定をし、リザルト画面へ
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
		{
			if (ClearJudge())
			{
				return new RESULT(this);
			}
		}
		//Bボタンを押したら、ゲーム画面へ
		else if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
		{
			pose = false;
		}
		else;
	}
	return this;
}


void NORMAL_DIF::Standby()
{
	//覚える時間をはかり、終わらせるフラグをtrueに
	if (standby_limit < 0)
	{
		stand = true;
	}
}


bool NORMAL_DIF::ClearJudge()
{

	//プレイヤーとお手本を比べて、解答用配列に格納
	int i;
	for (i = 0; i < NORMAL_SIZE; i++)
	{
		for (int j = 0; j < NORMAL_SIZE; j++)
		{
			if (player_stage[i][j] == normal_stage[i][j])
			{
				answer_stage[i][j] = true;
				point += 100 / (NORMAL_SIZE * NORMAL_SIZE);
			}
		}
	}
	if (i >= NORMAL_SIZE)
	{
		return true;
	}

	return false;
}


void NORMAL_DIF::Draw() const
{
	//ゲームを止めているかどうか判定
	if (!pose)
	{
		DrawBox(0, 0, 1280, 720, 0xffffff, TRUE);
		//覚える時間が終わっているかどうか
		if (stand)
		{
			SetFontSize(10);
			for (int i = 0; i < NORMAL_SIZE; i++)
			{
				for (int j = 0; j < NORMAL_SIZE; j++)
				{
					//プレイヤーの描画

					switch (player_stage[i][j])
					{
					case 0:
						DrawGraph((Nflame_x + j) + (IMAGE_SIZE * j), (Nflame_y + i) + (IMAGE_SIZE * i), block_image[0], TRUE); //白
						break;
					case 1:
						DrawGraph((Nflame_x + j) + (IMAGE_SIZE * j), (Nflame_y + i) + (IMAGE_SIZE * i), block_image[1], TRUE); //赤
						break;
					case 2:
						DrawGraph((Nflame_x + j) + (IMAGE_SIZE * j), (Nflame_y + i) + (IMAGE_SIZE * i), block_image[2], TRUE); //緑
						break;
					case 3:
						DrawGraph((Nflame_x + j) + (IMAGE_SIZE * j), (Nflame_y + i) + (IMAGE_SIZE * i), block_image[3], TRUE); //青
						break;
					case 4:
						DrawGraph((Nflame_x + j) + (IMAGE_SIZE * j), (Nflame_y + i) + (IMAGE_SIZE * i), block_image[4], TRUE); //黄色
						break;
					default:
						break;
					}
				}
			}
			DrawGraph(Nflame_x, Nflame_y, frame_image, TRUE);
			DrawGraph(Nflame_x + (101 * cursol_count_x), Nflame_y + (101 * cursol_count_y), cursol_image, TRUE);
			SetFontSize(20);
			DrawFormatString(0, 0, 0xffff00, "%3d", time_limit);
		}
		//覚える時間
		else
		{

			DrawGraph(425, 10, mozi_image, TRUE);

			for (int i = 0; i < NORMAL_SIZE; i++)
			{
				for (int j = 0; j < NORMAL_SIZE; j++)
				{
					//お手本画像描画
					switch (normal_stage[i][j])
					{
					case 0:
						DrawGraph((Nflame_x + j) + (IMAGE_SIZE * j), (Nflame_y + i) + (IMAGE_SIZE * i), block_image[0], TRUE); //白
						break;
					case 1:
						DrawGraph((Nflame_x + j) + (IMAGE_SIZE * j), (Nflame_y + i) + (IMAGE_SIZE * i), block_image[1], TRUE); //赤
						break;
					case 2:
						DrawGraph((Nflame_x + j) + (IMAGE_SIZE * j), (Nflame_y + i) + (IMAGE_SIZE * i), block_image[2], TRUE); //緑
						break;
					case 3:
						DrawGraph((Nflame_x + j) + (IMAGE_SIZE * j), (Nflame_y + i) + (IMAGE_SIZE * i), block_image[3], TRUE); //青
						break;
					case 4:
						DrawGraph((Nflame_x + j) + (IMAGE_SIZE * j), (Nflame_y + i) + (IMAGE_SIZE * i), block_image[4], TRUE); //黄色
						break;
					default:
						break;
					}
				}
			}
			DrawGraph(Nflame_x, Nflame_y, frame_image, TRUE);
			SetFontSize(20);
			DrawFormatString(0, 0, 0xffff00, "%3d", standby_limit);
		}
	}
	else
	{
		DrawGraph(0, 0, kakunin_image, TRUE);
	}
}