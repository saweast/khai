/*

    ���� "������ ��������".
    ������������� ������ � ��������.
*/

#include <vcl.h>
#pragma hdrstop

#include "DPpicMain.h"
#pragma package(smart_init)
#pragma resource "*.dfm"


#include <Math.hpp>  // ��� ������� � ���

#define  MAX_SIZE  32 // ������������ ���-�� ��� ��������
#define  MAX_H  8     // ������������ ������ ���� - 8�8
#define  MAX_W  8

// #define DEBUG    // ����� �������

int  Pole[MAX_W][MAX_H]; // ����
     /* Pole[i][j] < 100 - ��� ��������, ������ �������;
        Pole[i][j] > 100 �� < 200 - ������ ������� (����� ����� ��������);
        Pole[i][j] > 200 - ����� ����� ���� ��� ���� �������� */

Graphics::TBitmap  *Pictures;    // ��������

int np;  // ���������� ��� ��������
int nf;  // ����� �������� (���������) ��� ��������
int no;  // ���������� �������� � ������ ������ ������

TPoint open1;  // ���������� 1-� �������� ������
TPoint open2;  // ���������� 2-� �������� ������

int W,H;    /* ���-�� ������ �� ����������� � ���������.
                 ������������ W � H ������ ���� ������ 2-� */

int WK, HK;  // ������ ������ (��������)

TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}





void __fastcall TForm1::FormCreate(TObject *Sender)
{
  //int np; // ���-�� �������� � ����� pictures

  Pictures  =  new Graphics::TBitmap();

  try {
    Pictures->LoadFromFile("pictures.bmp");
  }
  catch (EFOpenError &e)
  {
   ShowMessage("������ ������� � ����� ��������.");
   return;
  }

  /* � ����� pictures ��������� ��� ��������. ��������������,
     ��� ������ �������� ����������. */

 /* �������, ��� � ����� 8,10,12,14 ��� 15 ��������:

    ��������   ������    ����
    -------------------------
       8        16       4�4
       10       20       4�5
       12       24       4�6
       14       28       4�7
       15       30       5�6
 */

  HK  =  Pictures->Height-1; // ������ ��������
  WK  =  HK;                 // ������ ��������

  np =  Pictures->Width / WK;
  if ( np < 15)
    H  =  4;
  else H  = 5;

  W  =  (np*2)/H;

  // ���������� ������� ���� (�����)
  ClientHeight  =  H * HK;
  ClientWidth  =  W * WK;

  // ��������� �������
  Timer1->Enabled  =  False;
  Timer1->Interval  =  200;

  NewGame();
}

// ����� ����
void __fastcall TForm1::NewGame()
{
  /* � ������ ������ Pole ���� �������� ����� ��������.
     ��� ��� ��� ������ �������� ������ ���� ����, ��
     ����� i ������ ���� � ���� ������� Pole */

  int r;       // ��������� �����

  int buf[MAX_SIZE];
  /* � buf[i] ����������, ������� ��� ����� i
    �������� � ������ Pole */

  int i, j; // ������� ��������

  // ������� � ������ Pole ��������� �����
  // �� 0 �� np, ��� n - ���-�� ��������
  // ������ ����� ������ ���� �������� ��� ����

  for (i = 0; i < np; i++)
      buf[i]  =  0;

  Randomize(); // ������������� ���
  for (i = 0; i < H; i++)
    for (j = 0; j < W; j++) {
        do  {
          r  =  RandomRange(0,np);
        } while ( buf[r] == 2 );
        Pole[i][j]  =  r;   // ��� ��������
        buf[r]++;
    }
  // ����� ���� �������������
   nf = 0;
};


// ������������ ����
void __fastcall  TForm1::ShowPole()
{
   int row,col;

   for ( row = 0; row < H; row++)
      for (col = 0; col < W; col++)
           Kletka(row,col);
}

// ������ ������ ����
void __fastcall TForm1::Kletka(int col,int row)
{
  int x, y;       // ����� ������� ���� ������ (����������)
  TRect src, dst; // �������� � ���������� �������� ������

  // ����������� ���������� ������
  // � ���������� �� ����������� �����
  x  =  (col)*WK;
  y  =  (row)*HK;

  if ( Pole[col][row] >= 200 ) {
        /* ��� ���� ������ ������� ����.
           ������ ���� ������ � ���� */

      // ���������� ���� ������� � �������� �������
      Canvas->Brush->Color =  clBtnFace;
      Canvas->Pen->Color =  clBtnFace;
      Canvas->Rectangle(x,y,x+WK-2,y+HK-2);
      return;
   };


   if ( (Pole[col][row] >= 100) && (Pole[col][row] < 200) ) {
       // ������ ������� - ������� ��������

      // Pole[col,row] == ����� �������� + 100,
      // ��� 100 - ������� ����, ��� ������ �������
      // ��������� ��������� �������� � Pictures
      src  =  Bounds((Pole[col][row]-100 )*WK,0,WK,HK);

      // ���������� �������� (������) �� �����
      dst  =  Bounds(x,y,HK-2,WK-2);

      // ������� �������� � ������
      Form1->Canvas->CopyRect(dst,Pictures->Canvas,src);

      // ���������� ������ ������
      Canvas->Pen->Color =  clBlack;
      Canvas->Brush->Style  =  bsClear;
      Canvas->Rectangle(x,y,x+WK-2,y+HK-2);
      return;
  };


  if ( (Pole[col][row] >= 0) && (Pole[col][row] < 100) )
    // ������ �������, ������ ������ ������
    {
      Canvas->Brush->Color =  clBtnFace;
      Canvas->Pen->Color =  clBlack;
      Canvas->Rectangle(x,y,x+WK-2,y+HK-2);
    }

#ifdef DEBUG
  // ��������� - ����� ��������
  Canvas->Font->Color = clBlack;
  Canvas->TextOut(x+15,y+15, IntToStr(Pole[col][row]));
#endif
};


// ������� ������ ����
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  int col;   // ����� ������ �� �����������
  int row;   //����� ������ �� ���������


  col = X/WK;
  row = Y/HK;

  if ( Pole[col][row] >= 200 )
     // ������ � �� ����� ��� �������� ��������
    return;

  if ( no == 0 ) // �������� ������ ���
  {
    no  =  1;
    open1.x  =  col;
    open1.y  =  row;

    // ������ ���������� ��� ��������
    Pole[open1.x][open1.y]  +=  100;
    Kletka(open1.x,open1.y);
    return;
  };

  if ( no == 1 )
  {
    // ������� ���� ������, ���� ������� ������
    open2.x  =  col;
    open2.y  =  row;

    // ���� ������� ���� ������ � ������ ������
    // � ���� ������, �� ������ �� ����������
    if ( (open1.x == open2.x) && (open1.y == open2.y) )
        return;

    else
    {
      no  =  2; // ������ ������� ��� ������
      Pole[open2.x][open2.y]  += 100;
      Kletka(open2.x,open2.y); // �������� ������ ������

      // ��������, �������� �������� ����������?
      if ( Pole[open1.x][open1.y] == Pole[open2.x][open2.y] )
        // ������� ��� ���������� ��������
        {
          nf++;
          Form1->Timer1->Enabled  =  True; // ��������� ������
          // �������� ��������� ������� OnTimer
          // "������" ��� ���������� ��������
        };
      return;
    }
  };

  if ( no == 2 )
  {
    // ������� 2 ������ � ������� ����������
    // ������� �� � ������� �����, � �������
    // ������ ������

    // ������� �������� ������
    Pole[open1.x][open1.y]  -= 100;
    Pole[open2.x][open2.y]  -= 100;
    Kletka(open1.x,open1.y);
    Kletka(open2.x,open2.y);

    // ������ � open1 ������ ������� ������
    open1.x  =  col;
    open1.y  =  row;
    no  =  1;   // ������� �������� ������

    // ������� ������� ������
    Pole[open1.x][open1.y]  +=  100;
    Kletka(open1.x,open1.y);
  };

}


// ������ �� �������
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  /* ������ ������������ ��� ���������� ��������.
     ������� �� ��� ��������� � ������ � ������. */
  Pole[open1.x][open1.y]  +=  100;
  Pole[open2.x][open2.y]  +=  100;
  no  =  0; // ���������� �������� ������

  // ���������� ������
  Kletka(open2.x,open2.y);
  Kletka(open1.x,open1.y);

  // ���������� ������
  Form1->Timer1->Enabled  =  False;

  if ( nf == W*H/2 )
  {
   // ������� ��� ����
    Canvas->Font->Name  =  "Tahoma";
    Canvas->Font->Size  =  16;
    Canvas->Font->Color = clBlue;
    Canvas->Font->Color =  clBlack;
    Canvas->TextOut(100,160,"Game Over!");
    Canvas->Font->Size  =  10;
    Canvas->TextOut(120,210,"(c) ������� �.�., 2005");
  };
}


// ��������� ������� Paint
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    ShowPole();
}

// ������� ����� ���������
void __fastcall TForm1::N1Click(TObject *Sender)
{
    NewGame();
    ShowPole();
}

// ������� �������/�������
void __fastcall TForm1::N3Click(TObject *Sender)
{
    WinExec("hh.exe dpic.chm", SW_RESTORE);
}

// ������� �������/� ���������
void __fastcall TForm1::N4Click(TObject *Sender)
{
    WinExec("hh.exe -mapid 3 dpic.chm", SW_RESTORE);
}

