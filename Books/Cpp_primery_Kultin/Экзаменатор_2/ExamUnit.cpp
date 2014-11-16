/*
  ������������� ��������� ������������ "�����������".
  ������������� ������������� ���������� XMLDocument (���� ����� - XML ��������).
  ��� ����� ����� ���������� � ��������� ����� �������� ��������� ������.

  ���� ������������ ����� ���� test
  "����" ����� ����: head, description, qw � levels

*/

#include <vcl.h>
#pragma hdrstop

#include "ExamUnit.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

int nQuery = 0; // ����� �������
int nRight;     // ���������� �������

int Right;      // ���������� �����
int Sel;        // �����, ��������� ����������

static int mode = 0; // 0 - ������ ������ ��������� (������� ������ ������)
                     // 1 - ������� ������������
                     // 2 - ������������ ���������

// ������ ������
void __fastcall TForm1::FormActivate(TObject *Sender)
{

    if (ParamCount() == 0) {
        Label1->Caption = "� ��������� ������ ���� ������� ��� ����� �����";
        mode = 2;
        return;
    }

    XMLDocument1->FileName = ParamStr(1);
    try
    {
        // ������� XML ��������
        XMLDocument1->Active = True;
    }
    catch  (EDOMParseError &e)
   {
        Label1->AutoSize = True;
        Label1->Caption = "������ ������� � ����� ����� " +
                          ParamStr(1) +
                          "\nMessage: " + e.Message;
        mode = 2;
        return;
    }

    Form1->Info(); // ������� ���������� � �����
}


// ��������� � ������� ������ � ��������� �������
int __fastcall TForm1::Qery(int i)
{

    // �������� ����� � �������� ���������
    RadioButton1->Visible = False;
    RadioButton2->Visible = False;
    RadioButton3->Visible = False;
    RadioButton4->Checked = True;
    Button3->Enabled = False;


    // ��������� ��������� �� ������ � ����� qw
     _di_IXMLNode qw = XMLDocument1->DocumentElement->ChildNodes->Nodes[WideString("qw")];
     if ( i > qw->ChildNodes->Count -1 )
     {
        return -1;
     };

     nQuery++; // ���������� ��������

     // ���� q - ��� ������. �������� text ���� q - ��� ����� �������
     // ���� ���� q - ��� �������������� ������
     _di_IXMLNode q = qw->ChildNodes->Nodes[i];
     /* ������� Text ���� qw - ��� ����� �������,
        ������� right - ����� ����������� ������ */

     // ������
     Label1->AutoSize = false;
     Label1->Width = ClientWidth -20;
     Label1->Height = 150;
     Label1->Caption = q->GetAttribute(WideString("text"));
     Label1->AutoSize = true;

     Right = StrToInt( q->GetAttribute(WideString("right")));

     // ���� "q" ������� �� ���������� ����� "a" (�������������� �������)
     _di_IXMLNode a;
     int j = 0; // ����� ���� "a"
     while ( j < q->ChildNodes->Count )
     {
        a = q->ChildNodes->Nodes[j];
        switch ( j ) {
            case 0 : RadioButton1->Caption = a->Text;
                     RadioButton1->Top = Label1->Top + Label1->Height + 10;
                     RadioButton1->Visible = True; break;
            case 1 : RadioButton2->Caption = a->Text;
                     RadioButton2->Top = RadioButton1->Top + RadioButton1->Height + 10;
                     RadioButton2->Visible = True; break;
            case 2 : RadioButton3->Caption = a->Text;
                     RadioButton3->Top = RadioButton2->Top + RadioButton2->Height + 10;
                     RadioButton3->Visible = True; break;
        }
        j++;
     }
     return 0;
}

// ���������� � �����
void __fastcall TForm1::Info()
{
   Form1->Caption = XMLDocument1->DocumentElement->ChildNodes->Nodes[WideString("head")]->Text;
   Label1->Caption = XMLDocument1->DocumentElement->ChildNodes->Nodes[WideString("description")]->Text;
}


// ������ �� ������ OK
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    static int i = 0;    // ����� �������
    int r;               // ��������� ������ �������: -1 - �������� ������ ���

    switch ( mode) {
        case 0:
                r = Qery(i++);
                mode = 1;
                break;

        case 1:
                // ��������, ���������� �� ����� ������ ����������
                if ( Sel == Right) nRight++;
                // ������� ��������� ������
                r = Qery(i++);
                if ( r == -1 ) { // ������ �������� ���

                    // ��������� ������������
                    Result();

                    Button3->Enabled = True;
                    mode = 2;
                }
                break;

        case 2: Form1->Close(); // ��������� ������ ���������
      }
}

// ������� ��������� ������������
void  __fastcall TForm1::Result()
{
    int i = 0;
    int score;
    _di_IXMLNode ls; // ��������� ������� � ���� levels
    _di_IXMLNode l;  // ��������� ������� � ���� level

    // ��������� ��������������� ���� level � ���������� ��������
    // ��������� score � ����������� ���������� �������
    ls = XMLDocument1->DocumentElement->ChildNodes->Nodes[WideString("levels")];
    while ( i < ls->ChildNodes->Count)
    {
        l = ls->ChildNodes->Nodes[i];
        score = StrToInt( l->GetAttribute(WideString("score")));
        if ( nRight >= score ) break;
        i++;
    }

    AnsiString mes;
    mes.printf("������� ��������\n"
               "����� ��������: %i\n"
               "���������� �������: %i\n",
               nQuery,nRight);
    mes = mes + l->GetAttribute(WideString("text"));
    Label1->Width = Form1->ClientWidth - 20;
    Label1->Caption = mes;
}


// ������������ ������ ������ �����
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
    Sel = 1;
    Button3->Enabled = True;
}

// ������������ ������ ������ �����
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
    Sel = 2;
    Button3->Enabled = True;
}

// ������������ ������ ������ �����
void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
    Sel = 3;
    Button3->Enabled = True;

}


