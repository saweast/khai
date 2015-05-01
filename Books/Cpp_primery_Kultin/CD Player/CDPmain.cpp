/*
   Полнофункциональный проигрыватель CD дисков.
   Контролирует наличие диска в дисководе и его тип.
   Демонстрирует использование компонента MediaPlayer.

*/

#include <vcl.h>
#pragma hdrstop

#include "CDPmain.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// картинки для кнопки Play/Stop
Graphics::TBitmap *bmPlay;   // Play
Graphics::TBitmap *bmStop;   // Stop

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    bmPlay   = new Graphics::TBitmap();
    bmStop   = new Graphics::TBitmap();

    // загрузить картинки для кнопки Play/Stop
    bmPlay->LoadFromResourceID((int)HInstance,101);
    bmStop->LoadFromResourceID((int)HInstance,102);
    // отобразить картинку
    SpeedButton2->Glyph->Assign(bmPlay);

    MediaPlayer->Notify = true; // разрешить событие Notify
}
// эти макросы обеспечивают перевод интервала времени
// выраженного в миллисекундах в минуты и секунды
#define MINUTE(ms) ((ms/1000)/60)
#define SECOND(ms) ((ms/1000)%60)

// выводит в поле Label1 информацию о текущем треке
void __fastcall TForm1::TrackInfo()
{
    int ms; // время звучания трека, мсек
    AnsiString st;

    Track  =  MCI_TMSF_TRACK(MediaPlayer->Position);

    MediaPlayer->TimeFormat = tfMilliseconds;
    ms = MediaPlayer->TrackLength[Track];
    MediaPlayer->TimeFormat = tfTMSF;

    st = IntToStr(SECOND(ms));
        if ( st.Length() == 1)
            st = "0" + st;

    st = "Трек "+ IntToStr(Track) +
         ". Длительность "+ IntToStr(MINUTE(ms)) + ":" + st;


    Label1->Caption = st;
}

// изменение состояния плеера
void __fastcall TForm1::MediaPlayerNotify(TObject *Sender)
{
  switch ( MediaPlayer->Mode )
  {
    case mpOpen: // пользователь открыл дисковод
    {
        SpeedButton1->Enabled  =  false;
        SpeedButton2->Glyph->Assign(bmPlay);
        SpeedButton2->Tag  =  0;
        SpeedButton3->Enabled  =  false;
        Label2->Caption  =  "00:00";

        /* по сигналу от таймера будем проверять
           состояние дисковода */
        Timer->Enabled  =  True;
    }
  }
  MediaPlayer->Notify  =  true;
}

// сигнал от таймера: вывести номер трека
// и время воспроизведения
void __fastcall TForm1::TimerTimer(TObject *Sender)
{
  int trk;          // трек
  int min, sec;     // время
  AnsiString st;

  if ( MediaPlayer->Mode == mpPlaying ) // режим воспроизведения
  {
    // получить номер воспроизводимого трека и
    trk  =  MCI_TMSF_TRACK(MediaPlayer->Position);

    if ( trk != Track ) // произошла смена трека
    {
      TrackInfo();
      Track  =  trk;
      if ( Track > 1 )
          SpeedButton1->Enabled  =  true;  // доступна кнопка "пред.трек"
      if ( Track == MediaPlayer->Tracks)
          SpeedButton3->Enabled  =  false; // кнопка "след.трек" недоступна
    }

    // вывод информации о воспроизводимом треке
    min  =  MCI_TMSF_MINUTE(MediaPlayer->Position);
    sec  =  MCI_TMSF_SECOND(MediaPlayer->Position);
    st.printf("%d:%.2d",min,sec);
    Label2->Caption = st;
    return;
  }

  // Если дисковод открыт или в нем нет
  // AudioCD, то Mode == mpOpen.
  // Ждем диск, т.е. до тех пор пока не будет Mode == mpStopped + кол-во треков > 1
  if ( (MediaPlayer->Mode == mpStopped) &&
     (MediaPlayer->Tracks > 1) )
  {
    // диск вставлен
    Timer->Enabled  =  false;
    SpeedButton2->Enabled = true;;
    SpeedButton2->Tag = 0;
    SpeedButton3->Enabled = true;
    MediaPlayer->Notify  =  true;

    // получить информацию о времени звучания CD
    MediaPlayer->TimeFormat = tfMilliseconds;

    int ms = MediaPlayer->Length;
    AnsiString st = "Audio CD. Время звучания: ";

    st = st +  IntToStr(MINUTE(ms));
    st = st + ":" + IntToStr(SECOND(ms));
    Label1->Caption  =  st;

    MediaPlayer->TimeFormat = tfTMSF;
    Label1->Visible  =  true;
    Track = 0;
    return;
  }

  // дисковод открыт или в дисководе не Audio CD
  if (( MediaPlayer->Mode == mpOpen )||
      (MediaPlayer->Mode == mpStopped) && (MediaPlayer->Tracks == 1))
  {
    Label1->Caption  =  "Вставьте Audio CD";
    if ( Label1->Visible )
          Label1->Visible  =  false;
    else  Label1->Visible  =  true;
  }
}

// пользователь закрыл окно программы
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    MediaPlayer->Stop();
    MediaPlayer->Close();
}

// предыдущий трек
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
MediaPlayer->Previous(); // в начало текущего трека
    MediaPlayer->Previous(); // в начало предыдущего трек
    if ( MCI_TMSF_TRACK(MediaPlayer->Position) == 1 )
      SpeedButton1->Enabled  =  false;
    if ( ! SpeedButton3->Enabled )
      SpeedButton3->Enabled  =  true;
    TrackInfo();
    Label2->Caption = "0:00";
}

// следующий трек
void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
  MediaPlayer->Next();
  // если перешли к последнему треку, то кнопку
  // Next сделать недоступной
  if ( MCI_TMSF_TRACK(MediaPlayer->Position) == MediaPlayer->Tracks )
    SpeedButton3->Enabled  =  false;
  if (! SpeedButton1->Enabled ) SpeedButton1->Enabled = true;
  TrackInfo();
  Label2->Caption = "0:00";
}

// щелчок на кнопке Play/Stop
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
if ( SpeedButton2->Tag == 0 ) {
    // щелчок на кнопке Play
    MediaPlayer->Play();
    SpeedButton2->Glyph->Assign(bmStop);
    SpeedButton2->Hint = "Стоп";
    SpeedButton2->Tag  =  1;
    //SpeedButton3->Enabled  =  true; // доступна кнопка "следующий трек"
    MediaPlayer->Notify  =  true;
    Timer->Enabled  = true;
    TrackInfo();
  }
  else {
    // щелчок на кнопке Stop
    SpeedButton2->Glyph->Assign(bmPlay);
    SpeedButton2->Hint = "Воспроизведение";
    SpeedButton2->Tag  =  0;
    MediaPlayer->Notify  =  true;
    MediaPlayer->Stop();
    Timer->Enabled  =  false;
  }
}

