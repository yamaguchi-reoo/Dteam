#pragma once
#include"AbstractScene.h"
class HELP : public AbstractScene
{
private:
	int help_image;
	//ここにタイトルで使う変数を

public:
	//ここにタイトルで使う関数を

	//コンストラクタ
	//この関数の中で上で宣言した変数を初期化する
	HELP();

	~HELP() {

	};

	//この関数に描画のすべてを書く（描画以外は書かない）
	void Draw() const override;

	//この関数内で値の更新をする
	AbstractScene* Update() override;



};

