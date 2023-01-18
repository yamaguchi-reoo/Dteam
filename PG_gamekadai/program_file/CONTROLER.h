#pragma once
#include"DxLib.h"

#define BUTTONS 16

//�X�e�B�b�N
struct Stick
{
    short ThumbX;    //�����l
    short ThumbY;    //�c���l
};

class PAD_INPUT
{
private:
    static char NowKey[BUTTONS]; //����̓��̓L�[
    static char OldKey[BUTTONS]; //�O��̓��̓L�[
    static XINPUT_STATE Input; //�p�b�h
    static Stick Rstick; //�E�X�e�B�b�N
    static Stick Lstick; //���X�e�B�b�N
private:
    //�R���X�g���N�^
    PAD_INPUT() = default;
public:
    //�p�b�h���̍X�V
    static void UpdateKey()
    {
        // ���̓L�[�擾
        GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);

        for (int i = 0; i < BUTTONS; i++)
        {
            OldKey[i] = NowKey[i];
            NowKey[i] = Input.Buttons[i];
        }
    }

    //�{�^���������ꂽ�u��
    static bool OnButton(int button)
    {
        bool ret = (NowKey[button] == 1 && OldKey[button] == 0);
        return ret;
    }

    //�{�^���������Ă��
    static bool OnPressed(int button)
    {
        bool ret = (NowKey[button] == 1);
        return ret;
    }

    //�{�^���𗣂����u��
    static bool OnRelease(int button)
    {
        bool ret = (NowKey[button] == 1 && OldKey[button] == 0);
        return ret;
    }

    bool Comp_Key(int button) 
    {
        if (OldKey[button] = NowKey[button])
        {
            return true;
        }
        return false;
    };

};