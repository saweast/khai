/*
    Запуск браузера (Internet Explorer или
    другой программы, обеспечивающей доступ в Internet).

*/

#include <vcl.h>
#pragma hdrstop

#include "wwwForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{

}


// щелчок в поле Label1
void __fastcall TForm1::Label1Click(TObject *Sender)
{
    // Открыть файл, имя которого находится в поле Label1
    ShellExecute(Form1->Handle,"open",Label1->Caption.c_str(),
                 NULL,NULL,SW_RESTORE);
}

