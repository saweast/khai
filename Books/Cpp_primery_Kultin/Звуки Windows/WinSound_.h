//---------------------------------------------------------------------------

#ifndef WinSound_H
#define WinSound_H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
    TLabel *Label1;
    TLabel *Label2;
    TListBox *ListBox1;
    TMediaPlayer *MediaPlayer1;
    TCheckBox *CheckBox1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ListBox1Click(TObject *Sender);
    void __fastcall MediaPlayer1Notify(TObject *Sender);
    
private:
    AnsiString SoundPath; // ���� � ������ Windows

public:	
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
