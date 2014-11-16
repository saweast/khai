/*
    Программа работы с базой данных "Ежедневник".
    Комплексный пример. Демонстрирует использование
    компонентов ADOConnection, ADODataSet, DataSource, Table и DBNavigator.


    База данных Ежедневник (Planer.mdb) представляет собой
    базу данных в формате Microsoft Access (Microsoft JET),
    которая состоит из одной единственной таблицы schedule.
    Таблица schedule, в свою очередь, состоит из двух столбцов
    aDate (тип DATETIME) и aTask (строковый, 50 символов).

    Для того стобы программа могла работать с базой
    данных, база данных должна быть зарегистрирована в системе
    как источник данных ODBC под именем dplanner.

    Регистрация:
    1. Пуск/Настройка/Панель управления/Администрирование/Источники данных
    2. Add
    3. Драйвер: Microsoft Access Driver (*.mdb)
    4.1 Имя источника данных: dPlaner
    4.2 Описание: Ежедневник
    4.3 База данных: Planner.mdb

*/

#include <vcl.h>
#pragma hdrstop

#include "Planner_.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

#include <DateUtils.hpp>
#include <ComObj.hpp>  // для доступа к EOleException

AnsiString stDay[7] = {"воскресенье","понедельник","вторник", "среда",
                           "четверг","пятница","суббота"};

AnsiString stMonth[12] = {"января","февраля","марта",
                          "апреля","мая","июня","июля",
                          "августа","сентября","октября",
                          "ноября","декабря"};


void __fastcall TForm1::FormShow(TObject *Sender)
{
        TDateTime Today,    // сегодня
              NextDay;  // следующий день (не обязательно завтра)

    Word  Year, Month, Day; // год, месяц, день

    Today = Now ();

    DecodeDate(Today, Year, Month, Day);

    Label1->Caption = "Сегодня " + IntToStr(Day) + " " +
                       stMonth[Month-1] + " " +
                       IntToStr(Year) + " года, " +
                       stDay[DayOfWeek(Today) -1];

    Label2->Caption = "Сегодня и ближайшие дни";

    // вычислим следующий день
    // если сегодня пятница, то, чтобы не забыть
    // что запланировано на понедельник, считаем, что следующий
    // день - понедельник
    switch ( DayOfWeek(Today) ) {
        case 6  : NextDay = Today + 3; break; // сегодня пятница
        case 7  : NextDay = Today + 2; break; // сегодня суббота
        default : NextDay = Today + 1; break;
    }

      ADODataSet1->CommandText =
          "SELECT * FROM schedule WHERE aDate BETWEEN DateValue('" +
          FormatDateTime("dd/mm/yyyy",Today) + "') AND DateValue('" +
          FormatDateTime("dd/mm/yyyy",NextDay) + "') ORDER BY aDate";

     // если надо, отобразить SQL-команду
     if ( CheckBox1->Checked) ShowSQL();

     // если БД не зарегистрирована как источник данных ODBC,
     // возникает исключение EOleException

     try
     {
     ADODataSet1->Open(); // открыть набор данных (выполнить
                           // SQL-команду ADODataSet1->CommandText
     }

     catch ( EOleException &e)
     // чтобы тип EOleException был доступен, в программу
     // надо поместить директиву #include <ComObj.hpp>
     {

        ShowMessage ("Ошибка обращения к БД. База данных Planner.mdb должна"
                      "быть зарегистрирована\nв системе как источник данных ODBC "
                      "под именем dplaner");

        Button1->Enabled = false;
        Button2->Enabled = false;
        Button3->Enabled = false;
        Button4->Enabled = false;
        return;
     }

     if ( ! ADODataSet1->RecordCount )
        ShowMessage("На сегодня и ближайшие дни ни каких дел не запланировано.");
}

// Щелчок на кнопке Сегодня
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    AnsiString today = FormatDateTime("dd/mm/yyyy",Now());

    Form1->Label2->Caption = "Сегодня";

    ADODataSet1->Close(); // закрыть набор данных

    // изменить критерий запроса
    ADODataSet1->CommandText =
         "SELECT * FROM schedule WHERE aDate = DateValue('" + today +"')";

    if ( CheckBox1->Checked) ShowSQL(); // отобразить запрос

    ADODataSet1->Open(); // открыть набор данных с новым запросом
}

// щелчок на кнопке Завтра
void __fastcall TForm1::Button2Click(TObject *Sender)
{

    AnsiString tomorrow = FormatDateTime("dd/mm/yyyy", Now() +1 );

    Label2->Caption = "Завтра";

    ADODataSet1->Close();

    // изменить критерий запроса
    ADODataSet1->CommandText =
       "SELECT * FROM schedule WHERE aDate = DateValue('" +
                         tomorrow + "')";

    if ( CheckBox1->Checked) ShowSQL();

    ADODataSet1->Open();  // выполнить запрос

    if ( ! ADODataSet1->RecordCount )
    {
        ShowMessage("На завтра ни каких дел не запланировано!");
    }
}

// щелчок на кнопке На этой неделе
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  // "эта неделя" - от текущего дня до конца недели (до воскресенья)
  TDateTime Present, eWeek;

  Label2->Caption = "На этой неделе";

  Present= Now(); // Now - возвращает текущую дату


  eWeek = EndOfAWeek(YearOf(Present),WeekOf(Present));

  /*
    для доступа к StartOfWeek, EndOfAWeek, YearOf и WeekOf
    надо подключить DateUtils.hpp (см. директивы #include )
  */

  ADODataSet1->Close();

  ADODataSet1->CommandText =
         " SELECT * FROM schedule WHERE aDate BETWEEN DateValue('" +
              FormatDateTime("dd/mm/yyyy",Present)+ "') AND DateValue('" +
              FormatDateTime("dd/mm/yyyy",eWeek)+"') ORDER BY aDate";

  if ( CheckBox1->Checked) ShowSQL();

  ADODataSet1->Open();

  if ( ! ADODataSet1->RecordCount )
        ShowMessage("На эту неделю ни каких дел не запланировано.");
}

//  Щелчок на кнопке Все
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    ADODataSet1->Close();

    ADODataSet1->CommandText = "SELECT * FROM schedule ORDER BY aDate";
    if ( CheckBox1->Checked) ShowSQL();

    ADODataSet1->Open();

    Label2->Caption = "Все, что намечено сделать";
}

// отображает SQL-команду
void __fastcall TForm1::ShowSQL(void)
{
    ShowMessage ( ADODataSet1->CommandText );
}



//---------------------------------------------------------------------------

