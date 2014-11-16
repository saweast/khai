/*
    Программа строит график изменеия курса доллара
*/

#include <vcl.h>
#pragma hdrstop

#include "GrafForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

float data[] = {27.98, 28.01, 27.96, 27.96, 28.11, 28.08, 28.00, 27.98, 28.15, 28.15, 28.11, 27.94, 27.86, 27.88, 27.95, 27.95};
                //, 27.74, 27.74, 27.77, 27.77, 27.82, 27.83, 27.83, 27.88, 27.89, 27.88, 27.83, 27.91, 27.99, 28.12};

AnsiString Title = "Изменение курса доллара";

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

void __fastcall TForm1::FormPaint(TObject *Sender)
{

    int n;      // количество точек
    int x,y;    // координаты точки
    int dx;     // шаг по X

    int x0,y0;  // координаты левого нижнего угла области построения графика

    // заголовок
    Canvas->Font->Name = "Tahoma";
    Canvas->Font->Size = 12;
    x0 = (ClientWidth - Canvas->TextWidth(Title)) /2;
    Canvas->Brush->Style = bsClear;
    Canvas->TextOutA(x0,10,Title);

    n = sizeof(data) / sizeof(float);

    // *** найти минимальное и максимальное значение данных ***
    int min,max;  // индекс минимального и максимального элемента

    min = 0;  // пусть первый элемент минимальный
    max = 0;  // пусть первый элемент максимальный
    for (int i = 1; i < n; i++)
    {
        if (data[i] < data[min]) min = i;
        if (data[i] > data[max]) max = i;
    }

    /*  Если отклонения значений ряда от среднего значения
        незначительное, то диаграмма получается ненаглядной.
        В этом случае можно построить не абсолютные значения,
        а отклонения от минимального значения ряда. */

    bool frmin = true; // true - отсчитывать от минимального значения

    dx= (ClientWidth - 20) / (n-1);

    Canvas->Font->Size -= 2;
    Canvas->Pen->Color = clGreen;
    Canvas->Pen->Width = 1;

    x0 = 10;
    y0 = ClientHeight - 10;

    x = x0;
    dx= (ClientWidth - 20) / (n-1);
    for ( int i = 0; i < n; i++)
    {
        /* максимальному значению соответствует
          точка с координатой ClientHeight - 90 */
        if (! frmin)
            y = y0 + (ClientHeight - 90) * data[i]/data[max];
        else
           // Отсчитывать от минимального значения
           y = y0-(ClientHeight - 90) * (data[i] - data[min])/(data[max] - data[min])-10;

        // поставить точку
        Canvas->Rectangle(x-2,y-2,x+2,y+2);

        if (i != 0)
            Canvas->LineTo(x,y);

        // ** подпись данных **
        /* т.к. метод TextOutA изменит положение точки привязки (точки,
           из которой рисует метод LineTo, то после вывода текста
           надо будет переместить указатель в точку (x,y) */
        if ( ( i == 0) || (data[i] != data[i-1]))
        {
            AnsiString st;
            st = FloatToStrF(data[i],ffGeneral,5,2);
            Canvas->Brush->Style = bsClear;  // область вывода текста - прозрачная
            Canvas->TextOutA(x,y-20,st);
        }
        Canvas->MoveTo(x,y);
        x += dx;
    }
}

// изменился размер окна
void __fastcall TForm1::FormResize(TObject *Sender)
{
    Form1->Refresh(); // обновить содержимое окна
}



