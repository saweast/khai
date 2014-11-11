//---------------------------------------------------------------------------

#ifndef SaperAboutH
#define SaperAboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TAbout : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
    TLabel *Label4;
        TButton *Button1;
    TLabel *Label5;
    TLabel *Label3;
    TBevel *Bevel1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Label5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAbout *About;
//---------------------------------------------------------------------------
#endif
