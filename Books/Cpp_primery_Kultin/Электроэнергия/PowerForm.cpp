//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "PowerForm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
        Edit2->OnKeyPress = EditKeyPress;
        Edit3->OnKeyPress = EditKeyPress;
        Edit1->Tag = 1;
        Edit2->Tag = 2;
        Edit3->Tag = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditKeyPress(TObject *Sender, char &Key)
{
        TEdit * Edit;
        Edit = (TEdit*)Sender;
        if ( Key == VK_RETURN)
        {
                switch (Edit->Tag)
                {
                        case 1 :
                                Edit2->SetFocus() ; break;
                        case 2 :
                                Edit3->SetFocus() ; break;
                        case 3 :
                                Button1->SetFocus() ; break;
                }
        return;
        }
        if ( (( Key >= '0') && ( Key <= '9' ) ) || (Key == VK_BACK))
        {
                return;
        }
        if ((Key == ',') || (Key == '.'))
        {
                Key = DecimalSeparator;
                if ( (Edit->Text).Pos(DecimalSeparator) != 0 )
                        Key = 0;
                return;
        }
        if ( Key == VK_BACK )
                return;
        Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        float prior, curr;
        float tariff;
        float summ;
        prior = StrToFloat(Edit1->Text);
        curr = StrToFloat(Edit2->Text);
        tariff = StrToFloat(Edit3->Text);
        if ( curr < prior)
        {
                MessageDlg("Данне значення показу счетчика не може бути меньше попереднього", mtWarning, TMsgDlgButtons() << mbOK,0);
                return;
        }
        summ = (curr - prior) * tariff;
        Label4->Caption = "Сумма к оплате: " + FloatToStrF(summ, ffCurrency, 6,2);
}
//---------------------------------------------------------------------------
