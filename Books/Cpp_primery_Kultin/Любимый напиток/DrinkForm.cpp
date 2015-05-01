/*
    Программа демонстрирует использование
    компонента ComboBox. Списки компонентов
    ComboBox2 и ComboBox3 формируются в начале
    работы программы. Пользователь может добавить
    элемент в список компонента ComboBox3 только
    в том случае, если такого элемента в списке нет.

*/
#include <vcl.h>
#pragma hdrstop

#include "DrinkForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    // сформировать список компонента ComboBox3
    ComboBox2->Sorted = true; // список упорядочен
    ComboBox2->Items->Add("Кока-Кола");
    ComboBox2->Items->Add("Меринда");
    ComboBox2->Items->Add("Пепси-Кола");
    ComboBox2->Items->Add("Спрайт");
    ComboBox2->Items->Add("Фанта");

    // сформировать список компонента ComboBox3
    ComboBox2->Sorted = true; // список упорядочен
    ComboBox3->Items->Add("Чай");
    ComboBox3->Items->Add("Чай с лимоном");
    ComboBox3->Items->Add("Кофе черный");
    ComboBox3->Items->Add("Кофе со сливками");
    ComboBox3->Items->Add("Какао");
}

// выбор элемента в списке ComboBox1
void __fastcall TForm1::ComboBox1Click(TObject *Sender)
{
    Label1->Caption = ComboBox1->Text;
}

// щелчок на элементе списка компонента ComboBox2
void __fastcall TForm1::ComboBox2Click(TObject *Sender)
{
    Label2->Caption = ComboBox2->Items->Strings[ComboBox2->ItemIndex];
}

// щелчок на элементе списка компонента ComboBox3
void __fastcall TForm1::ComboBox3Click(TObject *Sender)
{
    Label3->Caption = ComboBox3->Items->Strings[ComboBox3->ItemIndex];
}

// нажатие клавиши в поле редактирования компонента ComboBox2
void __fastcall TForm1::ComboBox2KeyPress(TObject *Sender, char &Key)
{
    if  (Key == VK_RETURN)
    {
         // Пользователь ввел в поле редактирования строку
         // и нажал <Enter>. Добавим строку в список.

         int n = ComboBox2->Items->Add(ComboBox2->Text);
         ComboBox2->ItemIndex = n;

         Label2->Caption = ComboBox2->Items->Strings[n];
    }
}

// нажатие клавиши в поле редактирования компонента ComboBox3
void __fastcall TForm1::ComboBox3KeyPress(TObject *Sender, char &Key)
{
     AnsiString st;  ///строка, которую ввел пользователь
                     // в поле редактирования компонента ComboBox

    if  (Key == VK_RETURN)
    {
         // Пользователь ввел в поле редактирования строку
         // и нажал <Enter>. Если такой строки в списке нет,
         // добавим ее в список

         st = ComboBox3->Text.Trim(); // удалить пробелы

         if ( ComboBox3->Items->IndexOf(st) == -1 )
         {
            // добавить
            int n = ComboBox3->Items->Add(st);
            ComboBox3->ItemIndex = n;

            Label3->Caption = ComboBox3->Items->Strings[n];
         }
    }
}

