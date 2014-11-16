/*

    Игра "Парные картинки".
    Демонстрирует работу с графикой.
*/

#include <vcl.h>
#pragma hdrstop

#include "DPpicMain.h"
#pragma package(smart_init)
#pragma resource "*.dfm"


#include <Math.hpp>  // для доступа к ГСЧ

#define  MAX_SIZE  32 // максимальное кол-во пар картинок
#define  MAX_H  8     // максимальный размер поля - 8х8
#define  MAX_W  8

// #define DEBUG    // режим отладки

int  Pole[MAX_W][MAX_H]; // поле
     /* Pole[i][j] < 100 - код картинки, клетка закрыта;
        Pole[i][j] > 100 но < 200 - клетка открыта (игрок видит картинку);
        Pole[i][j] > 200 - игрок нашел пару для этой картинки */

Graphics::TBitmap  *Pictures;    // картинки

int np;  // количество пар картинок
int nf;  // колво открытых (найденных) пар картинок
int no;  // количества открытых в данный момент клеток

TPoint open1;  // координаты 1-й открытой клетки
TPoint open2;  // координаты 2-й открытой клетки

int W,H;    /* Кол-во клеток по горизонтали и вертикали.
                 Произведение W и H должно быть кратно 2-м */

int WK, HK;  // размер клетки (картинки)

TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}





void __fastcall TForm1::FormCreate(TObject *Sender)
{
  //int np; // кол-во картинок в файле pictures

  Pictures  =  new Graphics::TBitmap();

  try {
    Pictures->LoadFromFile("pictures.bmp");
  }
  catch (EFOpenError &e)
  {
   ShowMessage("Ошибка доступа к файлу картинок.");
   return;
  }

  /* В файле pictures находятся все картинки. Предполагается,
     что каждая картинка квадратная. */

 /* Считаем, что в файле 8,10,12,14 или 15 картинок:

    Картинок   Клеток    Поле
    -------------------------
       8        16       4х4
       10       20       4х5
       12       24       4х6
       14       28       4х7
       15       30       5х6
 */

  HK  =  Pictures->Height-1; // высота картинки
  WK  =  HK;                 // ширина картинки

  np =  Pictures->Width / WK;
  if ( np < 15)
    H  =  4;
  else H  = 5;

  W  =  (np*2)/H;

  // установить размера поля (формы)
  ClientHeight  =  H * HK;
  ClientWidth  =  W * WK;

  // настройка таймера
  Timer1->Enabled  =  False;
  Timer1->Interval  =  200;

  NewGame();
}

// новая игра
void __fastcall TForm1::NewGame()
{
  /* В каждую ячейку Pole надо записать номер картинки.
     Так как для каждой картинки должна быть пара, то
     число i должно быть в двух ячейках Pole */

  int r;       // случайное число

  int buf[MAX_SIZE];
  /* в buf[i] записываем, сколько раз число i
    записали в массив Pole */

  int i, j; // индексы массивов

  // запишем в массив Pole случайные числа
  // от 0 до np, где n - кол-во картинок
  // каждое число должно быть записано два раза

  for (i = 0; i < np; i++)
      buf[i]  =  0;

  Randomize(); // инициализация ГСЧ
  for (i = 0; i < H; i++)
    for (j = 0; j < W; j++) {
        do  {
          r  =  RandomRange(0,np);
        } while ( buf[r] == 2 );
        Pole[i][j]  =  r;   // код картинки
        buf[r]++;
    }
  // здесь поле сгенерировано
   nf = 0;
};


// отрисовывает поле
void __fastcall  TForm1::ShowPole()
{
   int row,col;

   for ( row = 0; row < H; row++)
      for (col = 0; col < W; col++)
           Kletka(row,col);
}

// рисует клетку поля
void __fastcall TForm1::Kletka(int col,int row)
{
  int x, y;       // левый верхний угол клетки (координаты)
  TRect src, dst; // источник и получатель битового образа

  // преобразуем координаты клетки
  // в координаты на поверхности формы
  x  =  (col)*WK;
  y  =  (row)*HK;

  if ( Pole[col][row] >= 200 ) {
        /* Для этой клетки найдена пара.
           Клетку надо убрать с поля */

      // установить цвет границы и закраски области
      Canvas->Brush->Color =  clBtnFace;
      Canvas->Pen->Color =  clBtnFace;
      Canvas->Rectangle(x,y,x+WK-2,y+HK-2);
      return;
   };


   if ( (Pole[col][row] >= 100) && (Pole[col][row] < 200) ) {
       // клетка открыта - вывести картинку

      // Pole[col,row] == номер картинки + 100,
      // где 100 - признак того, что клетка открыта
      // определим положение картинки в Pictures
      src  =  Bounds((Pole[col][row]-100 )*WK,0,WK,HK);

      // координаты картинки (клетки) на форме
      dst  =  Bounds(x,y,HK-2,WK-2);

      // вывести картинку в клетку
      Form1->Canvas->CopyRect(dst,Pictures->Canvas,src);

      // нарисовать контур клетки
      Canvas->Pen->Color =  clBlack;
      Canvas->Brush->Style  =  bsClear;
      Canvas->Rectangle(x,y,x+WK-2,y+HK-2);
      return;
  };


  if ( (Pole[col][row] >= 0) && (Pole[col][row] < 100) )
    // клетка закрыта, рисуем только контур
    {
      Canvas->Brush->Color =  clBtnFace;
      Canvas->Pen->Color =  clBlack;
      Canvas->Rectangle(x,y,x+WK-2,y+HK-2);
    }

#ifdef DEBUG
  // подсказка - номер картинки
  Canvas->Font->Color = clBlack;
  Canvas->TextOut(x+15,y+15, IntToStr(Pole[col][row]));
#endif
};


// нажатие кнопки мыши
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  int col;   // номер клетки по горизонтали
  int row;   //номер клетки по вертикали


  col = X/WK;
  row = Y/HK;

  if ( Pole[col][row] >= 200 )
     // щелчок в на месте уже открытой картинки
    return;

  if ( no == 0 ) // открытых клеток нет
  {
    no  =  1;
    open1.x  =  col;
    open1.y  =  row;

    // клетка помечается как открытая
    Pole[open1.x][open1.y]  +=  100;
    Kletka(open1.x,open1.y);
    return;
  };

  if ( no == 1 )
  {
    // открыта одна клетка, надо открыть вторую
    open2.x  =  col;
    open2.y  =  row;

    // если открыта одна клетка и щелчок сделан
    // в этой клетке, то ничего не происходит
    if ( (open1.x == open2.x) && (open1.y == open2.y) )
        return;

    else
    {
      no  =  2; // теперь открыты две клетки
      Pole[open2.x][open2.y]  += 100;
      Kletka(open2.x,open2.y); // отрисуем вторую клетку

      // проверим, открытые картинки одинаковые?
      if ( Pole[open1.x][open1.y] == Pole[open2.x][open2.y] )
        // открыты две одинаковые картинки
        {
          nf++;
          Form1->Timer1->Enabled  =  True; // запустить таймер
          // процедур обработки события OnTimer
          // "сотрет" две одинаковые картинки
        };
      return;
    }
  };

  if ( no == 2 )
  {
    // открыты 2 клетки с разными картинками
    // закроем их и откроем новую, в которой
    // сделан щелчок

    // закрыть открытые клетки
    Pole[open1.x][open1.y]  -= 100;
    Pole[open2.x][open2.y]  -= 100;
    Kletka(open1.x,open1.y);
    Kletka(open2.x,open2.y);

    // запись в open1 номера текущей клетки
    open1.x  =  col;
    open1.y  =  row;
    no  =  1;   // счетчик открытых клеток

    // открыть текущую клетки
    Pole[open1.x][open1.y]  +=  100;
    Kletka(open1.x,open1.y);
  };

}


// сигнал от таймера
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  /* Сейчас отображаются две одинаковые картинки.
     Пометим их как найденные и уберем с экрана. */
  Pole[open1.x][open1.y]  +=  100;
  Pole[open2.x][open2.y]  +=  100;
  no  =  0; // количество открытых клеток

  // Отрисовать клетки
  Kletka(open2.x,open2.y);
  Kletka(open1.x,open1.y);

  // остановить таймер
  Form1->Timer1->Enabled  =  False;

  if ( nf == W*H/2 )
  {
   // открыты все пары
    Canvas->Font->Name  =  "Tahoma";
    Canvas->Font->Size  =  16;
    Canvas->Font->Color = clBlue;
    Canvas->Font->Color =  clBlack;
    Canvas->TextOut(100,160,"Game Over!");
    Canvas->Font->Size  =  10;
    Canvas->TextOut(120,210,"(c) Культин Н.Б., 2005");
  };
}


// обработка события Paint
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    ShowPole();
}

// команда Новая программа
void __fastcall TForm1::N1Click(TObject *Sender)
{
    NewGame();
    ShowPole();
}

// Команда Справка/Справка
void __fastcall TForm1::N3Click(TObject *Sender)
{
    WinExec("hh.exe dpic.chm", SW_RESTORE);
}

// Команда Справка/О программе
void __fastcall TForm1::N4Click(TObject *Sender)
{
    WinExec("hh.exe -mapid 3 dpic.chm", SW_RESTORE);
}

