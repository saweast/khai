/*
   ��������������, �������� ������� ����������� �� bmp-�����.
   ��������� ���� ����������� � ������, � ����� ���������
   �� ����������� �����.

*/

#include <vcl.h>
#pragma hdrstop

#include "FlightMain.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    // ��������� ������� ������� �� bmp �����
    back = new Graphics::TBitmap();
    back->LoadFromFile("sky.bmp");

    // ���������� ������ ���������� (�������) ������� �����
    // � ������������ � �������� �������� �������
    ClientWidth = back->Width;
    ClientHeight = back->Height;

    // ��������� ��������
    sprite =  new Graphics::TBitmap();
    sprite->LoadFromFile("plane.bmp");
    sprite->Transparent = true;

    // ������������ ����
    kadr = new Graphics::TBitmap();
    kadr->LoadFromFile("plane.bmp");

    // �������� ��������� ��������
    x=-40; // ����� ������� "�������" ��-�� ����� ������� ����
    y=20;

    Timer1->Interval = 10;
    Timer1->Enabled = true;

}

// ������ �� �������
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    TRect badRect; // ��������� � ������ ������� ����,
                   // ������� ���� ������������

    TRect  frameRect;

    badRect = Rect(x,y,x+sprite->Width,y+sprite->Height);
    frameRect = Rect(0,0, kadr->Width, kadr->Height);

    #ifdef ONCANVAS
    // *** ����������� ��������� �� ����������� ����� ***

    // ������� ������� (������������ "�����������" ���)
    Canvas->CopyRect(badRect,back->Canvas,badRect);

    // �������� ����� ���������� �������
    x +=2;
    if (x > ClientWidth)
    {
        // ������� ������ �� ������ ������� �����
        // ������� ������ � �������� ������
        x = -20;
        y = random(ClientHeight - 30);  // ������ ������
        // �������� ������ ������������ �������� �������������
        // ������� OnTimer, �������, � ���� �������, �������
        // �� �������� �������� Interval
        Timer1->Interval = random(20) + 10; // �������� "������" �� 10 �� 29
    }
    Canvas->Draw(x,y,sprite);

    #else
    //  ����������� ��������� �� ������� �����������,
    // ����� ������� �� ����������� �����

    // ������������ ��������� ����

    // ����������� �������� ����
    kadr->Canvas->CopyRect(frameRect, back->Canvas,badRect);
    // ���������� ������
    kadr->Canvas->Draw(0,0,sprite);

    // ������� ����
    Form1->Canvas->Draw(x,y,kadr);

    // �������� ����� ���������� �������
    x += 1;
    if (x > ClientWidth)
    {
        // ������� ������ �� ������ ������� �����
        //   ������� ������ � �������� ������
        x = -20;
        y = random(ClientHeight - 30);  // ������ ������
        // �������� ������ ������������ �������� �������������
        // ������� OnTimer, �������, � ���� �������, �������
        // �� �������� �������� Interval
        Timer1->Interval = random(20) + 10; // �������� "������" �� 10 �� 29
    }
    #endif
}

void __fastcall TForm1::FormPaint(TObject *Sender)
{
    // ������������ ������� �������
    Canvas->Draw(0,0,back);    // ���
}

