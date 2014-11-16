/*
    Программа добавляет в базу данных,
    реализованную как текстовый файл,
    информацию о температуре воздуха.
    База данных реализована в виде текстового
    файла. Если файла нет, то программа создаст его.
*/

#include <vcl.h>
#pragma hdrstop

#include "MeteoFrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

int f; // дескриптор файла

// конструктор
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    MonthCalendar1->ShowTodayCircle = false;
    MonthCalendar1->Date = Now();
    Button1->Enabled = false;
}

// изменилось содержимое поле редактирования
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
    // кнопка "Добавить" доступна, если в поле редактирования
    // находится число. Если в поле символов нет или первый
    // символ - "минус", кнопка недоступна.
    if ( (Edit1->Text.Length() == 0 ) ||
          ( (Edit1->Text.Length() == 1) && (Edit1->Text[1] == '-') ) )
        Button1->Enabled = false;
    else
        Button1->Enabled = true;
}

// щелчок на кнопке "Добавить"
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    AnsiString st;

    /* файл можно открыть в режиме fmCreate, тогда, если
       файл существует, он будет открыт для записи,
       если файла нет, то он будет создан */

    st = MonthCalendar1->Date.DateString() + " " + Edit1->Text + "\r\n";

    /* открыть для записи или создать файл meteo.txt */


    if ( FileExists("meteo.txt") )
        f = FileOpen("meteo.txt",fmOpenWrite);
    else
       f = FileCreate("meteo.txt");


    if ( f != -1 )
    {
        // файл открыт для записи
        FileSeek(f,0,2); // установить указатель на конец файла
        FileWrite(f,st.c_str(),st.Length());
        FileClose(f);
        Button1->Enabled = false;
    }

    else
    {
        /* ошибка доступа к файлу: ни открыть,
           ни создать не получилось */
        ShowMessage("Oшибка доступа к файлу: ни открыть,"
                     "ни создать не получилось");
    }
}

// в поле редактирования можно ввести только
// положительное или отрицательное число
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
    if (( Key >= '0') && (Key <= '9'))
        return;

    // десятичная точка (запятая)
    if ( ( Key == '.') || (Key == ','))
    {
        Key = ',';
        if ( Edit1->Text.Pos(',') != 0 )
            Key = 0;
        return;
    }

   if ( Key == 8)
        return;

   if ((Key == '-') && (Edit1->Text.Length() == 0))
        // "минус" может быть только первым символом
        return;

   // все остальные символы запрещены
   Key = 0;

}

// щелчок в поле компонента MonthCalendar
void __fastcall TForm1::MonthCalendar1Click(TObject *Sender)
{
    Edit1->Text = "";    // очистить поле ввода температуры
    Edit1->SetFocus();   // установить курсор в поле ввода температуры
}

