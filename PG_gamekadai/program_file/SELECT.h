#pragma once
#include"AbstractScene.h"

#define LETT_X 570
#define LETT_Y 170
#define LETT_SPACE 160
#define CURSOL_SIZE_Y 170
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
	int cursol;
	int selectimage;
	DIFFICULTY difficul;
public:

	SELECT();
	~SELECT() {
		
	};

	void Draw() const override;
	AbstractScene* Update() override;

};

