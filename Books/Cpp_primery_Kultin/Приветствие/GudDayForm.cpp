#include <vcl.h>
#pragma hdrstop

#include "GudDayForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

#include "DateUtils.hpp"

TForm1 *Form1;

Graphics::TBitmap *bgp; // фоновый рисунок

AnsiString sMonth[] = {"","€нвар€","феврал€","марта",
      "апрел€","ма€","июн€",
      "июл€","августа","сент€бр€",
      "окт€бр€","но€бр€","декабр€"};

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    bgp = new Graphics::TBitmap();
    try
    {
        bgp->LoadFromFile("sky.bmp");
    }
    catch (EFOpenError &e)
    {

    }
}

// обаботка событи€ Paint
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    int h;           // текущее врем€ (часы)
    AnsiString mes;  // сообщение
    int wt,ht;         // размер (ширина и высота) области вывода текста
    int x,y;         // координаты области вывода текста

    h = HourOf( Now() );

    if ( h <= 4 ) mes = "ƒоброй ночи!";
    else if ( h < 12 ) mes = "ƒоброе утро!" ;
    else if ( h <= 16)  mes = "ƒобрый день!" ;
    else if ( h <= 16)  mes = "ƒобрый день!" ;
         else mes = "ƒобрый вечер!";

    Form1->Font->Name = "Times New Roman";
    //Form1->Font->Color = clBlue;
    Form1->Canvas->Font->Size = 20;

    // определить размер области вывода текста
    wt = Canvas->TextWidth(mes);
    ht = Canvas->TextHeight(mes);

    x = (ClientWidth - wt) / 2;
    y = ClientHeight / 2 - ht;

    // фонова€ картинка
    Canvas->Draw(0,0,bgp);

    // чтобы область вывода текста была прозрачной
    Canvas->Brush->Style = bsClear;

    Canvas->TextOutA(x,y,mes);

    y = y + ht; // коорднината нижней границы области вывода текста

    // дата и день недели
    mes = FormatDateTime("—егодн€ d", Now() );
    mes = mes + " " + sMonth[MonthOf( Now())] + ", " +
                FormatDateTime("dddd", Now() );

    /* размер шрифта вывода даты на 4 пункта меньше
       размера шрифта приветстви€ */
    Canvas->Font->Size -= 4;
    wt = Canvas->TextWidth(mes);
    ht = Canvas->TextHeight(mes);

    x = (ClientWidth - wt) / 2;
    y = y + 6;

    Canvas->TextOutA(x,y,mes);
}

// пользователь изменил размер формы
void __fastcall TForm1::FormResize(TObject *Sender)
{
    Form1->Refresh(); // перерисовать окно
}

