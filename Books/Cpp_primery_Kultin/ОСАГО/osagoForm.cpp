/*
    Программа позволяет расcчитать
    тариф ОСАГО.
    Демонстрирует использование компонента ComboBox,
    обработку одной функцией событий от нескольких
    компонентов.

*/

#include <vcl.h>
#pragma hdrstop

#include "osagoForm.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

AnsiString reg[8] = {"Москва","Московская обл.","Санкт-Петербург",
                    "Нижний новгород","Ленинградская обл.","Ростов-наДону", "Самара",
                     "Мурманск"};

// коэф., учитывающий регион
float Kt [8] = {1.8,1.6, 1.8,1.3,1,1,1,1};

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    int i,n;
    n = sizeof (Kt) / sizeof (float);
    for (i=0; i<n; i++)
        ComboBox1->Items->Add(reg[i]);

    /* событие Change всех компонентов обрабатывает
       функция TForm1::Change */
    ComboBox1->OnChange = Change;
    ComboBox2->OnChange = Change;
    ComboBox4->OnChange = Change;
    ComboBox4->OnChange = Change;
    Edit1->OnChange = Change;
    Edit2->OnChange = Change;
    Edit3->OnChange = Change;
}


/* таблица определения коэффициента страхового тарифа
Первый год - 3й класс, второй год (если не было страховых
случаев) 4й класс и т.д.). Если страховой случай был,
то класс ячейка таблицы: строка - класс предыдущего
года, столбец - кол-во страховых случаев. */

// класс безаварийности
int Cb[6][5] = {
{1,-1,-1,-1,-1},
{2,-1,-1,-1,-1},
{3,1,-1,-1,-1},
{4,1,-1,-1,-1},
{5,2,1,-1,-1},
{6,3,1,-1,-1}};

// коэффициент безаварийности
float Kb[7] = {2.3, 1.55, 1.4, 1, 0.95, 0.9};

// щелчок на кнопке OK
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    float aTb;  // базовая ставка тарифа
    float aKt;  // коэф. тарифа
    float aKb;   // коэф. безаварийности
    float aKvs; // коэф. водительского стажа
    float aKo;  // коэф., учитывающий количество лиц, допущеных к управлению
    float aKm;  // коэф. мощности двигателя
    float aKs;  // коэф., учитывающий период использования ТС

    int pcb,ccb; // предыдущий и текущий класс безаваийности
    int nss;     // количество страховых случаев предыдущего периода


    aTb = StrToFloat(Edit3->Text);
    aKt = Kt[ComboBox1->ItemIndex];

    pcb = StrToInt(Edit1->Text);
    nss = StrToInt(Edit2->Text);
    ccb =   Cb[pcb][nss];
    if ( ccb != -1)
        aKb = Kb[ccb];
    else aKb = 2.45;

    // коэфф. водительского стажа
    switch (ComboBox2->ItemIndex)
    {
        case 0: aKvs = 1.3;  break;
        case 1: aKvs = 1.2;  break;
        case 2: aKvs = 1.15; break;
        case 3: aKvs = 1.0;  break;
    }

    // коэф., учитывающий количество лиц, допущеных к управлению
    if (CheckBox1->Checked)
        aKo = 1;
    else
        aKo = 1.5;

    // коэф. мощности двигателя
    switch (ComboBox3->ItemIndex)
    {
        case 0 : aKm = 0.5; break;
        case 1 : aKm = 0.7; break;
        case 2 : aKm = 1.0; break;
        case 3 : aKm = 1.3; break;
        case 4 : aKm = 1.5; break;
        case 5 : aKm = 1.7; break;
        case 6 : aKm = 1.9; break;
    }

    // коэф., учитывающий период использования ТС
    switch (ComboBox4->ItemIndex)
    {
        case 0 : aKs = 0.7; break;
        case 1 : aKs = 0.8; break;
        case 2 : aKs = 0.9; break;
        case 3 : aKs = 0.95; break;
        case 4 : aKs = 1.0; break;
    }

    // все коэффициенты определены

    float T; // тариф
    AnsiString st;

    T = aTb * aKt * aKb * aKvs * aKo * aKm *aKs;

    st = "Базовая ставка тарифа: " + FloatToStrF(aTb,ffCurrency,5,2)+
    "\nКоэф. тарифа: " + FloatToStrF(aKt,ffGeneral,2,2)+
    "\nКоэф. безаварийности: " + FloatToStrF(aKb,ffGeneral,2,2)+
    "\nKоэф. водительского стажа: " + FloatToStrF(aKvs,ffGeneral,2,2)+
    "\nКоэф. кол-ва лиц, допущеных к управлению: " + FloatToStrF(aKo,ffGeneral,2,2)+
    "\nКоэф. мощности двигател: " + FloatToStrF(aKm,ffGeneral,2,2)+
    "\nКоэф. периода использования ТС: " + FloatToStrF(aKs,ffGeneral,2,2)+
    "\n\nТариф: " + FloatToStrF(T,ffCurrency,5,2);

    ShowMessage(st);
}

// пользователь изменил состояние какого-либо из компонентов формы
void __fastcall TForm1::Change(TObject *Sender)
{
    Button1->Enabled =
        (ComboBox1->ItemIndex != -1) &&
        (ComboBox2->ItemIndex != -1) &&
        (ComboBox3->ItemIndex != -1) &&
        (ComboBox4->ItemIndex != -1) &&
        (Edit1->Text.Length() != 0) &&
        (Edit2->Text.Length() != 0) &&
        (Edit3->Text.Length() != 0);
}

