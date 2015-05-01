/*
   ������� ����������. ������������� �������������:
     - ���������� MediaPlayer ��� ���������������
       ����� ������� (������ AVI, MPG);
     - ���������� SpeedButton.

   ���������. ���� ���� ���������, ����� ��������������� ����� ���������,
   ��������� ������ �����, �� ���� ����� ��������. ����� ����� �� ����,
   ���� �������� ������� ��������� ������� Paint ��� �����.
*/

#include <vcl.h>
#pragma hdrstop

#include "VPlayerMain.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

// ��� ������� ������������ ������� ��������� �������
// ����������� � ������������� � ������ � �������
#define MINUTE(ms) ((ms/1000)/60)
#define SECOND(ms) ((ms/1000)%60)

// �������� ��� ������
Graphics::TBitmap *bmPlay;   // Play
Graphics::TBitmap *bmPause;  // Pause

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    bmPlay   = new Graphics::TBitmap();
    bmPause   = new Graphics::TBitmap();

    // ��������� �������� ��� ������ Play/Stop
    bmPlay->LoadFromResourceID((int)HInstance,101);
    bmPause->LoadFromResourceID((int)HInstance,102);
    // ���������� ��������
    SpeedButton2->Glyph->Assign(bmPlay);
    MediaPlayer1->Display = Form1;
}

// ���������� ������ �����
void __fastcall GetFrameSize(AnsiString f, int *w, int *h)
{
    if ( f.Pos(".avi") == 0 )
    {
        // ������������ ������ mpg-����
        *w = 352;
        *h = 240;
        return;
    }

    // *** ������������ ������ AVI-���� ***
    // � ��������� AVI ����� ���� ���������� � ������� �����
    struct  {
        char     RIFF[4]; // ������ RIFF
        long int nu_1[5]; // �� ������������
        char     AVIH[4]; // ������ AVIH
        long int nu_2[9]; // �� ������������
        long int w;       // ������ �����
        long int h;       // ������ �����
    } header;

    TFileStream *fs;   // �����, ��� ������ ��������� �����

    /* ��������� ���������� ������ � ��� ��������
    ����� ����������: TFileStream *fs = new TFileStream(f,fmOpenRead); */

    fs = new TFileStream(f,fmOpenRead);   // ������� ����� ��� ������
    fs->Read(&header, sizeof(header));    // ��������� ��������� �����
    *w = header.w;
    *h = header.h;
    delete fs;
}

// ������ �� ������ Eject (����� ����� �����)
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
    int fw, fh;   // ������ ����� �����
    int top,left; // ����� ������� ���� ������
    int sw, sh;   // ������ ������ (������, ������)

    int mw, mh;   // ����������� ��������� ������ ������
                  // (������������ ������� �������� �����)

    float kw, kh; // ����-�� ��������������� ����� �� ������ � ������
    float k;      // ����������� ��������������� �����


    OpenDialog1->Title = "����� �����";
    OpenDialog1->InitialDir = "";
    OpenDialog1->Filter =
        "��� �������|*.avi;*.mpg;*.mpeg|"
        "AVI|*.avi|MPG|*.mpg|MGEG|*.mpeg";

    if ( ! OpenDialog1->Execute() )
        return; // ������������ ����� ������ ������

     /* ��� ������� ������� ���� �����, ������� ��� ������,
       ��������� ������. */

    if ( MediaPlayer1->FileName == OpenDialog1->FileName )
        return;

    /* ������������ ������ ����. ������� ������ � ��������� "������",
       �� ������� ����� ������� ����. ��� ����� ���� ����� ������
       ������ �����. */


    GetFrameSize(OpenDialog1->FileName,&fw, &fh);// �������� ������ �����

    // �������� ����������� ��������� ������ �����
    mw = Form1->ClientWidth;
    mh = Form1->Panel1->Top-10;

    if ( fw < mw)
       kw = 1; // ���� �� ������ ������ ������� ������
    else kw = (float) mw / fw;

    if ( fh < mh)
       kh = 1; // ���� �� ������ ������ ������� ������
    else kh = (float) mh / fh;

    // ��������������� ������ ���� ����������������
    if ( kw < kh)
        k = kw;
    else k = kh;

   // ����� ������� ���������
   sw = fw * k; // ������ ������
   sh = fh * k; // ������ ������

   left = (Form1->ClientWidth - sw) / 2;
   top = (Panel1->Top - sh) / 2;

   MediaPlayer1->FileName = OpenDialog1->FileName;

   MediaPlayer1->Open();
   MediaPlayer1->DisplayRect = Rect(left,top,sw,sh);
    /* ���� ������ ����� ���������� ����� ������ �������
       ����� ����������� �����, �� ����� (������� �����)
       ���� �������� */
   Form1->Canvas->FillRect(Rect(0,0,ClientWidth,Panel1->Top));

   SpeedButton2->Enabled = True; // ������ Play ������ ��������

   // ������� ���������� � ������� ���������������
   MediaPlayer1->TimeFormat = tfMilliseconds;
   int ms = MediaPlayer1->Length;
   AnsiString st = IntToStr(SECOND(ms));
   if ( st.Length() == 1)
        st = "0" + st;
   st = IntToStr(MINUTE(ms)) + ":" + st;
   Label1->Caption = st;
   Label3->Caption = "0:00";

   // ������������ ������� ���������������
   SpeedButton2->Glyph->Assign(bmPause);
   SpeedButton2->Hint = "Pause";
   SpeedButton2->Tag = 1;
   SpeedButton1->Enabled = False; // ������ Eject ����������
   MediaPlayer1->Play();
   Timer1->Enabled = true;
}

// ������ �� ������ Play/Stop (���������������/����)
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
    if (SpeedButton2->Tag == 0)
    {
        // ������ ������ Play
        SpeedButton2->Glyph->Assign(bmPause);
        SpeedButton2->Hint = "Pause";
        SpeedButton2->Tag = 1;
        SpeedButton1->Enabled = False; // ������ Eject ����������
        MediaPlayer1->Play();
        Timer1->Enabled = true;
    }
    else  // ������ ������ Stop
    {
        MediaPlayer1->Stop();
        SpeedButton2->Glyph->Assign(bmPlay);
        SpeedButton2->Hint = "Play";
        SpeedButton2->Tag = 0;
        SpeedButton1->Enabled = True; // ������ Eject ��������
        Timer1->Enabled = false;
    }
}

// ������ �� ������
void __fastcall TForm1::MediaPlayer1Notify(TObject *Sender)
{
    if ( ( MediaPlayer1->Mode == mpStopped ) && ( SpeedButton2->Tag == 1))
    {
        Timer1->Enabled = false;
        SpeedButton2->Glyph->Assign(bmPlay);
        SpeedButton2->Hint = "Play";
        SpeedButton2->Tag = 0;
        SpeedButton1->Enabled = True; // ������� ��������� ������ Eject
    }
}

/* ��������� ��������� ������� Pain ������������
   ����������� (�����������) ������� �����,
   ��� ��������� ����, ��������, ����� ����,
   ��� ������������ ��������� ������ ����, �������������
   ���� Video Player. */
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    if ( MediaPlayer1->Mode == mpStopped )
    {
        MediaPlayer1->Position = 1;
        MediaPlayer1->Position = 0;
    }
}


// ���������� ������ ���������
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    MediaPlayer1->Close();
}

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   // ������� ���������� � ������� ���������������
//   MediaPlayer1->TimeFormat = tfMilliseconds;
   int ms = MediaPlayer1->Position;
   AnsiString st = IntToStr(SECOND(ms));
   if ( st.Length() == 1)
        st = "0" + st;
   st = IntToStr(MINUTE(ms)) + ":" + st;
   Label3->Caption = st;
}

