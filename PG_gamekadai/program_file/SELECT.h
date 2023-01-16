#pragma once
#include"AbstractScene.h"

#define LETT_X 570
#define LETT_Y 80
#define LETT_SPACE 160
#define CURSOL_SIZE_Y 80
#define CURSOL_SIZE_X 

enum class DIFFICULTY
{
	EAZY = 0,
	NORMAL, 
	HARD
};

class SELECT : public AbstractScene
{
private:
	int cursol_x, cursol_y;
	DIFFICULTY difficul;
public:

	SELECT();
	~SELECT() {};

	void Draw() const override;
	AbstractScene* Update() override;

};

