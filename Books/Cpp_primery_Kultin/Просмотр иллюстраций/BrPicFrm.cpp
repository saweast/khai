/*
    Просмотр иллюстраций.
    Программа демонстрирует использование компонентов
    ListBox, OpenDialog а также функций FindFirst и FindeNext
    для формирования списка файлов.
*/

#include <vcl.h>
#pragma hdrstop

#include "BrPicFrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

#include <jpeg.hpp>      // обеспечивает работу с иллюстрациями в формате JPEG

AnsiString aPath;      // каталог, в котором находится иллюстрация
TSearchRec aSearchRec; // рез-т поиска файла

// конструктор
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    Image1->Proportional = true;
    if ( FindFirst(aPath+ "*.jpg", faAnyFile, aSearchRec) == 0)
    {
       ListBox1->Items->Add(aSearchRec.Name);
       while ( FindNext(aSearchRec) == 0 )  // найти след. иллюстрацию
       {
           ListBox1->Items->Add(aSearchRec.Name);
       }

       // отобразить первую иллюстрацию
       ListBox1->ItemIndex = 0;
       Label1->Caption = ListBox1->Items->Strings[0];
       Image1->Picture->LoadFromFile(aPath + ListBox1->Items->Strings[0]);
    }
}

// щелчок в строке компонента ListBox
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
    int n = ListBox1->ItemIndex; // номер выбранного эл-та списка
    Label1->Caption = ListBox1->Items->Strings[n];
    Image1->Picture->LoadFromFile(aPath + ListBox1->Items->Strings[n]);
}

// щелчок на кнопке Выбор
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
    if ( OpenDialog1->Execute() )
    {
        // пользователь выбрал файл
        ListBox1->Clear(); // очистить список

        aPath = ExtractFilePath(OpenDialog1->FileName);
        Form1->Caption = "Просмотр иллюстраций - " + aPath;
        if ( FindFirst(aPath+ "*.jpg", faAnyFile, aSearchRec) == 0)
        {
            ListBox1->Items->Add(aSearchRec.Name);
            while ( FindNext(aSearchRec) == 0 )  // найти след. иллюстрацию
            {
                ListBox1->Items->Add(aSearchRec.Name);
            }

         // определим позицию выбранного пользователем файла
         // в списке ListBox и отобразим его
         int n = ListBox1->Items->
            IndexOf(ExtractFileName(OpenDialog1->FileName));
         ListBox1->ItemIndex = n;
         Label1->Caption = ListBox1->Items->Strings[n];
         Image1->Picture->LoadFromFile(aPath + ListBox1->Items->Strings[n]);
        }

    }
}

