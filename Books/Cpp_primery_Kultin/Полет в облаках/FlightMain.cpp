/*
   Мультипликация, элементы которой загружаются из bmp-файла.
   Очередной кадр формируется в памяти, а затем выводится
   на поверхность формы.

*/

#include <vcl.h>
#pragma hdrstop

#include "FlightMain.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    // загрузить фоновый рисунок из bmp файла
    back = new Graphics::TBitmap();
    back->LoadFromFile("sky.bmp");

    // установить размер клиентской (рабочей) области формы
    // в соответствии с размером фонового рисунка
    ClientWidth = back->Width;
    ClientHeight = back->Height;

    // загрузить картинку
    sprite =  new Graphics::TBitmap();
    sprite->LoadFromFile("plane.bmp");
    sprite->Transparent = true;

    // сформировать кадр
    kadr = new Graphics::TBitmap();
    kadr->LoadFromFile("plane.bmp");

    // исходное положение самолета
    x=-40; // чтобы самолет "вылетал" из-за левой границы окна
    y=20;

    Timer1->Interval = 10;
    Timer1->Enabled = true;

}

// сигнал от таймера
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    TRect badRect; // положение и размер области фона,
                   // которую надо восстановить

    TRect  frameRect;

    badRect = Rect(x,y,x+sprite->Width,y+sprite->Height);
    frameRect = Rect(0,0, kadr->Width, kadr->Height);

    #ifdef ONCANVAS
    // *** изображение формируем на поверхности формы ***

    // стереть самолет (восстановить "испорченный" фон)
    Canvas->CopyRect(badRect,back->Canvas,badRect);

    // вычислим новые координаты спрайта
    x +=2;
    if (x > ClientWidth)
    {
        // самолет улетел за правую границу формы
        // изменим высоту и скорость полета
        x = -20;
        y = random(ClientHeight - 30);  // высота полета
        // скорость полета определяется периодом возникновения
        // события OnTimer, который, в свою очередь, зависит
        // от значения свойства Interval
        Timer1->Interval = random(20) + 10; // скорость "полета" от 10 до 29
    }
    Canvas->Draw(x,y,sprite);

    #else
    //  изображение формируем на рабочей поверхности,
    // затем выводим на поверхность формы

    // сформировать очередной кадр

    // скопировать фрагмент фона
    kadr->Canvas->CopyRect(frameRect, back->Canvas,badRect);
    // нарисовать объект
    kadr->Canvas->Draw(0,0,sprite);

    // вывести кадр
    Form1->Canvas->Draw(x,y,kadr);

    // вычислим новые координаты спрайта
    x += 1;
    if (x > ClientWidth)
    {
        // самолет улетел за правую границу формы
        //   изменим высоту и скорость полета
        x = -20;
        y = random(ClientHeight - 30);  // высота полета
        // скорость полета определяется периодом возникновения
        // события OnTimer, который, в свою очередь, зависит
        // от значения свойства Interval
        Timer1->Interval = random(20) + 10; // скорость "полета" от 10 до 29
    }
    #endif
}

void __fastcall TForm1::FormPaint(TObject *Sender)
{
    // восстановить фоновый рисунок
    Canvas->Draw(0,0,back);    // фон
}

