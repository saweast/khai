#ifndef CDPmainH
#define CDPmainH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <MPlayer.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>

class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TTimer *Timer;
    TLabel *Label1;
    TLabel *Label2;
    TMediaPlayer *MediaPlayer;
    TShape *Shape1;
    TShape *Shape2;
        TPanel *Panel1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;

    void __fastcall MediaPlayerNotify(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);

    void __fastcall TimerTimer(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall SpeedButton3Click(TObject *Sender);
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);


private:
    int Track; // номер воспроизводимого трека
    void __fastcall TrackInfo();
public:
    __fastcall TForm1(TComponent* Owner);

    protected:
    /* Cистема направляет сообщение WM_NCHITTEST окну приложения,
       когда указатель мыши перемещается и в момент нажатия/отпускания кнопки мыши.
       Функция WMNCHITTEST обрабатывает это сообщение.
    */
    void __fastcall WMNCHITTEST(TMessage &Message);
    BEGIN_MESSAGE_MAP
         MESSAGE_HANDLER(WM_NCHITTEST, TMessage, WMNCHITTEST)
    END_MESSAGE_MAP(TControl)
};

extern PACKAGE TForm1 *Form1;

#endif
