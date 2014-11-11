/*
   Очистка диска.
   Программа удаляет ненужные, созданные в процессе компиляции
   проектов C++Builder, файлы (obj, tds) и резервные
   копии (~bpr, ~dfm, ~h, ~cpp) из указанного пользователем
   каталога и его подкаталогов.
   Для выбора каталога используется стандартное
   окно Обзор папок.

*/

#include <vcl.h>
#pragma hdrstop

#include "ClearMain.h"



#pragma package(smart_init)
#pragma resource "*.dfm"

TMainForm *MainForm;

__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
}

#include <FileCtrl.hpp> // для доступа к SelectDirectory

AnsiString aDirectory; // каталог, который выбрал пользователь
                      //  (в котором находятся проекты C++Builder)

AnsiString cDir;      // текущий каталог
AnsiString FileExt;   // расширение файла

int n = 0;            // количество удаленных файлов

// Щелчок на кнопке Обзор (выбор каталога)
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
    if ( SelectDirectory("Выберите каталог","", aDirectory))
    {
        // диалог Выбор файла завершен щелчком на OK
        Label3->Caption = aDirectory;
        Button2->Enabled = true; // теперь кнопка Выполнить доступна
    };
}

// удаляет ненужные файлы из текущего каталога и его подкаталогов
void __fastcall Clear(void)
{

   TSearchRec SearchRec; // информация о файле или каталоге

   cDir = GetCurrentDir()+"\\";

   if ( FindFirst("*.*", faArchive,SearchRec) == 0)
       do {
            // проверим расширение файла
            int p = SearchRec.Name.Pos(".");
            FileExt = SearchRec.Name.SubString(p+1,MAX_PATH);
            if ( ( FileExt[1] == '~') || ( FileExt == "obj" ) ||
                 ( FileExt == "tds" ) )
            {
                  MainForm->Memo1->Lines->Add(cDir+SearchRec.Name);
                  DeleteFile(SearchRec.Name);
                  n++;
            }
        }
        while ( FindNext(SearchRec) == 0);

       // обработка подкаталогов текущего каталога
       if ( FindFirst("*", faDirectory, SearchRec) == 0)
          do
              if ((SearchRec.Attr & faDirectory) == SearchRec.Attr )
              {
                    // каталоги ".." и "." тоже каталоги,
                    // но в них входить не надо !!!
                    if (( SearchRec.Name != "." ) && (SearchRec.Name != ".."))
                    {
                         ChDir(SearchRec.Name); // войти в подкаталог
                         Clear();               // очистить каталог
                         ChDir("..");           // выйти из каталога

                    };
               }
          while ( FindNext(SearchRec) == 0 );
}

// щелчок на кнопке Выполнить
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
    Memo1->Clear();       // очистить поле Memo1
    ChDir(aDirectory);    // войти в каталог, который выбрал пользователь

    Clear();              // очистить текущий каталог и его подкаталоги

    Memo1->Lines->Add("");
    if (n)
        Memo1->Lines->Add("Удалено файлов: " + IntToStr(n));
     else
        Memo1->Lines->Add("В указанном каталоге нет файлов, которые надо удалить.");
}

