/*
    ������ ����� "� ���������.
    ������ �� ���� ������ (��������� #include "about.h")
    ���� ��������� � ������ ������� ����� (MEditFrm.cpp)

*/
#include <vcl.h>
#pragma hdrstop

#include "About.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutForm *AboutForm;

__fastcall TAboutForm::TAboutForm(TComponent* Owner)
    : TForm(Owner)
{
}

// ������ �� ������ OK
void __fastcall TAboutForm::Button1Click(TObject *Sender)
{
    ModalResult = mrOk;

}

