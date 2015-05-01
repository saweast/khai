//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ClockForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


#include "DateUtils.hpp" // для доступа к SecondOf, MinuteOf и HourOf
#include "math.h"        // для доступа к sin и cos

/* Для вычисления синуса и косинуса можно воспользоваться
   функцией SinCos, которая возвращает синус и косинус угла,
   заданного в радианах. Чтобы использовать эту функцию,
   в программу надо добавить директиву #include "Math.hpp" */

#define R 75     // радиус циферблата часов


int  x0, y0;         // центр циферблата
int ahr,amin,asec;   // положение стрелок (угол)


__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    TDateTime t;

    // зададим размер формы
    // в соответствии с размером циферблата
    ClientHeight = (R + 30)*2;
    ClientWidth  = (R + 30)*2;
    x0  =  R + 30;
    y0  =  R + 30;

    t  =  Now();

    // Определить положение стрелок.
    // Угол между метками (цифрами) часов, например, цифрами 2 и 3, - 30 градусов.
    // Угол между метками минут - 6 градусов.
    // Угол отсчитываем от 12-ти часов
    ahr  =   90 - HourOf(t)*30-(MinuteOf(Today() ) / 12) *6;
    amin  =  90 - MinuteOf(t)*6;
    asec  =  90 - SecondOf( Today() )*6;

    Timer1->Interval =  1000; // период сигнал от таймера 1 сек
    Timer1->Enabled  =  true; // пуск таймера
}

// рисует вектор из точки (x0,y0) под углом a относительно
// оси X. Длинна вектора l
void __fastcall TForm1::Vector(int x0, int y0, int a, int l)
{
    // x0,y0 - начало вектора
    // a - угол между осью x и вектором
    // l - длина вектора
    #define TORAD 0.0174532  // коэффициент пересчета угла из градусов в радианы

  int x, y;       // координаты конца вектора

  Canvas->MoveTo(x0,y0);
  x  =  x0 + l * cos(a*TORAD);
  y  =  y0 - l * sin(a*TORAD);
  Canvas->LineTo(x,y);

}


// прорисовка циферблата
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    int x, y;  // координаты маркера на циферблате
    int a;     // угол между OX и прямой (x0,yo) (x,y)
    int h;     // метка часовой риски

    TBrushStyle bs; // стиль кисти
    TColor pc;      // цвет карандаша
    int pw;         // ширина карандаша

    bs  =  Canvas->Brush->Style;
    pc  =  Canvas->Pen->Color;
    pw  =  Canvas->Pen->Width;

    Canvas->Brush->Style  =  bsClear;
    Canvas->Pen->Width  =  1;
    Canvas->Pen->Color =  clBlack;

    a = 0; // метки ставим от 3-х часов, против часовой стрелки
    h = 3; // угол 0 градусов - это 3 часа

    // циферблат
    while ( a < 360 )
    {
        x = x0 +  R * cos(a * TORAD);
        y = x0 -  R * sin(a * TORAD);
        Form1->Canvas->MoveTo(x,y);
        if ( (a % 30) == 0 )
        {
            Canvas->Ellipse(x-2,y-2,x+3,y+3);
            // цифры по большему радиусу
            x = x0 +  (R+15) * cos(a * TORAD);
            y = x0 -  (R+15) * sin(a * TORAD);
            Canvas->TextOut(x-5,y-7,IntToStr(h));
            h--;
            if ( h == 0 ) h = 12;
        }
        else
            Canvas->Ellipse(x-1,y-1,x+1,y+1);
        a = a + 6; // 1 минута - 6 градусов
    }
    // восстановить карандаш кисть
    Canvas->Brush->Style  =  bs;
    Canvas->Pen->Width  =  pw;
    Canvas->Pen->Color =  pc;

    DrawClock();

}

void __fastcall TForm1::DrawClock(void)
{
    TDateTime t;

  // шаг секундной и минутной стрелок 6 градусов,
  // часовой - 30.

  // стереть изображение стрелок
  Canvas->Pen->Color =  clBtnFace;
  Canvas->Pen->Width  = 3;
  // часовую
  Vector(x0,y0, ahr, R-20);
  // минутную
  Vector(x0,y0, amin, R-15);
  // секундную
  Vector(x0,y0, asec, R-7);

  t  =  Now();

  // новое положение стрелок
  ahr  =   90 - HourOf(t)*30-(MinuteOf(t)% 12)*6;
  amin  =  90 - MinuteOf(t)*6;
  asec  =  90 - SecondOf(t)*6;

  // нарисовать стрелки
  // часовая стрелка
  Canvas->Pen->Width  =  3;
  Canvas->Pen->Color =  clBlack;
  Vector(x0,y0, ahr, R-20);

  // минутная стрелка
  Canvas->Pen->Width  =  2;
  Canvas->Pen->Color =  clBlack;
  Vector(x0,y0, amin, R-15);

  // секундная стрелка
  Canvas->Pen->Width  =  1;
  Canvas->Pen->Color =  clYellow;
  Vector(x0,y0, asec, R-7);
}

// сигнал от таймера
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    DrawClock();
}

