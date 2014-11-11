//---------------------------------------------------------------------------

#ifndef AlarmFormH
#define AlarmFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------

#define WM_MYTRAYNOTIFY (WM_USER + 123)

class TForm1 : public TForm
{
__published:
    TTimer *Timer1;
    TEdit *Edit1;
    TButton *Button1;

    // индикатор текущего времени
    TGroupBox *GroupBox2;
    TLabel *Label1; // часы
    TLabel *Label2; // двоеточие
    TLabel *Label3; // минуты

    // индикатор времени сигнала
    TGroupBox *GroupBox1;
    TLabel *Label4; // часы
    TLabel *Label5; // двоеточие
    TLabel *Label6; // минуты

    // кнопки установки времени будильника
    TUpDown *UpDown1; // часы
    TUpDown *UpDown2; // минуты

    TPopupMenu *PopupMenu1; // контекстное меню
    TMenuItem *N1; // команда ¬осстановить
    TMenuItem *N2; // команда «акрыть

    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
    void __fastcall UpDown2Click(TObject *Sender, TUDBtnType Button);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);

    // *** определение этих функций вставлено сюда вручную ***

    // создать и поместить значок на System Tray
    void __fastcall CreateTrayIcon(int n, AnsiString Tip);
    // удалить значок с System Tray
    void __fastcall DeleteTrayIcon(int n);

protected:
    // процедура обработки сообщени€ WM_MYTRAYNOTIFY,
    // которое генерирует значок, наход€щийс€ на System Tray
    void __fastcall MYTRAYNOTIFY(TMessage &Message);
    BEGIN_MESSAGE_MAP
        MESSAGE_HANDLER(WM_MYTRAYNOTIFY, TMessage, MYTRAYNOTIFY)
    END_MESSAGE_MAP(TControl)

private:

public:

    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;
#endif
