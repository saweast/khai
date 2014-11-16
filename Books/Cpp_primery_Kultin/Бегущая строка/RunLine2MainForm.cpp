//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RunLine2MainForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Graphics::TBitmap *banner;   // ������ - �������� ����������� �� �������

int x,y;    // ���������� ������ �������� ���� ������� ������ �������
int pause;  // ����� (���������� ������ �������) ������������ �������� �������
int xp;     // ���������� ������������ �������� ������
TColor bc;  // ���� ���� �������

// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    banner = new Graphics::TBitmap();
    // ��������� ������ �� �������
    banner->LoadFromResourceID((int)HInstance,101);
    bc = banner->Canvas->Pixels[0][0]; // ���� ���� �������
    x = Form1->ClientWidth; // ������ "���������" ��-�� ������ ������� ����
    y = 0;
    // ��������� ���������� X ����� ������������ �������� �������
    xp = (Form1->ClientWidth - banner->Width) / 2;
    if (xp < 0 ) xp = 0;
}

// ������ �� �������
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if ( pause > 0 )
    {
        pause--;
        return;
    }

    Form1->Canvas->Draw(x,y,banner);
    //x--;
    if ( --x == xp)
    {
        pause = 100; // ���������� �������� ������ �� 100 ������ �������
    }

    if ( x < - banner->Width)
        x = Form1->ClientWidth;

}

// ��������� ������� Paint
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    TColor b,p;

    b = Canvas->Brush->Color; // ��������� ������� ���� �����
    p = Canvas->Pen->Color;   // ��������� ������� ���� ���������

    // ��������� ������� ������ ������ ������ ���� ������
    Canvas->Brush->Color = bc;
    Canvas->Pen->Color = bc;
    Canvas->Rectangle(0,0,ClientWidth,banner->Height);

    Canvas->Brush->Color = b; // ������������ ���� �����
    Canvas->Pen->Color = p;   // ������������ ���� ���������
}

// ������������ ������� ������ �����
void __fastcall TForm1::FormResize(TObject *Sender)
{
    // ��������� ���������� X ����� ������������ �������� �������
    xp = (Form1->ClientWidth - banner->Width) / 2;
    if (xp < 0 ) xp = 0;
}

