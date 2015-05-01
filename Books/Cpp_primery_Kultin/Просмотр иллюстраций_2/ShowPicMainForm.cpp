/*
    Программа позволяет просматривать jpg-иллюстрации.
    Просмотр возможен "по кадрам" или в режиме слайд-шоу.

    Программа демонстрирует:
       - использование компонента Image для просмотра
         jpg и bmp иллюстраций;
       - использование функций FindFirst и FindNext;
       - доступ к стандартному окну Обзор папок.
*/

#include <vcl.h>
#pragma hdrstop

#include "ShowPicMainForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

#include <FileCtrl.hpp>  // для доступа к SelectDirectory
#include <jpeg.hpp>      // обеспечивает работу с иллюстрациями в формате JPEG

AnsiString aPath;      // каталог, в котором находится иллюстрация
TSearchRec aSearchRec; // рез-т поиска файла

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    aPath = ""; // текущий каталог - каталог, из которого запущена программа
    FirstPicture(); // показать картинку, которая есть в каталоге программы
}

// щелчок на кнопке Каталог
void __fastcall TForm1::Button1Click(TObject *Sender)
{
     if (SelectDirectory("Выберикте каталог, в котором находятся иллюстрации",
                     "",aPath) != 0 )
     {
        // пользователь выбрал каталог и щелкнул на OK
        aPath = aPath + "\\";
        if ( FirstPicture() )  // вывести иллюстрацию
            CheckBox1->Enabled = true;
        else
            Label1->Caption = "В каталоге " + aPath +
                      " нет jpg-иллюстраций." ;
     }
}

// вывести первую картинку и найти следующую
bool __fastcall TForm1::FirstPicture()
{
    Image1->Visible = false;   // скрыть компонент Image1
    Button2->Enabled = false;  // кнопка Дальше недоступна
    CheckBox1->Enabled = false;
    CheckBox1->Checked = false;
    Label1->Caption = "";
    if ( FindFirst(aPath+ "*.jpg", faAnyFile, aSearchRec) == 0)
    {
        Image1->Picture->LoadFromFile(aPath+aSearchRec.Name);
        Image1->Visible = true;
        Label1->Caption = aPath + aSearchRec.Name;
        if ( FindNext(aSearchRec) == 0 )  // найти след. иллюстрацию
        {
            // иллюстрация есть
            Button2->Enabled = true; // теперь кнопка Дальше доступна
            CheckBox1->Enabled = true;

            return true;
        }
    }
    return false;
}

// вывести текущую и найти следующую картинку
bool __fastcall TForm1::NextPicture()
{
    Image1->Picture->LoadFromFile(aPath+aSearchRec.Name);
    Label1->Caption = aPath + aSearchRec.Name;
    if ( FindNext(aSearchRec) != 0 )  // найти след. иллюстрацию
    {
        // иллюстраций больше нет
        Button2->Enabled = false;   // теперь кнопка Дальше недоступна
        CheckBox1->Enabled = false;
        return false;
    }
    return true;
}

// щелчок на кнопке Дальше
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    NextPicture();
}

// щелчок на переключателе "непрерывно"
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
    if ( CheckBox1->Checked)
        Timer1->Enabled = true;  // слайд-шоу
    else
        Timer1->Enabled = false; // по кадрам
}

// Сигнал от таймера - вывести следующую иллюстрацию
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if ( ! NextPicture())
        Timer1->Enabled = false;
}

