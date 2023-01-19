#pragma once
#include "AbstractScene.h"
#include "EAZY.h"
#include "NORMAL.h"
#include "HARD.h"
class RESULT : public AbstractScene
{
private:
	EAZY_DIF* easy;
	NORMAL_DIF* normal;
	HARD_DIF* hard;

	int point;
	int h_stage[HARD_SIZE][HARD_SIZE];
	int h_p_stage[HARD_SIZE][HARD_SIZE];
	int n_stage[NORMAL_SIZE][NORMAL_SIZE];
	int n_p_stage[NORMAL_SIZE][NORMAL_SIZE];
	int e_stage[EAZY_SIZE][EAZY_SIZE];
	int e_p_stage[EAZY_SIZE][EAZY_SIZE];
	int image[5];
	int frame_image[3];


	int zibun_image;
	int kotae_image;
	int botan_image;
public:
	RESULT();
	RESULT(EAZY_DIF*);
	RESULT(NORMAL_DIF*);
	RESULT(HARD_DIF*);
	~RESULT() {};

	AbstractScene* Update() override;
	void Draw() const override;
};

