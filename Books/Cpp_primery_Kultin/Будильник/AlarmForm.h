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

    // ��������� �������� �������
    TGroupBox *GroupBox2;
    TLabel *Label1; // ����
    TLabel *Label2; // ���������
    TLabel *Label3; // ������

    // ��������� ������� �������
    TGroupBox *GroupBox1;
    TLabel *Label4; // ����
    TLabel *Label5; // ���������
    TLabel *Label6; // ������

    // ������ ��������� ������� ����������
    TUpDown *UpDown1; // ����
    TUpDown *UpDown2; // ������

    TPopupMenu *PopupMenu1; // ����������� ����
    TMenuItem *N1; // ������� ������������
    TMenuItem *N2; // ������� �������

    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
    void __fastcall UpDown2Click(TObject *Sender, TUDBtnType Button);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);

    // *** ����������� ���� ������� ��������� ���� ������� ***

    // ������� � ��������� ������ �� System Tray
    void __fastcall CreateTrayIcon(int n, AnsiString Tip);
    // ������� ������ � System Tray
    void __fastcall DeleteTrayIcon(int n);

protected:
    // ��������� ��������� ��������� WM_MYTRAYNOTIFY,
    // ������� ���������� ������, ����������� �� System Tray
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
