/*
    Воспроизведение анимации при помощи компонента Animate.
    Анимация загружается из файла в начале работы программы.
    Процесс воспроизведения активизируется автоматически,
    в момент появления окна.

*/

#include <vcl.h>
#pragma hdrstop

#include "animForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


bool loaded = false; // анимация загружена

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    /* если файл анимации недоступен или анимация
       сопровождается звуком, возникает исключение */
    try
    {
        Animate1->FileName = "delphi.avi";
    }
    catch (Exception &e)
    {
    }
    Form1->Caption = "Анимация - " + Animate1->FileName;
    loaded = true;
    Label1->Caption =
        "Кадров: " + IntToStr(Animate1->FrameCount) +
        "  Размер кадров: " + IntToStr(Animate1->Width) +
                    "x" + IntToStr(Animate1->Height);

}

// начало работы программы
void __fastcall TForm1::FormActivate(TObject *Sender)
{
    if ( loaded)
        // воспроизвести анимацию один раз с певого по последний кадр
        Animate1->Play(1,Animate1->FrameCount,1);
}

// щелчок на кнопке Play
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if ( loaded)
        // воспроизвести анимацию один раз с певого по последний кадр
        Animate1->Play(1,Animate1->FrameCount,1);
}


