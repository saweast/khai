/*
   ������� �������� ������.
   ������������� ������������� ����������� RichEdit, MainMenu,
   ToolBar, SpeedButton, OpenDialog, SaveDialog.

   */

#include <vcl.h>
#pragma hdrstop

#include "MEditFrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

// ������ �� ������ ����� "� ���������" ��������� �������
#include "about.h"

TForm1 *Form1;
AnsiString aFileName; // ��� �������������� �����


// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    aFileName = "";

    /* ������ ������� ��������� ������� Click ���
       ������ ������ ������������
       ��������! ������� ���� ������� ������� ���������
       ������� Click ��� ������ ����/������� � ����/���������,
       ����� - �������� � ����� ��������� ��� ����������. */
    SpeedButton1->OnClick = imOpenClick;
    SpeedButton2->OnClick = imSaveClick;
}

// ��������� ����� � �����
bool __fastcall TForm1::SaveText()
{
    // �������� ������� SaveText ����� false, ����
    // � ���� ��������� ������������������ ������ �� ������ ��������
    if ( aFileName == "" )
    {
        // �������� � ������������ ��� �����
        //SaveDialog1->FileName = "Text.txt";
        SaveDialog1->Options << ofPathMustExist << ofOverwritePrompt;
        if ( SaveDialog1->Execute() )
             aFileName = SaveDialog1->FileName;
        else
           return false; // ������������ ������ ���� ������� �� ������ "��������"
    }

    RichEdit1->Lines->SaveToFile(aFileName); // �������� ����� � ����
    return true;
}

// ������� ����/�������
void __fastcall TForm1::imOpenClick(TObject *Sender)
{
    int r;

    // ���� ����� �������, �� ��� ���� ���������
    if ( RichEdit1->Modified )
    {
        // ����� �������
        r = MessageDlg("����� ��� �������.\n��������� ���������?",
                    mtWarning, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);

        if ( r == mrCancel )
            // � ���� ��������� ������������ ������� �� ������ Cancel
            return;

        // ����� ������������ ������ Yes
        if ( ( r == mrYes ) && ( ! SaveText() ))
              return;
    }

    // ������� ����
    OpenDialog1->FileName = "*.txt";
    OpenDialog1->Options << ofPathMustExist << ofFileMustExist;

    if ( OpenDialog1->Execute() )
    {
        RichEdit1->Lines->LoadFromFile(OpenDialog1->FileName);
        RichEdit1->Modified = false;
        Form1->Caption = "MEdit - " +  OpenDialog1->FileName;
        aFileName = OpenDialog1->FileName;
    }
}

// ������� ����/���������
void __fastcall TForm1::imSaveClick(TObject *Sender)
{
    // �������� ����� � ����
    if ( SaveText() )
    {
        RichEdit1->Modified = false;
        Form1->Caption = "MEdit - " + aFileName;
    }
}

// ������� ����/�����
void __fastcall TForm1::imExitClick(TObject *Sender)
{
     Form1->Close();
     /* ��������� ������� FormCloseQuery,
        ������� �������� ���������, ������� ��
        �������� � ����� */
}

// ������������ ������ ������ �� ������ "������� ����"
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    int r;
    if ( RichEdit1->Modified ) // ����� �������
    {
        r = MessageDlg("����� ��� �������.\n��������� ���������?",
                    mtWarning, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);

        switch ( r )
        {
            case mrYes : // ������������ ������� �� ������ Yes
                if ( ! SaveText() )
                    CanClose = false;  // ���� �� ���������
                break;

            case mrCancel : // ������������ ������� �� ������ Cancel
                    CanClose = false; // ���������� ������ � �������
        }
     }
}

// ������� ���������/������ ������������
void __fastcall TForm1::imToolBarClick(TObject *Sender)
{
    // ������/���������� ������ ������������
    ToolBar1->Visible = ! ToolBar1->Visible;

    // ���������/������ "�������" � ���� ���������/������ ������������
    imToolBar->Checked = ! imToolBar->Checked;
}

// ������� �������/� ���������
void __fastcall TForm1::imAboutClick(TObject *Sender)
{
    TAboutForm *AboutForm;
     // �������� Position ����� AboutForm ���� ��������� �������� poOwnerForm
    AboutForm = new TAboutForm (this);
    AboutForm->ShowModal();
    delete AboutForm;
}

