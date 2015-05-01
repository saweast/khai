/*
    Программа пересчитывает цену из долларов в рубли.
    Демонстрирует вывод справочной информации в формате HTML Help 1.0.

    Отображение справочной информации в формате HTML Help 1.0
    осуществляет системная утилита hh.exe

    Файл справочной информации должен находится в том же каталоге что и программа,
    или в системном каталоге Help.
*/

#include <vcl.h>
#pragma hdrstop

#include "ConvertorForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

/* Нажатие клавиши в поле "Цена". Процедура
   обработки события KeyDown позволяет обрабатывать
   нажатие всех клавиш, в том числе и функциональных
   (при нажатии функциональной клавиши событие KeyPress
   не возникает) */
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_F1 )
     /* Отображение справочной информации
       обеспечивает утилита hh.exe, входящая
       в состав Windows. Ключ mappid задает
       отображаемый раздел справочной информации. */
        WinExec("hh.exe -mapid 3 convertor.chm", SW_RESTORE);
}

// нажатие клавиши в поле "Курс"
void __fastcall TForm1::Edit2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_F1 )
        WinExec("hh.exe -mapid 4 convertor.chm", SW_RESTORE);
}

// щелчок на кнопке "Справка"
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    WinExec("hh.exe -mapid 1 convertor.chm", SW_RESTORE);
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
    }

    // ввод исходных данных
    usd = StrToFloat(Edit1->Text);
    k = StrToFloat(Edit2->Text);

    // вычисление
    rub = usd * k;

    // вывод результата
    Label4->Caption = FloatToStrF(usd,ffGeneral,7,2) + "$ = " +
    			FloatToStrF(rub,ffGeneral,7,2) + " руб." ;

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
        {
        	Key = 0; // разделитель уже введен
        	return;
    	}
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
    }

    // остальные клавиши запрещены
    Key = 0; // не отображать символ
}

//щелчок на кнопке Завершить
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Form1->Close(); // закрыть форму приложения
}




