//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "olFlagForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Canvas->Font->Name = "Tahoma";
    Canvas->Font->Size = 12;
}

void __fastcall TForm1::FormPaint(TObject *Sender)
{
    #define WB 140
    #define HB 80
    #define D  36 // диаметр колец

    int x,y;
    AnsiString st = "Быстрее, выше, сильнее!";

    // вычислить координаты левого верхнего угла флага
    x = (ClientWidth -  WB) / 2;
    y = (ClientHeight - HB ) / 2 - Canvas->Font->Size;

    // полотнище
    Canvas->Brush->Color = (TColor) RGB(255,255,255);
    Canvas->FillRect( Rect(x,y,x+WB,y+HB) );

    int x1 = (ClientWidth - Canvas->TextWidth(st)) / 2;

    Canvas->Brush->Style = bsClear;
    Canvas->TextOutA(x1,y+HB+6,st);


    /* Чтобы область вывода текста не была закрашена цветом фона,
       а также чтобы метод Ellipse рисовал окружность, а не круг,
       значение свойства Brush->Style должно быть равно bsClear */

    Canvas->Brush->Style = bsClear;
    Canvas->Pen->Width = 2; // ширина колец - два пикселя

    // первый ряд колец
    x = x + (WB - 3.2 * D) / 2; // 3.2 *  D - ширина области, занимаемой кольцами первого ряда
    y = y + (HB - 1.6 * D) /2;

    Canvas->Pen->Color = (TColor) RGB(0,0,225);  // синий
    Canvas->Ellipse(x,y,x+D,y+D);

    x = x + 1.1* D;
    Canvas->Pen->Color = clBlack;       // черный
    Canvas->Ellipse(x,y,x+D,y+D);

    x = x + 1.1 * D;
    Canvas->Pen->Color = (TColor) RGB(255,0,0);  // красный
    Canvas->Ellipse(x,y,x+D,y+D);

    // второй ряд колец
    x = x - D * 0.55;
    y = y + 0.6 * D;

    Canvas->Pen->Color = (TColor) RGB(0,128,0);  // зеленый
    Canvas->Ellipse(x,y,x+D,y+D);

    x = x - 1.1 * D;
    Canvas->Pen->Color = (TColor) RGB(250,217,25);  // желтый
    Canvas->Ellipse(x,y,x+D,y+D);
}

// пользователь изменил размер окна
void __fastcall TForm1::FormResize(TObject *Sender)
{
    Form1->Refresh();
}

