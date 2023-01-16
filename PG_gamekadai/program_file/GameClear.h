#pragma once
#include"CONTROLER.h"
#include"AbstractScene.h"
class GameClear:public AbstractScene
{
private:
	//ここにゲームクリアで使う変数を
public:
	//ここにゲームクリアで使う関数を

	//コンストラクタ
	//この中で上で宣言した変数を初期化する
	GameClear();
	//この中で作ったものを消す
	~GameClear();


	//ここでGameClearで使う変数の値の更新をする
	AbstractScene* Update() override;
	//ここでGameClearの描画のすべてを書く
	void Draw() const override;
};

