//---------------------------------------------------------------------------

#ifndef ShowPicMainFormH
#define ShowPicMainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TButton *Button2;
    TImage *Image1;
    TLabel *Label1;
    TCheckBox *CheckBox1;
    TTimer *Timer1;
    void __fastcall Button1Click(TObject *Sender);
   
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall CheckBox1Click(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
private:
    bool __fastcall FirstPicture(); // выводит првую иллюстрацию
    bool __fastcall NextPicture();  // выводит следующую иллюстрацию


public:
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
