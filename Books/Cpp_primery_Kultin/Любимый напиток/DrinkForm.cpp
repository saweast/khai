/*
    ��������� ������������� �������������
    ���������� ComboBox. ������ �����������
    ComboBox2 � ComboBox3 ����������� � ������
    ������ ���������. ������������ ����� ��������
    ������� � ������ ���������� ComboBox3 ������
    � ��� ������, ���� ������ �������� � ������ ���.

*/
#include <vcl.h>
#pragma hdrstop

#include "DrinkForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    // ������������ ������ ���������� ComboBox3
    ComboBox2->Sorted = true; // ������ ����������
    ComboBox2->Items->Add("����-����");
    ComboBox2->Items->Add("�������");
    ComboBox2->Items->Add("�����-����");
    ComboBox2->Items->Add("������");
    ComboBox2->Items->Add("�����");

    // ������������ ������ ���������� ComboBox3
    ComboBox2->Sorted = true; // ������ ����������
    ComboBox3->Items->Add("���");
    ComboBox3->Items->Add("��� � �������");
    ComboBox3->Items->Add("���� ������");
    ComboBox3->Items->Add("���� �� ��������");
    ComboBox3->Items->Add("�����");
}

// ����� �������� � ������ ComboBox1
void __fastcall TForm1::ComboBox1Click(TObject *Sender)
{
    Label1->Caption = ComboBox1->Text;
}

// ������ �� �������� ������ ���������� ComboBox2
void __fastcall TForm1::ComboBox2Click(TObject *Sender)
{
    Label2->Caption = ComboBox2->Items->Strings[ComboBox2->ItemIndex];
}

// ������ �� �������� ������ ���������� ComboBox3
void __fastcall TForm1::ComboBox3Click(TObject *Sender)
{
    Label3->Caption = ComboBox3->Items->Strings[ComboBox3->ItemIndex];
}

// ������� ������� � ���� �������������� ���������� ComboBox2
void __fastcall TForm1::ComboBox2KeyPress(TObject *Sender, char &Key)
{
    if  (Key == VK_RETURN)
    {
         // ������������ ���� � ���� �������������� ������
         // � ����� <Enter>. ������� ������ � ������.

         int n = ComboBox2->Items->Add(ComboBox2->Text);
         ComboBox2->ItemIndex = n;

         Label2->Caption = ComboBox2->Items->Strings[n];
    }
}

// ������� ������� � ���� �������������� ���������� ComboBox3
void __fastcall TForm1::ComboBox3KeyPress(TObject *Sender, char &Key)
{
     AnsiString st;  ///������, ������� ���� ������������
                     // � ���� �������������� ���������� ComboBox

    if  (Key == VK_RETURN)
    {
         // ������������ ���� � ���� �������������� ������
         // � ����� <Enter>. ���� ����� ������ � ������ ���,
         // ������� �� � ������

         st = ComboBox3->Text.Trim(); // ������� �������

         if ( ComboBox3->Items->IndexOf(st) == -1 )
         {
            // ��������
            int n = ComboBox3->Items->Add(st);
            ComboBox3->ItemIndex = n;

            Label3->Caption = ComboBox3->Items->Strings[n];
         }
    }
}

