//---------------------------------------------------------------------------

#ifndef osagoFormH
#define osagoFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TComboBox *ComboBox1;
    TLabel *Label3;
    TLabel *Label4;
    TEdit *Edit1;
    TLabel *Label5;
    TEdit *Edit2;
    TLabel *Label7;
    TComboBox *ComboBox2;
    TCheckBox *CheckBox1;
    TLabel *Label8;
    TLabel *Label9;
    TComboBox *ComboBox3;
    TEdit *Edit3;
    TComboBox *ComboBox4;
    TLabel *Label6;
    TButton *Button1;
    void __fastcall Button1Click(TObject *Sender);

private:
    // обрабатывает событие Change всех компонентов формы
    void __fastcall Change(TObject *Sender);

public:
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
