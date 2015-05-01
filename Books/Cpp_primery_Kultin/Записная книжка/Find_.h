//---------------------------------------------------------------------------

#ifndef Find_H
#define Find_H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFindForm : public TForm
{
__published:	// IDE-managed Components
    TButton *Button1;
    TLabel *Label1;
    TEdit *Edit1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
    __fastcall TFindForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFindForm *FindForm;
//---------------------------------------------------------------------------
#endif
