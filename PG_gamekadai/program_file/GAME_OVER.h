#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
class GAME_OVER : public AbstractScene
{
private:

public:
	GAME_OVER();
	~GAME_OVER() {};

	AbstractScene* Update() override;
	void Draw() const override;
};

