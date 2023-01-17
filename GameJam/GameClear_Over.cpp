#include"DxLib.h"

/* プロトタイプ宣言 */
void DrawGameClear(void);	// ゲームクリア処理
void DrawGameOver(void);	// ゲームオーバー処理

int LoadImages(void);		// 画像読込

/* ゲームクリア処理 */
void DrawGameClear(void)
{
	// ゲームクリア画像処理

	// Bボタンでメニュー画面へ

	// 表示メッセージ
	SetFontSize(16);
	DrawString(150, 420, " ---- Bボタンでメニュー画面へ ---- ", 0xffffff, 0x000000);
}

/* ゲームオーバー処理 */
void DrawGameOver(void)
{
	// ゲームオーバー画像処理

	// Bボタンでメニュー画面へ
	
	// 表示メッセージ
	SetFontSize(16);
	DrawString(150, 420, " ---- Bボタンでメニュー画面へ ----", 0xffffff, 0x000000);
}

/* 画像読込処理 */
int LoadImages(void)
{

}

