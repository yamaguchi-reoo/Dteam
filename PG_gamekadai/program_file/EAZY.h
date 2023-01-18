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

	int block_image[4];
	int cursol_x, cursol_y;
	int eazy_stage[EAZY_SIZE][EAZY_SIZE];
	int player_stage[EAZY_SIZE][EAZY_SIZE];
	bool answer_stage[EAZY_SIZE][EAZY_SIZE];
	int frame_image;
	int cursol_image;
	int cursol_count_x ,cursol_count_y;
	int standby_count;
	int game_count;
	int time_limit;
	int standby_limit;
	int point;
	bool stand;
	bool pose;
	EAZY_DIF* eazy;

public:
	//コンストラクタ
	EAZY_DIF();
	~EAZY_DIF() {};

	//ここにGame_Mainで使う関数を
	//この関数で値の更新を行う
	AbstractScene* Update() override;
	//この関数で描画をすべて書く
	void Draw() const override;

	void Standby();
	bool ClearJudge();

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

