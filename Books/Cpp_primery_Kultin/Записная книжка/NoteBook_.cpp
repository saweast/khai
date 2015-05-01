/*

    Программа работы с базой данных "Записная книжка" (adrbk.db).
    Демонстрирует использование BDE-компонентов Table и Qery, а также
    компонентов DBGrid и DataSource.

    Программа работает с базой данных в режиме таблицы и позволяет просматривать,
    редактировать, добавлять и удалять записи, а также обеспечивает поиск информации
    по содержимому поля "Name".

    База данных "Записная книжка" (формат Paradox) состоит из аблицы adrbk.db

    Поле       Тип
    --------------------
    Name       Alpha
    Phone      Alpha
    Cell       Alpha
    Email      Alpha

    Создать таблицу adrbk.db можно при помощи Database Desktop

    Для доступа к файлу таблицы (adrbk.db) программа использует
    псевдоним adrbk (Type: STANDARD, DEFAULT DRIVER: PARADOX).
    Создать псевдоним можно при помощи BDEAdministrator или SQL Explorer.

*/

#include <vcl.h>
#pragma hdrstop

#include "NoteBook_.h"

// эта директива вставлена сюда вручную
#include "Find_.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
}

// начало работы программы
void __fastcall TMainForm::FormShow(TObject *Sender)
{
    // если псевдоним adrbk не зарегистрирован, возникает ошибка
    try
    {
        Table1->Open();
    }
    catch (EDBEngineError &e)
    {
        ShowMessage("Ошибка доступа к базе данных: не определе псевдоним adrbk\n" +
                     e.Message );

        Button2->Enabled = false;
        BitBtn1->Enabled = false;
        CheckBox1->Enabled = false;
    }
}

// щелчок на кнопке Поиск информации
void __fastcall TMainForm::BitBtn1Click(TObject *Sender)
{
       FindForm->Tag = 0;
       FindForm->ShowModal();  // отобразить окно Запрос
       if ( FindForm->Tag )
       {
           // пользователь закрыл окно Запрос
           // щелчком на кнопке OK, то есть он ввел
           // фамилию или имя
           Query1->SQL->Text =
                   "SELECT * FROM adrbk WHERE Name LIKE \042%" +
                                FindForm->Edit1->Text  +"%\042";

                   // \042 - это восьмеричный код двойной кавычки
           if ( CheckBox1->Checked )
                  ShowMessage (Query1->SQL->Text);

           Query1->Open(); // открыть (выполнить) запрос
            if ( Query1->RecordCount != 0)
                DataSource1->DataSet = Query1;
            else
            {
                ShowMessage ("В базе данных нет запрашиваемой информации: " +
                              FindForm->Edit1->Text);
                DataSource1->DataSet = Table1;
            }
       }
}

// щелчок на кнопке Все записи
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
    DataSource1->DataSet = Table1; // источник данных - таблица
}

// завершение работы программы
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    Table1->Close();
}




