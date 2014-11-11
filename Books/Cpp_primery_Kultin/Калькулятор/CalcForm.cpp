#include <vcl.h>
#pragma hdrstop

#include "CalcForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

float accum; // аккумулятор (рез-т выполнения операции)
int op;      /* операция:
                  1 - "+";
                  2 - "-";
                  0 - "выполнить" (нажата кнопка "=" */

int f;       /* f == 0 - ждем первую цифру нового числа, например, после выполнения
                         операции, когда на индикаторе результат.
                f == 1 - ждем остальные цифры */

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    f =0;     // ждем первую цифру
    op = 0;   // предыдущая операция выполнена
    StaticText1->Caption = 0;
}

// кнопка "0"
void __fastcall TForm1::Btn0Click(TObject *Sender)
{
    if ( f != 0)
           StaticText1->Caption = StaticText1->Caption + "0";
}

// кнопка "1"
void __fastcall TForm1::Btn1Click(TObject *Sender)
{
 if ( f == 0)
    {
       StaticText1->Caption = "1";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "1";
}

// кнопка "2"
void __fastcall TForm1::Btn2Click(TObject *Sender)
{
 if ( f == 0)
    {
       StaticText1->Caption = "2";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "2";
}

// кнопка "3"
void __fastcall TForm1::Btn3Click(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "3";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "3";
}

// кнопка "4"
void __fastcall TForm1::Btn4Click(TObject *Sender)
{
if ( f == 0)
    {
       StaticText1->Caption = "4";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "4";
}

// кнопка "5"
void __fastcall TForm1::Btn5Click(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "5";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "5";
}

// кнопка "6"
void __fastcall TForm1::Btn6Click(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "6";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "6";
}

// кнопка "7"
void __fastcall TForm1::Btn7Click(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "7";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "7";
}

// кнопка "8"
void __fastcall TForm1::Btn8Click(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "8";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "8";
}

// кнопка "9"
void __fastcall TForm1::Btn9Click(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "9";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "9";
}

// кнопка "," (десятичная точка)
void __fastcall TForm1::BtnkClick(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "0,";
       f = 1;
    }
    else
    {
        if ( StaticText1->Caption.Pos(",") == 0)
            StaticText1->Caption = StaticText1->Caption + ",";
    }
}

// кнопка "С" (сброс)
void __fastcall TForm1::BtnCClick(TObject *Sender)
{
    StaticText1->Caption = "0";
    accum = 0;
    op = 0;
    f = 0; // ждем первую цифру числа
}

// выполнить операцию
void __fastcall TForm1::DoOp(void)
{
    /* accum содержит результат предыдущей операции.
       Сейчас надо выполнить операцию, код которой op.
       перанд находится на индикаторе.*/

    float op2 =  StrToFloat(StaticText1->Caption);
    switch ( op )
    {
        case 0 : accum = op2;  break;
        case 1 : accum += op2; break;
        case 2 : accum -= op2; break;
    }
    StaticText1->Caption = FloatToStrF(accum,ffGeneral,6,3);
}

// кнопка "+"
void __fastcall TForm1::BtnPClick(TObject *Sender)
{
    /* надо выполнить предыдущую операцию,
       вывести результат на индикатор, запомнить
       текущую операцию и установить режим ввода
       нового числа */
    if ( f != 0)
    {
        // на индикаторе есть число
        DoOp(); // выполнить предыдущую операцию
        f = 0;  // ждем первую цифру нового числа
    }
    op =1;
}

// кнопка "-"
void __fastcall TForm1::BtnMClick(TObject *Sender)
{
    if ( f != 0)
    {
        // на индикаторе есть число
        DoOp(); // выполнить предыдущую операцию
        f = 0;  // ждем первую цифру нового числа
    }
    op = 2; // запомнить текущую операцию
}

// кнопка "="
void __fastcall TForm1::BtnEClick(TObject *Sender)
{
    if ( f != 0)
    {
        DoOp(); // выполнить опрерацию
        f = 0;  // ждем первую цифру нового числа
    }
    op = 0;
}

