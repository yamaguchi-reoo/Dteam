#pragma once
#include"AbstractScene.h"
#include"SELECT.h"

#define HARD_SIZE 5
#define CURSOL_X 300
#define CURSOL_Y 200



class HARD_DIF :public AbstractScene
{
private:
	//ここにGame_Mainで使う変数を

	int block_image[4];							//ブロック画像用変数
	int hard_stage[HARD_SIZE][HARD_SIZE];		//お手本画像用変数
	int player_stage[HARD_SIZE][HARD_SIZE];		//プレイヤー入力用変数
	bool answer_stage[HARD_SIZE][HARD_SIZE];	//採点用配列
	int frame_image;							//罫線画像用変数
	int cursol_image;							//カーソル画像用変数
	int cursol_count_x, cursol_count_y;			//カーソル移動用変数
	int standby_count;							//記憶時間用フレーム数
	int game_count;								//ゲーム時間用フレーム数
	int time_limit;								//ゲーム実時間変数
	int standby_limit;							//記憶実時間変数
	int point;									//点数
	bool stand;									//記憶時間かどうか
	bool pose;									//画面を止めているかどうか

public:
	//コンストラクタ
	HARD_DIF();
	//デストラクタ
	~HARD_DIF() {};

	//ここにGame_Mainで使う関数を
	//この関数で値の更新を行う
	AbstractScene* Update() override;
	//この関数で描画をすべて書く
	void Draw() const override;

	//記憶時間用関数
	void Standby();
	//クリア判定用関数
	bool ClearJudge();

	//変数をゲットする関数たち
	int Get_H_Stage(int i,int j)
	{
		return hard_stage[i][j];
	}
	int Get_P_Stage(int i, int j)
	{
		return player_stage[i][j];
	}
	int Get_Point() { return point; }
};

