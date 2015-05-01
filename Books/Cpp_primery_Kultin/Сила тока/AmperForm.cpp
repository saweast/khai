/*
    ��������� ��������� ���� ���� � ������������� ����.
    ������������� ���������:
        - ������� KeyPress;
        - ���������� EZerroDevide (������� �� ����)
          ��� ������ ���������� try � catch.
*/
#include <vcl.h>
#pragma hdrstop

#include "AmperForm.h"

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
    float u; // ����������
    float r; // �������������
    float i; // ���

    // ��������, ������� �� ������ � ���� ���������� � �������������
    if ( ((Edit1->Text).Length() == 0) || ((Edit2->Text).Length() == 0))
    {
        MessageDlg("���� ������ ���������� � �������������",
                    mtInformation, TMsgDlgButtons() << mbOK, 0);
        if ((Edit1->Text).Length() == 0)
            Edit1->SetFocus(); // ������ � ���� ����������
        else
            Edit2->SetFocus(); // ������ � ���� �������������
        return;
    };

    // �������� ������ �� ����� �����
    u = StrToFloat(Edit1->Text);
    r = StrToFloat(Edit2->Text);

    // ��������� ���
    try
    {
    i = u/r;
    }
    catch (EZeroDivide &e)
    {
        ShowMessage("�������� ������������� �� ������ ���� ����� ����");
        Edit2->SetFocus();   // ������ � ���� �������������
        return;
    }

    // ������� ��������� � ���� Label4
   Label4->Caption = "��� : " +
                     FloatToStrF(i,ffGeneral,7,2) + " A";
}

// ������� ������� � ���� ����������
// ���� ����������� ������ ������� �����, � ����������
// ������� ���� ������ � ���� �������������� �� ��������
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
    // Key - ��� ������� �������
    // ��������, �������� �� ������ ����������

    if ( ( Key >= '0') && ( Key <= '9' ) ) // �����
        return;

    // ���������� ���������� Decimalseparator
    // �������� ������, ������������ � �������� �����������
    // ��� ������ ������� �����
    if ( Key == DecimalSeparator)
    {
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
    };

    // ��������� ������� ���������
    Key = 0; // �� ���������� ������
}

// ������� ������� � ���� �������������
void __fastcall TForm1::Edit2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if ( ( Key >= '0') && ( Key <= '9' ) ) // �����
        return;

    if ( Key == DecimalSeparator) {
       if ( (Edit2->Text).Pos(DecimalSeparator) != 0 )
           Key = 0; // ����������� ��� ������
       return;
    }

    if (Key == VK_BACK) // ������� <Backspace>
        return;

    if ( Key == VK_RETURN) // ������� <Enter>
    {
       Button1->SetFocus(); // ������� � ������ ���������
                            // ��������� ������� ������� <Enter>
                            // ������������ ������� ���������� ����
                            // ��. Button1Click
       return;
    };

    // ��������� ������� ���������
    Key = 0; // �� ���������� ������
}

// ������ �� ������ ���������
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Form1->Close(); // ������� ����� ����������
}


/* ��������� Edit1Change ������������ ������� Change
   ��� ���� Edit1, ��� � ���� Edit2.
   ������� ���� ������� ��������� ��������� ������� Change
   ��� ���� Edit1, ����� - � ������ ������� Change ���������� Edit2
   �������� �� ������ ��������������� ������ � ������� Edit1Change. */
void __fastcall TForm1::EditChange(TObject *Sender)
{
    Label4->Caption = "";
}

