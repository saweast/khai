/*
    ��������� ������ � ����� ������ "�������".
    ������ ���� ������ - Paradox.
    ���� ������ ������� �� �����-������������ ������� stock (stock.db).

    ������ � ���� ������ �������������� ����� BDE.

    ��� ������� � ���� ������ ���������� ��� ������ BDE Administrator ������� ��������� stock (Type: Standard; Default Driver: Paradox).

    ��������� ������� stock.db
    --------------------------
     ����     ���     ������
    --------------------------
     Title    A        50
     Price    $        -
     Memo     A        50
     Photo    A        30
    --------------------------

*/
#include <vcl.h>
#pragma hdrstop

#include "Stock_.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;



__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{

}

// ������ ������ ���������
void __fastcall TForm1::FormShow(TObject *Sender)
{
    try
    {
        Table1->Open(); // ������� ���� ������
    }
    catch ( EDBEngineError &e)
    {
        ShowMessage("��� ������� � ���� ������ ���� ������� ��������� stock");
    }
}

// ���������� ��������� ������ ������
void __fastcall TForm1::DataSource1StateChange(TObject *Sender)
{
    if ( DataSource1->State == dsBrowse)
        StatusBar1->Panels->Items[1]->Text = "���������";
    else
        StatusBar1->Panels->Items[1]->Text = "��������������";
}

// ������� AfterScroll ��������� ����� �������� � ������
// ������ (����� ������� ������)
void __fastcall TForm1::Table1AfterScroll(TDataSet *DataSet)
{
    AnsiString Picture;
    if ( Table1->RecNo != -1)
    {
        StatusBar1->Panels->Items[0]->Text = "������: " + IntToStr(  Table1->RecNo );
        // ������ � �������� ���� ������� ������ ����� ��������
        // ����� �������� FieldValue.
        // ���� ���� Image ������, �� ��� ������� ������ �� ����
        // ������ ��������� ������.
        try {
            Picture =
                  Table1->Database->Directory + DataSet->FieldValues["Image"];
        }
        catch (EVariantTypeCastError &e) {
            Image1->Visible = false;
            return;
        }
        ShowPhoto(Picture);
    }
    else
    {
        StatusBar1->Panels->Items[0]->Text = "";
        StatusBar1->Panels->Items[1]->Text = "����� ������";
        Image1->Visible = false;
    }
}

// ���������� �������� � ���� ���������� Image1
void __fastcall TForm1::ShowPhoto(AnsiString Picture)
{

    try
    {
        Image1->Picture->LoadFromFile(Picture);
    }
    catch ( EFOpenError &e)
    {
        // �� ���� �� ������, ������ �� ���������� ��������
        Image1->Visible = false;
        return;
    }
}

// ���������� ������ ���������
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (Table1->State == dsEdit )
        // ������� � ������ ��������������
        Table1->Post(); // ��������� ��������� ���������
}



