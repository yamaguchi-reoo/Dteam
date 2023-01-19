#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
class GAME_OVER : public AbstractScene
{
private:
	int gameoverimg;	// 画像用変数
	int count;	// カウント
	int blink;	// 点滅用変数
	
public:
	GAME_OVER();
	~GAME_OVER() {};

	AbstractScene* Update() override;
	void Draw() const override;
};

