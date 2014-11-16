/*
    Вывод на печать.

*/

#include <vcl.h>
#pragma hdrstop

#include "SheetFrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}


void __fastcall TForm1::FormCreate(TObject *Sender)
{
     // *** настроить таблицу ***
    StringGrid1->Options
            << goEditing             // разрешить редактировать
            << goTabs;                // <Tab> - переход к следующей ячейке
//            << goAlwaysShowEditor;  // всегда отображать урсор

    // заголовки столбцов
    StringGrid1->Cells[0][0] = "";
    StringGrid1->Cells[1][0] = "        Наименование";
    StringGrid1->Cells[2][0] = "    Цена";
    StringGrid1->Cells[3][0] = " Кол-во";
    StringGrid1->Cells[4][0] = "    Сумма";

    // ширина столбцов
    StringGrid1->ColWidths[0] = 30;
    StringGrid1->ColWidths[1] = 250;
    StringGrid1->ColWidths[2] = 80;
    StringGrid1->ColWidths[3] = 50;
    StringGrid1->ColWidths[4] = 80;

    // заполнить первый столбец
    for ( int i = 1; i < 11; i++)
        if (i < 10)
            StringGrid1->Cells[0][i] = "  " + IntToStr(i);
        else
            StringGrid1->Cells[0][i] = IntToStr(i);

    int w = 0;
    for (int i = 0; i < StringGrid1->ColCount; i++)
        w += StringGrid1->ColWidths[i];

    // установить размер StringGrid в соответствии с размером
    // столбцов и количеством строк
    StringGrid1->Width = w + StringGrid1->ColCount +1 ;
    StringGrid1->Height =
        StringGrid1->DefaultRowHeight * StringGrid1->RowCount +
        StringGrid1->RowCount + 1;
}

#include "Printers.hpp"
// щелчок на кнопке Печать
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    TPrinter *Prn; // принтер

    #define LEFT_MARGIN 2 // отступ слева 2 см
    #define TOP_MARGIN  2 // отступ сверху 2 см


    float dpiX, dpiY; // разрешение принтера по X и Y
    float kx, ky;     // коэф. пересчета координат экрана
                    // в координаты принтера по Х и Y
    // таблица
    int p[5];  // позиции колонок
    int x1,y1,x2,y2; // границы таблицы

    int px, py; // указатель точки вывода
    int i, j;

    /* Разрешение экрана и принтера разное,
       поэтому чтобы добиться соответствия
       размеров изображения на экране и принтере,
       координаты точек экрана надо преобразовать
       в координаты принтера, умножить на коэф.,
       значение которого зависит от разрешения принтера.
       Например, если разрешение принтера 300 dpi,
       то значение коэффициента равно 3.125, т.к.
       разрешение экрана - 96 dpi */

    Prn = Printer();

     /* ф-я GetDeviceCaps позволяет получить характеристики
       устройства. LOGPIXELSX - кол-во пикселей на дюйм по X */

    dpiX  =  GetDeviceCaps(Prn->Handle,LOGPIXELSX);
    dpiY  =  GetDeviceCaps(Prn->Handle,LOGPIXELSY);
    kx  =  dpiX / Screen->PixelsPerInch;
    ky  =  dpiY / Screen->PixelsPerInch;

    px  =  LEFT_MARGIN / 2.54 * dpiX;
    py  =  TOP_MARGIN  / 2.54 * dpiY;

    // вычислим "принтерные" координаты колонок таблицы
    p[0]  =  px;
    for (i = 1; i < 5; i++ )
        p[i]  =  p[i-1] + StringGrid1->ColWidths[i-1]* kx + i;

    Prn->BeginDoc(); // открыть печать

    // заголовок таблицы
    Prn->Canvas->Font->Name  =  Label1->Font->Name;
    Prn->Canvas->Font->Size  =  Label1->Font->Size;
    Prn->Canvas->TextOut(px,py,Label1->Caption);

    // таблица - содержимое StringGrid1
    py  =  py + Label1->Font->Size * 2 * ky;

    x1  =  px; y1  =  py; // левый верхний угол таблицы

    Prn->Canvas->Font->Name  =  StringGrid1->Font->Name;
    Prn->Canvas->Font->Size  =  StringGrid1->Font->Size;

    x2  =  p[4] + StringGrid1->ColWidths[4]* kx;
    y2  =  py +
           StringGrid1->RowCount * StringGrid1->RowHeights[1] * ky;

    for ( j = 0; j < StringGrid1->RowCount; j++)
    {
       // строки таблицы
       for (i = 0; i < StringGrid1->ColCount; i++)
       {
          Prn->Canvas->TextOut(p[i],py,StringGrid1->Cells[i][j]);
          // гор->линия
          Prn->Canvas->MoveTo(p[0],py);
          Prn->Canvas->LineTo(x2,py);
       }
       py = py+ StringGrid1->RowHeights[j]* ky;
    }

    // вертикальные линии
    for ( i = 0; i < StringGrid1->ColCount; i++ )
    {
        Prn->Canvas->MoveTo(p[i],y1);
        Prn->Canvas->LineTo(p[i],y2);
    }
    // правая граница
    Prn->Canvas->MoveTo(x2,y1);
    Prn->Canvas->LineTo(x2,y2);

    // нижняя граница
    Prn->Canvas->MoveTo(x1,y2);
    Prn->Canvas->LineTo(x2,y2);

    py = y2 + 0.5 / 2.54 * dpiY; // здесь 1 - это 1 см.
    Prn->Canvas->TextOut(p[3],py,Label2->Caption);

    Prn->EndDoc();  // закрыть печать
}

// щелчок на кнопке Готово
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    float summ;

    summ = 0;
    for ( int i = 1; i < 11; i++)
    {
        // если ячейка Сумма пустая, то при выполнении
        // функции StrToFloat возникает ошибка (исключение)
        try
        {
            summ += StrToFloat(StringGrid1->Cells[4][i]);
        }
        catch (Exception &e)
        {
        }
    }

    Label2->Caption = "Всего: " + FloatToStr(summ) + " руб.";
}

