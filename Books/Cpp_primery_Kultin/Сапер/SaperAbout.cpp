#include <vcl.h>
#pragma hdrstop

#include "SaperAbout.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TAbout *About;

__fastcall TAbout::TAbout(TComponent* Owner)
        : TForm(Owner)
{
}

// Выбор URL адреса (щелчок в поле компонента Label5)
void __fastcall TAbout::Label5Click(TObject *Sender)
{
  /* наиболее просто передать в функцию ShellExecute
     строку-константу (URL адрес), так как показано ниже
    ShellExecute(AboutForm->Handle,
                "open",
                "http:\\\\www.bhv.ru",
                NULL,NULL)

    Лучше URL адрес брать из поля метки.
    В функцию ShellExute надо передать указатель (char*) на
    null terminated строку, но свойство Caption - это AnsiString.
    Преобразование Ansi строки в (char*) строку выполняет метод c_str()
*/

    // открыть файл, имя которого находится в поле Label5
    ShellExecute(About->Handle,"open",Label5->Caption.c_str(),
                 NULL,NULL,SW_RESTORE);
}

// щелчок на кнопке OK
void __fastcall TAbout::Button1Click(TObject *Sender)
{
    ModalResult = mrOk;
}

