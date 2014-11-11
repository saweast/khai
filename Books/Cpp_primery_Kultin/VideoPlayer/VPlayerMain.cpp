/*
   Простой видеоплеер. Демонстрирует использование:
     - компонента MediaPlayer для воспроизведения
       видео роликов (формат AVI, MPG);
     - компонента SpeedButton.

   Змаечание. Если окно программы, когда воспроизведение клипа закончено,
   перекрыть другим окном, то кадр будет испорчен. Чтобы этого не было,
   надо написать функцию обработки события Paint для формы.
*/

#include <vcl.h>
#pragma hdrstop

#include "VPlayerMain.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

// эти макросы обеспечивают перевод интервала времени
// выраженного в миллисекундах в минуты и секунды
#define MINUTE(ms) ((ms/1000)/60)
#define SECOND(ms) ((ms/1000)%60)

// картинки для кнопок
Graphics::TBitmap *bmPlay;   // Play
Graphics::TBitmap *bmPause;  // Pause

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    bmPlay   = new Graphics::TBitmap();
    bmPause   = new Graphics::TBitmap();

    // загрузить картинки для кнопки Play/Stop
    bmPlay->LoadFromResourceID((int)HInstance,101);
    bmPause->LoadFromResourceID((int)HInstance,102);
    // отобразить картинку
    SpeedButton2->Glyph->Assign(bmPlay);
    MediaPlayer1->Display = Form1;
}

// возвращает размер кадра
void __fastcall GetFrameSize(AnsiString f, int *w, int *h)
{
    if ( f.Pos(".avi") == 0 )
    {
        // пользователь выбрал mpg-файл
        *w = 352;
        *h = 240;
        return;
    }

    // *** Пользователь выбрал AVI-файл ***
    // В заголовке AVI файла есть информация о размере кадра
    struct  {
        char     RIFF[4]; // строка RIFF
        long int nu_1[5]; // не используется
        char     AVIH[4]; // строка AVIH
        long int nu_2[9]; // не используется
        long int w;       // ширина кадра
        long int h;       // высота кадра
    } header;

    TFileStream *fs;   // поток, для чтения заголовка файла

    /* операторы объявления потока и его создания
    можно объединить: TFileStream *fs = new TFileStream(f,fmOpenRead); */

    fs = new TFileStream(f,fmOpenRead);   // открыть поток для чтения
    fs->Read(&header, sizeof(header));    // прочитать заголовок файла
    *w = header.w;
    *h = header.h;
    delete fs;
}

// щелчок на кнопке Eject (выбор видео клипа)
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
    int fw, fh;   // размер кадра клипа
    int top,left; // левый верхний угол экрана
    int sw, sh;   // размер экрана (ширина, высота)

    int mw, mh;   // максимально возможный размер экрана
                  // (определяется текущим размером формы)

    float kw, kh; // коэф-ты масштабирования кадра по ширине и высоте
    float k;      // коэффициент масштабирования кадра


    OpenDialog1->Title = "Выбор клипа";
    OpenDialog1->InitialDir = "";
    OpenDialog1->Filter =
        "Все форматы|*.avi;*.mpg;*.mpeg|"
        "AVI|*.avi|MPG|*.mpg|MGEG|*.mpeg";

    if ( ! OpenDialog1->Execute() )
        return; // пользователь нажал кнопку Отмена

     /* При попытке открыть файл клипа, который уже открыт,
       возникает ошибка. */

    if ( MediaPlayer1->FileName == OpenDialog1->FileName )
        return;

    /* Пользователь выбрал клип. Зададим размер и положение "экрана",
       на котором будет выведен клип. Для этого надо знать размер
       кадров клипа. */


    GetFrameSize(OpenDialog1->FileName,&fw, &fh);// получить размер кадра

    // вычислим максимально возможный размер кадра
    mw = Form1->ClientWidth;
    mh = Form1->Panel1->Top-10;

    if ( fw < mw)
       kw = 1; // кадр по ширине меньше размера экрана
    else kw = (float) mw / fw;

    if ( fh < mh)
       kh = 1; // кадр по высоте меньше размера экрана
    else kh = (float) mh / fh;

    // масштабирование должно быть пропорциональным
    if ( kw < kh)
        k = kw;
    else k = kh;

   // здесь масштаб определен
   sw = fw * k; // ширина экрана
   sh = fh * k; // высота экрана

   left = (Form1->ClientWidth - sw) / 2;
   top = (Panel1->Top - sh) / 2;

   MediaPlayer1->FileName = OpenDialog1->FileName;

   MediaPlayer1->Open();
   MediaPlayer1->DisplayRect = Rect(left,top,sw,sh);
    /* если размер кадра выбранного клипа меньше размера
       кадра предыдущего клипа, то экран (область формы)
       надо очистить */
   Form1->Canvas->FillRect(Rect(0,0,ClientWidth,Panel1->Top));

   SpeedButton2->Enabled = True; // кнопка Play теперь доступна

   // вывести информацию о времени воспроизведения
   MediaPlayer1->TimeFormat = tfMilliseconds;
   int ms = MediaPlayer1->Length;
   AnsiString st = IntToStr(SECOND(ms));
   if ( st.Length() == 1)
        st = "0" + st;
   st = IntToStr(MINUTE(ms)) + ":" + st;
   Label1->Caption = st;
   Label3->Caption = "0:00";

   // активизируем процесс воспроизведения
   SpeedButton2->Glyph->Assign(bmPause);
   SpeedButton2->Hint = "Pause";
   SpeedButton2->Tag = 1;
   SpeedButton1->Enabled = False; // кнопка Eject недоступна
   MediaPlayer1->Play();
   Timer1->Enabled = true;
}

// щелчок на кнопке Play/Stop (воспроизведение/стоп)
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
    if (SpeedButton2->Tag == 0)
    {
        // нажата кнопка Play
        SpeedButton2->Glyph->Assign(bmPause);
        SpeedButton2->Hint = "Pause";
        SpeedButton2->Tag = 1;
        SpeedButton1->Enabled = False; // кнопка Eject недоступна
        MediaPlayer1->Play();
        Timer1->Enabled = true;
    }
    else  // нажата кнопка Stop
    {
        MediaPlayer1->Stop();
        SpeedButton2->Glyph->Assign(bmPlay);
        SpeedButton2->Hint = "Play";
        SpeedButton2->Tag = 0;
        SpeedButton1->Enabled = True; // кнопка Eject доступна
        Timer1->Enabled = false;
    }
}

// сигнал от плеера
void __fastcall TForm1::MediaPlayer1Notify(TObject *Sender)
{
    if ( ( MediaPlayer1->Mode == mpStopped ) && ( SpeedButton2->Tag == 1))
    {
        Timer1->Enabled = false;
        SpeedButton2->Glyph->Assign(bmPlay);
        SpeedButton2->Hint = "Play";
        SpeedButton2->Tag = 0;
        SpeedButton1->Enabled = True; // сделать доступной кнопку Eject
    }
}

/* Процедура обработки события Pain обеспечивает
   отображение (перерисовку) первого кадра,
   при появлении окна, например, после того,
   как пользователь отодвинет другое окно, перекрывающее
   окон Video Player. */
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    if ( MediaPlayer1->Mode == mpStopped )
    {
        MediaPlayer1->Position = 1;
        MediaPlayer1->Position = 0;
    }
}


// завершение работы программы
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    MediaPlayer1->Close();
}

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   // вывести информацию о времени воспроизведения
//   MediaPlayer1->TimeFormat = tfMilliseconds;
   int ms = MediaPlayer1->Position;
   AnsiString st = IntToStr(SECOND(ms));
   if ( st.Length() == 1)
        st = "0" + st;
   st = IntToStr(MINUTE(ms)) + ":" + st;
   Label3->Caption = st;
}

