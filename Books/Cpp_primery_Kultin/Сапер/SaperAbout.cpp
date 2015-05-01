#include <vcl.h>
#pragma hdrstop

#include "SaperAbout.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TAbout *About;

__fastcall TAbout::TAbout(TComponent* Owner)
        : TForm(Owner)
{
}

// ����� URL ������ (������ � ���� ���������� Label5)
void __fastcall TAbout::Label5Click(TObject *Sender)
{
  /* �������� ������ �������� � ������� ShellExecute
     ������-��������� (URL �����), ��� ��� �������� ����
    ShellExecute(AboutForm->Handle,
                "open",
                "http:\\\\www.bhv.ru",
                NULL,NULL)

    ����� URL ����� ����� �� ���� �����.
    � ������� ShellExute ���� �������� ��������� (char*) ��
    null terminated ������, �� �������� Caption - ��� AnsiString.
    �������������� Ansi ������ � (char*) ������ ��������� ����� c_str()
*/

    // ������� ����, ��� �������� ��������� � ���� Label5
    ShellExecute(About->Handle,"open",Label5->Caption.c_str(),
                 NULL,NULL,SW_RESTORE);
}

// ������ �� ������ OK
void __fastcall TAbout::Button1Click(TObject *Sender)
{
    ModalResult = mrOk;
}

