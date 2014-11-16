/*
    Модуль формы "О программе.
    Ссылку на этот модуль (директиву #include "about.h")
    надо поместить в модуль главной формы (MEditFrm.cpp)

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

// щелчок на кнопке OK
void __fastcall TAboutForm::Button1Click(TObject *Sender)
{
    ModalResult = mrOk;

}

