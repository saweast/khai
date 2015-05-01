//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RunLine2MainForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Graphics::TBitmap *banner;   // баннер - картинка загружается из ресурса

int x,y;    // координаты левого верхнего угла области вывода баннера
int pause;  // время (количество тактов таймера) приостановки движения баннера
int xp;     // координата приостановки движения банера
TColor bc;  // цвет фона баннера

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    banner = new Graphics::TBitmap();
    // загрузить баннер из ресурса
    banner->LoadFromResourceID((int)HInstance,101);
    bc = banner->Canvas->Pixels[0][0]; // цвет фона баннера
    x = Form1->ClientWidth; // баннер "выплывает" из-за правой границы окна
    y = 0;
    // вычислить координату X точки приостановки двидения баннера
    xp = (Form1->ClientWidth - banner->Width) / 2;
    if (xp < 0 ) xp = 0;
}

// сигнал от таймера
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if ( pause > 0 )
    {
        pause--;
        return;
    }

    Form1->Canvas->Draw(x,y,banner);
    //x--;
    if ( --x == xp)
    {
        pause = 100; // остановить движение банера на 100 тактов таймера
    }

    if ( x < - banner->Width)
        x = Form1->ClientWidth;

}

// обработка события Paint
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    TColor b,p;

    b = Canvas->Brush->Color; // сохранить текущий цвет кисти
    p = Canvas->Pen->Color;   // сохранить текущий цвет карандаша

    // закрасить область вывода банера цветом фона банера
    Canvas->Brush->Color = bc;
    Canvas->Pen->Color = bc;
    Canvas->Rectangle(0,0,ClientWidth,banner->Height);

    Canvas->Brush->Color = b; // восстановить цвет кисти
    Canvas->Pen->Color = p;   // восстановить цвет карандаша
}

// пользователь изменил размер формы
void __fastcall TForm1::FormResize(TObject *Sender)
{
    // вычислить координату X точки приостановки двидения баннера
    xp = (Form1->ClientWidth - banner->Width) / 2;
    if (xp < 0 ) xp = 0;
}

