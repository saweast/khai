/*
    ������������� ������ ������ �� ���������� �����.
    � ����� meteo.txt ��������� ���������� � ������� �����������.
    ��������� ������� � ���� ����������
    Memo ���������� �����, � ����� ��������� ��� ��������� - ���������
    �������������� �����������.
*/

#include <vcl.h>

#pragma hdrstop

#include "InfoFrm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

#include "DateUtils.hpp"  // ��� ������ � MonthOf

/* ������� GetString ������ �� ����� ������ ��������
   �� ������� ������� �� ������� �������.
   �������� ������� - ���-�� ����������� �������� */
int GetString(int f, AnsiString *st);

// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    ComboBox1->Style = csDropDownList;
    ComboBox1->Items->Add("������");
    ComboBox1->Items->Add("�������");
    ComboBox1->Items->Add("����");
    ComboBox1->Items->Add("������");
    ComboBox1->Items->Add("���");
    ComboBox1->Items->Add("����");
    ComboBox1->Items->Add("����");
    ComboBox1->Items->Add("������");
    ComboBox1->Items->Add("��������");
    ComboBox1->Items->Add("�������");
    ComboBox1->Items->Add("������");
    ComboBox1->Items->Add("�������");

    ComboBox1->ItemIndex = MonthOf( Now() ) -1 ; // ��-�� ������ ���������� � ����
}

// ������ �� ������ OK
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int h; // ���������� �����

    h = FileOpen("meteo.txt",fmOpenRead);
    if ( h == -1)
    {
        ShowMessage("���� ������ meteo.txt �� ������.");
        return;
    }

    Memo1->Lines->Clear();

    // ��������� �����

    AnsiString st; // ������, ����������� �� �����
    int ls;         // ������ ������

    TDateTime aDate;  // ����
    float temp;       // �����������
    int nMonth;       // �����

    int n = 0;     // ���������� ���� (����������� �����)
    float sum = 0; // ����� ����������
    float sred;    // ������� ��������

    AnsiString buf;

    /* ������ ������ ����� ����� ���:
       ��.��.���� �
       ���: ��.��.���� - ����; � - ����������� */

    do
    {
        ls = GetString(h,&st); // ����
        if ( ls != 0)
        {
            nMonth = MonthOf (StrToDate(st)) - 1; // �����
            buf = st;

            ls = GetString(h,&st); // �����������
            temp = StrToFloat(st);
            if ( nMonth == ComboBox1->ItemIndex )
            {
                n++;
                sum = sum + temp;
                buf = buf + "   " + st;
                Memo1->Lines->Add(buf);
            }
        }
    } while ( ls != 0);

    FileClose(h);

    if ( n != 0 )
    {
        sred = sum / n;
        Label1->Caption = "������� ��������: " +
                     FloatToStrF(sred,ffGeneral,3,2);
    }
    else
        Label1->Caption = "� �� ��� ���������� � ����������� �� " +
                    ComboBox1->Text;
}

// ������������ ������ ������ �����
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
    Label1->Caption = "";
    Memo1->Text = "";
}

// ������� GetString ������ �� ����� ������ ��������
// �� ������� ������� �� ������� �������.
// �������� ������� - ���-�� ����������� ��������
int GetString(int f, AnsiString *st)
{
    unsigned char buf[256]; // ������ (�����)
    unsigned char *p = buf;  // ��������� �� ������

    int n;       // ���-�� ����������� ���� (�������� �-� FileRead)
    int len = 0; // ����� ������

    // ������� ������� �������
    do
        n = FileRead(f, p, 1);
    while ((n != 0) && (*p == ' '));

    while (( n != 0 ) && ( *p != ' '))
    {
        if ( *p == '\r')
        {
            n = FileRead(f, p, 1); // ��������� '\n'
            break;
        }
        len++;
        p++;
        n = FileRead(f, p, 1);
    }

    *p = '\0';
    if ( len !=0 )
        st->printf("%s", buf);
    return len;
}

// ������� GetLine ������ �� ����� ������ ��������
// �� ������� ������� �� ������� "����� ������".
// �������� ������� - ���-�� ����������� ��������
int GetLine(int f, AnsiString *st)
{
    unsigned char buf[256]; // ������ (�����)
    unsigned char *p = buf;  // ��������� �� ������

    int n;       // ���-�� ����������� ���� (�������� �-� FileRead)
    int len = 0; // ����� ������

    n = FileRead(f, p, 1);
    while ( n != 0 )
    {
        if ( *p == '\r')
        {
            n = FileRead(f, p, 1); // ��������� '\n'
            break;
        }
        len++;
        p++;
        n = FileRead(f, p, 1);
    }

    *p = '\0';
    if ( len !=0)
        st->printf("%s", buf);
    return len;
}
