/*
    ��������������� �������� ��� ������ ���������� Animate.
    �������� ����������� �� ����� � ������ ������ ���������.
    ������� ��������������� �������������� �������������,
    � ������ ��������� ����.

*/

#include <vcl.h>
#pragma hdrstop

#include "animForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


bool loaded = false; // �������� ���������

// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    /* ���� ���� �������� ���������� ��� ��������
       �������������� ������, ��������� ���������� */
    try
    {
        Animate1->FileName = "delphi.avi";
    }
    catch (Exception &e)
    {
    }
    Form1->Caption = "�������� - " + Animate1->FileName;
    loaded = true;
    Label1->Caption =
        "������: " + IntToStr(Animate1->FrameCount) +
        "  ������ ������: " + IntToStr(Animate1->Width) +
                    "x" + IntToStr(Animate1->Height);

}

// ������ ������ ���������
void __fastcall TForm1::FormActivate(TObject *Sender)
{
    if ( loaded)
        // ������������� �������� ���� ��� � ������ �� ��������� ����
        Animate1->Play(1,Animate1->FrameCount,1);
}

// ������ �� ������ Play
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if ( loaded)
        // ������������� �������� ���� ��� � ������ �� ��������� ����
        Animate1->Play(1,Animate1->FrameCount,1);
}


