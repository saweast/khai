//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PingPongForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;



/* ���� "����-����"
   ������������� ������� ���������������� ������������� �������.
  (�) ������� �.�., 2004 */


int x, y;     // ��������� ������
int dx, dy;   // ���������� ���������
int r;        // ������ ������
TColor cBall; // ���� ������
TColor cBack; // ���� ����
int wp, hp;   // ������ ���� (�����)


// ��� ���������� ��� ���������� ��������� �������
int rd;        //  0 - ������� �� ��������; 1 - �������� �����; 2 - �������� ������
int rx1, rx2;  // ���������� X ������ �������
int ry;        // ���������� Y ������ �������
int rdx;       // ��� ����������� �������

// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    r = 5;          // ������ ������
    x = r; y = 50;  // ��������� ��������� ������
    dx = 1;
    dy = 1;

    cBall = (TColor)RGB(217, 217, 25); // ���� ������
    cBack = (TColor)RGB(33, 94, 33);   // ���� ����

    Form1->Color = cBack;

    wp = Form1->ClientWidth;
    hp = Form1->ClientHeight;

    //  ���������� ��������
    rd = 0;     // ������� �� ����� (�� ��������)
    rx1 = 100;
    rx2 = 125;
    ry = Form1->ClientHeight - 20; // ���������� �� ������ ������� ����� 20 ��������
    rdx = 2; // ��� �������� �������

    // ��������� �������
    Timer1->Interval = 10;
    Timer1->Enabled = true;
}

void __fastcall TForm1::FormPaint(TObject *Sender)
{
    // ���������� �������
    Form1->Canvas->Pen->Color = clRed;
    Form1->Canvas->Rectangle(rx1, ry, rx2, ry+1);
}

// ������ �� �������
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    // ������� ����������� ����
    Form1->Canvas->Pen->Color = cBack;
    Form1->Canvas->Ellipse(x,y,x+r,y+r);


    // ** ��������� ����� ��������� ���� **
    if ( dx > 0 )
    {
        // ��� �������� ������
        if ( x + dx + r > wp ) dx = - dx;
    }
    else
        // ��� �������� �����
        if ( x + dx - r < 0 ) dx = -dx;

    if ( dy > 0 )
    {
        // ��� �������� ����
        if ((x >= rx1) && (x <= rx2 -r) && (y == ry - r - 1) )
            // ����� ����� � �������
            dy = - dy;
        else
            if (  y + dy + r > Form1->ClientHeight ) dy = -dy;
    }
    else
    {
        // ��� �������� �����
        if ((x >= rx1) && (x <= rx2) && (y >= ry - r) && (y <= ry + r) )
        {
            // ����� �������� �� ������ ������ � ����� � ������� �����.
            // ����� �� ���� ����� � �������, ���������� ��.
            Form1->Canvas->Pen->Color = clRed;
            Form1->Canvas->Rectangle(rx1, ry, rx2, ry+1);
        }
        if ( y + dy - r < 0 ) dy = -dy;
    }
    x += dx;
    y += dy;

    // ���������� ��� � ����� �����
    Form1->Canvas->Pen->Color = cBall;
    Form1->Canvas->Ellipse(x,y,x+r,y+r);

    // *** ������� ***
    if ( rd != 0 )
    {
        // ����� ����� � ���������� ���� �� ������
        // "������� ������" ��� "������� �����"
        // (��. FormKeyDown )
        if ( rd == 1 )
        {
            // ������
            if ( rx2 < wp )
            {
                // ������� ����� �����
                Form1->Canvas->Pen->Color = cBack;
                Form1->Canvas->Rectangle(rx1, ry, rx1 + rdx, ry +1);
                // ���������� ����� ������
                Form1->Canvas->Pen->Color = clRed;
                Form1->Canvas->Rectangle (rx2, ry, rx2 + rdx, ry+1);
                rx1 += rdx;
                rx2 += rdx;
            }
        }
        else
           // �����
           if (rx1 > 1 )
           {    // ������� ����� ������
                Form1->Canvas->Pen->Color = cBack;
                Form1->Canvas->Rectangle (rx2, ry, rx2 - rdx, ry+1);
                // ���������� �����
                Form1->Canvas->Pen->Color = clRed;
                Form1->Canvas->Rectangle(rx1 - rdx, ry, rx1 + rdx, ry+1);
                rx1 -= rdx;
                rx2 -= rdx;
            }
    }

}

// ������ �������
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (rd != 0 )
        // ������������ ���������� �������, ������� ��������
        return;

    switch ( Key )
    {
        case VK_LEFT : // ��� (�������) �����
            rd = 2; break;
        case VK_RIGHT :  // ��� (�������) �����
            rd = 1; break;
    }
}

// ������� ��������
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    rd = 0;
}

