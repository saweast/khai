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

// окно Найти стало доступным
void __fastcall TFindForm::FormShow(TObject *Sender)
{
    Edit1->SetFocus(); // установить курсор в поле редактирования
}

// Щелчок на кнопке OK (пользователь ввел критерий запроса)
void __fastcall TFindForm::Button1Click(TObject *Sender)
{
    Tag = 1; // пользователь щелкнул на кнопке OK
    Close();
}

// нажата клавиша
void __fastcall TFindForm::Edit1KeyPress(TObject *Sender, char &Key)
{
    if ( Key == 13) Button1->SetFocus(); // переместить фокус на кнопку OK
}

