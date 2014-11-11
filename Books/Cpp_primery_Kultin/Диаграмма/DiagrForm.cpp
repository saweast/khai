/*
    ��������� ������ ���������
*/

#include <vcl.h>
#pragma hdrstop

#include "DiagrForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

float data[] = {27.98, 28.01, 27.96, 27.96, 28.11, 28.08, 28.00, 27.98, 28.15, 28.15, 28.11, 27.94, 27.86, 27.88, 27.95, 27.95};
                //, 27.74, 27.74, 27.77, 27.77, 27.82, 27.83, 27.83, 27.88, 27.89, 27.88, 27.83, 27.91, 27.99, 28.12};
AnsiString Title = "��������� ����� �������";

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}


void __fastcall TForm1::FormPaint(TObject *Sender)
{
    int x,y;

    // ���������
    Canvas->Font->Name = "Tahoma";
    Canvas->Font->Size = 12;
    x = (ClientWidth - Canvas->TextWidth(Title)) /2;
    Canvas->Brush->Style = bsClear;
    Canvas->TextOutA(x,10,Title);

    // �����������

    int n;    // ���������� ��������
    int wCol; // ������ �������

    #define MC 5 // ���������� ����� ���������� �� �����������

    n = sizeof(data) / sizeof(float);
    wCol = (ClientWidth - (n - 1)*MC - 20) / n;


    x = 10;
    y = ClientHeight - 20;

    // *** ����� ����������� � ������������ �������� ������ ***
    int min,max;  // ������ ������������ � ������������� ��������

    min = 0;  // ����� ������ ������� �����������
    max = 0;  // ����� ������ ������� ������������
    for (int i = 1; i < n; i++)
    {
        if (data[i] < data[min]) min = i;
        if (data[i] > data[max]) max = i;
    }

    /*
        ���� ���������� �������� ���� �� �������� ��������
        ��������������, �� ��������� ���������� �����������.
        � ���� ������ ����� ��������� �� ���������� ��������,
        � ���������� �� ������������ �������� ����.
    */

    bool frmin = true; // true - ����������� �� ������������ ��������


    int h; // ������ ��������
    // ������������� �������� �������������
    // ������� ������� ClientHeight - 90


    Canvas->Font->Size -= 2;
    for ( int i = 0; i < n; i++)
    {
        if (! frmin)
            h = (ClientHeight - 90) * data[i]/data[max];
        else
            /* ����������� �� ������������ ��������.
               ����������� �������� ��������� ���������
               ������� 10 �������� */
           h = (ClientHeight - 90) * (data[i] - data[min])/(data[max] - data[min]) + 10;

        Canvas->Brush->Style = bsSolid;
        //Canvas->Brush->Color = clMaroon;
        Canvas->Brush->Color = clLime;
        Canvas->Rectangle(x,y,x+wCol,y-h); // �������

        // ������� ������
        AnsiString st;
        st = FloatToStrF(data[i],ffGeneral,5,2);
        Canvas->Brush->Style = bsClear;  // ������� ������ ������ - ����������
        Canvas->TextOutA(x,y-h-20,st);

        x = x + wCol + MC;
    }

}

// ��������� ������ ����
void __fastcall TForm1::FormResize(TObject *Sender)
{
    Form1->Refresh(); // �������� ���������� ����
}



