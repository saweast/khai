//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FuntToKg_u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    /* ��� ��� ���� Edit1 ������ (������������
    ��� �� ���� �������� ������), ��
    ������� ������ �������� ����������� */
    Button1->Enabled  =  False;
}

// ������� ������� � ���� Edit1
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
	// ��� ������������ ������� ������� �����, � ����������
    // ������ � ���� �������������� �� ��������

    // Key - ��� ������� �������
    // ��������, �������� �� ������ ����������
    if ((Key >= '0') && (Key <= '9')) //�����
        return;

    // ���������� ���������� DecimalSeparator
    // �������� ������, ������������ � �������� �����������
    // ��� ������ ������� �����
    if (Key == DecimalSeparator)
    {
        if ((Edit1->Text).Pos(DecimalSeparator) != 0)
            Key = 0; // ����������� ��� ������
        return;
    }

    if (Key == VK_BACK) // ������� <Backspace>
        return;

    if (Key == VK_RETURN) // ������� <Enter>
    {
        Button1->SetFocus();
        return;
    }

    // ��������� ������� ���������
    Key = 0; // �� ���������� ������
}

// ���������� ���� Edit1 ����������
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
    // ��������, ���� �� � ���� Edit1 �������� ������
    if ( (Edit1->Text).Length() == 0)
        Button1->Enabled  =  False; // ������ �������� ����������
    else Button1->Enabled  =  True; // ������ �������� ��������

   Label2->Caption = "";
}

// ������ �� ������ ��������
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   double funt; // ��� � ������
   double kg;   // ��� � �����������

   // ������ �������� �������� ������ � ��� ������,
   // ���� � ���� Edit1 ���� ������. �������,
   // ������� � ���� ���������� ����� �� ���������.
   funt  =  StrToFloat(Edit1->Text);
   kg  =  funt * 0.4995;
   Label2->Caption  =  FloatToStrF(funt,ffGeneral,5,2) +
                     " �. - ��� " +
                     FloatToStrF(kg,ffGeneral,5,2) + " ��";
}

