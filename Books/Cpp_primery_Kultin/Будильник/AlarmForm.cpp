/*
    Программа "Будильник".
    Показывеет, как поместить на System Tray
    значок программы, обеспечить вывод подсказки и контекстного
    меню значка.

*/

#include <vcl.h>
#pragma hdrstop

#include "AlarmForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

#include "DateUtils.hpp"
#include "ShellAPI.hpp"  // для доступа к Shell_NottifyIcon
#include "mmsystem.hpp"  // для доступа к PlaySound

int cHour, cMinute;     // время на индикаторе
int alrHour, alrMinute; // время сигнала

// преобразует целое в строку с ведущим нулем
AnsiString __fastcall mm(int m)
{
    if (m <= 9)
        return "0" + IntToStr(m);
    else
        return IntToStr(m);
}

// констуктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    // отобразить текущее время
    cHour = HourOf( Now() );
    Label1->Caption = IntToStr(cHour);
    cMinute = MinuteOf( Now() );
    Label3->Caption = mm(cMinute);
}

// добавить значок на System Tray
void __fastcall TForm1::CreateTrayIcon(int n, AnsiString Tip)
{
    TNotifyIconData nidata;

    /* заполнить структуру nidat, поля которой
       определяют значок на System Tray */

   nidata.cbSize = sizeof(TNotifyIconData);
   nidata.hWnd = Form1->Handle; // окно приложения, которое представляет значок
   nidata.uID = n; // номер значка (одно приложение может разместить на панели
                   // несколько значков
   nidata.uFlags =  NIF_ICON + NIF_MESSAGE + NIF_TIP;

   /* при позиционировании указателя мыши на
      на щначке, генерируется определенное
      программистом событие WM_MYTRAYNOTIFY
     ( см. AlarmMainForm.h ) */
   nidata.uCallbackMessage = WM_MYTRAYNOTIFY;

   // значок
   nidata.hIcon = Application->Icon->Handle;

   // посказка (всплывающий текст)
   StrPCopy(nidata.szTip,Tip);

   Shell_NotifyIcon(NIM_ADD, &nidata);  // добавить значок
}

// удалить картинку с System Tray
void __fastcall TForm1::DeleteTrayIcon(int n)
{
    TNotifyIconData nidata;

    nidata.cbSize = sizeof(TNotifyIconData);
    nidata.hWnd = Form1->Handle; // окно приложения, которое представляет значок
    nidata.uID = n; // номер значка, который надо убрать
                    // (одно приложение может разместить на панели
                    // несколько значков

    Shell_NotifyIcon(NIM_DELETE, &nidata);
}

// щелчок на кнопке OK
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
        st.printf("Сейчас %i:%i\nБудильник установлен на %i:%i",
                   cHour,cMinute,alrHour,alrMinute);
        r = MessageDlg(st, mtWarning, TMsgDlgButtons() << mbOK <<mbCancel, 0);
        if (r == mrCancel) return;
    }

    st = "Будильник. " + IntToStr(alrHour) + ":" + mm(alrMinute);
    CreateTrayIcon(1,st);
    Form1->Hide();
}

// сигнал от таймера
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if ( Form1->Visible )
    {
        // окно программы на экране
        if ( HourOf( Now() ) != cHour) {
            cHour = HourOf( Now() );
            Label1->Caption = IntToStr(cHour);
        }
        if ( MinuteOf( Now() ) != cMinute) {
            cMinute = MinuteOf( Now() );
            Label3->Caption = mm(cMinute);
        }
        // показать/скрыть двоеточие
        Label2->Visible = ! Label2->Visible;
    }
    else
    {
        TDateTime t = Now();
        if ( (alrHour == HourOf(t) ) && (alrMinute == MinuteOf(t)) )
        {
            PlaySound("notify.wav", 0, SND_ASYNC);
            DeleteTrayIcon(1); // убрать значок с System Tray
            Form1->Show();
        }
    }
}

// щелчок на кнопке компонента UpDown1 (часы)
void __fastcall TForm1::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
    Label4->Caption = IntToStr(UpDown1->Position);
}

// щелчок на кнопке компонента UpDown2 (минуты)
void __fastcall TForm1::UpDown2Click(TObject *Sender, TUDBtnType Button)
{
    Label6->Caption = mm(UpDown2->Position);
}


// обработка определенного пользователем сообщения WM_MYTRAYNOTIFY
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

// команда  Восстановить
void __fastcall TForm1::N1Click(TObject *Sender)
{
    Timer1->Enabled = false;
    Form1->Show();
    DeleteTrayIcon(1); // убрать значок с System Tray
}

// команда контекстного меню Закрыть
// (завершение работы программы)
void __fastcall TForm1::N2Click(TObject *Sender)
{
    Form1->DeleteTrayIcon(1); // убрать значок с System Tray
    Form1->Close();
}

