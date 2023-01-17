#pragma once
#include"AbstractScene.h"
#include"SELECT.h"

#define EAZY_SIZE 2


class EAZY_DIF :public AbstractScene
{
private:
	//ここにGame_Mainで使う変数を

	int block_image[4];
	int cursol_x, cursol_y;
	int eazy_stage[4][4];
	int frame_image;
	int cursol_image;
	int stand_count;
	bool stand;

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
};

