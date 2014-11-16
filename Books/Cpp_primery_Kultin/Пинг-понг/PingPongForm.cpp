//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PingPongForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;



/* Игра "Пинг-понг"
   Демонстрирует принцип программирования интерактивной графики.
  (с) Культин Н.Б., 2004 */


int x, y;     // положение мячика
int dx, dy;   // приращение координат
int r;        // радиус мячика
TColor cBall; // цвет мячика
TColor cBack; // цвет поля
int wp, hp;   // размер поля (формы)


// это переменные для управления движением ракетки
int rd;        //  0 - ракетка не движется; 1 - движется влево; 2 - движется вправо
int rx1, rx2;  // координаты X концов ракетки
int ry;        // координата Y концов ракетки
int rdx;       // шаг перемещения ракетки

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    r = 5;          // радиус мячика
    x = r; y = 50;  // начальное положение мячика
    dx = 1;
    dy = 1;

    cBall = (TColor)RGB(217, 217, 25); // цвет мячика
    cBack = (TColor)RGB(33, 94, 33);   // цвет поля

    Form1->Color = cBack;

    wp = Form1->ClientWidth;
    hp = Form1->ClientHeight;

    //  управление ракеткой
    rd = 0;     // ракетка на месте (не движется)
    rx1 = 100;
    rx2 = 125;
    ry = Form1->ClientHeight - 20; // расстояние до нижней границы формы 20 пикселей
    rdx = 2; // шаг движения ракетки

    // настройка таймера
    Timer1->Interval = 10;
    Timer1->Enabled = true;
}

void __fastcall TForm1::FormPaint(TObject *Sender)
{
    // нарисовать ракетку
    Form1->Canvas->Pen->Color = clRed;
    Form1->Canvas->Rectangle(rx1, ry, rx2, ry+1);
}

// сигнал от таймера
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    // стереть изображение мяча
    Form1->Canvas->Pen->Color = cBack;
    Form1->Canvas->Ellipse(x,y,x+r,y+r);


    // ** вычислить новое положение мяча **
    if ( dx > 0 )
    {
        // мяч движется вправо
        if ( x + dx + r > wp ) dx = - dx;
    }
    else
        // мяч движется влево
        if ( x + dx - r < 0 ) dx = -dx;

    if ( dy > 0 )
    {
        // мяч движется вниз
        if ((x >= rx1) && (x <= rx2 -r) && (y == ry - r - 1) )
            // мячик попал в ракетку
            dy = - dy;
        else
            if (  y + dy + r > Form1->ClientHeight ) dy = -dy;
    }
    else
    {
        // мяч движется вверх
        if ((x >= rx1) && (x <= rx2) && (y >= ry - r) && (y <= ry + r) )
        {
            // Мячик отскочил от нижней стенки и попал в ракетку снизу.
            // Чтобы не было дырок в ракетке, перерисуем ее.
            Form1->Canvas->Pen->Color = clRed;
            Form1->Canvas->Rectangle(rx1, ry, rx2, ry+1);
        }
        if ( y + dy - r < 0 ) dy = -dy;
    }
    x += dx;
    y += dy;

    // нарисовать мяч в новой точке
    Form1->Canvas->Pen->Color = cBall;
    Form1->Canvas->Ellipse(x,y,x+r,y+r);

    // *** ракетка ***
    if ( rd != 0 )
    {
        // игрок нажал и удерживает одну из клавиш
        // "стрелка вправо" или "стрелка влево"
        // (см. FormKeyDown )
        if ( rd == 1 )
        {
            // вправо
            if ( rx2 < wp )
            {
                // стереть часть слева
                Form1->Canvas->Pen->Color = cBack;
                Form1->Canvas->Rectangle(rx1, ry, rx1 + rdx, ry +1);
                // дорисовать часть справа
                Form1->Canvas->Pen->Color = clRed;
                Form1->Canvas->Rectangle (rx2, ry, rx2 + rdx, ry+1);
                rx1 += rdx;
                rx2 += rdx;
            }
        }
        else
           // влево
           if (rx1 > 1 )
           {    // стереть часть справа
                Form1->Canvas->Pen->Color = cBack;
                Form1->Canvas->Rectangle (rx2, ry, rx2 - rdx, ry+1);
                // дорисовать слева
                Form1->Canvas->Pen->Color = clRed;
                Form1->Canvas->Rectangle(rx1 - rdx, ry, rx1 + rdx, ry+1);
                rx1 -= rdx;
                rx2 -= rdx;
            }
    }

}

// нажата клавиша
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (rd != 0 )
        // пользователь удерживает клавишу, ракетка движется
        return;

    switch ( Key )
    {
        case VK_LEFT : // Шаг (стрелка) право
            rd = 2; break;
        case VK_RIGHT :  // Шаг (стрелка) влево
            rd = 1; break;
    }
}

// клавиша отпущена
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    rd = 0;
}

