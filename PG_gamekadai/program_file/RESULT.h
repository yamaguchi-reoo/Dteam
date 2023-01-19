#pragma once
#include "AbstractScene.h"
#include "EAZY.h"
#include "NORMAL.h"
#include "HARD.h"
class RESULT : public AbstractScene
{
private:
	EAZY_DIF* easy;			//イージーを持つ
	NORMAL_DIF* normal;		//ノーマルを持つ
	HARD_DIF* hard;			//ハードを持つ

	int point;				//点数
	int h_stage[HARD_SIZE][HARD_SIZE];			//ハードステージ変数
	int h_p_stage[HARD_SIZE][HARD_SIZE];		//ハードのプレイヤーの解答
	int n_stage[NORMAL_SIZE][NORMAL_SIZE];		//ノーマルステージ変数
	int n_p_stage[NORMAL_SIZE][NORMAL_SIZE];	//ノーマルのプレイヤーの解答
	int e_stage[EAZY_SIZE][EAZY_SIZE];			//イージーステージ変数
	int e_p_stage[EAZY_SIZE][EAZY_SIZE];		//イージーのプレイヤーの解答
	int image[5];								//ブロック画像
	int frame_image[3];							//各難易度の罫線


	int zibun_image;
	int kotae_image;
	int botan_image;
public:
	//各難易度のコンストラクタ
	RESULT();
	RESULT(EAZY_DIF*);
	RESULT(NORMAL_DIF*);
	RESULT(HARD_DIF*);
	~RESULT() {};

	AbstractScene* Update() override;
	void Draw() const override;
};

