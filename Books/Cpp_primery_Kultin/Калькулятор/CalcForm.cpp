#include <vcl.h>
#pragma hdrstop

#include "CalcForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

float accum; // ����������� (���-� ���������� ��������)
int op;      /* ��������:
                  1 - "+";
                  2 - "-";
                  0 - "���������" (������ ������ "=" */

int f;       /* f == 0 - ���� ������ ����� ������ �����, ��������, ����� ����������
                         ��������, ����� �� ���������� ���������.
                f == 1 - ���� ��������� ����� */

// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    f =0;     // ���� ������ �����
    op = 0;   // ���������� �������� ���������
    StaticText1->Caption = 0;
}

// ������ "0"
void __fastcall TForm1::Btn0Click(TObject *Sender)
{
    if ( f != 0)
           StaticText1->Caption = StaticText1->Caption + "0";
}

// ������ "1"
void __fastcall TForm1::Btn1Click(TObject *Sender)
{
 if ( f == 0)
    {
       StaticText1->Caption = "1";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "1";
}

// ������ "2"
void __fastcall TForm1::Btn2Click(TObject *Sender)
{
 if ( f == 0)
    {
       StaticText1->Caption = "2";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "2";
}

// ������ "3"
void __fastcall TForm1::Btn3Click(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "3";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "3";
}

// ������ "4"
void __fastcall TForm1::Btn4Click(TObject *Sender)
{
if ( f == 0)
    {
       StaticText1->Caption = "4";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "4";
}

// ������ "5"
void __fastcall TForm1::Btn5Click(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "5";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "5";
}

// ������ "6"
void __fastcall TForm1::Btn6Click(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "6";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "6";
}

// ������ "7"
void __fastcall TForm1::Btn7Click(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "7";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "7";
}

// ������ "8"
void __fastcall TForm1::Btn8Click(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "8";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "8";
}

// ������ "9"
void __fastcall TForm1::Btn9Click(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "9";
       f = 1;
    }
    else
        StaticText1->Caption = StaticText1->Caption + "9";
}

// ������ "," (���������� �����)
void __fastcall TForm1::BtnkClick(TObject *Sender)
{
    if ( f == 0)
    {
       StaticText1->Caption = "0,";
       f = 1;
    }
    else
    {
        if ( StaticText1->Caption.Pos(",") == 0)
            StaticText1->Caption = StaticText1->Caption + ",";
    }
}

// ������ "�" (�����)
void __fastcall TForm1::BtnCClick(TObject *Sender)
{
    StaticText1->Caption = "0";
    accum = 0;
    op = 0;
    f = 0; // ���� ������ ����� �����
}

// ��������� ��������
void __fastcall TForm1::DoOp(void)
{
    /* accum �������� ��������� ���������� ��������.
       ������ ���� ��������� ��������, ��� ������� op.
       ������ ��������� �� ����������.*/

    float op2 =  StrToFloat(StaticText1->Caption);
    switch ( op )
    {
        case 0 : accum = op2;  break;
        case 1 : accum += op2; break;
        case 2 : accum -= op2; break;
    }
    StaticText1->Caption = FloatToStrF(accum,ffGeneral,6,3);
}

// ������ "+"
void __fastcall TForm1::BtnPClick(TObject *Sender)
{
    /* ���� ��������� ���������� ��������,
       ������� ��������� �� ���������, ���������
       ������� �������� � ���������� ����� �����
       ������ ����� */
    if ( f != 0)
    {
        // �� ���������� ���� �����
        DoOp(); // ��������� ���������� ��������
        f = 0;  // ���� ������ ����� ������ �����
    }
    op =1;
}

// ������ "-"
void __fastcall TForm1::BtnMClick(TObject *Sender)
{
    if ( f != 0)
    {
        // �� ���������� ���� �����
        DoOp(); // ��������� ���������� ��������
        f = 0;  // ���� ������ ����� ������ �����
    }
    op = 2; // ��������� ������� ��������
}

// ������ "="
void __fastcall TForm1::BtnEClick(TObject *Sender)
{
    if ( f != 0)
    {
        DoOp(); // ��������� ���������
        f = 0;  // ���� ������ ����� ������ �����
    }
    op = 0;
}

