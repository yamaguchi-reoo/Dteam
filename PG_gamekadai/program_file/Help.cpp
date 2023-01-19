#include "Help.h"
#include"AbstractScene.h"
#include"DxLib.h"
#include"CONTROLER.h"
#include"title.h"

HELP::HELP()
{

	if ((help_image = LoadGraph("images/helpimage.png")) == -1);
}


AbstractScene* HELP::Update()
{

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {

		return new TITLE();
	}

	return this;
}

void HELP::Draw() const
{

	DrawGraph(0, 0, help_image, TRUE);

}
