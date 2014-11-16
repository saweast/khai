/*
    �������� �����������.
    ��������� ������������� ������������� �����������
    ListBox, OpenDialog � ����� ������� FindFirst � FindeNext
    ��� ������������ ������ ������.
*/

#include <vcl.h>
#pragma hdrstop

#include "BrPicFrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

#include <jpeg.hpp>      // ������������ ������ � ������������� � ������� JPEG

AnsiString aPath;      // �������, � ������� ��������� �����������
TSearchRec aSearchRec; // ���-� ������ �����

// �����������
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Image1->Proportional = true;
    if ( FindFirst(aPath+ "*.jpg", faAnyFile, aSearchRec) == 0)
    {
       ListBox1->Items->Add(aSearchRec.Name);
       while ( FindNext(aSearchRec) == 0 )  // ����� ����. �����������
       {
           ListBox1->Items->Add(aSearchRec.Name);
       }

       // ���������� ������ �����������
       ListBox1->ItemIndex = 0;
       Label1->Caption = ListBox1->Items->Strings[0];
       Image1->Picture->LoadFromFile(aPath + ListBox1->Items->Strings[0]);
    }
}

// ������ � ������ ���������� ListBox
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
    int n = ListBox1->ItemIndex; // ����� ���������� ��-�� ������
    Label1->Caption = ListBox1->Items->Strings[n];
    Image1->Picture->LoadFromFile(aPath + ListBox1->Items->Strings[n]);
}

// ������ �� ������ �����
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
    if ( OpenDialog1->Execute() )
    {
        // ������������ ������ ����
        ListBox1->Clear(); // �������� ������

        aPath = ExtractFilePath(OpenDialog1->FileName);
        Form1->Caption = "�������� ����������� - " + aPath;
        if ( FindFirst(aPath+ "*.jpg", faAnyFile, aSearchRec) == 0)
        {
            ListBox1->Items->Add(aSearchRec.Name);
            while ( FindNext(aSearchRec) == 0 )  // ����� ����. �����������
            {
                ListBox1->Items->Add(aSearchRec.Name);
            }

         // ��������� ������� ���������� ������������� �����
         // � ������ ListBox � ��������� ���
         int n = ListBox1->Items->
            IndexOf(ExtractFileName(OpenDialog1->FileName));
         ListBox1->ItemIndex = n;
         Label1->Caption = ListBox1->Items->Strings[n];
         Image1->Picture->LoadFromFile(aPath + ListBox1->Items->Strings[n]);
        }

    }
}

