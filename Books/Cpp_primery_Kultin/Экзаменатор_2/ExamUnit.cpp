/*
  Универсальная программа тестирования "Экзаменатор".
  Демонстрирует использование компонента XMLDocument (Файл теста - XML документ).
  Имя файла теста передается в программу через параметр командной строки.

  Тест представляет собой узел test
  "дети" этого узла: head, description, qw и levels

*/

#include <vcl.h>
#pragma hdrstop

#include "ExamUnit.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

int nQuery = 0; // всего вопроов
int nRight;     // правильных ответов

int Right;      // правильный ответ
int Sel;        // ответ, выбранный испытуемым

static int mode = 0; // 0 - начало работы программы (вывести первый вопрос)
                     // 1 - процесс тестирования
                     // 2 - тестирование завершено

// начало работы
void __fastcall TForm1::FormActivate(TObject *Sender)
{

    if (ParamCount() == 0) {
        Label1->Caption = "В командной строке надо указать имя файла теста";
        mode = 2;
        return;
    }

    XMLDocument1->FileName = ParamStr(1);
    try
    {
        // открыть XML документ
        XMLDocument1->Active = True;
    }
    catch  (EDOMParseError &e)
   {
        Label1->AutoSize = True;
        Label1->Caption = "Ошибка доступа к файлу теста " +
                          ParamStr(1) +
                          "\nMessage: " + e.Message;
        mode = 2;
        return;
    }

    Form1->Info(); // вывести информацию о тесте
}


// считывает и выводит вопрос с указанным номером
int __fastcall TForm1::Qery(int i)
{

    // привести форму в исходное состояние
    RadioButton1->Visible = False;
    RadioButton2->Visible = False;
    RadioButton3->Visible = False;
    RadioButton4->Checked = True;
    Button3->Enabled = False;


    // настроить интерфейс на работу с узлом qw
     _di_IXMLNode qw = XMLDocument1->DocumentElement->ChildNodes->Nodes[WideString("qw")];
     if ( i > qw->ChildNodes->Count -1 )
     {
        return -1;
     };

     nQuery++; // количество вопросов

     // Узел q - это вопрос. Параметр text узла q - это текст вопроса
     // дети узла q - это альтернативные ответы
     _di_IXMLNode q = qw->ChildNodes->Nodes[i];
     /* Атрибут Text узла qw - это текст вопроса,
        атрибут right - номер правильного ответа */

     // вопрос
     Label1->AutoSize = false;
     Label1->Width = ClientWidth -20;
     Label1->Height = 150;
     Label1->Caption = q->GetAttribute(WideString("text"));
     Label1->AutoSize = true;

     Right = StrToInt( q->GetAttribute(WideString("right")));

     // узел "q" состоит из нескольких узлов "a" (альтернативных ответов)
     _di_IXMLNode a;
     int j = 0; // номер узла "a"
     while ( j < q->ChildNodes->Count )
     {
        a = q->ChildNodes->Nodes[j];
        switch ( j ) {
            case 0 : RadioButton1->Caption = a->Text;
                     RadioButton1->Top = Label1->Top + Label1->Height + 10;
                     RadioButton1->Visible = True; break;
            case 1 : RadioButton2->Caption = a->Text;
                     RadioButton2->Top = RadioButton1->Top + RadioButton1->Height + 10;
                     RadioButton2->Visible = True; break;
            case 2 : RadioButton3->Caption = a->Text;
                     RadioButton3->Top = RadioButton2->Top + RadioButton2->Height + 10;
                     RadioButton3->Visible = True; break;
        }
        j++;
     }
     return 0;
}

// информация о тесте
void __fastcall TForm1::Info()
{
   Form1->Caption = XMLDocument1->DocumentElement->ChildNodes->Nodes[WideString("head")]->Text;
   Label1->Caption = XMLDocument1->DocumentElement->ChildNodes->Nodes[WideString("description")]->Text;
}


// щелчок на кнопке OK
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    static int i = 0;    // номер вопроса
    int r;               // результат вывода вопроса: -1 - вопросов больше нет

    switch ( mode) {
        case 0:
                r = Qery(i++);
                mode = 1;
                break;

        case 1:
                // проверим, правильный ли ответ выбрал испытуемый
                if ( Sel == Right) nRight++;
                // вывести следующий вопрос
                r = Qery(i++);
                if ( r == -1 ) { // больше вопросов нет

                    // результат тестирования
                    Result();

                    Button3->Enabled = True;
                    mode = 2;
                }
                break;

        case 2: Form1->Close(); // завершить работу программы
      }
}

// вывести результат тестирования
void  __fastcall TForm1::Result()
{
    int i = 0;
    int score;
    _di_IXMLNode ls; // интерфейс доступа к узлу levels
    _di_IXMLNode l;  // интерфейс доступа к узлу level

    // считываем последовательно узлы level и сравниваем значение
    // параметра score с количеством правильных ответов
    ls = XMLDocument1->DocumentElement->ChildNodes->Nodes[WideString("levels")];
    while ( i < ls->ChildNodes->Count)
    {
        l = ls->ChildNodes->Nodes[i];
        score = StrToInt( l->GetAttribute(WideString("score")));
        if ( nRight >= score ) break;
        i++;
    }

    AnsiString mes;
    mes.printf("Экзамен закончен\n"
               "Всего вопросов: %i\n"
               "Правильных ответов: %i\n",
               nQuery,nRight);
    mes = mes + l->GetAttribute(WideString("text"));
    Label1->Width = Form1->ClientWidth - 20;
    Label1->Caption = mes;
}


// пользователь выбрал первый ответ
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
    Sel = 1;
    Button3->Enabled = True;
}

// пользователь выбрал второй ответ
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
    Sel = 2;
    Button3->Enabled = True;
}

// пользователь выбрал третий ответ
void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
    Sel = 3;
    Button3->Enabled = True;

}


