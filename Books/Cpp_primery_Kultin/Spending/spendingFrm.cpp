/*
    Программа демонстрирует, как загрузить данные
    из файла в компонент StringGrid и как
    записать данные из компоента в файл.
    
*/

#include <vcl.h>
#pragma hdrstop

#include "spendingFrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    // *** настроить таблицу ***

    StringGrid1->Options
            << goEditing            // разрешить редактировать
            << goTabs;              // <Tab> - переход к следующей ячейке

    // заголовки столбцов
    StringGrid1->Cells[0][0] = "Дата";
    StringGrid1->Cells[1][0] = "Сумма";
    StringGrid1->Cells[2][0] = "Комментарий";

    // ширина столбцов
    StringGrid1->ColWidths[0] = 70;
    StringGrid1->ColWidths[1] = 70;
    StringGrid1->ColWidths[2] = 200;

}

// нажатие клавиши в ячейке таблицы
void __fastcall TForm1::StringGrid1KeyPress(TObject *Sender, char &Key)
{
    int cRow, cCol;
    if ( Key == VK_RETURN )
    {
        // переместить курсор в следующую ячейку
        cRow = StringGrid1->Row;
        cCol = StringGrid1->Col;
        if ( cCol < StringGrid1->ColCount - 1 )
            StringGrid1->Col = StringGrid1->Col + 1;
        else
            if ( cRow < StringGrid1->RowCount - 1 )
            {
                StringGrid1->Row = StringGrid1->Row + 1;
                StringGrid1->Col = 1;
            }
    }
}

// добавить строку
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    // добавить строку в таблицу
    StringGrid1->Row = StringGrid1->RowCount-1;  // перейти к последней строке
    StringGrid1->RowCount++;                     // добавить строку
    StringGrid1->Row = StringGrid1->RowCount-1;  // перейти к последней строке
}


// завершение работы программы
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    int f; // дескриптор файла

      /* файл можно открыть в режиме fmCreate, тогда, если
       файл существует, он будет открыт для записи,
       если файла нет, то он будет создан */

    if ( FileExists("tabl.grd") )
        f = FileOpen("tabl.grd",fmOpenWrite);
    else
       f = FileCreate("tabl.grd");

    if ( f != -1 )
    {
        // сохранить таблицу в файле
        for (int i = 1; i < StringGrid1->RowCount; i++)
        {
             AnsiString st = StringGrid1->Rows[i]->DelimitedText +"\r\n";
             FileWrite(f,st.c_str(), st.Length());
        }
        FileClose(f);
    }

    else
        // ошибка доступа к файлу
        ShowMessage("Oшибка доступа к файлу");
}



int GetLine(int f, AnsiString *st); // читает строку из файла

// загружает таблицу из файла
void __fastcall TForm1::FormActivate(TObject *Sender)
{
    int f;          // дескриптор файла
    AnsiString st;  // прочитанная строка
    bool fl = true; // true - чтение первой строки

    if (( f = FileOpen("tabl.grd",fmOpenRead)) == -1 )
        return;

    // файл открыт

    // загрузить таблицу
    while ( GetLine(f, &st) != 0)
    {
        // добавить строку в таблицу
        if ( fl )
        {
            StringGrid1->Rows[StringGrid1->Row]->DelimitedText = st;
            fl = false;
        }    
        else
        {
            StringGrid1->RowCount++;
            StringGrid1->Row = StringGrid1->RowCount-1;
            StringGrid1->Rows[StringGrid1->Row]->DelimitedText = st;
        }    
    }
    FileClose(f);
}

// читает из файла строку символов
// от текущей позиции до символа "новая строка"
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



