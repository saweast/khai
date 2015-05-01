#include <vcl.h>
#pragma hdrstop

#include "Find_.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TFindForm *FindForm;

__fastcall TFindForm::TFindForm(TComponent* Owner)
    : TForm(Owner)
{
}

// ���� ����� ����� ���������
void __fastcall TFindForm::FormShow(TObject *Sender)
{
    Edit1->SetFocus(); // ���������� ������ � ���� ��������������
}

// ������ �� ������ OK (������������ ���� �������� �������)
void __fastcall TFindForm::Button1Click(TObject *Sender)
{
    Tag = 1; // ������������ ������� �� ������ OK
    Close();
}

// ������ �������
void __fastcall TFindForm::Edit1KeyPress(TObject *Sender, char &Key)
{
    if ( Key == 13) Button1->SetFocus(); // ����������� ����� �� ������ OK
}

