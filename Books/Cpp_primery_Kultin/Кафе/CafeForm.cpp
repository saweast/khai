#include <vcl.h>
#pragma hdrstop

#include "CafeForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

float summ; // ����� ������

// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    // ������� ����������� ������������� "����"
    CheckBox2->Enabled = false;
}

// ������ �� ������������� "���-���"
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
    if ( CheckBox1->Checked )
    {
        /* ������������� ��� �������,
           ������������ ��������� ��� */
        summ += 54;

        // ������� ��������� ������������� "����"
        CheckBox2->Enabled = true;
    }
    else
    {
        /* ������������� ��� ����������,
           ������������ ������� ��� */

       summ -= 54;

       // �������� � ������� ����������� ������������� "����"
       if (CheckBox2->Checked)
            CheckBox2->Checked = false;
       CheckBox2->Enabled = false;
    }

    // ���������� ���������� ����� � ����
    Label1->Caption = FloatToStrF(summ,ffCurrency,6,2);
}

// ������ �� ������������� "����"
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
    if ( CheckBox2->Checked)
        summ += 10.5;
    else
        summ -= 10.5;

    Label1->Caption = FloatToStrF(summ,ffCurrency,6,2);
}

// ������ �� ������������� "��������"
void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
    if ( CheckBox3->Checked)
        summ += 18.5;
    else
        summ -= 18.5;

    Label1->Caption = FloatToStrF(summ,ffCurrency,6,2);
}

// ������ �� ������������� "����-����"
void __fastcall TForm1::CheckBox4Click(TObject *Sender)
{
    if ( CheckBox4->Checked)
        summ += 14;
    else
        summ -= 14;

    Label1->Caption = FloatToStrF(summ,ffCurrency,6,2);
}


// ������ �� ������ OK
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if ( (CheckBox1->Checked)&& (CheckBox2->Checked)&&
          (CheckBox3->Checked)&&(CheckBox4->Checked) )
    {
        /* ������������ ������� ������ �����
           ������������ ������ 5% */
        summ = summ * 0.95;
        ShowMessage("��� ��������������� ������ 5%.\n"
        "����� ������: " + FloatToStrF(summ,ffCurrency,6,2)+ " ���.");
    }
    else
        if ( (CheckBox1->Checked)|| (CheckBox3->Checked)||(CheckBox4->Checked))
             ShowMessage("����� ������: " + FloatToStrF(summ,ffGeneral,6,2)+ " ���.");
        else ShowMessage("�� ������ �� ��������");
}

