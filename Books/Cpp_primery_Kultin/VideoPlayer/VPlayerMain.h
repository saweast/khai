//---------------------------------------------------------------------------

#ifndef VPlayerMainH
#define VPlayerMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <MPlayer.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TOpenDialog *OpenDialog1;
    TPanel *Panel1;
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton1;
    TMediaPlayer *MediaPlayer1;
    TTimer *Timer1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall MediaPlayer1Notify(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Timer1Timer(TObject *Sender);

private:	// User declarations

public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
