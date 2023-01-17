#pragma once
#include"AbstractScene.h"
#include"COLOR.h"
#include"SELECT.h"

#define HARD_SIZE 6

class HARD_DIF :public AbstractScene
{
private:
	//ここにGame_Mainで使う変数を

	int block_image[4];
	int cursol_x, cursol_y;
	int hard_stage[HARD_SIZE][HARD_SIZE];


public:
	//コンストラクタ
	HARD_DIF();
	~HARD_DIF() {};


	//ここにGame_Mainで使う関数を
	//この関数で値の更新を行う
	AbstractScene* Update() override;
	//この関数で描画をすべて書く
	void Draw() const override;
};
