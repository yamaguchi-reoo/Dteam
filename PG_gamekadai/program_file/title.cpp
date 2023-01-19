#include"DxLib.h"
#include "title.h"
#include <stdio.h>
#include"CONTROLER.h"
#include"SELECT.h"
#include"GameEnd.h"

TITLE::TITLE()
{
	titleimage = LoadGraph("images/title.png", FALSE);
	titlearrow = LoadGraph("images/yazirusi.png", FALSE);
	cursor_x = 400;
    cursor_no = 0;	
}


AbstractScene* TITLE::Update()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN)) 
	{
		if (cursor_no < 1)++cursor_no;
		else --cursor_no;

	}
	
	else if(PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
	{
		if (cursor_no > 0)--cursor_no;
		else ++cursor_no;
	}
	
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B)) {
		//ステージセレクト画面に行く
		if (cursor_no == 0)
		{
			return new SELECT();
		}
		if(cursor_no == 1) {
			return nullptr;
		}
	}

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {
		return nullptr;
	}

	return this;
}

void TITLE::Draw() const
{

	DrawGraph(0, 0, titleimage, TRUE);//タイトルの画像表示
	DrawGraph(cursor_x, 400+(cursor_no*150), titlearrow, TRUE);//タイトルカーソル表示


}