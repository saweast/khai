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
    void __fastcall FormDestroy(TObject *Sender); // ���������

private:
     // ** ��� ���������� ��������� ���� ������� **

    TSpeedButton * btn[16];    // ������

    // ��������� ��������� ������� Click �� ������
    void __fastcall btnClick(TObject *Sender);

public:
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;

#endif
