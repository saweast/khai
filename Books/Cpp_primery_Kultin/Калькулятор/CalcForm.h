//---------------------------------------------------------------------------

#ifndef CalcFormH
#define CalcFormH
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
    TPanel *Panel1;
    TButton *Btn7;
    TButton *Btn4;
    TButton *Btn1;
    TButton *Btn8;
    TButton *Btn9;
    TButton *Btn5;
    TButton *Btn6;
    TButton *Btn2;
    TButton *Btn3;
    TButton *Btn0;
    TButton *Btnk;
    TButton *BtnP;
    TButton *BtnM;
    TButton *BtnE;
    TButton *BtnC;
    TStaticText *StaticText1;
    void __fastcall Btn0Click(TObject *Sender);
    void __fastcall Btn2Click(TObject *Sender);
    void __fastcall Btn3Click(TObject *Sender);
    void __fastcall Btn4Click(TObject *Sender);
    void __fastcall Btn5Click(TObject *Sender);
    void __fastcall Btn6Click(TObject *Sender);
    void __fastcall Btn7Click(TObject *Sender);
    void __fastcall Btn8Click(TObject *Sender);
    void __fastcall Btn9Click(TObject *Sender);
    void __fastcall BtnkClick(TObject *Sender);
    void __fastcall Btn1Click(TObject *Sender);
    void __fastcall BtnCClick(TObject *Sender);
    void __fastcall BtnPClick(TObject *Sender);
    void __fastcall BtnMClick(TObject *Sender);
    void __fastcall BtnEClick(TObject *Sender);

private:
    void __fastcall DoOp(void);

public:
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
