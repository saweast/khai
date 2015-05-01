/*
    ����� �� ������.

*/

#include <vcl.h>
#pragma hdrstop

#include "SheetFrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}


void __fastcall TForm1::FormCreate(TObject *Sender)
{
     // *** ��������� ������� ***
    StringGrid1->Options
            << goEditing             // ��������� �������������
            << goTabs;                // <Tab> - ������� � ��������� ������
//            << goAlwaysShowEditor;  // ������ ���������� �����

    // ��������� ��������
    StringGrid1->Cells[0][0] = "";
    StringGrid1->Cells[1][0] = "        ������������";
    StringGrid1->Cells[2][0] = "    ����";
    StringGrid1->Cells[3][0] = " ���-��";
    StringGrid1->Cells[4][0] = "    �����";

    // ������ ��������
    StringGrid1->ColWidths[0] = 30;
    StringGrid1->ColWidths[1] = 250;
    StringGrid1->ColWidths[2] = 80;
    StringGrid1->ColWidths[3] = 50;
    StringGrid1->ColWidths[4] = 80;

    // ��������� ������ �������
    for ( int i = 1; i < 11; i++)
        if (i < 10)
            StringGrid1->Cells[0][i] = "  " + IntToStr(i);
        else
            StringGrid1->Cells[0][i] = IntToStr(i);

    int w = 0;
    for (int i = 0; i < StringGrid1->ColCount; i++)
        w += StringGrid1->ColWidths[i];

    // ���������� ������ StringGrid � ������������ � ��������
    // �������� � ����������� �����
    StringGrid1->Width = w + StringGrid1->ColCount +1 ;
    StringGrid1->Height =
        StringGrid1->DefaultRowHeight * StringGrid1->RowCount +
        StringGrid1->RowCount + 1;
}

#include "Printers.hpp"
// ������ �� ������ ������
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    TPrinter *Prn; // �������

    #define LEFT_MARGIN 2 // ������ ����� 2 ��
    #define TOP_MARGIN  2 // ������ ������ 2 ��


    float dpiX, dpiY; // ���������� �������� �� X � Y
    float kx, ky;     // ����. ��������� ��������� ������
                    // � ���������� �������� �� � � Y
    // �������
    int p[5];  // ������� �������
    int x1,y1,x2,y2; // ������� �������

    int px, py; // ��������� ����� ������
    int i, j;

    /* ���������� ������ � �������� ������,
       ������� ����� �������� ������������
       �������� ����������� �� ������ � ��������,
       ���������� ����� ������ ���� �������������
       � ���������� ��������, �������� �� ����.,
       �������� �������� ������� �� ���������� ��������.
       ��������, ���� ���������� �������� 300 dpi,
       �� �������� ������������ ����� 3.125, �.�.
       ���������� ������ - 96 dpi */

    Prn = Printer();

     /* �-� GetDeviceCaps ��������� �������� ��������������
       ����������. LOGPIXELSX - ���-�� �������� �� ���� �� X */

    dpiX  =  GetDeviceCaps(Prn->Handle,LOGPIXELSX);
    dpiY  =  GetDeviceCaps(Prn->Handle,LOGPIXELSY);
    kx  =  dpiX / Screen->PixelsPerInch;
    ky  =  dpiY / Screen->PixelsPerInch;

    px  =  LEFT_MARGIN / 2.54 * dpiX;
    py  =  TOP_MARGIN  / 2.54 * dpiY;

    // �������� "����������" ���������� ������� �������
    p[0]  =  px;
    for (i = 1; i < 5; i++ )
        p[i]  =  p[i-1] + StringGrid1->ColWidths[i-1]* kx + i;

    Prn->BeginDoc(); // ������� ������

    // ��������� �������
    Prn->Canvas->Font->Name  =  Label1->Font->Name;
    Prn->Canvas->Font->Size  =  Label1->Font->Size;
    Prn->Canvas->TextOut(px,py,Label1->Caption);

    // ������� - ���������� StringGrid1
    py  =  py + Label1->Font->Size * 2 * ky;

    x1  =  px; y1  =  py; // ����� ������� ���� �������

    Prn->Canvas->Font->Name  =  StringGrid1->Font->Name;
    Prn->Canvas->Font->Size  =  StringGrid1->Font->Size;

    x2  =  p[4] + StringGrid1->ColWidths[4]* kx;
    y2  =  py +
           StringGrid1->RowCount * StringGrid1->RowHeights[1] * ky;

    for ( j = 0; j < StringGrid1->RowCount; j++)
    {
       // ������ �������
       for (i = 0; i < StringGrid1->ColCount; i++)
       {
          Prn->Canvas->TextOut(p[i],py,StringGrid1->Cells[i][j]);
          // ���->�����
          Prn->Canvas->MoveTo(p[0],py);
          Prn->Canvas->LineTo(x2,py);
       }
       py = py+ StringGrid1->RowHeights[j]* ky;
    }

    // ������������ �����
    for ( i = 0; i < StringGrid1->ColCount; i++ )
    {
        Prn->Canvas->MoveTo(p[i],y1);
        Prn->Canvas->LineTo(p[i],y2);
    }
    // ������ �������
    Prn->Canvas->MoveTo(x2,y1);
    Prn->Canvas->LineTo(x2,y2);

    // ������ �������
    Prn->Canvas->MoveTo(x1,y2);
    Prn->Canvas->LineTo(x2,y2);

    py = y2 + 0.5 / 2.54 * dpiY; // ����� 1 - ��� 1 ��.
    Prn->Canvas->TextOut(p[3],py,Label2->Caption);

    Prn->EndDoc();  // ������� ������
}

// ������ �� ������ ������
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    float summ;

    summ = 0;
    for ( int i = 1; i < 11; i++)
    {
        // ���� ������ ����� ������, �� ��� ����������
        // ������� StrToFloat ��������� ������ (����������)
        try
        {
            summ += StrToFloat(StringGrid1->Cells[4][i]);
        }
        catch (Exception &e)
        {
        }
    }

    Label2->Caption = "�����: " + FloatToStr(summ) + " ���.";
}

