/*
    Программа работы с базой данных "Магазин".
    Формат базы данных - Paradox.
    База данных состоит из одной-единственной таблицы stock (stock.db).

    Доступ к базе банных осуществляется через BDE.

    Для доступа к базе данных необходимо при помощи BDE Administrator создать псевдоним stock (Type: Standard; Default Driver: Paradox).

    Структура таблицы stock.db
    --------------------------
     Поле     Тип     Размер
    --------------------------
     Title    A        50
     Price    $        -
     Memo     A        50
     Photo    A        30
    --------------------------

*/
#include <vcl.h>
#pragma hdrstop

#include "Stock_.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;



__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{

}

// начало работы программы
void __fastcall TForm1::FormShow(TObject *Sender)
{
    try
    {
        Table1->Open(); // открыть базу данных
    }
    catch ( EDBEngineError &e)
    {
        ShowMessage("Для доступа к базе данных надо создать псевдоним stock");
    }
}

// изменилось состояние набора данных
void __fastcall TForm1::DataSource1StateChange(TObject *Sender)
{
    if ( DataSource1->State == dsBrowse)
        StatusBar1->Panels->Items[1]->Text = "Просмортр";
    else
        StatusBar1->Panels->Items[1]->Text = "Редактирование";
}

// событие AfterScroll возникает после перехода к другой
// записи (смены текущей записи)
void __fastcall TForm1::Table1AfterScroll(TDataSet *DataSet)
{
    AnsiString Picture;
    if ( Table1->RecNo != -1)
    {
        StatusBar1->Panels->Items[0]->Text = "Запись: " + IntToStr(  Table1->RecNo );
        // Доступ к значению поля текущей записи можно получить
        // через свойство FieldValue.
        // Если поле Image пустое, то при попытке чтения из него
        // данных возникает ошибка.
        try {
            Picture =
                  Table1->Database->Directory + DataSet->FieldValues["Image"];
        }
        catch (EVariantTypeCastError &e) {
            Image1->Visible = false;
            return;
        }
        ShowPhoto(Picture);
    }
    else
    {
        StatusBar1->Panels->Items[0]->Text = "";
        StatusBar1->Panels->Items[1]->Text = "Новая запись";
        Image1->Visible = false;
    }
}

// отображает картинку в поле компонента Image1
void __fastcall TForm1::ShowPhoto(AnsiString Picture)
{

    try
    {
        Image1->Picture->LoadFromFile(Picture);
    }
    catch ( EFOpenError &e)
    {
        // ни чего не делаем, просто не отображаем картинку
        Image1->Visible = false;
        return;
    }
}

// завершение работы программы
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (Table1->State == dsEdit )
        // таблица в режиме редактирования
        Table1->Post(); // сохранить внесенные изменения
}



