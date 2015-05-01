//---------------------------------------------------------------------------

#ifndef PuzMainH
#define PuzMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *N4;
    TMenuItem *N5;
    TMenuItem *N6;

    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);

    void __fastcall NewGame();
    void __fastcall Mixer();
    void __fastcall ShowPole();
    void __fastcall Move(int x, int y);
    
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall N4Click(TObject *Sender);
    void __fastcall N3Click(TObject *Sender);
    void __fastcall N6Click(TObject *Sender);
    
private:
     Graphics::TBitmap *pic; // картинка
public:
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;
#endif
