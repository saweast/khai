// Пересчет цены из долларов в рубли

#include <vcl.h>
#pragma hdrstop

#include "usd2rub_u.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}


// нажатие клавиши в поле Цена
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
    	Edit2->SetFocus();
        return;
    }

    // остальные клавиши запрещены
    Key = 0; // не отображать символ
}

// нажатие клавиши в поле Курс
void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
	if ((Key >= '0') && (Key <= '9')) //цифра
    	return;

    if (Key == DecimalSeparator)
    {
    	if ((Edit2->Text).Pos(DecimalSeparator) != 0)
        	Key = 0; // разделитель уже введен
        return;
    }

    if (Key == VK_BACK) // клавиша <Backspace>
    	return;

    if (Key == VK_RETURN) // клавиша <Enter>
    {
    	Button1->SetFocus();// переход к кнопке Вычислить
        					// повторное нажатие клавиши <Enter>
        					// активизирует процесс вычисления денег
        return;
    };

    // остальные клавиши запрещены
    Key = 0; // не отображать символ
}

// щелчок на кнопке Пересчет
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	float usd; // цена в долларах
    float k;   // курс
    float rub; // цена в рублях

    // проверим, введены ли данные в поля Цена и Курс
    if (((Edit1->Text).Length() == 0) || ((Edit2->Text).Length() == 0))
    {
    	MessageDlg("Надо ввсети цену и курс",
        	mtInformation, TMsgDlgButtons() << mbOK, 0);
        if ((Edit1->Text).Length() == 0)
        	Edit1->SetFocus(); // курсор вполе Цена
        else
        	Edit2->SetFocus(); // курсор вполе Курс
        return;
    };

    // ввод исходных данных
    usd = StrToFloat(Edit1->Text);
    k = StrToFloat(Edit2->Text);

    // вычисление
    rub = usd * k;

    // вывод результата
    Label4->Caption = FloatToStrF(usd,ffGeneral,7,2) + "$ = " +
    			FloatToStrF(rub,ffGeneral,7,2) + " руб." ;
}

//щелчок на кнопке Завершить
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Form1->Close(); // закрыть форму приложения
}



