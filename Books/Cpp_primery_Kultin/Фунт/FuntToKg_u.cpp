//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FuntToKg_u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    /* так как поле Edit1 пустое (пользователь
    еще не ввел исходные данные), то
    сделаем кнопку Пересчет недоступной */
    Button1->Enabled  =  False;
}

// нажатие клавиши в поле Edit1
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
	// код запрещенного символа заменим нулем, в результате
    // символ в поле редактирования не появится

    // Key - код нажатой клавиши
    // проверим, является ли символ допустимым
    if ((Key >= '0') && (Key <= '9')) //цифра
        return;

    // глобальная переменная DecimalSeparator
    // содержит символ, используемый в качестве разделителя
    // при записи дробных чисел
    if (Key == DecimalSeparator)
    {
        if ((Edit1->Text).Pos(DecimalSeparator) != 0)
            Key = 0; // разделитель уже введен
        return;
    }

    if (Key == VK_BACK) // клавиша <Backspace>
        return;

    if (Key == VK_RETURN) // клавиша <Enter>
    {
        Button1->SetFocus();
        return;
    }

    // остальные клавиши запрещены
    Key = 0; // не отображать символ
}

// Содержимое поля Edit1 изменилось
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
    // проверим, есть ли в поле Edit1 исходные данные
    if ( (Edit1->Text).Length() == 0)
        Button1->Enabled  =  False; // кнопка Пересчет недоступна
    else Button1->Enabled  =  True; // кнопка Пересчет доступна

   Label2->Caption = "";
}

// щелчок на кнопке Пересчет
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   double funt; // вес в фунтах
   double kg;   // вес в килограммах

   // кнопка Пересчет доступна только в том случае,
   // если в поле Edit1 есть данные. Поэтому,
   // наличие в поле информации можно не проверять.
   funt  =  StrToFloat(Edit1->Text);
   kg  =  funt * 0.4995;
   Label2->Caption  =  FloatToStrF(funt,ffGeneral,5,2) +
                     " ф. - это " +
                     FloatToStrF(kg,ffGeneral,5,2) + " кг";
}

