#pragma once
#include"CONTROLER.h"
#include"AbstractScene.h"
class GameClear:public AbstractScene
{
private:
	//ここにゲームクリアで使う変数を

	int gameclear_img;	// 画像用変数
	int count;	// カウント
	int blink;	// 点滅用変数
	int font;	// フォント用変数

public:
	//ここにゲームクリアで使う関数を

	//コンストラクタ
	//この中で上で宣言した変数を初期化する
	GameClear();
	//この中で作ったものを消す
	~GameClear() {};


	//ここでGameClearで使う変数の値の更新をする
	AbstractScene* Update() override;
	//ここでGameClearの描画のすべてを書く
	void Draw() const override;
};

