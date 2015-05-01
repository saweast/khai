/*
    Программа вычисляет сопротивление электрической цепи,
    которая состоит из двух сопротивлений.
    Сопротивления могут быть соединены последовательно
    или параллельно.

*/
#include <vcl.h>
#pragma hdrstop

#include "SoprForm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

// щелчок на кнопке Вычислить
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    float r1,r2,r;

    r1 = StrToFloat(Edit1->Text);
    r2 = StrToFloat(Edit2->Text);

    /* Переключатели RadioButton1 и RadioButton2
       зависимые, поэтому о типе соединения можно
       судить по состоянию одного из них */
    if ( RadioButton1->Checked )
    {
        // выбран переключатель "последовательно"
        r = r1 + r2;
    }
    else
    {
        // выбран переключатель "параллельно"

        // при вычислении сопротивления возможно
        // исключение EInvalidOp
        try
        {
            r = (r1 * r2) / (r1 + r2);
        }
        catch ( EInvalidOp &e)
        {
            ShowMessage("Необходимо задать величину сопротивлений");
            return;
        }
    }
    Label4->Caption = FloatToStrF(r,ffGeneral,6,2) + " Ом";
}

// щелчок на переключателе "последовательно"
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
    Label4->Caption = "";
}

// щелчок на переключателе "параллельно"
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
    Label4->Caption = "";
}

// нажатие клавиши в поле R1
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
    if ( ( Key >= '0') && ( Key <= '9' ) ) // цифра
        return;

    if ((Key == ',') || (Key == '.'))
    {
        /* Чтобы не раздражать пользователя, заменим
           неправильный разделитель правильным.
           Глобальная переменная Decimalseparator
           содержит символ, используемый в качестве
           разделителя при записи дробных чисел.
       */

       Key = DecimalSeparator;
       if ( (Edit1->Text).Pos(DecimalSeparator) != 0 )
           Key = 0; // разделитель уже введен
       return;
    }

    if (Key == VK_BACK) // клавиша <Backspace>
        return;

    if ( Key == VK_RETURN) // клавиша <Enter>
    {
       Edit2->SetFocus();
       return;
    }

    // остальные символы запрещены
    Key = 0;
}

// нажатие клавиши в поле R2
void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
        if ( ( Key >= '0') && ( Key <= '9' ) ) // цифра
            return;

    if ((Key ==',') || (Key == '.'))
    {
       Key = DecimalSeparator;
       if ( (Edit1->Text).Pos(DecimalSeparator) != 0 )
           Key = 0; // разделитель уже введен
       return;
    }

    if (Key == VK_BACK) // клавиша <Backspace>
        return;

    if ( Key == VK_RETURN) // клавиша <Enter>
    {
       Button1->SetFocus();
       return;
    }

    // остальные символы запрещены
    Key = 0;
}




