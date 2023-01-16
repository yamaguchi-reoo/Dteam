#pragma once
#include"AbstractScene.h"
class GameMain:public AbstractScene
{
private:
	//ここにGame_Mainで使う変数を

public:
	//コンストラクタ
	GameMain();
	~GameMain();


	//ここにGame_Mainで使う関数を
	//この関数で値の更新を行う
	AbstractScene* Update() override;
	//この関数で描画をすべて書く
	void Draw() const override;
};

