#pragma once
#include"AbstractScene.h"
#include"SELECT.h"

#define EAZY_SIZE 3
#define CURSOL_X 300
#define CURSOL_Y 200



class EAZY_DIF :public AbstractScene
{
private:
	//ここにGame_Mainで使う変数を

	int block_image[4];							//ブロック画像
	int eazy_stage[EAZY_SIZE][EAZY_SIZE];		//お手本画像
	int player_stage[EAZY_SIZE][EAZY_SIZE];		//プレイヤー用配列
	bool answer_stage[EAZY_SIZE][EAZY_SIZE];	//解答
	int frame_image;							//罫線
	int cursol_image;							//カーソル
	int cursol_count_x ,cursol_count_y;			//カーソル移動
	int standby_count;							//記憶時間（フレーム）
	int game_count;								//ゲーム時間（フレーム）
	int time_limit;								//ゲーム実時間
	int standby_limit;							//記憶実時間
	int point;									//点数
	bool stand;									//記憶時間かどうか
	bool pose;									//ポーズ中かどうか
	EAZY_DIF* eazy;								//自分自身を持つ

public:
	//コンストラクタ
	EAZY_DIF();
	~EAZY_DIF() {};

	//ここにGame_Mainで使う関数を
	//この関数で値の更新を行う
	AbstractScene* Update() override;
	//この関数で描画をすべて書く
	void Draw() const override;

	//記憶時間関数
	void Standby();
	//クリア判定
	bool ClearJudge();


	//変数ゲット
	int Get_E_Stage(int i, int j)
	{
		return eazy_stage[i][j];
	}
	int Get_P_Stage(int i, int j)
	{
		return player_stage[i][j];
	}
	int Get_Point() { return point; }
};

