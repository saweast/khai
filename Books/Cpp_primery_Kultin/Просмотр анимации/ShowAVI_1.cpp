/*
   ��������� ��������� �����������, � ��� ����� � �� ������,
   ������� (�� �������������� ������) �������� (���������� avi-�����).
   ������������� ������������� �����������:
     - Animate;
     - FileOpen;
     - CheckBox.

*/

#include <vcl.h>
#pragma hdrstop

#include "ShowAVI_1.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

// ��������� ������� OnCreate
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    TSearchRec sr;  // �������� ����������
                    // � �����, ��������� �������� FindFirst

    //  ������ AVI-���� � ������� ��������
    if (FindFirst("*.avi",faAnyFile,sr) == 0 )
    {
        Edit1->Text = sr.Name;

        /* ���� �������� �������� ����, �� ���
           ���������� ���������� ��������� ����������
           ������, �.�. ��������� Animate ������������
           ��������������� ������ �������, ��
           ���������� ����� ��������
        */

        try
        {
            Animate1->FileName = sr.Name;
        }
        catch (Exception &e)
        {
            return;
        }

        RadioButton1->Enabled = true;
        RadioButton2->Enabled = true;
        Button1->Enabled = true;
    }
}

// ������ �� ������ �������
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    OpenDialog1->InitialDir = "";     // ������� �������, �� ��������
                                      // �������� ���������
    OpenDialog1->FileName = "*.avi";  // ������� ������ AVI-������

    if ( OpenDialog1->Execute())
    {
        // ������������ ������ ���� � ����� ������ �������

        // ��������� Animate ����� ���������� ������ �������,
        // �� �������������� ������ ��������. �������,
        // ��� ���������� ��������� ���������� �������� ������.
        try
        {
            Animate1->FileName = OpenDialog1->FileName;
        }
        catch (Exception &e)
        {
            Edit1->Text = "";
            // ������� ������������ ������ ����������
            RadioButton1->Enabled = false;
            RadioButton2->Enabled = false;
            Button1->Enabled = false;
            Button2->Enabled = false;
            Button3->Enabled = false;

            AnsiString msg =
                "������ �������� ����� " +
                OpenDialog1->FileName +
                "\n��������� �������� �������������� ������.";
            ShowMessage(msg);
            return;
        }
        Edit1->Text = OpenDialog1->FileName; // ���������� ��� �����


        RadioButton1->Checked = true;// ����� ��������� - ����������
        Button1->Enabled = true;     // ������ ���� ��������
        Button2->Enabled = false;    // ������ ���������� ���� ����������
        Button3->Enabled = false;     // ������ ��������� ���� ����������

        RadioButton1->Enabled = true;
        RadioButton2->Enabled = true;
    }
}

// ������ �� ������ ����/����
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if (Animate1->Active)
    {
        // �������� ������������, ������ �� ������ ����
        Animate1->Active = false;
        Button1->Caption = "����";
        RadioButton2->Enabled = true;
    }
    else  // ������ �� ������ ����
    {
        // �������������� ����������� ��������
        Animate1->StartFrame = 1;                   // � ������� �����
        Animate1->StopFrame = Animate1->FrameCount; // �� ��������� ����
        Animate1->Active = true;
        Button1->Caption = "����";
        RadioButton2->Enabled = false;
    }
}

// ����� ������ ��������� ���� ��������
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
    Button1->Enabled = true; // ������ ����/���� ��������
    // ������� ������������ ������ ������ ��������� �� ������
    Button2->Enabled = false;
    Button3->Enabled = false;

    Animate1->Active = false;
}

// ����� ������ ��������� �� ������
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
    Button1->Enabled = false; // ������ ����/���� ����������

    Button2->Enabled = true;   // ������ ��������� ���� ��������
    Button3->Enabled = false;  // ������ ���������� ���� ����������
    // ���������� ������ ����
    Animate1->StartFrame =1;
    Animate1->StopFrame = 1;
    Animate1->Active = true;
    CFrame = 1; // �������� ����� ������������� �����
}

// ������ �� ������ ��������� ����
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    CFrame++;
    // ���������� ����
    Animate1->StartFrame = CFrame;
    Animate1->StopFrame = CFrame;
    Animate1->Active = true;

    if (CFrame > 1)
        Button3->Enabled = true;

    if (CFrame == Animate1->FrameCount) // ���������� ��������� ����
        Button2->Enabled = false;      // ������ ������ ��������� ���� ����������
}

// ������ �� ������ ���������� ����
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    if (CFrame == Animate1->FrameCount) // ��������� ����
        Button2->Enabled = true;

    CFrame--;

    // ���������� ����
    Animate1->StartFrame = CFrame;
    Animate1->StopFrame = CFrame;
    Animate1->Active = true;

    if (CFrame == 1)
        Button3->Enabled = false;  // ������ ��������� ���� ����������
}

