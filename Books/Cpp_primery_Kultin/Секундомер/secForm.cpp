/*
    Программа "Секундомер".
    Демонстрирует использование компонента Timer
*/

#include <vcl.h>
#pragma hdrstop

#include "secForm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"


TForm1 *Form1;

// время
int min;   // минуты
int sec;   // секунды
int msec;  // миллисекунды

// конструктор
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    // настройка таймера
    Timer1->Enabled = false;
    Timer1->Interval = 10;  // период сигналов от таймера 1 сек
}

// щелчок на кнопке Пуск/Стоп
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if ( ! Timer1->Enabled )
    {
        // запустить таймер
        Timer1->Enabled = true;
        Button1->Caption = "Стоп";
        Button2->Enabled = false;
     }
     else
     {
        // остановить таймер
        Timer1->Enabled = false;
        Button1->Caption = "Пуск";
        Button2->Enabled = true;
     }
}

// сигнал от таймера
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if ( msec < 99)
        msec++;
    else
    {
        msec = 0;
        if ( sec < 59 )
            sec++;
        else
        {
            sec = 0;
            min++;
            Label1->Caption = IntToStr(min);
        }
        if ( sec <= 9 )
            Label2->Caption = "0" + IntToStr(sec);
        else
            Label2->Caption = IntToStr(sec);

        // двоеточие
        Label4->Visible = ! Label4->Visible;
    }
    if ( msec <= 9 )
            Label3->Caption = "0" + IntToStr(msec);
        else
            Label3->Caption = IntToStr(msec);
}

// щелчок на кнопке Сброс
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    min = 0;
    sec = 0;
    msec = 0;
    Label1->Caption = "0";
    Label2->Caption = "00";
    Label3->Caption = "00";
}

