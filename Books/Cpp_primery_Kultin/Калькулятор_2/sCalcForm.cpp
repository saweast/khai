 /*
   ��������� ������������� �������� ����������� �� ����� ������ ���������.
   ������ ������������ - ��� ������������ � ������ ���������� SpeedButton.
*/

#include <vcl.h>
#pragma hdrstop

#include "sCalcForm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

float ac;  // ����������� (������ �������)
int op;    // ��������
int fd;    /* fd == 0 - ���� ������ ����� �����, ��������, �����
              ����, ��� ���� ������ ������� "+";
              fd = 1 - ���� ����� ��������� ����� ���
              ������� ������� �������� */

#define WBTN  35  // ������ ������
#define HBTN  20  // ������ ������
#define DXBTN  6  // ��� ������ �� X
#define DYBTN  6  // ��� ������ �� Y


// ����� �� ������
Char btnText[] = "789+456-123=00.c";

#define CM -1  // �������
#define EQ -2  // "="
#define PL -3  // "+"
#define MN -4  // "-"
#define CL -5  // "C"

// ������������� ������
int  btnTag[]  = {7,8,9,PL,4,5,6,MN,1,2,3,EQ,0,0,CM,CL};

//  ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    int left, top; // ��������� ������

    top = 48;

    int k = 0; // ������ ������� btn
    for ( int i = 0; i < 4; i++ )  // ������ ���� ������
    {
        left = 8;
        for ( int j = 0;  j < 4; j++) // �� ������ � ������ ����
        {
            btn[k] = new TSpeedButton(Form1);
            btn[k]->Parent = Form1; // "��������" ������ �� �����
            // ��������� ������
            btn[k]->Left = left;
            btn[k]->Top = top;
            btn[k]->Width = WBTN;
            btn[k]->Height = HBTN;
            //btn[k]->Flat = true;
            btn[k]->Font->Color = clNavy;

            btn[k]->Caption = btnText[k]; // ����� �� ������
            btn[k]->Tag = btnTag[k];      // ������������� ������

            // ������ ��������� ��������� ������� Click
            btn[k]->OnClick = btnClick; // ��. ���������� � h-����� �����

            k++;
            left = left + WBTN+ DXBTN;
         }
         top = top + HBTN + DYBTN;
    }
    // ���������� ��� ������ "0" (btn[12] � btn[13]) � ����
    btn[13]->Visible = false;
    btn[12]->Width = 2* WBTN + DXBTN;

    op = EQ;
}

// ������ ������ btn[i]
// ( ���� ��������� ��� ���� ������ )
void __fastcall TForm1::btnClick(TObject *Sender)
{
    TSpeedButton *btn;
    int id; // ������������� ������� ������

    btn = (TSpeedButton*)Sender;

    // �������� Tag ������ �������� �� �������������
    id = btn->Tag;

    // ShowMessage ( IntToStr(btn->Tag) );

    // ������ "1" .. "9"
    if ( id > 0 ) {
        if ( fd == 0 ) {
            StaticText1->Caption = btn->Tag;
            fd = 1;
        }
        else
            StaticText1->Caption = StaticText1->Caption + btn->Tag;
        return;
    }

   // ������ "0"
   if ( id == 0) {
        if ( StaticText1->Caption != "0" )
            StaticText1->Caption = StaticText1->Caption + btn->Tag;
        return;
   }

   // ������ ","
   if ( id == CM) {
        if ( StaticText1->Caption.Pos(",") == 0 ) {
            StaticText1->Caption = StaticText1->Caption + ",";
            fd = 1;
        }
        return;
   }

   // ������ "c"
   if ( id == CL) {
     ac = 0;
     id = EQ;
     fd = 0;
     StaticText1->Caption = 0;
     return;
  }

   // ��������� ������: "+", "-"  � "="
   float op2; // ������� (����� �� ���������e)
   op2 = StrToFloat(StaticText1->Caption);

   /* ��� ��� ������ ������� ��������, �� ��� ������,
      ��� ���� ��������� ���������� ��������, ��� �������
      ��������� � ���������� op */
   switch (op) {
        case EQ : ac = op2;  break;
        case PL : ac = ac + op2; break;
        case MN : ac = ac - op2; break;
    }
    StaticText1->Caption = FloatToStrF(ac,ffGeneral,15,6);

   op = id;  // ��������� ������� ��������
   fd = 0;    // ���� ����� �����
}

// ���������� �����
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    // ���������� ����������, ��������� ����������
    for ( int i = 0; i < 16; i++)
        delete btn[i];
}


