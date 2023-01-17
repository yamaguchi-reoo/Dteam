#pragma once
#include"AbstractScene.h"
#include"COLOR.h"
#include"SELECT.h"

#define NORMAL_SIZE 4


class NORMAL_DIF :public AbstractScene
{
private:
	//ここにGame_Mainで使う変数を

	int block_image[4];
	int cursol_x, cursol_y;
	int normal_stage[6][6];


public:
	//コンストラクタ
	NORMAL_DIF();
	~NORMAL_DIF() {};


	//ここにGame_Mainで使う関数を
	//この関数で値の更新を行う
	AbstractScene* Update() override;
	//この関数で描画をすべて書く
	void Draw() const override;
};

