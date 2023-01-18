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

	int block_image[4];
	int cursol_x, cursol_y;
	int hard_stage[HARD_SIZE][HARD_SIZE];
	int player_stage[HARD_SIZE][HARD_SIZE];
	bool answer_stage[HARD_SIZE][HARD_SIZE];
	int frame_image;
	int cursol_image;
	int cursol_count_x, cursol_count_y;
	int standby_count;
	int game_count;
	int time_limit;
	int standby_limit;
	int point;
	bool stand;
	bool pose;

public:
	//コンストラクタ
	HARD_DIF();
	~HARD_DIF() {};

	//ここにGame_Mainで使う関数を
	//この関数で値の更新を行う
	AbstractScene* Update() override;
	//この関数で描画をすべて書く
	void Draw() const override;

	void Standby();
	bool ClearJudge();

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

