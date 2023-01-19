#include "SELECT.h"
#include "DxLib.h"
#include <stdio.h>
#include"CONTROLER.h"
#include"HARD.h"
#include"EAZY.h"
#include"NORMAL.h"
#include "title.h"
#include"Help.h"
SELECT::SELECT()
{
	cursol_x = 490;
	cursol_y = CURSOL_SIZE_Y;
	difficul = DIFFICULTY::EAZY;
	selectimage = LoadGraph("images/select.png");
}


AbstractScene* SELECT::Update()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
		return new TITLE(); //title‚Ö
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_X))
	{
		return new HELP();
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
	{
		switch (difficul)
		{
		case DIFFICULTY::EAZY:
			cursol_y += LETT_SPACE;
			difficul = DIFFICULTY::NORMAL;
			break;
		case DIFFICULTY::NORMAL:
			cursol_y += LETT_SPACE;
			difficul = DIFFICULTY::HARD;
			break;
		case DIFFICULTY::HARD:
			cursol_y = CURSOL_SIZE_Y;
			difficul = DIFFICULTY::EAZY;
		default:
			break;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
	{
		switch (difficul)
		{
		case DIFFICULTY::EAZY:
			cursol_y = CURSOL_SIZE_Y + (LETT_SPACE * 2);
			difficul = DIFFICULTY::HARD;
			break;
		case DIFFICULTY::NORMAL:
			cursol_y -= LETT_SPACE;
			difficul = DIFFICULTY::EAZY;
			break;
		case DIFFICULTY::HARD:
			cursol_y -= LETT_SPACE;
			difficul = DIFFICULTY::NORMAL;
			break;
		default:
			break;
		}
	}


	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		switch (difficul)
		{
		case DIFFICULTY::EAZY:
			return new EAZY_DIF();
			break;
		case DIFFICULTY::NORMAL:
			return new NORMAL_DIF();
			break;
		case DIFFICULTY::HARD:
			return new HARD_DIF();
			break;
		default:
			break;
		}
	}



	return this;
}

void SELECT::Draw() const
{

	DrawGraph(0, 0, selectimage, FALSE);
	DrawBox(cursol_x, cursol_y, cursol_x + 290, cursol_y + 80, 0x000000, FALSE);
}

 