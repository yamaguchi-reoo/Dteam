#pragma once
#include"AbstractScene.h"

class TITLE : public AbstractScene
{private:
	//ここにタイトルで使う変数を
	int titleimage;//タイトル変数
	int titlearrow;//タイトルカーソル
	int cursor_x;
	int cursor_no;
	
public:
	//ここにタイトルで使う関数を

	//コンストラクタ
	//この関数の中で上で宣言した変数を初期化する
	TITLE();

	~TITLE() {};

	//この関数に描画のすべてを書く（描画以外は書かない）
	void Draw() const override;

	//この関数内で値の更新をする
	AbstractScene* Update() override;
};

