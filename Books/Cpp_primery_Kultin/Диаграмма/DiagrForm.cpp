/*
    Программа строит диаграмму
*/

#include <vcl.h>
#pragma hdrstop

#include "DiagrForm.h"

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
    int x,y;

    // заголовок
    Canvas->Font->Name = "Tahoma";
    Canvas->Font->Size = 12;
    x = (ClientWidth - Canvas->TextWidth(Title)) /2;
    Canvas->Brush->Style = bsClear;
    Canvas->TextOutA(x,10,Title);

    // гистограмма

    int n;    // количество столбцов
    int wCol; // ширина столбца

    #define MC 5 // расстояние между столбиками по горизонтали

    n = sizeof(data) / sizeof(float);
    wCol = (ClientWidth - (n - 1)*MC - 20) / n;


    x = 10;
    y = ClientHeight - 20;

    // *** найти минимальное и максимальное значение данных ***
    int min,max;  // индекс минимального и максимального элемента

    min = 0;  // пусть первый элемент минимальный
    max = 0;  // пусть первый элемент максимальный
    for (int i = 1; i < n; i++)
    {
        if (data[i] < data[min]) min = i;
        if (data[i] > data[max]) max = i;
    }

    /*
        Если отклонения значений ряда от среднего значения
        незначительное, то диаграмма получается ненаглядной.
        В этом случае можно построить не абсолютные значения,
        а отклонения от минимального значения ряда.
    */

    bool frmin = true; // true - отсчитывать от минимального значения


    int h; // высота столбика
    // максимальному значению соответствует
    // столбик высотой ClientHeight - 90


    Canvas->Font->Size -= 2;
    for ( int i = 0; i < n; i++)
    {
        if (! frmin)
            h = (ClientHeight - 90) * data[i]/data[max];
        else
            /* Отсчитывать от минимального значения.
               Минимальное значение отобразим столбиком
               высотой 10 пикселов */
           h = (ClientHeight - 90) * (data[i] - data[min])/(data[max] - data[min]) + 10;

        Canvas->Brush->Style = bsSolid;
        //Canvas->Brush->Color = clMaroon;
        Canvas->Brush->Color = clLime;
        Canvas->Rectangle(x,y,x+wCol,y-h); // столбик

        // подпись данных
        AnsiString st;
        st = FloatToStrF(data[i],ffGeneral,5,2);
        Canvas->Brush->Style = bsClear;  // область вывода текста - прозрачная
        Canvas->TextOutA(x,y-h-20,st);

        x = x + wCol + MC;
    }

}

// изменился размер окна
void __fastcall TForm1::FormResize(TObject *Sender)
{
    Form1->Refresh(); // обновить содержимое окна
}



