 /*
   Программа демонстрирует создание компонентов во время работы программы.
   Кнопки калькулятора - это объединенные в массив компоненты SpeedButton.
*/

#include <vcl.h>
#pragma hdrstop

#include "sCalcForm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

float ac;  // аккумулятор (первый операнд)
int op;    // операция
int fd;    /* fd == 0 - ждем первую цифру числа, например, после
              того, как была нажата клавиша "+";
              fd = 1 - ждем ввода следующей цифры или
              нажатия клавиши операции */

#define WBTN  35  // ширина кнопки
#define HBTN  20  // высота кнопки
#define DXBTN  6  // шаг кнопок по X
#define DYBTN  6  // шаг кнопок по Y


// текст на кнопке
Char btnText[] = "789+456-123=00.c";

#define CM -1  // запятая
#define EQ -2  // "="
#define PL -3  // "+"
#define MN -4  // "-"
#define CL -5  // "C"

// идентификатор кнопки
int  btnTag[]  = {7,8,9,PL,4,5,6,MN,1,2,3,EQ,0,0,CM,CL};

//  конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    int left, top; // положение кнопки

    top = 48;

    int k = 0; // индекс массива btn
    for ( int i = 0; i < 4; i++ )  // четыре ряда кнопок
    {
        left = 8;
        for ( int j = 0;  j < 4; j++) // по четыре в каждом ряду
        {
            btn[k] = new TSpeedButton(Form1);
            btn[k]->Parent = Form1; // "посадить" кнопку на форму
            // настройка кнопки
            btn[k]->Left = left;
            btn[k]->Top = top;
            btn[k]->Width = WBTN;
            btn[k]->Height = HBTN;
            //btn[k]->Flat = true;
            btn[k]->Font->Color = clNavy;

            btn[k]->Caption = btnText[k]; // текст на кнопке
            btn[k]->Tag = btnTag[k];      // идентификатор кнопки

            // задать процедуру обработки события Click
            btn[k]->OnClick = btnClick; // см. объявление в h-файле формы

            k++;
            left = left + WBTN+ DXBTN;
         }
         top = top + HBTN + DYBTN;
    }
    // объединить две кнопки "0" (btn[12] и btn[13]) в одну
    btn[13]->Visible = false;
    btn[12]->Width = 2* WBTN + DXBTN;

    op = EQ;
}

// Щелчок кнопке btn[i]
// ( одна процедура для всех кнопок )
void __fastcall TForm1::btnClick(TObject *Sender)
{
    TSpeedButton *btn;
    int id; // идентификатор нажатой кнопки

    btn = (TSpeedButton*)Sender;

    // свойство Tag кнопки содержит ее идентификатор
    id = btn->Tag;

    // ShowMessage ( IntToStr(btn->Tag) );

    // кнопка "1" .. "9"
    if ( id > 0 ) {
        if ( fd == 0 ) {
            StaticText1->Caption = btn->Tag;
            fd = 1;
        }
        else
            StaticText1->Caption = StaticText1->Caption + btn->Tag;
        return;
    }

   // кнопка "0"
   if ( id == 0) {
        if ( StaticText1->Caption != "0" )
            StaticText1->Caption = StaticText1->Caption + btn->Tag;
        return;
   }

   // кнопка ","
   if ( id == CM) {
        if ( StaticText1->Caption.Pos(",") == 0 ) {
            StaticText1->Caption = StaticText1->Caption + ",";
            fd = 1;
        }
        return;
   }

   // кнопка "c"
   if ( id == CL) {
     ac = 0;
     id = EQ;
     fd = 0;
     StaticText1->Caption = 0;
     return;
  }

   // остальные кнопки: "+", "-"  и "="
   float op2; // операнд (число на индикаторe)
   op2 = StrToFloat(StaticText1->Caption);

   /* так как нажата клавиша операции, то это значит,
      что надо выполнить предыдущую операцию, код которой
      находится в переменной op */
   switch (op) {
        case EQ : ac = op2;  break;
        case PL : ac = ac + op2; break;
        case MN : ac = ac - op2; break;
    }
    StaticText1->Caption = FloatToStrF(ac,ffGeneral,15,6);

   op = id;  // запомнить текущую операцию
   fd = 0;    // ждем новое число
}

// деструктор формы
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    // уничтожить компоненты, созданные программой
    for ( int i = 0; i < 16; i++)
        delete btn[i];
}


