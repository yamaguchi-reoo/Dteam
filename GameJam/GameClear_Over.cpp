#include"DxLib.h"

/* �v���g�^�C�v�錾 */
void DrawGameClear(void);	// �Q�[���N���A����
void DrawGameOver(void);	// �Q�[���I�[�o�[����

int LoadImages(void);		// �摜�Ǎ�

/* �Q�[���N���A���� */
void DrawGameClear(void)
{
	// �Q�[���N���A�摜����

	// B�{�^���Ń��j���[��ʂ�

	// �\�����b�Z�[�W
	SetFontSize(16);
	DrawString(150, 420, " ---- B�{�^���Ń��j���[��ʂ� ---- ", 0xffffff, 0x000000);
}

/* �Q�[���I�[�o�[���� */
void DrawGameOver(void)
{
	// �Q�[���I�[�o�[�摜����

	// B�{�^���Ń��j���[��ʂ�
	
	// �\�����b�Z�[�W
	SetFontSize(16);
	DrawString(150, 420, " ---- B�{�^���Ń��j���[��ʂ� ----", 0xffffff, 0x000000);
}

/* �摜�Ǎ����� */
int LoadImages(void)
{

}

