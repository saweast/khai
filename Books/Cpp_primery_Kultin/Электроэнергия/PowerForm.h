//---------------------------------------------------------------------------

#ifndef PowerFormH
#define PowerFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *Edit1;
    TEdit *Edit2;
    TLabel *Label3;
    TEdit *Edit3;
    TButton *Button1;
    TLabel *Label4;
    void __fastcall EditKeyPress(TObject *Sender, char &Key);
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
