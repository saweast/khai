//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ClockForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


#include "DateUtils.hpp" // ��� ������� � SecondOf, MinuteOf � HourOf
#include "math.h"        // ��� ������� � sin � cos

/* ��� ���������� ������ � �������� ����� ���������������
   �������� SinCos, ������� ���������� ����� � ������� ����,
   ��������� � ��������. ����� ������������ ��� �������,
   � ��������� ���� �������� ��������� #include "Math.hpp" */

#define R 75     // ������ ���������� �����


int  x0, y0;         // ����� ����������
int ahr,amin,asec;   // ��������� ������� (����)


__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    TDateTime t;

    // ������� ������ �����
    // � ������������ � �������� ����������
    ClientHeight = (R + 30)*2;
    ClientWidth  = (R + 30)*2;
    x0  =  R + 30;
    y0  =  R + 30;

    t  =  Now();

    // ���������� ��������� �������.
    // ���� ����� ������� (�������) �����, ��������, ������� 2 � 3, - 30 ��������.
    // ���� ����� ������� ����� - 6 ��������.
    // ���� ����������� �� 12-�� �����
    ahr  =   90 - HourOf(t)*30-(MinuteOf(Today() ) / 12) *6;
    amin  =  90 - MinuteOf(t)*6;
    asec  =  90 - SecondOf( Today() )*6;

    Timer1->Interval =  1000; // ������ ������ �� ������� 1 ���
    Timer1->Enabled  =  true; // ���� �������
}

// ������ ������ �� ����� (x0,y0) ��� ����� a ������������
// ��� X. ������ ������� l
void __fastcall TForm1::Vector(int x0, int y0, int a, int l)
{
    // x0,y0 - ������ �������
    // a - ���� ����� ���� x � ��������
    // l - ����� �������
    #define TORAD 0.0174532  // ����������� ��������� ���� �� �������� � �������

  int x, y;       // ���������� ����� �������

  Canvas->MoveTo(x0,y0);
  x  =  x0 + l * cos(a*TORAD);
  y  =  y0 - l * sin(a*TORAD);
  Canvas->LineTo(x,y);

}


// ���������� ����������
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    int x, y;  // ���������� ������� �� ����������
    int a;     // ���� ����� OX � ������ (x0,yo) (x,y)
    int h;     // ����� ������� �����

    TBrushStyle bs; // ����� �����
    TColor pc;      // ���� ���������
    int pw;         // ������ ���������

    bs  =  Canvas->Brush->Style;
    pc  =  Canvas->Pen->Color;
    pw  =  Canvas->Pen->Width;

    Canvas->Brush->Style  =  bsClear;
    Canvas->Pen->Width  =  1;
    Canvas->Pen->Color =  clBlack;

    a = 0; // ����� ������ �� 3-� �����, ������ ������� �������
    h = 3; // ���� 0 �������� - ��� 3 ����

    // ���������
    while ( a < 360 )
    {
        x = x0 +  R * cos(a * TORAD);
        y = x0 -  R * sin(a * TORAD);
        Form1->Canvas->MoveTo(x,y);
        if ( (a % 30) == 0 )
        {
            Canvas->Ellipse(x-2,y-2,x+3,y+3);
            // ����� �� �������� �������
            x = x0 +  (R+15) * cos(a * TORAD);
            y = x0 -  (R+15) * sin(a * TORAD);
            Canvas->TextOut(x-5,y-7,IntToStr(h));
            h--;
            if ( h == 0 ) h = 12;
        }
        else
            Canvas->Ellipse(x-1,y-1,x+1,y+1);
        a = a + 6; // 1 ������ - 6 ��������
    }
    // ������������ �������� �����
    Canvas->Brush->Style  =  bs;
    Canvas->Pen->Width  =  pw;
    Canvas->Pen->Color =  pc;

    DrawClock();

}

void __fastcall TForm1::DrawClock(void)
{
    TDateTime t;

  // ��� ��������� � �������� ������� 6 ��������,
  // ������� - 30.

  // ������� ����������� �������
  Canvas->Pen->Color =  clBtnFace;
  Canvas->Pen->Width  = 3;
  // �������
  Vector(x0,y0, ahr, R-20);
  // ��������
  Vector(x0,y0, amin, R-15);
  // ���������
  Vector(x0,y0, asec, R-7);

  t  =  Now();

  // ����� ��������� �������
  ahr  =   90 - HourOf(t)*30-(MinuteOf(t)% 12)*6;
  amin  =  90 - MinuteOf(t)*6;
  asec  =  90 - SecondOf(t)*6;

  // ���������� �������
  // ������� �������
  Canvas->Pen->Width  =  3;
  Canvas->Pen->Color =  clBlack;
  Vector(x0,y0, ahr, R-20);

  // �������� �������
  Canvas->Pen->Width  =  2;
  Canvas->Pen->Color =  clBlack;
  Vector(x0,y0, amin, R-15);

  // ��������� �������
  Canvas->Pen->Width  =  1;
  Canvas->Pen->Color =  clYellow;
  Vector(x0,y0, asec, R-7);
}

// ������ �� �������
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    DrawClock();
}

