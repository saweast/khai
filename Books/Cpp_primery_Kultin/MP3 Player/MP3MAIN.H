#ifndef mp3mainH
#define mp3mainH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <MPlayer.hpp>      // эта ссылка вставлена вручную

class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton3;
    TSpeedButton *SpeedButton4;
    TSpeedButton *SpeedButton1;
    TListBox *ListBox1;
    TTrackBar *TrackBar1;
    TTimer *Timer1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;

    void __fastcall FormCreate(TObject *Sender);
    void __fastcall SpeedButton3Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall SpeedButton4Click(TObject *Sender);
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall ListBox1Click(TObject *Sender);
    void __fastcall TrackBar1Change(TObject *Sender);

private:
    // компонент MediaPlayer
    TMediaPlayer *MediaPlayer1;

    // формирует список MP3 файлов указанного каталога
    void __fastcall PlayList(AnsiString path);

    void __fastcall Play(void);
    void __fastcall Stop(void);

public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
