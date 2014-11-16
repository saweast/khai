/*

    ��������� ������ � ����� ������ "�������� ������" (adrbk.db).
    ������������� ������������� BDE-����������� Table � Qery, � �����
    ����������� DBGrid � DataSource.

    ��������� �������� � ����� ������ � ������ ������� � ��������� �������������,
    �������������, ��������� � ������� ������, � ����� ������������ ����� ����������
    �� ����������� ���� "Name".

    ���� ������ "�������� ������" (������ Paradox) ������� �� ������ adrbk.db

    ����       ���
    --------------------
    Name       Alpha
    Phone      Alpha
    Cell       Alpha
    Email      Alpha

    ������� ������� adrbk.db ����� ��� ������ Database Desktop

    ��� ������� � ����� ������� (adrbk.db) ��������� ����������
    ��������� adrbk (Type: STANDARD, DEFAULT DRIVER: PARADOX).
    ������� ��������� ����� ��� ������ BDEAdministrator ��� SQL Explorer.

*/

#include <vcl.h>
#pragma hdrstop

#include "NoteBook_.h"

// ��� ��������� ��������� ���� �������
#include "Find_.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
}

// ������ ������ ���������
void __fastcall TMainForm::FormShow(TObject *Sender)
{
    // ���� ��������� adrbk �� ���������������, ��������� ������
    try
    {
        Table1->Open();
    }
    catch (EDBEngineError &e)
    {
        ShowMessage("������ ������� � ���� ������: �� �������� ��������� adrbk\n" +
                     e.Message );

        Button2->Enabled = false;
        BitBtn1->Enabled = false;
        CheckBox1->Enabled = false;
    }
}

// ������ �� ������ ����� ����������
void __fastcall TMainForm::BitBtn1Click(TObject *Sender)
{
       FindForm->Tag = 0;
       FindForm->ShowModal();  // ���������� ���� ������
       if ( FindForm->Tag )
       {
           // ������������ ������ ���� ������
           // ������� �� ������ OK, �� ���� �� ����
           // ������� ��� ���
           Query1->SQL->Text =
                   "SELECT * FROM adrbk WHERE Name LIKE \042%" +
                                FindForm->Edit1->Text  +"%\042";

                   // \042 - ��� ������������ ��� ������� �������
           if ( CheckBox1->Checked )
                  ShowMessage (Query1->SQL->Text);

           Query1->Open(); // ������� (���������) ������
            if ( Query1->RecordCount != 0)
                DataSource1->DataSet = Query1;
            else
            {
                ShowMessage ("� ���� ������ ��� ������������� ����������: " +
                              FindForm->Edit1->Text);
                DataSource1->DataSet = Table1;
            }
       }
}

// ������ �� ������ ��� ������
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
    DataSource1->DataSet = Table1; // �������� ������ - �������
}

// ���������� ������ ���������
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    Table1->Close();
}




