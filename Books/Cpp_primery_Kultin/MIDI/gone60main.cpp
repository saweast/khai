/*
   ��������� ������������� ������������� ���������� MediaPlayer
   ��� ��������������� MIDI-�����. ������� ��������������� "�� �����",
   �� ��� ���, ���� ������������ �� ������� ����� ��� �� ������� �����,
   ���������� �� ������� ������.
*/

#include <vcl.h>
#pragma hdrstop

#include "gone60main.h"
#include "Math.hpp"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;



__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

int pw;       // "���������" �����
int rem = 60; // ������� ������� �� ���������� �������

// ������ ������ ���������
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    TSearchRec sr;

    if ( FindFirst("*.mid",faAnyFile, sr) == 0)
    {
        MediaPlayer1->FileName = sr.Name;
        MediaPlayer1->Open();
        MediaPlayer1->Play();
    }

    Randomize();
    pw = RandomRange(100,999); // "���������" �����
}

// ���������, ���������� �� ����� ���� �����
void __fastcall TForm1::isRight(void)
{
    if ( StrToInt(Edit1->Text) == pw )
        {
            Timer1->Enabled = false;
            Button1->Enabled = false;
            Edit1->Enabled = false;
            MediaPlayer1->Stop();
            MediaPlayer1->Close();
            // ������������!
            //PlaySound("Applause.wav",0, SND_ASYNC);
            ShowMessage("����������!\n�� ������� ����� �� " +
                        IntToStr(60 - rem)+ " ���");
        }
}

// ������� ������� � ���� ��������������
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
    if ( ( Edit1->Text.Length() < 3) && ((Key >= '0') && (Key <= '9')))
        return;

    if ( Key == VK_RETURN)
    {
        isRight(); // ���������, ���������� �� ����� ���� ������������
        return;
    }

    if ( Key == VK_BACK) return;

    // ��������� ������� ���������
    Key = 0;
}

// ���������� ���� �������������� ����������
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
    // ������ OK �������� ������ � ��� ������,
    // ���� � ���� �������������� ��� ������� (�����)
    if ( Edit1->Text.Length() == 3)
        Button1->Enabled = true;
    else
        Button1->Enabled = false;
}

// ������ �� ������ OK
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    isRight();  // ���������, ���������� �� ����� ���� ������������
}

// ������ �� �������
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    rem--;
    Label4->Caption = IntToStr(rem);
    if (rem == 0 )
    {
        // �����, ���������� �� ������� ������ �������
        Timer1->Enabled = false;
        Edit1->Enabled = false;
        Button1->Enabled = false;

        MediaPlayer1->Stop();

        ShowMessage("� ���������, �� �� ���������� � ������������ �������\n"
                    "\"���������\" ����� - " + IntToStr(pw) );
    }
}

// ��������� ������ ����������
void __fastcall TForm1::MediaPlayer1Notify(TObject *Sender)
{
    /* ���� ����� ������������� ���� � �������� �������� Notify ����� true
       (����� Play �� ��������� ����������� �������� Notify �������� true),
       �� � ������ ��������� ��������������� ��������� ������� Notyfy */

    //ShowMessage("Notify" + IntToStr(MediaPlayer1->Mode) );
    if (Timer1->Enabled)
        /* ������������ ������� ������ �������, �����������
           �� ������� ������. ��������� ��� ���. */
        MediaPlayer1->Play();
}

// ���������� ������ ���������
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    Timer1->Enabled = false;
    MediaPlayer1->Stop();
    MediaPlayer1->Close();
}


