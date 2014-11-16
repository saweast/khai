//---------------------------------------------------------------------------

#ifndef gone60mainH
#define gone60mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMediaPlayer *MediaPlayer1;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *Edit1;
    TButton *Button1;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TTimer *Timer1;
    void __fastcall Edit1Change(TObject *Sender);
    void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall MediaPlayer1Notify(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button1Click(TObject *Sender);


private:
    void __fastcall isRight(void); // проверяет, правильное ли число ввел пользователь
public:
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
