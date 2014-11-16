/*
    Игра "15"
*/

#include <vcl.h>
#pragma hdrstop

#include "g15frm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

#include "math.hpp" // для доступа к Randomize и RandomRange

// размер клеток 48х48
#define WC 48
#define HC 48

byte pole[4][4]; // игровое поле
byte ex,ey;      // координаты пустой клетки

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Form1->Font->Size = 12;
}

// начало работы программы
void __fastcall TForm1::FormShow(TObject *Sender)
{
    NewGame();
}

// новая игра
void __fastcall TForm1::NewGame()
{
    // установить размер формы
    ClientWidth = WC * 4;
    ClientHeight = HC * 4;

    // исходное (правильное) положение фишек
    int k = 1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            pole[i][j] = k++;

    Mixer();     // перемешать фишки
    ShowPole();  // отобразить игровое поле
}

// перемешивает фишки
void __fastcall TForm1::Mixer()
{
    int x1,y1; // пустая клетка
    int x2,y2; // эту переместить в пустую
    int d;     // направление относительно пустой

    Randomize();

    x1 = 3; y1 = 3; // см. описание массива stp
    for ( int i = 0; i < 150; i++)  // кол-во перестановок
    {
        do {
            x2 = x1;
            y2 = y1;
            /* выберем фишку, примыкающую к пустой клетке,
               которую переместим в пустую клетку */
            d = RandomRange(1,5);
            switch ( d ) {
                case 1: x2--; break;
                case 2: x2++; break;
                case 3: y2--; break;
                case 4: y2++; break;
            }
        } while ((x2 < 0) || (x2 >= 4) || (y2 < 0) || (y2 >= 4));

        /* здесь определили фишку, которую
           надо переместить в пустую клетку */
        pole[y1][x1]  =  pole[y2][x2];
        pole[y2][x2]  =  16;
        x1 = x2;
        y1 = y2;
    };
    // запомним координаты пустой клетки
    ex =  x1;
    ey =  y1;
}

// отображает на поверхности формы игровое поле
void __fastcall TForm1::ShowPole()
{
    int x,y; // координаты левого верхнего угла клетки

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            x = j * HC;
            y = i * WC;
            if (pole[i][j] != 16 ) {
                Canvas->Brush->Color = clBtnFace;
                Canvas->Rectangle(x,y, x+WC-1, y+HC-1);
                Canvas->TextOutA(x+15,y+10, IntToStr(pole[i][j]));
            }
            else {
                Canvas->Brush->Color = clBtnHighlight;
                Canvas->Rectangle(x,y, x+WC-1, y+HC-1);
            }
        }
}

bool Finish(); // проверяет, правильно ли размещены фишки

// щелчок в клетке
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    int cx,cy; // координаты клетки

    cx = X / WC;
    cy = Y / HC;

    // переместить выбранную клетку в соседнюю свободную
    if  ( ( abs(cx - ex) == 1  &&  cy-ey == 0  ) ||
          ( abs(cy - ey) == 1  &&  cx-ex == 0  ) )
    {
        // переместить фишку из (cx,cy) в (ex,ey)
        pole[ey][ex] = pole[cy][cx];
        pole[cy][cx] = 16;
        ex = cx;
        ey = cy;
        ShowPole();    // отрисовать поле
        if ( Finish () )
        {
            ShowPole();
            int r = MessageDlg ("Цель достигнута!\Еще раз?",
                                mtInformation, TMsgDlgButtons() << mbYes << mbNo, 0);
            if ( r == mrNo )
                Form1->Close(); // завершить работу программы
            else
            {
                NewGame();
                ShowPole();
            }
        }
    }
}

/* проверяет, расположены ли
  клетки (фрагменты картинки) в нужном порядке */
bool Finish()
{
    bool result;
    int row, col;
    int k = 1;

    result  =  true; // пусть фишки в нужном порядке
    for (row = 0; row < 4; row++)
    {
        for (col = 0; col < 4; col++)
            if ( pole[row][col] == k )
                k++;
            else {
                result = false;
                break;
            }
        if ( ! result ) break;
    }
     return (result);
};

// обработка события Paint
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    ShowPole();
}

