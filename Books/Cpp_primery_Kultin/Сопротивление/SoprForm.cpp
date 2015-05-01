/*
    ��������� ��������� ������������� ������������� ����,
    ������� ������� �� ���� �������������.
    ������������� ����� ���� ��������� ���������������
    ��� �����������.

*/
#include <vcl.h>
#pragma hdrstop

#include "SoprForm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

// ������ �� ������ ���������
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    float r1,r2,r;

    r1 = StrToFloat(Edit1->Text);
    r2 = StrToFloat(Edit2->Text);

    /* ������������� RadioButton1 � RadioButton2
       ���������, ������� � ���� ���������� �����
       ������ �� ��������� ������ �� ��� */
    if ( RadioButton1->Checked )
    {
        // ������ ������������� "���������������"
        r = r1 + r2;
    }
    else
    {
        // ������ ������������� "�����������"

        // ��� ���������� ������������� ��������
        // ���������� EInvalidOp
        try
        {
            r = (r1 * r2) / (r1 + r2);
        }
        catch ( EInvalidOp &e)
        {
            ShowMessage("���������� ������ �������� �������������");
            return;
        }
    }
    Label4->Caption = FloatToStrF(r,ffGeneral,6,2) + " ��";
}

// ������ �� ������������� "���������������"
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
    Label4->Caption = "";
}

// ������ �� ������������� "�����������"
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
    Label4->Caption = "";
}

// ������� ������� � ���� R1
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
    if ( ( Key >= '0') && ( Key <= '9' ) ) // �����
        return;

    if ((Key == ',') || (Key == '.'))
    {
        /* ����� �� ���������� ������������, �������
           ������������ ����������� ����������.
           ���������� ���������� Decimalseparator
           �������� ������, ������������ � ��������
           ����������� ��� ������ ������� �����.
       */

       Key = DecimalSeparator;
       if ( (Edit1->Text).Pos(DecimalSeparator) != 0 )
           Key = 0; // ����������� ��� ������
       return;
    }

    if (Key == VK_BACK) // ������� <Backspace>
        return;

    if ( Key == VK_RETURN) // ������� <Enter>
    {
       Edit2->SetFocus();
       return;
    }

    // ��������� ������� ���������
    Key = 0;
}

// ������� ������� � ���� R2
void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
        if ( ( Key >= '0') && ( Key <= '9' ) ) // �����
            return;

    if ((Key ==',') || (Key == '.'))
    {
       Key = DecimalSeparator;
       if ( (Edit1->Text).Pos(DecimalSeparator) != 0 )
           Key = 0; // ����������� ��� ������
       return;
    }

    if (Key == VK_BACK) // ������� <Backspace>
        return;

    if ( Key == VK_RETURN) // ������� <Enter>
    {
       Button1->SetFocus();
       return;
    }

    // ��������� ������� ���������
    Key = 0;
}




