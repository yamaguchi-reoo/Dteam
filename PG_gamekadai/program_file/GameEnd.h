#pragma once
#include"AbstractScene.h"
class GameEnd : AbstractScene
{
private:
	//ここにGAMEエンドで使う変数を
	int endy = 0;
	int endtime = 0;

	int EndImg;


public:
	//ここにGAMEエンドで使う関数を

	//コンストラクタ
	//この中で宣言した変数を初期化する
	GameEnd();
	~GameEnd(){};

	//ここでGameEndで使う変数の値を更新する


	AbstractScene* Update() override;
	//ここで描画をすべて書く
	void Draw() const override;


};

