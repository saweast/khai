#ifndef GrafFormH
#define GrafFormH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

class TForm1 : public TForm
{
__published:	// IDE-managed Components
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);

private:

public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;

#endif
