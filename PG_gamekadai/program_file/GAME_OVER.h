#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
class GAME_OVER : public AbstractScene
{
private:
	int gameoverimg;	// ‰æ‘œ—p•Ï”
	
public:
	GAME_OVER();
	~GAME_OVER() {};

	AbstractScene* Update() override;
	void Draw() const override;
};

