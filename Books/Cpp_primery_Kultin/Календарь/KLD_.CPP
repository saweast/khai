/*
    Программа Календарь выводит изображение календаря на текущий месяц.
    Выходные и праздничные дни выделяются цветом, текущая дата - рамкой.
    Имеется возможность задать праздничные дни.
    Демонстрирует вывод графики на поверхность формы,
    работу с функциями манипулирования датами.
*/

#include <vcl.h>
#pragma hdrstop

#include "kld_.h"



#pragma package(smart_init)
#pragma resource "*.dfm"


#include <DateUtils.hpp>

TForm1 *Form1;

#define BACKGROUND
#undef BACKIMAGE

AnsiString stMonth[12] = {"Январь","Февраль","Март","Апрель",
                          "Май","Июнь","Июль","Август",
                          "Сентябрь","Октябрь","Ноябрь","Декабрь"};

AnsiString stDay[7] = {"ПН","ВТ","СР", "ЧТ","ПТ","СБ","ВС"};

// праздничные дни в формате dd.mm
AnsiString holiday ="01.01;02.01;07.01;23.02;08.03;01.05;09.05;07.11;12.12;";

Word aYear, aMonth, aDay; // год, месяц, день

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
   DecodeDate(Now(),aYear,aMonth,aDay);
   UpDown1->Position = aMonth;
   #ifdef BACKIMAGE
   // загрузка фоновой картинки
   backimage = new Graphics::TBitmap();
   try {
        backimage->LoadFromFile("back.bmp");
   }
   catch (EFOpenError &e) {
        return;
   }
   #endif
}

// возвращает строковое представление двузначного числа
// с ведущем нулем: 01, 02 и т.д.
AnsiString __fastcall IntToStr_(int i)
{
  AnsiString s;
  if ( IntToStr(i).Length() == 1) s = "0"+IntToStr(i);
  else s = IntToStr(i);
  return s;
}

// обработка события Paint - вывести календарь
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    Word aDayOfWeek; // день недели
    AnsiString st;   // дата в формате dd.mm

    int x, y,
        dx, dy, // шаг столбцов и строк цифр
        x0,y0;  // левый верхний угол области вывода календаря

    int i;

    x0 = 50; y0 = 40;
    dx = 20; dy = 20;

    Caption = "Календарь " + IntToStr(aYear);
    #ifdef BACKGROUND
    Canvas->Brush->Color = clBackground;
    #endif

    #ifdef BACKIMAGE
    Canvas->Draw(0,0,backimage);
    #else
    Canvas->Pen->Color = Canvas->Brush->Color;
    Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    #endif
    // вывести календарь на текущий месяц
    Canvas->Brush->Style = bsClear;
    Canvas->Font->Size = 12;
    Canvas->Font->Color = clBlack;
    Canvas->TextOutA(x0,y0-35, stMonth[aMonth-1]);

    Canvas->Font->Size = 10;

    // первая колонка - название дней недели
    x = x0 - 30;
    y = y0;
    for ( i = 0; i < 7; i++)
    {
        if ( i < 5 )
            Canvas->Font->Color = clBlack;
        else
            Canvas->Font->Color = clRed;

        Canvas->TextOutA(x,y, stDay[i]);
        y += dy;
    }


    /* определим день недели, с которого
      начинается месяц */
    aDayOfWeek = DayOfTheWeek( EncodeDate(aYear,aMonth,1));

    x = x0;
    y = y0 + dy * (aDayOfWeek-1);

    for ( i = 1; i <= DaysInAMonth(aYear,aMonth); i++ )
    {
        // проверим, не является ли день праздничным
        st = IntToStr_(i) + "." + IntToStr_(aMonth);
        if ( holiday.Pos(st) !=0 )
            Canvas->Font->Color = clRed; // праздничный
        else  // обычный
            if ( aDayOfWeek < 6 )
                Canvas->Font->Color = clBlack;
            else
                Canvas->Font->Color = clRed; // суббота и воскресенье

        Canvas->TextOutA(x,y, IntToStr(i));

        if ( i == aDay) {
            // выделить сегодняшнее число
            // рамка
            Canvas->Brush->Style = bsClear;
            Canvas->Pen->Color = clGray;
            Canvas->Rectangle(x-3,y-1,x+dx-2,y+dy-1);
         }

        if ( aDayOfWeek != 7 ) {
            y += dy;
            aDayOfWeek ++;
        }
        else {
            aDayOfWeek =1;
            x += dx;
            y = y0;
        }
    }
}

// щелчок на кнопке компонента UpDown
void __fastcall TForm1::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
     switch (UpDown1->Position) {
        case 0 : UpDown1->Position = 12; aYear--; break;
        case 13: UpDown1->Position = 1;  aYear++;; break;
     };

     aMonth = UpDown1->Position;
     Paint(); // обновить календарь
}

// нажатие клавиши
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if ( Key == 27) // клавиша <Esc>
        Form1->Close(); // завершить работу программы
}


/*
 Cистема направляет сообщение WM_NCHITTEST окну приложения,
 момент нажатия/отпускания кнопки мыши.
 определение функции обработки сообщения см. в h-файле
 */

void __fastcall TForm1::WMNCHITTEST(TMessage &Message)
{
         /* пусть система "думает", что кнопка
            мыши нажата в заголовке окна */
         Message.Result = HTCAPTION;
}

