#include <vcl.h>
#pragma hdrstop

#include "GudDayForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

#include "DateUtils.hpp"

TForm1 *Form1;

Graphics::TBitmap *bgp; // ������� �������

AnsiString sMonth[] = {"","������","�������","�����",
      "������","���","����",
      "����","�������","��������",
      "�������","������","�������"};

// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    bgp = new Graphics::TBitmap();
    try
    {
        bgp->LoadFromFile("sky.bmp");
    }
    catch (EFOpenError &e)
    {

    }
}

// �������� ������� Paint
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    int h;           // ������� ����� (����)
    AnsiString mes;  // ���������
    int wt,ht;         // ������ (������ � ������) ������� ������ ������
    int x,y;         // ���������� ������� ������ ������

    h = HourOf( Now() );

    if ( h <= 4 ) mes = "������ ����!";
    else if ( h < 12 ) mes = "������ ����!" ;
    else if ( h <= 16)  mes = "������ ����!" ;
    else if ( h <= 16)  mes = "������ ����!" ;
         else mes = "������ �����!";

    Form1->Font->Name = "Times New Roman";
    //Form1->Font->Color = clBlue;
    Form1->Canvas->Font->Size = 20;

    // ���������� ������ ������� ������ ������
    wt = Canvas->TextWidth(mes);
    ht = Canvas->TextHeight(mes);

    x = (ClientWidth - wt) / 2;
    y = ClientHeight / 2 - ht;

    // ������� ��������
    Canvas->Draw(0,0,bgp);

    // ����� ������� ������ ������ ���� ����������
    Canvas->Brush->Style = bsClear;

    Canvas->TextOutA(x,y,mes);

    y = y + ht; // ����������� ������ ������� ������� ������ ������

    // ���� � ���� ������
    mes = FormatDateTime("������� d", Now() );
    mes = mes + " " + sMonth[MonthOf( Now())] + ", " +
                FormatDateTime("dddd", Now() );

    /* ������ ������ ������ ���� �� 4 ������ ������
       ������� ������ ����������� */
    Canvas->Font->Size -= 4;
    wt = Canvas->TextWidth(mes);
    ht = Canvas->TextHeight(mes);

    x = (ClientWidth - wt) / 2;
    y = y + 6;

    Canvas->TextOutA(x,y,mes);
}

// ������������ ������� ������ �����
void __fastcall TForm1::FormResize(TObject *Sender)
{
    Form1->Refresh(); // ������������ ����
}

