/*
   ������������������� ������������� CD ������.
   ������������ ������� ����� � ��������� � ��� ���.
   ������������� ������������� ���������� MediaPlayer.

*/

#include <vcl.h>
#pragma hdrstop

#include "CDPmain.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// �������� ��� ������ Play/Stop
Graphics::TBitmap *bmPlay;   // Play
Graphics::TBitmap *bmStop;   // Stop

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    bmPlay   = new Graphics::TBitmap();
    bmStop   = new Graphics::TBitmap();

    // ��������� �������� ��� ������ Play/Stop
    bmPlay->LoadFromResourceID((int)HInstance,101);
    bmStop->LoadFromResourceID((int)HInstance,102);
    // ���������� ��������
    SpeedButton2->Glyph->Assign(bmPlay);

    MediaPlayer->Notify = true; // ��������� ������� Notify
}
// ��� ������� ������������ ������� ��������� �������
// ����������� � ������������� � ������ � �������
#define MINUTE(ms) ((ms/1000)/60)
#define SECOND(ms) ((ms/1000)%60)

// ������� � ���� Label1 ���������� � ������� �����
void __fastcall TForm1::TrackInfo()
{
    int ms; // ����� �������� �����, ����
    AnsiString st;

    Track  =  MCI_TMSF_TRACK(MediaPlayer->Position);

    MediaPlayer->TimeFormat = tfMilliseconds;
    ms = MediaPlayer->TrackLength[Track];
    MediaPlayer->TimeFormat = tfTMSF;

    st = IntToStr(SECOND(ms));
        if ( st.Length() == 1)
            st = "0" + st;

    st = "���� "+ IntToStr(Track) +
         ". ������������ "+ IntToStr(MINUTE(ms)) + ":" + st;


    Label1->Caption = st;
}

// ��������� ��������� ������
void __fastcall TForm1::MediaPlayerNotify(TObject *Sender)
{
  switch ( MediaPlayer->Mode )
  {
    case mpOpen: // ������������ ������ ��������
    {
        SpeedButton1->Enabled  =  false;
        SpeedButton2->Glyph->Assign(bmPlay);
        SpeedButton2->Tag  =  0;
        SpeedButton3->Enabled  =  false;
        Label2->Caption  =  "00:00";

        /* �� ������� �� ������� ����� ���������
           ��������� ��������� */
        Timer->Enabled  =  True;
    }
  }
  MediaPlayer->Notify  =  true;
}

// ������ �� �������: ������� ����� �����
// � ����� ���������������
void __fastcall TForm1::TimerTimer(TObject *Sender)
{
  int trk;          // ����
  int min, sec;     // �����
  AnsiString st;

  if ( MediaPlayer->Mode == mpPlaying ) // ����� ���������������
  {
    // �������� ����� ���������������� ����� �
    trk  =  MCI_TMSF_TRACK(MediaPlayer->Position);

    if ( trk != Track ) // ��������� ����� �����
    {
      TrackInfo();
      Track  =  trk;
      if ( Track > 1 )
          SpeedButton1->Enabled  =  true;  // �������� ������ "����.����"
      if ( Track == MediaPlayer->Tracks)
          SpeedButton3->Enabled  =  false; // ������ "����.����" ����������
    }

    // ����� ���������� � ��������������� �����
    min  =  MCI_TMSF_MINUTE(MediaPlayer->Position);
    sec  =  MCI_TMSF_SECOND(MediaPlayer->Position);
    st.printf("%d:%.2d",min,sec);
    Label2->Caption = st;
    return;
  }

  // ���� �������� ������ ��� � ��� ���
  // AudioCD, �� Mode == mpOpen.
  // ���� ����, �.�. �� ��� ��� ���� �� ����� Mode == mpStopped + ���-�� ������ > 1
  if ( (MediaPlayer->Mode == mpStopped) &&
     (MediaPlayer->Tracks > 1) )
  {
    // ���� ��������
    Timer->Enabled  =  false;
    SpeedButton2->Enabled = true;;
    SpeedButton2->Tag = 0;
    SpeedButton3->Enabled = true;
    MediaPlayer->Notify  =  true;

    // �������� ���������� � ������� �������� CD
    MediaPlayer->TimeFormat = tfMilliseconds;

    int ms = MediaPlayer->Length;
    AnsiString st = "Audio CD. ����� ��������: ";

    st = st +  IntToStr(MINUTE(ms));
    st = st + ":" + IntToStr(SECOND(ms));
    Label1->Caption  =  st;

    MediaPlayer->TimeFormat = tfTMSF;
    Label1->Visible  =  true;
    Track = 0;
    return;
  }

  // �������� ������ ��� � ��������� �� Audio CD
  if (( MediaPlayer->Mode == mpOpen )||
      (MediaPlayer->Mode == mpStopped) && (MediaPlayer->Tracks == 1))
  {
    Label1->Caption  =  "�������� Audio CD";
    if ( Label1->Visible )
          Label1->Visible  =  false;
    else  Label1->Visible  =  true;
  }
}

// ������������ ������ ���� ���������
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    MediaPlayer->Stop();
    MediaPlayer->Close();
}

// ���������� ����
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
MediaPlayer->Previous(); // � ������ �������� �����
    MediaPlayer->Previous(); // � ������ ����������� ����
    if ( MCI_TMSF_TRACK(MediaPlayer->Position) == 1 )
      SpeedButton1->Enabled  =  false;
    if ( ! SpeedButton3->Enabled )
      SpeedButton3->Enabled  =  true;
    TrackInfo();
    Label2->Caption = "0:00";
}

// ��������� ����
void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
  MediaPlayer->Next();
  // ���� ������� � ���������� �����, �� ������
  // Next ������� �����������
  if ( MCI_TMSF_TRACK(MediaPlayer->Position) == MediaPlayer->Tracks )
    SpeedButton3->Enabled  =  false;
  if (! SpeedButton1->Enabled ) SpeedButton1->Enabled = true;
  TrackInfo();
  Label2->Caption = "0:00";
}

// ������ �� ������ Play/Stop
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
if ( SpeedButton2->Tag == 0 ) {
    // ������ �� ������ Play
    MediaPlayer->Play();
    SpeedButton2->Glyph->Assign(bmStop);
    SpeedButton2->Hint = "����";
    SpeedButton2->Tag  =  1;
    //SpeedButton3->Enabled  =  true; // �������� ������ "��������� ����"
    MediaPlayer->Notify  =  true;
    Timer->Enabled  = true;
    TrackInfo();
  }
  else {
    // ������ �� ������ Stop
    SpeedButton2->Glyph->Assign(bmPlay);
    SpeedButton2->Hint = "���������������";
    SpeedButton2->Tag  =  0;
    MediaPlayer->Notify  =  true;
    MediaPlayer->Stop();
    Timer->Enabled  =  false;
  }
}

