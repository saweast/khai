/*
  Игра "Собери картинку" - игра "15" с графическим
  интерфейсом (вместо цифр - фрагменты картинки).
  Картинка загружается из файла pic_1.bmp,
  который находится в том же каталоге
  что и выполняемый файл программы.
  (с) Культин Н.Б., 2005.
*/

#include <vcl.h>
#pragma hdrstop

#include "PuzMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


#include "math.hpp" // для доступа к Randomize и RandomRange

// размер поля WxH
#define W 4
#define H 4

int wc, hc; // размер клетки

byte pole[H][W]; // игровое поле
byte ex,ey;      // координаты пустой клетки

bool GameOver;

AnsiString fn; // имя bmp-файла (картинка)
TSearchRec SearchRec; // результат поиска файла

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    pic = new Graphics::TBitmap();
}

// начало работы программы
void __fastcall TForm1::FormShow(TObject *Sender)
{
    NewGame();
}

// новая игра
void __fastcall TForm1::NewGame()
{
    static int Tag = 0;
       // загрузить файл иллюстрации
    if (( ParamCount() == 0 ) && (Tag == 0 )) Tag = 1;

    switch ( Tag )
    {
        case 0 :  // имя файла - из командной строки
             fn = ParamStr(1);
             Tag = 1;
             break;

        case 1:  // выбрать первый по порядку bmp-файл
             { FindFirst("*.bmp",faAnyFile,SearchRec);
               fn = SearchRec.Name;
               Tag = 2;
             }
             break;

        case 2: // выбрать следующий bmp-файл
             {
                if ( FindNext(SearchRec) != 0)
                    FindFirst("*.bmp",faAnyFile,SearchRec);
                fn = SearchRec.Name;
             }
             break;
    }

    // загрузить иллюстрацию
    try {
        pic->LoadFromFile(fn);
    }
    catch (EFOpenError &e)
    {
        MessageDlg("Ошибка доступа к файлу иллюстрации",
          mtWarning, TMsgDlgButtons()<< mbOK<<mbHelp,0);
        return;
    }

    // определить размер клетки
    wc = pic->Width / W;
    hc = pic->Height / H;

    // установить размер формы
    ClientWidth = wc * W;
    ClientHeight = hc * H;

    // исходное (правильное) положение фишек
    int k = 1;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            pole[i][j] = k++;

    GameOver = false;
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
            // выберем фишку, примыкающую к пустой клетке,
            //   которую переместим в пустую клетку
            d = RandomRange(1,5);
            switch ( d ) {
                case 1: x2--; break;
                case 2: x2++; break;
                case 3: y2--; break;
                case 4: y2++; break;
            }
        } while ((x2 < 0) || (x2 >= W) || (y2 < 0) || (y2 >= H));

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
    TRect src, dst; /* фрагмен картинки и область ее
                       ее отображения на поверхности формы */
    int sx,sy;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            /* Преобразуем номер фрагмента картинки в координаты
               левого верхнего угла области-источника */
            sx = ((pole[i][j]-1) % W) * wc;
            sy = ((pole[i][j]-1) / H) * hc;

            src = Bounds(sx,sy,wc,hc);
            dst = Bounds(j*wc,i*hc,wc,hc);

            if ((  pole[i][j] != 16 ) || GameOver )
                // фрагмент картинки
                Canvas->CopyRect(dst,pic->Canvas,src);
            else
            {
                // пустая клетка
                Canvas->Brush->Style = bsSolid;
                Canvas->Brush->Color = clBtnFace;
                Canvas->Rectangle(dst);
            }
        }
    if ( N6->Checked )
    {
        // вывести номер фишки
        Canvas->Brush->Style = bsClear;
        for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            Canvas->TextOutA(wc*j,hc*i, IntToStr(pole[i][j]));
    }
}

// щелчок в клетке
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    int cx,cy; // координаты клетки

    cx = X / wc;
    cy = Y / hc;

    Move(cx,cy); // переместить выбранную клетку в соседнюю свободную
}

bool Finish(); // проверяет, правильно ли размещены фишки

// перемещает фишку из клетки, в которой сделан щелчок
// в свободную клетку
void __fastcall TForm1::Move(int cx, int cy)
{
    if  ( ( abs(cx - ex) == 1  &&  cy-ey == 0  ) ||
          ( abs(cy - ey) == 1  &&  cx-ex == 0  ) )
    {
        // переместить фишку из (cx,cy) в (ex,ey)
        pole[ey][ex] = pole[cy][cx];
        pole[cy][cx] = 16;
        ex = cx;
        ey = cy;
        // отрисовать поле
        ShowPole();
        if ( Finish () )
        {
            GameOver = true;
            ShowPole();
            int r = MessageDlg ("Цель достигнута! Еще раз (другая картинка)?",
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
    for (row = 0; row < H; row++)
    {
        for (col = 0; col < W; col++)
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

// выбор в строке меню команды Новая игра
void __fastcall TForm1::N1Click(TObject *Sender)
{
    NewGame();
}

// выбор в меню Справка команды Справка
void __fastcall TForm1::N3Click(TObject *Sender)
{
    WinExec("hh.exe puzzle.chm", SW_RESTORE);
}

// выбор в меню Справка команды О программе
void __fastcall TForm1::N4Click(TObject *Sender)
{
    WinExec("hh.exe -mapid 3 puzzle.chm", SW_RESTORE);

}

// команда Параметры/Номер фишки
void __fastcall TForm1::N6Click(TObject *Sender)
{
    N6->Checked = ! N6->Checked;
    ShowPole();
}

