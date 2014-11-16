/*
    ��������� ��������� ������������� jpg-�����������.
    �������� �������� "�� ������" ��� � ������ �����-���.

    ��������� �������������:
       - ������������� ���������� Image ��� ���������
         jpg � bmp �����������;
       - ������������� ������� FindFirst � FindNext;
       - ������ � ������������ ���� ����� �����.
*/

#include <vcl.h>
#pragma hdrstop

#include "ShowPicMainForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

#include <FileCtrl.hpp>  // ��� ������� � SelectDirectory
#include <jpeg.hpp>      // ������������ ������ � ������������� � ������� JPEG

AnsiString aPath;      // �������, � ������� ��������� �����������
TSearchRec aSearchRec; // ���-� ������ �����

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    aPath = ""; // ������� ������� - �������, �� �������� �������� ���������
    FirstPicture(); // �������� ��������, ������� ���� � �������� ���������
}

// ������ �� ������ �������
void __fastcall TForm1::Button1Click(TObject *Sender)
{
     if (SelectDirectory("��������� �������, � ������� ��������� �����������",
                     "",aPath) != 0 )
     {
        // ������������ ������ ������� � ������� �� OK
        aPath = aPath + "\\";
        if ( FirstPicture() )  // ������� �����������
            CheckBox1->Enabled = true;
        else
            Label1->Caption = "� �������� " + aPath +
                      " ��� jpg-�����������." ;
     }
}

// ������� ������ �������� � ����� ���������
bool __fastcall TForm1::FirstPicture()
{
    Image1->Visible = false;   // ������ ��������� Image1
    Button2->Enabled = false;  // ������ ������ ����������
    CheckBox1->Enabled = false;
    CheckBox1->Checked = false;
    Label1->Caption = "";
    if ( FindFirst(aPath+ "*.jpg", faAnyFile, aSearchRec) == 0)
    {
        Image1->Picture->LoadFromFile(aPath+aSearchRec.Name);
        Image1->Visible = true;
        Label1->Caption = aPath + aSearchRec.Name;
        if ( FindNext(aSearchRec) == 0 )  // ����� ����. �����������
        {
            // ����������� ����
            Button2->Enabled = true; // ������ ������ ������ ��������
            CheckBox1->Enabled = true;

            return true;
        }
    }
    return false;
}

// ������� ������� � ����� ��������� ��������
bool __fastcall TForm1::NextPicture()
{
    Image1->Picture->LoadFromFile(aPath+aSearchRec.Name);
    Label1->Caption = aPath + aSearchRec.Name;
    if ( FindNext(aSearchRec) != 0 )  // ����� ����. �����������
    {
        // ����������� ������ ���
        Button2->Enabled = false;   // ������ ������ ������ ����������
        CheckBox1->Enabled = false;
        return false;
    }
    return true;
}

// ������ �� ������ ������
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    NextPicture();
}

// ������ �� ������������� "����������"
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
    if ( CheckBox1->Checked)
        Timer1->Enabled = true;  // �����-���
    else
        Timer1->Enabled = false; // �� ������
}

// ������ �� ������� - ������� ��������� �����������
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if ( ! NextPicture())
        Timer1->Enabled = false;
}

