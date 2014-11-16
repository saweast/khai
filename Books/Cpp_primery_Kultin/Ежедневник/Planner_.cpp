/*
    ��������� ������ � ����� ������ "����������".
    ����������� ������. ������������� �������������
    ����������� ADOConnection, ADODataSet, DataSource, Table � DBNavigator.


    ���� ������ ���������� (Planer.mdb) ������������ �����
    ���� ������ � ������� Microsoft Access (Microsoft JET),
    ������� ������� �� ����� ������������ ������� schedule.
    ������� schedule, � ���� �������, ������� �� ���� ��������
    aDate (��� DATETIME) � aTask (���������, 50 ��������).

    ��� ���� ����� ��������� ����� �������� � �����
    ������, ���� ������ ������ ���� ���������������� � �������
    ��� �������� ������ ODBC ��� ������ dplanner.

    �����������:
    1. ����/���������/������ ����������/�����������������/��������� ������
    2. Add
    3. �������: Microsoft Access Driver (*.mdb)
    4.1 ��� ��������� ������: dPlaner
    4.2 ��������: ����������
    4.3 ���� ������: Planner.mdb

*/

#include <vcl.h>
#pragma hdrstop

#include "Planner_.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

#include <DateUtils.hpp>
#include <ComObj.hpp>  // ��� ������� � EOleException

AnsiString stDay[7] = {"�����������","�����������","�������", "�����",
                           "�������","�������","�������"};

AnsiString stMonth[12] = {"������","�������","�����",
                          "������","���","����","����",
                          "�������","��������","�������",
                          "������","�������"};


void __fastcall TForm1::FormShow(TObject *Sender)
{
        TDateTime Today,    // �������
              NextDay;  // ��������� ���� (�� ����������� ������)

    Word  Year, Month, Day; // ���, �����, ����

    Today = Now ();

    DecodeDate(Today, Year, Month, Day);

    Label1->Caption = "������� " + IntToStr(Day) + " " +
                       stMonth[Month-1] + " " +
                       IntToStr(Year) + " ����, " +
                       stDay[DayOfWeek(Today) -1];

    Label2->Caption = "������� � ��������� ���";

    // �������� ��������� ����
    // ���� ������� �������, ��, ����� �� ������
    // ��� ������������� �� �����������, �������, ��� ���������
    // ���� - �����������
    switch ( DayOfWeek(Today) ) {
        case 6  : NextDay = Today + 3; break; // ������� �������
        case 7  : NextDay = Today + 2; break; // ������� �������
        default : NextDay = Today + 1; break;
    }

      ADODataSet1->CommandText =
          "SELECT * FROM schedule WHERE aDate BETWEEN DateValue('" +
          FormatDateTime("dd/mm/yyyy",Today) + "') AND DateValue('" +
          FormatDateTime("dd/mm/yyyy",NextDay) + "') ORDER BY aDate";

     // ���� ����, ���������� SQL-�������
     if ( CheckBox1->Checked) ShowSQL();

     // ���� �� �� ���������������� ��� �������� ������ ODBC,
     // ��������� ���������� EOleException

     try
     {
     ADODataSet1->Open(); // ������� ����� ������ (���������
                           // SQL-������� ADODataSet1->CommandText
     }

     catch ( EOleException &e)
     // ����� ��� EOleException ��� ��������, � ���������
     // ���� ��������� ��������� #include <ComObj.hpp>
     {

        ShowMessage ("������ ��������� � ��. ���� ������ Planner.mdb ������"
                      "���� ����������������\n� ������� ��� �������� ������ ODBC "
                      "��� ������ dplaner");

        Button1->Enabled = false;
        Button2->Enabled = false;
        Button3->Enabled = false;
        Button4->Enabled = false;
        return;
     }

     if ( ! ADODataSet1->RecordCount )
        ShowMessage("�� ������� � ��������� ��� �� ����� ��� �� �������������.");
}

// ������ �� ������ �������
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    AnsiString today = FormatDateTime("dd/mm/yyyy",Now());

    Form1->Label2->Caption = "�������";

    ADODataSet1->Close(); // ������� ����� ������

    // �������� �������� �������
    ADODataSet1->CommandText =
         "SELECT * FROM schedule WHERE aDate = DateValue('" + today +"')";

    if ( CheckBox1->Checked) ShowSQL(); // ���������� ������

    ADODataSet1->Open(); // ������� ����� ������ � ����� ��������
}

// ������ �� ������ ������
void __fastcall TForm1::Button2Click(TObject *Sender)
{

    AnsiString tomorrow = FormatDateTime("dd/mm/yyyy", Now() +1 );

    Label2->Caption = "������";

    ADODataSet1->Close();

    // �������� �������� �������
    ADODataSet1->CommandText =
       "SELECT * FROM schedule WHERE aDate = DateValue('" +
                         tomorrow + "')";

    if ( CheckBox1->Checked) ShowSQL();

    ADODataSet1->Open();  // ��������� ������

    if ( ! ADODataSet1->RecordCount )
    {
        ShowMessage("�� ������ �� ����� ��� �� �������������!");
    }
}

// ������ �� ������ �� ���� ������
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  // "��� ������" - �� �������� ��� �� ����� ������ (�� �����������)
  TDateTime Present, eWeek;

  Label2->Caption = "�� ���� ������";

  Present= Now(); // Now - ���������� ������� ����


  eWeek = EndOfAWeek(YearOf(Present),WeekOf(Present));

  /*
    ��� ������� � StartOfWeek, EndOfAWeek, YearOf � WeekOf
    ���� ���������� DateUtils.hpp (��. ��������� #include )
  */

  ADODataSet1->Close();

  ADODataSet1->CommandText =
         " SELECT * FROM schedule WHERE aDate BETWEEN DateValue('" +
              FormatDateTime("dd/mm/yyyy",Present)+ "') AND DateValue('" +
              FormatDateTime("dd/mm/yyyy",eWeek)+"') ORDER BY aDate";

  if ( CheckBox1->Checked) ShowSQL();

  ADODataSet1->Open();

  if ( ! ADODataSet1->RecordCount )
        ShowMessage("�� ��� ������ �� ����� ��� �� �������������.");
}

//  ������ �� ������ ���
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    ADODataSet1->Close();

    ADODataSet1->CommandText = "SELECT * FROM schedule ORDER BY aDate";
    if ( CheckBox1->Checked) ShowSQL();

    ADODataSet1->Open();

    Label2->Caption = "���, ��� �������� �������";
}

// ���������� SQL-�������
void __fastcall TForm1::ShowSQL(void)
{
    ShowMessage ( ADODataSet1->CommandText );
}



//---------------------------------------------------------------------------

