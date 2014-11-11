/*
    ��������� "���������".
    ����������, ��� ��������� �� System Tray
    ������ ���������, ���������� ����� ��������� � ������������
    ���� ������.

*/

#include <vcl.h>
#pragma hdrstop

#include "AlarmForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

#include "DateUtils.hpp"
#include "ShellAPI.hpp"  // ��� ������� � Shell_NottifyIcon
#include "mmsystem.hpp"  // ��� ������� � PlaySound

int cHour, cMinute;     // ����� �� ����������
int alrHour, alrMinute; // ����� �������

// ����������� ����� � ������ � ������� �����
AnsiString __fastcall mm(int m)
{
    if (m <= 9)
        return "0" + IntToStr(m);
    else
        return IntToStr(m);
}

// ���������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    // ���������� ������� �����
    cHour = HourOf( Now() );
    Label1->Caption = IntToStr(cHour);
    cMinute = MinuteOf( Now() );
    Label3->Caption = mm(cMinute);
}

// �������� ������ �� System Tray
void __fastcall TForm1::CreateTrayIcon(int n, AnsiString Tip)
{
    TNotifyIconData nidata;

    /* ��������� ��������� nidat, ���� �������
       ���������� ������ �� System Tray */

   nidata.cbSize = sizeof(TNotifyIconData);
   nidata.hWnd = Form1->Handle; // ���� ����������, ������� ������������ ������
   nidata.uID = n; // ����� ������ (���� ���������� ����� ���������� �� ������
                   // ��������� �������
   nidata.uFlags =  NIF_ICON + NIF_MESSAGE + NIF_TIP;

   /* ��� ���������������� ��������� ���� ��
      �� ������, ������������ ������������
      ������������� ������� WM_MYTRAYNOTIFY
     ( ��. AlarmMainForm.h ) */
   nidata.uCallbackMessage = WM_MYTRAYNOTIFY;

   // ������
   nidata.hIcon = Application->Icon->Handle;

   // �������� (����������� �����)
   StrPCopy(nidata.szTip,Tip);

   Shell_NotifyIcon(NIM_ADD, &nidata);  // �������� ������
}

// ������� �������� � System Tray
void __fastcall TForm1::DeleteTrayIcon(int n)
{
    TNotifyIconData nidata;

    nidata.cbSize = sizeof(TNotifyIconData);
    nidata.hWnd = Form1->Handle; // ���� ����������, ������� ������������ ������
    nidata.uID = n; // ����� ������, ������� ���� ������
                    // (���� ���������� ����� ���������� �� ������
                    // ��������� �������

    Shell_NotifyIcon(NIM_DELETE, &nidata);
}

// ������ �� ������ OK
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    AnsiString st;
    alrHour = UpDown1->Position;
    alrMinute = UpDown2->Position;

    if ( ( alrHour == cHour ) && (alrMinute <= cMinute) ||
         ( alrHour < cHour )  )
    {
        AnsiString st;
        int r;
        st.printf("������ %i:%i\n��������� ���������� �� %i:%i",
                   cHour,cMinute,alrHour,alrMinute);
        r = MessageDlg(st, mtWarning, TMsgDlgButtons() << mbOK <<mbCancel, 0);
        if (r == mrCancel) return;
    }

    st = "���������. " + IntToStr(alrHour) + ":" + mm(alrMinute);
    CreateTrayIcon(1,st);
    Form1->Hide();
}

// ������ �� �������
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if ( Form1->Visible )
    {
        // ���� ��������� �� ������
        if ( HourOf( Now() ) != cHour) {
            cHour = HourOf( Now() );
            Label1->Caption = IntToStr(cHour);
        }
        if ( MinuteOf( Now() ) != cMinute) {
            cMinute = MinuteOf( Now() );
            Label3->Caption = mm(cMinute);
        }
        // ��������/������ ���������
        Label2->Visible = ! Label2->Visible;
    }
    else
    {
        TDateTime t = Now();
        if ( (alrHour == HourOf(t) ) && (alrMinute == MinuteOf(t)) )
        {
            PlaySound("notify.wav", 0, SND_ASYNC);
            DeleteTrayIcon(1); // ������ ������ � System Tray
            Form1->Show();
        }
    }
}

// ������ �� ������ ���������� UpDown1 (����)
void __fastcall TForm1::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
    Label4->Caption = IntToStr(UpDown1->Position);
}

// ������ �� ������ ���������� UpDown2 (������)
void __fastcall TForm1::UpDown2Click(TObject *Sender, TUDBtnType Button)
{
    Label6->Caption = mm(UpDown2->Position);
}


// ��������� ������������� ������������� ��������� WM_MYTRAYNOTIFY
void __fastcall TForm1::MYTRAYNOTIFY(TMessage &Message)
{
    TPoint p;
    if ( Message.LParam == WM_RBUTTONDOWN )
    {
        GetCursorPos(&p);
        SetForegroundWindow(Application->MainForm->Handle);
        Form1->PopupMenu1->Popup(p.x,p.y);
    }
}

// �������  ������������
void __fastcall TForm1::N1Click(TObject *Sender)
{
    Timer1->Enabled = false;
    Form1->Show();
    DeleteTrayIcon(1); // ������ ������ � System Tray
}

// ������� ������������ ���� �������
// (���������� ������ ���������)
void __fastcall TForm1::N2Click(TObject *Sender)
{
    Form1->DeleteTrayIcon(1); // ������ ������ � System Tray
    Form1->Close();
}

