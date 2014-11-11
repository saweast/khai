/*
   ��������� ��������� ���������� �������� ����� (WAV, RIM, MIDI),
   ������� ��������� � �������� Windows\Media.

   ������������� ������������� ���������� MediaPlayer, � �����
   ������� FindFirst � FindNext ��� ������������ ������ ������.

*/

#include <vcl.h>
#pragma hdrstop

#include "WinSound_.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

// ������ ������ ���������
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    char *wd; // ������� Windows

    wd = (char*)AllocMem(MAX_PATH);
    GetWindowsDirectory(wd,MAX_PATH);
    SoundPath = wd;

    // �������� ����� ��������� � ����������� Media
    SoundPath = SoundPath + "\\Media\\";

    // ���������� ������ �������� ������
    TSearchRec sr;
    if (FindFirst( SoundPath + "*.wav", faAnyFile, sr) == 0 )
    {
        // ������ ���� � ����������� WAV
        ListBox1->Items->Add(sr.Name); // ������� ��� ����� � ������
        // ��� ���� ����� � ����������� WAV ?
        while (FindNext(sr) == 0 )
            ListBox1->Items->Add(sr.Name);
    }

    if (FindFirst( SoundPath + "*.mid", faAnyFile, sr) == 0 )
    {
        // ������ ���� � ����������� MID
        ListBox1->Items->Add(sr.Name); // ������� ��� ����� � ������
        // ��� ���� ����� � ����������� MID ?
        while (FindNext(sr) == 0 )
            ListBox1->Items->Add(sr.Name);
    }

    if (FindFirst( SoundPath + "*.rmi", faAnyFile, sr) == 0 )
    {
        // ������ ���� � ����������� RMI
        ListBox1->Items->Add(sr.Name); // ������� ��� ����� � ������
        // ��� ���� ����� � ����������� RMI ?
        while (FindNext(sr) == 0 )
            ListBox1->Items->Add(sr.Name);
    }

    // ������������� ������ ����
    if ( ListBox1->Items->Count != 0)
    {
        Label2->Caption = ListBox1->Items->Strings[1];
        ListBox1->ItemIndex = 0;

        MediaPlayer1->FileName = SoundPath + ListBox1->Items->Strings[1];
        MediaPlayer1->Open();
        MediaPlayer1->Play();
    }
}

// ������ �� �������� ������
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
    if ( (CheckBox1->Checked) && ( MediaPlayer1->Mode == mpPlaying ) ) return;

    Label2->Caption = ListBox1->Items->Strings[ListBox1->ItemIndex];
    MediaPlayer1->FileName = SoundPath + Label2->Caption;
    MediaPlayer1->Open();
    if ( ! CheckBox1->Checked)
            MediaPlayer1->Notify = false;
    MediaPlayer1->Play();
}


// ������� Notify ��������� � ������ ���������� ���������������
// ��������� �����, ���� ����� ������������ ������ Play,
// �������� �������� Notify ����� true
void __fastcall TForm1::MediaPlayer1Notify(TObject *Sender)
{
    if ( ListBox1->ItemIndex < ListBox1->Items->Count )
    {
        ListBox1->ItemIndex = ListBox1->ItemIndex + 1;
        Label2->Caption = ListBox1->Items->Strings[ListBox1->ItemIndex];
        MediaPlayer1->FileName = SoundPath + Label2->Caption;
        MediaPlayer1->Open();
        if ( ! CheckBox1->Checked)
            MediaPlayer1->Notify = false;
        MediaPlayer1->Play();

    }
}

