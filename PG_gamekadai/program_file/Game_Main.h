#pragma once
#include"AbstractScene.h"
#include"COLOR.h"
#include"SELECT.h"



class GameMain:public AbstractScene
{
private:
	//ここにGame_Mainで使う変数を

	int time;
	int cursol_x, cursol_y;
	int eazy_stage[4][4];
	int normal_stage[6][6];
	int hard_stage[8][8];
	COLOR* color;
	DIFFICULTY select;


public:
	//コンストラクタ
	GameMain();
	GameMain(DIFFICULTY);
	~GameMain() {};


	//ここにGame_Mainで使う関数を
	//この関数で値の更新を行う
	AbstractScene* Update() override;
	//この関数で描画をすべて書く
	void Draw() const override;
};

