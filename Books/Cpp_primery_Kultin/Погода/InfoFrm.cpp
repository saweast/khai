/*
    Демонстрирует чтение данных из текстового файла.
    В файле meteo.txt находится информация о дневной температуре.
    Программа выводит в поле компонента
    Memo содержимое файла, а также выполняет его обработку - вычисляет
    среднемесячную температуру.
*/

#include <vcl.h>

#pragma hdrstop

#include "InfoFrm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

#include "DateUtils.hpp"  // для достпа к MonthOf

/* Функция GetString читает из файла строку символов
   от текущей позиции до первого пробела.
   значение функции - кол-во прочитанных символов */
int GetString(int f, AnsiString *st);

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    ComboBox1->Style = csDropDownList;
    ComboBox1->Items->Add("Январь");
    ComboBox1->Items->Add("Февраль");
    ComboBox1->Items->Add("Март");
    ComboBox1->Items->Add("Апрель");
    ComboBox1->Items->Add("Май");
    ComboBox1->Items->Add("Июнь");
    ComboBox1->Items->Add("Июль");
    ComboBox1->Items->Add("Август");
    ComboBox1->Items->Add("Сентябрь");
    ComboBox1->Items->Add("Октябрь");
    ComboBox1->Items->Add("Ноябрь");
    ComboBox1->Items->Add("Декабрь");

    ComboBox1->ItemIndex = MonthOf( Now() ) -1 ; // эл-ты списка нумеруются с нуля
}

// щелчок на кнопке OK
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int h; // дескриптор файла

    h = FileOpen("meteo.txt",fmOpenRead);
    if ( h == -1)
    {
        ShowMessage("Файл данных meteo.txt не найден.");
        return;
    }

    Memo1->Lines->Clear();

    // Обработка файла

    AnsiString st; // строка, прочитанная из файла
    int ls;         // длинна строки

    TDateTime aDate;  // дата
    float temp;       // температура
    int nMonth;       // месяц

    int n = 0;     // количество дней (прочитанных строк)
    float sum = 0; // сумма температур
    float sred;    // среднее значение

    AnsiString buf;

    /* каждая строка файла имеет вид:
       ДД.ММ.ГГГГ Т
       где: ДД.ММ.ГГГГ - дата; Т - температура */

    do
    {
        ls = GetString(h,&st); // дата
        if ( ls != 0)
        {
            nMonth = MonthOf (StrToDate(st)) - 1; // месяц
            buf = st;

            ls = GetString(h,&st); // температура
            temp = StrToFloat(st);
            if ( nMonth == ComboBox1->ItemIndex )
            {
                n++;
                sum = sum + temp;
                buf = buf + "   " + st;
                Memo1->Lines->Add(buf);
            }
        }
    } while ( ls != 0);

    FileClose(h);

    if ( n != 0 )
    {
        sred = sum / n;
        Label1->Caption = "Среднее значение: " +
                     FloatToStrF(sred,ffGeneral,3,2);
    }
    else
        Label1->Caption = "В БД нет информации о температуре за " +
                    ComboBox1->Text;
}

// пользователь выбрал другой месяц
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
    Label1->Caption = "";
    Memo1->Text = "";
}

// Функция GetString читает из файла строку символов
// от текущей позиции до первого пробела.
// значение функции - кол-во прочитанных символов
int GetString(int f, AnsiString *st)
{
    unsigned char buf[256]; // строка (буфер)
    unsigned char *p = buf;  // указатель на строку

    int n;       // кол-во прочитанных байт (значение ф-и FileRead)
    int len = 0; // длина строки

    // удалить ведущие пробелы
    do
        n = FileRead(f, p, 1);
    while ((n != 0) && (*p == ' '));

    while (( n != 0 ) && ( *p != ' '))
    {
        if ( *p == '\r')
        {
            n = FileRead(f, p, 1); // прочитать '\n'
            break;
        }
        len++;
        p++;
        n = FileRead(f, p, 1);
    }

    *p = '\0';
    if ( len !=0 )
        st->printf("%s", buf);
    return len;
}

// Функция GetLine читает из файла строку символов
// от текущей позиции до символа "новая строка".
// значение функции - кол-во прочитанных символов
int GetLine(int f, AnsiString *st)
{
    unsigned char buf[256]; // строка (буфер)
    unsigned char *p = buf;  // указатель на строку

    int n;       // кол-во прочитанных байт (значение ф-и FileRead)
    int len = 0; // длина строки

    n = FileRead(f, p, 1);
    while ( n != 0 )
    {
        if ( *p == '\r')
        {
            n = FileRead(f, p, 1); // прочитать '\n'
            break;
        }
        len++;
        p++;
        n = FileRead(f, p, 1);
    }

    *p = '\0';
    if ( len !=0)
        st->printf("%s", buf);
    return len;
}
