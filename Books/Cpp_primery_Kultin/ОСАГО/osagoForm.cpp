/*
    ��������� ��������� ���c������
    ����� �����.
    ������������� ������������� ���������� ComboBox,
    ��������� ����� �������� ������� �� ����������
    �����������.

*/

#include <vcl.h>
#pragma hdrstop

#include "osagoForm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString reg[8] = {"������","���������� ���.","�����-���������",
                    "������ ��������","������������� ���.","������-������", "������",
                     "��������"};

// ����., ����������� ������
float Kt [8] = {1.8,1.6, 1.8,1.3,1,1,1,1};

// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    int i,n;
    n = sizeof (Kt) / sizeof (float);
    for (i=0; i<n; i++)
        ComboBox1->Items->Add(reg[i]);

    /* ������� Change ���� ����������� ������������
       ������� TForm1::Change */
    ComboBox1->OnChange = Change;
    ComboBox2->OnChange = Change;
    ComboBox4->OnChange = Change;
    ComboBox4->OnChange = Change;
    Edit1->OnChange = Change;
    Edit2->OnChange = Change;
    Edit3->OnChange = Change;
}


/* ������� ����������� ������������ ���������� ������
������ ��� - 3� �����, ������ ��� (���� �� ���� ���������
�������) 4� ����� � �.�.). ���� ��������� ������ ���,
�� ����� ������ �������: ������ - ����� �����������
����, ������� - ���-�� ��������� �������. */

// ����� ��������������
int Cb[6][5] = {
{1,-1,-1,-1,-1},
{2,-1,-1,-1,-1},
{3,1,-1,-1,-1},
{4,1,-1,-1,-1},
{5,2,1,-1,-1},
{6,3,1,-1,-1}};

// ����������� ��������������
float Kb[7] = {2.3, 1.55, 1.4, 1, 0.95, 0.9};

// ������ �� ������ OK
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    float aTb;  // ������� ������ ������
    float aKt;  // ����. ������
    float aKb;   // ����. ��������������
    float aKvs; // ����. ������������� �����
    float aKo;  // ����., ����������� ���������� ���, ��������� � ����������
    float aKm;  // ����. �������� ���������
    float aKs;  // ����., ����������� ������ ������������� ��

    int pcb,ccb; // ���������� � ������� ����� �������������
    int nss;     // ���������� ��������� ������� ����������� �������


    aTb = StrToFloat(Edit3->Text);
    aKt = Kt[ComboBox1->ItemIndex];

    pcb = StrToInt(Edit1->Text);
    nss = StrToInt(Edit2->Text);
    ccb =   Cb[pcb][nss];
    if ( ccb != -1)
        aKb = Kb[ccb];
    else aKb = 2.45;

    // �����. ������������� �����
    switch (ComboBox2->ItemIndex)
    {
        case 0: aKvs = 1.3;  break;
        case 1: aKvs = 1.2;  break;
        case 2: aKvs = 1.15; break;
        case 3: aKvs = 1.0;  break;
    }

    // ����., ����������� ���������� ���, ��������� � ����������
    if (CheckBox1->Checked)
        aKo = 1;
    else
        aKo = 1.5;

    // ����. �������� ���������
    switch (ComboBox3->ItemIndex)
    {
        case 0 : aKm = 0.5; break;
        case 1 : aKm = 0.7; break;
        case 2 : aKm = 1.0; break;
        case 3 : aKm = 1.3; break;
        case 4 : aKm = 1.5; break;
        case 5 : aKm = 1.7; break;
        case 6 : aKm = 1.9; break;
    }

    // ����., ����������� ������ ������������� ��
    switch (ComboBox4->ItemIndex)
    {
        case 0 : aKs = 0.7; break;
        case 1 : aKs = 0.8; break;
        case 2 : aKs = 0.9; break;
        case 3 : aKs = 0.95; break;
        case 4 : aKs = 1.0; break;
    }

    // ��� ������������ ����������

    float T; // �����
    AnsiString st;

    T = aTb * aKt * aKb * aKvs * aKo * aKm *aKs;

    st = "������� ������ ������: " + FloatToStrF(aTb,ffCurrency,5,2)+
    "\n����. ������: " + FloatToStrF(aKt,ffGeneral,2,2)+
    "\n����. ��������������: " + FloatToStrF(aKb,ffGeneral,2,2)+
    "\nK���. ������������� �����: " + FloatToStrF(aKvs,ffGeneral,2,2)+
    "\n����. ���-�� ���, ��������� � ����������: " + FloatToStrF(aKo,ffGeneral,2,2)+
    "\n����. �������� ��������: " + FloatToStrF(aKm,ffGeneral,2,2)+
    "\n����. ������� ������������� ��: " + FloatToStrF(aKs,ffGeneral,2,2)+
    "\n\n�����: " + FloatToStrF(T,ffCurrency,5,2);

    ShowMessage(st);
}

// ������������ ������� ��������� ������-���� �� ����������� �����
void __fastcall TForm1::Change(TObject *Sender)
{
    Button1->Enabled =
        (ComboBox1->ItemIndex != -1) &&
        (ComboBox2->ItemIndex != -1) &&
        (ComboBox3->ItemIndex != -1) &&
        (ComboBox4->ItemIndex != -1) &&
        (Edit1->Text.Length() != 0) &&
        (Edit2->Text.Length() != 0) &&
        (Edit3->Text.Length() != 0);
}

