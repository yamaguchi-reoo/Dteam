#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
class GAME_OVER : public AbstractScene
{
private:
	int gameoverimg;	// �摜�p�ϐ�
	int count;	// �J�E���g
	int blink;	// �_�ŗp�ϐ�
	
public:
	GAME_OVER();
	~GAME_OVER() {};

	AbstractScene* Update() override;
	void Draw() const override;
};

