#include "EAZY.h"
#include "DxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include "CONTROLER.h"
#include <time.h>
#include"GAME_OVER.h"
#include"GameClear.h"
#include"RESULT.h"
#include <math.h>

EAZY_DIF::EAZY_DIF()
{

	standby_count = 0;
	cursol_count_x = 0;
	cursol_count_y = 0;
	game_count = 0;
	time_limit = 60;
	standby_limit = 5;
	stand = false;
	eazy = nullptr;
	pose = false;
	point = 0;

	if ((LoadDivGraph("images/Color.png", 5, 5, 1, IMAGE_SIZE, IMAGE_SIZE, block_image)) == -1)
	{
		throw "Images/block_image.png";
	}
	if ((frame_image = LoadGraph("images/FrameImage1.png")) == -1)
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
	//ポーズかどうか
	if (!pose)
	{
		//記憶時間かどうか
		if (!stand)
		{
			Standby();
			//記憶時間フレーム加算
			if (standby_count++ % 60 == 0)
			{
				standby_limit--;
			}
		}
		else
		{
			//スタートボタンでポーズ
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
			{
				pose = true;
			}
			else
			{
				game_count++;
			}
			//ゲーム時間計測
			if (game_count % 60 == 0)
			{
				time_limit--;
				if (time_limit <= 0)
				{
					return new GAME_OVER();
				}
			}

			//カーソル移動
			//十字キー下
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
			//上移動
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
			//右移動
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
			//左移動
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

			//色付け
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
			{
				player_stage[cursol_count_y][cursol_count_x] = 2;//緑
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
			{
				player_stage[cursol_count_y][cursol_count_x] = 1;//赤
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_Y))
			{
				player_stage[cursol_count_y][cursol_count_x] = 4;//黄色
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_X))
			{
				player_stage[cursol_count_y][cursol_count_x] = 3;//青
			}
		}
	}
	else
	{
		//ポーズ中にAでクリア判定＆リザルトへ
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
		{
			if (ClearJudge())
			{
				return new RESULT(this);
			}
		}
		//ポーズ中にBでポーズ解除
		else if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
		{
			pose = false;
		}
		else;
	}
	return this;
}


void EAZY_DIF::Standby()
{
	//記憶時間計測
	if (standby_limit <= 0)
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
			//採点
			if (player_stage[i][j] == eazy_stage[i][j])
			{
				answer_stage[i][j] = true;
				point += 100 / (EAZY_SIZE * EAZY_SIZE);
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
	//ポーズかどうか
	if (!pose)
	{
		DrawBox(0, 0, 1280, 720, 0xffffff, TRUE);
		//記憶時間中かどうか
		if (stand)
		{
			SetFontSize(10);
			for (int i = 0; i < EAZY_SIZE; i++)
			{
				for (int j = 0; j < EAZY_SIZE; j++)
				{
					//プレイヤー描画
					switch (player_stage[i][j])
					{
					case 0:
						DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[0], TRUE);//白
						break;
					case 1:
						DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[1], TRUE);//赤
						break;
					case 2:
						DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[2], TRUE);//緑
						break;
					case 3:
						DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[3], TRUE);//青
						break;
					case 4:
						DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[4], TRUE);//黄色
						break;
					default:
						break;
					}
				}
			}
			DrawGraph(300, 200, frame_image, TRUE);
			SetFontSize(20);
			DrawFormatString(0, 0, 0xffff00, "%3d", time_limit);
			DrawGraph(300 + (101 * cursol_count_x), 200 + (101 * cursol_count_y), cursol_image, TRUE);
		}
		//記憶時間中
		else
		{

			SetFontSize(20);
			DrawString(400, 600, "覚えろ", 0xff00ff);

			for (int i = 0; i < EAZY_SIZE; i++)
			{
				for (int j = 0; j < EAZY_SIZE; j++)
				{
					//お手本描画
					switch (eazy_stage[i][j])
					{
					case 0:
						DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[0], TRUE);//白
						break;
					case 1:
						DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[1], TRUE);//赤
						break;
					case 2:
						DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[2], TRUE);//緑
						break;
					case 3:
						DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[3], TRUE);//青
						break;
					case 4:
						DrawGraph((300 + j) + (IMAGE_SIZE * j), (200 + i) + (IMAGE_SIZE * i), block_image[4], TRUE);//黄色
						break;
					default:
						break;
					}
				}
			}
			DrawGraph(300, 200, frame_image, TRUE);
			SetFontSize(20);
			DrawFormatString(0, 0, 0xffff00, "%3d", standby_limit);
		}
	}
	//ポーズ中
	else
	{
		SetFontSize(30);
		DrawFormatString(0, 0, 0xffff00, "Final Answer？");
		DrawFormatString(0, 40, 0x00ff00, "Aで採点画面　　　Bでゲーム画面に戻る");
	}
}