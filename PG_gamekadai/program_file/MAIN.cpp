#include "MAIN.h"
#include"GameEnd.h"
#include <DxLib.h>
#include <stdio.h>
#include"SELECT.h"
#include"GameClear.h"
#include"GAME_OVER.h"
#include"EAZY.h"
#include"HARD.h"
#include"NORMAL.h"
#include"Help.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	double dNextTime = GetNowCount();

	SetMainWindowText("いろあい");
	SetWindowIconID(01);

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);  //画面サイズを設定
	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetAlwaysRunFlag(true);		//常にアクティブにする

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);		//フォントをアンチエイリアス対応にする。

	SetJoypadDeadZone(DX_INPUT_PAD1, 0.0);

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SceneManager* sceneMng;
	try
	{
		sceneMng = new SceneManager((AbstractScene*)new TITLE());

	}
	catch (const char* err)
	{
		FILE* fp = NULL;

		DATEDATA data;

		GetDateTime(&data);
		//ファイルオープン
		fopen_s(&fp, "data/ErrLog/ErrLog.txt", "a");
		//エラーデータの書き込み
		fprintf_s(fp, "%02d年 %02d月 %02d日 %02d時 %02d分 %02d秒 : %sがありません。\n", data.Year, data.Mon, data.Day, data.Hour, data.Min, data.Sec, err);

		return 0;
	}

	// ゲームループ
	while ((ProcessMessage() == 0) && (sceneMng->Update() != nullptr)) {


		ClearDrawScreen();		// 画面の初期化
		PAD_INPUT::UpdateKey();	//パッドの入力状態の更新
		sceneMng->Draw();

		ScreenFlip();			// 裏画面の内容を表画面に反映

		//フレームレートの設定
		dNextTime += 16.66;
		if (dNextTime > GetNowCount()) {
			WaitTimer((int)dNextTime - GetNowCount());
		}

		//Backボタンを押したら強制終了
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_BACK))
		{
			break;
		}
		//STARTボタンでタイトル画面へ移行
		//if ((PAD_INPUT::GetNowKey() == XINPUT_BUTTON_START) && (PAD_INPUT::GetPadState() == PAD_STATE::ON)) { sceneMng = new SceneManager((AbstractScene*)new Title()); }
	}

	InitFontToHandle();	//全てのフォントデータを削除
	InitGraph();		//読み込んだ全てのグラフィックデータを削除
	InitSoundMem();		//読み込んだ全てのサウンドデータを削除
	DxLib_End();
	return 0;
}