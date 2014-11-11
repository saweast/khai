#include <vcl.h>
#pragma hdrstop

#include "CDiagrForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

#include "Math.h" // для доступа к sin и cos

TForm1 *Form1;


#undef MOBY      // диаграмма "Рынок мобильных телефонов"
#undef PEOPLE    // диаграмма "Население земли"

#define ENERGY      // диаграмма "Источники энергии"

#ifdef MOBI
#define HB 5
#define OBR /* выполнить предварительную обработку
                    исходных данных (вычислить долю каждой категории
                    в общей сумме) */

                    // *** исходные данные ***
AnsiString Title = "Рынок мобильных телефонов";
float data[] = {38,55,30,20,25}; // значения по каждой категории
float pr[];  // доля категории в общей сумме (процент)

// *** подписи легенды ***
AnsiString dTitle[] = {"Samsung","Nokia","LG","Sony Ericson","Motorola"};

// *** цвет для каждой категории ***
TColor cl[] = {clLime, clNavy, clMaroon, clGreen, clYellow};
#endif

#ifdef PEOPLE
#define HB 6
#define OBR /* выполнить предварительную обработку
                    исходных данных (вычислить долю каждой категории
                    в общей сумме) */

// *** исходные данные ***
AnsiString Title = "Население земли";
float data[HB] = {1.25e9,1e9,274e6,216e6,172e6,146e6}; // значения по каждой категории
float pr[HB];  // доля категории в общей сумме (процент)

// *** подписи легенды ***
AnsiString dTitle[HB] = {"Китай","Индия","США","Индонезия","Бразилия","Россия"};

// *** цвет для каждой категории ***
TColor cl[HB] = {clLime, clBlue, clMaroon, clGreen, clYellow, clTeal};

#endif

#ifdef ENERGY
#define HB 6
#undef OBR /* предварительную обработку
             исходных данных выполнять не надо - сумма элементов
             массива data должна быть равна 100 */

// *** исходные данные ***
AnsiString Title = "Использование энергии";
float data[HB] = {0.5,2.5,7,23,24,40}; // значения по каждой категории
float pr[HB];  // доля категории в общей сумме (процент)

// *** подписи легенды ***
AnsiString dTitle[HB] = {"Другие","Гидро электростанции","Атомные электростанции",
                         "Газ","Уголь","Нефть"};

// *** цвет для каждой категории ***
TColor cl[HB] = {clLime, clBlue, clPurple, clSkyBlue, clYellow, clTeal};

#endif

#define R 80  // радиус диаграммы
#define D 160 // диаметр диаграммы

#define TORAD 0.0174532 // коэф пересчета угла из градусов в радианы
/* для пересчета величины угла из градусов в радианы,
   величину в градусах надо умножить на Pi/180 */

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    int i,j;
    // сортировка исходных данных методом "пузырька"
    float bd;
    AnsiString bt;
    TColor bc;
    for (i = 0; i < HB; i ++)
        for (j = 0; j < HB-1; j++)
            if (data[j+1] < data[j])
            {
                // обменять местами i-ый и i+1-ый элементы массива

                bd = data[j];
                data[j] = data[j+1];
                data[j+1] = bd;

                bt = dTitle[j];
                dTitle[j] = dTitle[j+1];
                dTitle[j+1] = bt;

                bc = cl[j];
                cl[j] = cl[j+1];
                cl[j+1] = bc;
            }

    #ifdef OBR
    // обработка данных - вычисление доли
    // каждой категории в общей сумме
    float sum = 0;
    for (i = 0; i < HB; i++)
        sum += data[i];

    for (i = 0; i < HB; i++)
        pr[i] = ( data[i] / sum) * 100;
    #else
        // исходные данные представлены в виде процентов
        for ( i = 0; i < HB; i++)
            pr[i] = data[i];

    #endif

}


// процедура обработки события Paint рисует диаграмму
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    int x,y;
    int i;

    // *** заголовок ***
    Canvas->Font->Name = "Tahoma";
    Canvas->Font->Size = 12;
    x = (ClientWidth - Canvas->TextWidth(Title)) /2;
    Canvas->Brush->Style = bsClear;
    Canvas->TextOutA(x,15,Title);


    // *** круговая диаграмма ***

    // здесь x,y - координаты левого верхнего угла
    // прямоугольника, в который вписан круг, из которого
    // вырезается сектор
    x = (ClientWidth - D) /2 - R;
    y = 15 + Canvas->TextHeight(Title) + 20;


    int x0,y0; // центр сектора (круга)
    int x1,y1; // координата точки начала дуги
    int x2,y2; // координата точки конца дуги
    int a1,a2; // угол между осью OX и прямыми, ограничивающими сектор

//    int n;     // количество категорий (секторов)
//    n = sizeof(data) / sizeof(float);

    x0 = x + R;
    y0 = y + R;

    a1 = 0; // первый сектор откладываем от оси OX

    //Canvas->Pen->Style = psClear;
    for (int i = 0; i < HB; i++ )
    {
        /* из-за ошибок округления возможна
           ситуация, когда между первым и последним
           секторами будет небольшой промежуток или
           последний сектор перекроет первый.
           Чтобы этого не было, зададим что граница
           последнего сектора совпадает с прямой OX */
        if (i != HB-1)
            a2 = ( a1 + 3.6 * pr[i]);
        else
            a2 = 359;

        // координата точки начала дуги
        x1 = x0 + R * cos (a2 * TORAD);
        y1 = y0 + R * sin (a2 * TORAD);

        // координата точки конца дуги
        x2 = x0 + R * cos (a1 * TORAD);
        y2 = y0 + R * sin (a1 * TORAD);

        if ( abs(a1-a2) <= 6 )
            Canvas->Pen->Style = psClear;
        else
            Canvas->Pen->Style = psSolid;

        Canvas->Brush->Color = cl[i];
        Canvas->Pie(x,y,x+D,y+D,x1,y1,x2,y2);

        a1 =a2; // следующий сектор рисуем от начала текущего
    }

    // легенда
    Canvas->Font->Size -= 2;
    int dy = Canvas->TextHeight("a");
    x = x + D + 40;
    y = y + 20;
    for (i =HB-1; i >=0; i--)
    {
        Canvas->Brush->Color = cl[i];
        Canvas->Rectangle(x,y,x+40,y+dy);

        Canvas->Brush->Style = bsClear;
        Canvas->TextOutA(x+50,y,dTitle[i]+
                 ", " + FloatToStrF(pr[i],ffGeneral,2,2) + "%");
        y = y + dy +10;
    }
}

void __fastcall TForm1::FormResize(TObject *Sender)
{
    Form1->Refresh();
}

