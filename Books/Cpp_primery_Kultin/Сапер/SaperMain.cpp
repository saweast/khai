/*
    ���� "�����". ������������� ������ � ��������,
    ������������� ��������, ������ � ����� ����������
    ����������.
*/
#include <vcl.h>
#include <stdlib.h>  // ��� ������� � ���
#include <time.h>
#include <stdio.h>

#pragma hdrstop

#include "SaperMain.h"
#include "SaperAbout.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TMain *Main; // ������� ����

__fastcall TMain::TMain(TComponent* Owner)
        : TForm(Owner)
{
}

#define MR 10 // ���-�� ������ �� ���������
#define MC 10 // ���-�� ������ �� �����������
#define NM 10 // ���-�� ���

int Pole[MR+2][MC+2]; // ������ ����
                      // 0..8 - ���������� ��� � �������� �������
                      // 9 - � ������ ����
                      // 100..109 - ������ �������
                      // 200..209 - � ������ ��������� ����

int nMin;   // ���-�� ��������� ���
int nFlag;  // ���-�� ������������ ������

int status = 0; // 0 - ������ ����; 1- ����; 2 -���������

// �������� �������� ���� ������������ ������ �������� ����
// ����������� �����
#define LEFT 0   // �� X
#define TOP  1   // �� Y 

#define W    40  // ������ ������ ����
#define H    40  // ������ ������ ����

void __fastcall NewGame(); // ����� ���� - "������������" ����
void __fastcall Open(int row, int col); /* ��������� ������� � ��������
                                           ������ ������ */

// ������� ������ ���� �� ������� ����
void __fastcall TMain::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int x, int y)
{
     if ( status == 2 ) return;

     if ( status == 0) status = 1;

     x -= LEFT;
     y -= TOP;
     if (x > 0 && y > 0)
     {
         // ����������� ���������� ���� � �������
         // ������ ����
         int row = y/H + 1;
         int col = x/W + 1;

         if (Button == mbLeft)
         {
            if ( Pole[row][col] == 9 )
            {
               Pole[row][col] +=100;
               status = 2;  // ���� ���������
               ShowPole(status);
            }
            else if  ( Pole[row][col] < 9 )
                 {
                    Open(row,col);
                    ShowPole(status);
                  }
          }
          else if (Button == mbRight)
               {
                 nFlag++;
                 if ( Pole[row][col] == 9 )
                    nMin++;
                 Pole[row][col] += 200;  // ��������� ����
                 if (nMin == NM && nFlag == NM)
                 {
                   status = 2;  // ���� ���������
                   ShowPole(status);
                 }
                 else Kletka(row, col, status);
               }
     }
}

// ������� ��������� ������� OnCreate ������ ������������
// ��� ������������� ���������� ����������
void __fastcall TMain::FormCreate(TObject *Sender)
{
   // � �������������� ��-�� �������, ������� �������������
   // ������� �� ������� �������� ����, ������� ����� -3.
   // ��� �������� ������������ �������� Open ��� ����������
   // ������������ �������� �������� �������� ������ ������.
   for ( int row=0; row <= MR+1; row++)
        for ( int col=0; col <= MC+1; col++)
	   Pole[row][col] = -3;

   NewGame();  // "����������" ����
   ClientWidth = W*MC;
   ClientHeight = H*MR+TOP+1;
}

// ����� ���� ��� ��������� ��������� ������� Paint
// ��������� ��������� ����� ����������� � ������ �� ����� ������ ���������
void __fastcall TMain::FormPaint(TObject *Sender)
{
        ShowPole(status);
}

// ���������� ����
void __fastcall TMain::ShowPole( int status)
{
    for ( int row = 1; row <= MR; row++ )
         for ( int col = 1; col <= MC; col++ )
              Kletka(row, col, status);
}

// ������ �� ������ ������
void __fastcall TMain::Kletka(int row, int col, int status)
{
     int x = LEFT + (col-1)* W;
     int y = TOP + (row-1)* H;

     if (status == 0) // ������ ����
     {
        // ������ - ����� �������
        Canvas->Brush->Color = clBtnFace;
        Canvas->Rectangle(x-1,y-1,x+W,y+H);
        return;
     }

    // �� ����� (status = 1) � � ����� (status = 2) ����
    if ( Pole[row][col] < 100 )
    {
         // ������ �� �������
         Canvas->Brush->Color = clBtnFace;  // �� �������� - �����
         Canvas->Rectangle(x-1,y-1,x+W,y+H);
         if (status == 2 && Pole[row][col] == 9)
             Mina( x, y); // ���� ���������, �������� ����
         return;
    }

    // ������ �������
    Canvas->Brush->Color = clWhite;      // �������� �����
    Canvas->Rectangle(x-1,y-1,x+W,y+H);
    if  ( Pole[row][col] == 100 ) // ������ �������, �� ��� ������
         return;

    if ( Pole[row][col] >= 101 && Pole[row][col] <= 108 )
    {
             Canvas->Font->Size = 11;
             Canvas->Font->Color = clBlue;
             Canvas->TextOutA(x+3,y+2,IntToStr(Pole[row][col] -100 ));
             return;
    }

    if ( Pole[row][col] >= 200 )
         Flag(x, y);

    if (Pole[row][col] == 109 ) // �� ���� ���� �����������!
    {
         Canvas->Brush->Color = clRed;
         Canvas->Rectangle(x-1,y-1,x+W,y+H);
    }
    if (( Pole[row][col] % 10 == 9)  &&  (status == 2))
               Mina( x, y);
}


// ����������� ������� ��������� ������� � ��� ��������
// ������, � ������� ��� ���
void __fastcall Open(int row, int col)
{
	if (Pole[row][col] == 0)
	{
        Pole[row][col] = 100;
        // ��������� ������ �����, ������, ����� � ������
	    Open(row,col-1);
	    Open(row-1,col);
	    Open(row,col+1);
	    Open(row+1,col);
        // ��������� ����������� �����������
        Open(row-1,col-1);
        Open(row-1,col+1);
        Open(row+1,col-1);
        Open(row+1,col+1);
	}

	else
          // -3 ��� ������� �������� ����
          if (Pole[row][col] < 100 && Pole[row][col] != -3)
                 Pole[row][col] += 100;
}

// ����� ���� - ���������� ����� ����
void __fastcall NewGame()
{
   // ������� ��-�� �������, ��������������� ������������
   // �������, � � �������������� (�� ������� �������� ����)
   // ������� ����� -3. ���������� �������� ������ �������
   // ������������ �������� Open ��� ���������� ������������
   // �������� �������� �������� ������ ������.
   int row,col;
   for (row=0; row <= MR+1; row++)
        for (col=0; col <= MC+1; col++)
	        Pole[row][col] = -3;
   for (row=1; row <= MR; row++)
        for (col=1; col <= MC; col++)
	        Pole[row][col] = 0;

   // ��������� ����
   time_t t;    // ������������ ���
   srand((unsigned) time(&t)); // ������������� ���
   int n = 0; // ���-�� ���
   do
   {
       row = rand() % MR +1;
       col = rand() % MC +1;
       if ( Pole[row][col] != 9)
       {
           Pole[row][col] = 9;
	   n++;
       }
   }
   while ( n < 10);

   // ���������� ���-�� ��� � �������� �������
   int k;
   for ( row = 1; row <= MR; row++)
   	for ( col = 1; col <= MC; col++)
	   if ( Pole[row][col] != 9 ) {
        k =0;
		if ( Pole[row-1][col-1] == 9 ) k++;
		if ( Pole[row-1][col]   == 9 ) k++;
		if ( Pole[row-1][col+1] == 9 ) k++;
		if ( Pole[row][col-1]   == 9 ) k++;
		if ( Pole[row][col+1]   == 9 ) k++;
		if ( Pole[row+1][col-1] == 9 ) k++;
		if ( Pole[row+1][col]   == 9 ) k++;
		if ( Pole[row+1][col+1] == 9 ) k++;
		Pole[row][col] = k;
	   }
   status = 0; // ������ ����
   nMin = 0;   // ��� ������������ ���
   nFlag = 0;  // ��� ������
}

// ������ ����
void __fastcall TMain::Mina(int x, int y)
{
    Canvas->Brush->Color = clGreen;
    Canvas->Pen->Color = clBlack;
    Canvas->Rectangle(x+16,y+26,x+24,y+30);

    // ������
    Canvas->Rectangle(x+8,y+30,x+32,y+34);
    Canvas->Pie(x+6,y+28,x+34,y+44,x+34,y+36,x+6,y+36);

    // ������ �� �������
    Canvas->MoveTo(x+12,y+32); Canvas->LineTo(x+28,y+32);
    
    // ���������
    Canvas->MoveTo(x+8,y+36);  Canvas->LineTo(x+32,y+36);

    // ������������ "��"
    Canvas->MoveTo(x+20,y+22); Canvas->LineTo(x+20,y+26);
    
    // ������� "���"
    Canvas->MoveTo(x+8, y+30); Canvas->LineTo(x+6,y+28);
    Canvas->MoveTo(x+32,y+30); Canvas->LineTo(x+34,y+28);
}

// ������ ����
void __fastcall TMain::Flag( int x, int y)
{
    TPoint p[4]; // ���������� ������ � ������ ����� ������

    // ����� ������
    p[0].x=x+4;   p[0].y=y+4;
    p[1].x=x+30;  p[1].y=y+12;
    p[2].x=x+4;   p[2].y=y+20;

    // ��������� ���� ����� � ���������
    Canvas->Brush->Color = clRed;
    Canvas->Pen->Color = clRed; // ����� ������ ������ ��� �������

    Canvas->Polygon(p, 2);  // ������

    // ������
    Canvas->Pen->Color = clBlack;
    Canvas->MoveTo(p[0].x, p[0].y);
    Canvas->LineTo(x+4,y+36);

    TPoint m[5];     // ����� �

    m[0].x=x+8; m[0].y=y+14;
    m[1].x=x+8; m[1].y=y+8;
    m[2].x=x+10; m[2].y=y+10;
    m[3].x=x+12; m[3].y=y+8;
    m[4].x=x+12; m[4].y=y+14;
    Canvas->Pen->Color = clWhite;
    Canvas->Polyline(m,4);
    Canvas->Pen->Color = clBlack;
}

// ������� �������� ���� ����� ����
void __fastcall TMain::N1Click(TObject *Sender)
{
        NewGame();
        ShowPole(status);
}

// ����� � ���� "?" ������� � ���������
void __fastcall TMain::N4Click(TObject *Sender)
{
//    AboutForm->Top = Form1->Top + Form1->Height/2
//                           - AboutForm->Height/2;
//    AboutForm->Left = Form1->Left + Form1->Width/2
//                           - AboutForm->Width/2;
    About->ShowModal();
}

// ����� � ���� "?" ������� �������
void __fastcall TMain::N3Click(TObject *Sender)
{
    /* ����������� ���������� ����������
       ������������ ������� hh.exe, ��������
       � ������ Windows. ���� mappid ������
       ������������ ������ ���������� ����������. */
    WinExec("hh.exe -mapid 1 saper.chm", SW_RESTORE);
}

