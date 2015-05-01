//---------------------------------------------------------------------------

#ifndef DrinkFormH
#define DrinkFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label7;
    TComboBox *ComboBox1;
    TComboBox *ComboBox3;
    TLabel *Label1;
    TLabel *Label3;
    TLabel *Label2;
    TComboBox *ComboBox2;
    void __fastcall ComboBox1Click(TObject *Sender);
    void __fastcall ComboBox3Click(TObject *Sender);
    void __fastcall ComboBox2Click(TObject *Sender);
    void __fastcall ComboBox2KeyPress(TObject *Sender, char &Key);
    void __fastcall ComboBox3KeyPress(TObject *Sender, char &Key);


private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
