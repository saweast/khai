/*
   ������� �����.
   ��������� ������� ��������, ��������� � �������� ����������
   �������� C++Builder, ����� (obj, tds) � ���������
   ����� (~bpr, ~dfm, ~h, ~cpp) �� ���������� �������������
   �������� � ��� ������������.
   ��� ������ �������� ������������ �����������
   ���� ����� �����.

*/

#include <vcl.h>
#pragma hdrstop

#include "ClearMain.h"



#pragma package(smart_init)
#pragma resource "*.dfm"

TMainForm *MainForm;

__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
}

#include <FileCtrl.hpp> // ��� ������� � SelectDirectory

AnsiString aDirectory; // �������, ������� ������ ������������
                      //  (� ������� ��������� ������� C++Builder)

AnsiString cDir;      // ������� �������
AnsiString FileExt;   // ���������� �����

int n = 0;            // ���������� ��������� ������

// ������ �� ������ ����� (����� ��������)
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
    if ( SelectDirectory("�������� �������","", aDirectory))
    {
        // ������ ����� ����� �������� ������� �� OK
        Label3->Caption = aDirectory;
        Button2->Enabled = true; // ������ ������ ��������� ��������
    };
}

// ������� �������� ����� �� �������� �������� � ��� ������������
void __fastcall Clear(void)
{

   TSearchRec SearchRec; // ���������� � ����� ��� ��������

   cDir = GetCurrentDir()+"\\";

   if ( FindFirst("*.*", faArchive,SearchRec) == 0)
       do {
            // �������� ���������� �����
            int p = SearchRec.Name.Pos(".");
            FileExt = SearchRec.Name.SubString(p+1,MAX_PATH);
            if ( ( FileExt[1] == '~') || ( FileExt == "obj" ) ||
                 ( FileExt == "tds" ) )
            {
                  MainForm->Memo1->Lines->Add(cDir+SearchRec.Name);
                  DeleteFile(SearchRec.Name);
                  n++;
            }
        }
        while ( FindNext(SearchRec) == 0);

       // ��������� ������������ �������� ��������
       if ( FindFirst("*", faDirectory, SearchRec) == 0)
          do
              if ((SearchRec.Attr & faDirectory) == SearchRec.Attr )
              {
                    // �������� ".." � "." ���� ��������,
                    // �� � ��� ������� �� ���� !!!
                    if (( SearchRec.Name != "." ) && (SearchRec.Name != ".."))
                    {
                         ChDir(SearchRec.Name); // ����� � ����������
                         Clear();               // �������� �������
                         ChDir("..");           // ����� �� ��������

                    };
               }
          while ( FindNext(SearchRec) == 0 );
}

// ������ �� ������ ���������
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
    Memo1->Clear();       // �������� ���� Memo1
    ChDir(aDirectory);    // ����� � �������, ������� ������ ������������

    Clear();              // �������� ������� ������� � ��� �����������

    Memo1->Lines->Add("");
    if (n)
        Memo1->Lines->Add("������� ������: " + IntToStr(n));
     else
        Memo1->Lines->Add("� ��������� �������� ��� ������, ������� ���� �������.");
}

