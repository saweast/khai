//---------------------------------------------------------------------------

#ifndef ExamUnitH
#define ExamUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TXMLDocument *XMLDocument1;
    TLabel *Label1;
    TRadioButton *RadioButton1;
    TRadioButton *RadioButton2;
    TRadioButton *RadioButton3;
    TRadioButton *RadioButton4;
    TButton *Button3;

    void __fastcall Button3Click(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall RadioButton1Click(TObject *Sender);
    void __fastcall RadioButton2Click(TObject *Sender);
    void __fastcall RadioButton3Click(TObject *Sender);

private:	// User declarations
    void  __fastcall Info();       // информация о тесте
    int   __fastcall Qery(int i);  // выводит вопрос
    void  __fastcall Result();     // результат тестирования

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);

};


//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
