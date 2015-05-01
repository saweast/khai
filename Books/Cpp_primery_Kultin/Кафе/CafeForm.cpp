#include <vcl.h>
#pragma hdrstop

#include "CafeForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

float summ; // сумма заказа

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    // сделать недоступным переключатель "соус"
    CheckBox2->Enabled = false;
}

// щелчок на переключателе "Биг-Мак"
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
    if ( CheckBox1->Checked )
    {
        /* переключатель был сброшен,
           пользователь установил его */
        summ += 54;

        // сделать доступным переключатель "соус"
        CheckBox2->Enabled = true;
    }
    else
    {
        /* переключатель был установлен,
           пользователь сбросил его */

       summ -= 54;

       // сбросить и сделать недоступным переключатель "соус"
       if (CheckBox2->Checked)
            CheckBox2->Checked = false;
       CheckBox2->Enabled = false;
    }

    // отобразить измененную сумму в поле
    Label1->Caption = FloatToStrF(summ,ffCurrency,6,2);
}

// щелчок на переключателе "соус"
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
    if ( CheckBox2->Checked)
        summ += 10.5;
    else
        summ -= 10.5;

    Label1->Caption = FloatToStrF(summ,ffCurrency,6,2);
}

// щелчок на переключателе "картошка"
void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
    if ( CheckBox3->Checked)
        summ += 18.5;
    else
        summ -= 18.5;

    Label1->Caption = FloatToStrF(summ,ffCurrency,6,2);
}

// щелчок на переключателе "Кока-Кола"
void __fastcall TForm1::CheckBox4Click(TObject *Sender)
{
    if ( CheckBox4->Checked)
        summ += 14;
    else
        summ -= 14;

    Label1->Caption = FloatToStrF(summ,ffCurrency,6,2);
}


// щелчок на кнопке OK
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if ( (CheckBox1->Checked)&& (CheckBox2->Checked)&&
          (CheckBox3->Checked)&&(CheckBox4->Checked) )
    {
        /* пользователь заказал полный набор
           предоставить скидку 5% */
        summ = summ * 0.95;
        ShowMessage("Вам предоставляется скидка 5%.\n"
        "Сумма заказа: " + FloatToStrF(summ,ffCurrency,6,2)+ " руб.");
    }
    else
        if ( (CheckBox1->Checked)|| (CheckBox3->Checked)||(CheckBox4->Checked))
             ShowMessage("Сумма заказа: " + FloatToStrF(summ,ffGeneral,6,2)+ " руб.");
        else ShowMessage("Вы ничего не заказали");
}

