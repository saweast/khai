/*
    ��������� ��������� � ���� ������,
    ������������� ��� ��������� ����,
    ���������� � ����������� �������.
    ���� ������ ����������� � ���� ����������
    �����. ���� ����� ���, �� ��������� ������� ���.
*/

#include <vcl.h>
#pragma hdrstop

#include "MeteoFrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

int f; // ���������� �����

// �����������
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    MonthCalendar1->ShowTodayCircle = false;
    MonthCalendar1->Date = Now();
    Button1->Enabled = false;
}

// ���������� ���������� ���� ��������������
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
    // ������ "��������" ��������, ���� � ���� ��������������
    // ��������� �����. ���� � ���� �������� ��� ��� ������
    // ������ - "�����", ������ ����������.
    if ( (Edit1->Text.Length() == 0 ) ||
          ( (Edit1->Text.Length() == 1) && (Edit1->Text[1] == '-') ) )
        Button1->Enabled = false;
    else
        Button1->Enabled = true;
}

// ������ �� ������ "��������"
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    AnsiString st;

    /* ���� ����� ������� � ������ fmCreate, �����, ����
       ���� ����������, �� ����� ������ ��� ������,
       ���� ����� ���, �� �� ����� ������ */

    st = MonthCalendar1->Date.DateString() + " " + Edit1->Text + "\r\n";

    /* ������� ��� ������ ��� ������� ���� meteo.txt */


    if ( FileExists("meteo.txt") )
        f = FileOpen("meteo.txt",fmOpenWrite);
    else
       f = FileCreate("meteo.txt");


    if ( f != -1 )
    {
        // ���� ������ ��� ������
        FileSeek(f,0,2); // ���������� ��������� �� ����� �����
        FileWrite(f,st.c_str(),st.Length());
        FileClose(f);
        Button1->Enabled = false;
    }

    else
    {
        /* ������ ������� � �����: �� �������,
           �� ������� �� ���������� */
        ShowMessage("O����� ������� � �����: �� �������,"
                     "�� ������� �� ����������");
    }
}

// � ���� �������������� ����� ������ ������
// ������������� ��� ������������� �����
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
    if (( Key >= '0') && (Key <= '9'))
        return;

    // ���������� ����� (�������)
    if ( ( Key == '.') || (Key == ','))
    {
        Key = ',';
        if ( Edit1->Text.Pos(',') != 0 )
            Key = 0;
        return;
    }

   if ( Key == 8)
        return;

   if ((Key == '-') && (Edit1->Text.Length() == 0))
        // "�����" ����� ���� ������ ������ ��������
        return;

   // ��� ��������� ������� ���������
   Key = 0;

}

// ������ � ���� ���������� MonthCalendar
void __fastcall TForm1::MonthCalendar1Click(TObject *Sender)
{
    Edit1->Text = "";    // �������� ���� ����� �����������
    Edit1->SetFocus();   // ���������� ������ � ���� ����� �����������
}

