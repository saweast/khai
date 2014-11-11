//---------------------------------------------------------------------------

#ifndef sCalcFormH
#define sCalcFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>


class TForm1 : public TForm
{
__published:
    TStaticText *StaticText1;
    void __fastcall FormDestroy(TObject *Sender); // индикатор

private:
     // ** эти объ€влени€ вставлены сюда вручную **

    TSpeedButton * btn[16];    // кнопки

    // процедура обработки событи€ Click на кнопке
    void __fastcall btnClick(TObject *Sender);

public:
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;

#endif
