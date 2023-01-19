#pragma once
#include"AbstractScene.h"
#include"SELECT.h"

#define NORMAL_SIZE 4
#define CURSOL_X 300
#define CURSOL_Y 200



class NORMAL_DIF :public AbstractScene
{
private:
	//ここにGame_Mainで使う変数を

	int block_image[4];                             //ブロック画像用変数
	int normal_stage[NORMAL_SIZE][NORMAL_SIZE];     //お手本用配列
	int player_stage[NORMAL_SIZE][NORMAL_SIZE];     //プレイヤーが実際に入力する変数
	bool answer_stage[NORMAL_SIZE][NORMAL_SIZE];    //解答用変数
	int frame_image;                                //罫線画像用変数
	int cursol_image;                               //カーソル画像用変数
	int cursol_count_x, cursol_count_y;             //カーソル用変数
	int standby_count;                              //お手本を見る時間をフレーム単位で数える変数
	int game_count;                                 //ゲーム時間をフレーム単位で数える変数
	int time_limit;                                 //実時間のタイムリミット用変数
	int standby_limit;                              //お手本用の実時間のタイムリミット用変数
	int point;                                      //点数用変数
	bool stand;                                     //スタンバイが終了したかどうかの変数
	bool pose;                                      //ゲームを止めているかどうかの変数

	int Nflame_x;
	int Nflame_y;

	int mozi_image;
	int kakunin_image;
	int timeer_image;

public:
	//コンストラクタ
	NORMAL_DIF();
	//デストラクタ
	~NORMAL_DIF() {};

	//ここにGame_Mainで使う関数を
	//この関数で値の更新を行う
	AbstractScene* Update() override;
	//この関数で描画をすべて書く
	void Draw() const override;

	//画像を覚える画面の関数
	void Standby();
	
	//点数を数えてクリアかどうか判定する変数
	bool ClearJudge();


	//変数の中身をゲットする関数
	int Get_N_Stage(int i, int j)
	{
		return normal_stage[i][j];
	}
	int Get_P_Stage(int i, int j)
	{
		return player_stage[i][j];
	}

	int Get_Point() { return point; }
};

