/*
    MP3 плеер с регулятором громкости.
    Демонстрирует работу с компонентом MediaPlayer.
    Картинки для кнопки Play/Stop загружаются из ресурса.

*/

#include <vcl.h>
#pragma hdrstop

#include "mp3main.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    /* Создать компонент MediaPlayer.
       Объявление MediaPlayer1 находится в объявлении
       формы (см. mp3main.h), там же находится ссылка
       на MPlayer.hpp (директива #include "MPlayer.hpp" ).
    */
    MediaPlayer1 = new TMediaPlayer(Form1->Handle);
}


#include "FileCtrl.hpp"  // для доступа к TSearchRec

AnsiString SoundPath; // путь к MP3 файлам
int min,sec;   // время воспроизведения (минуты, секунды)


int mode = 0;  // 0 - режим "Стоп"
               // 1 - режим "Воспроизведение"

/* Процедуре vaweOutSetVolume в качестве параметра
   передается двойное слово, старший байт которого
  определяет громкость левого канала, младший - правого.
  Определив таким образом тип TVolume, имеется возможноcть
  независимой регулировки громкости каждого канала.
  Максимальной громкости канала соответствует значение 0xFFFF.
*/
union TVolume{
          unsigned long Volume;
          struct
		    {
			    Word Left;
			    Word Right;
		    };
    } volume;

// начало работы программы
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    PlayList("");

    // установить движок регулятора громкости в соответствии
    // с текущем уровнем, установленным в системе
    waveOutGetVolume(0,&volume.Volume);
    TrackBar1->Position = - volume.Left;

    ListBox1->Color = (TColor)RGB(56,176,222);
}

// формирует список MP3 файлов, находящихся в указанном каталоге
void __fastcall TForm1::PlayList(AnsiString path)
{
    TSearchRec SearchRec;  // структура SearchRec содержит информацию
                           // о файле, удовлетворяющем условию поиска

    ListBox1->Clear();
    // сформировать список mp3 файлов
    if ( FindFirst(path + "*.mp3", faAnyFile, SearchRec) != 0 )
    {
        // в выбранном каталоге нет mp3-файлов
        SpeedButton2->Enabled = false;
        SpeedButton3->Glyph->LoadFromResourceID((int)HInstance,103);
        SpeedButton4->Enabled = false;
        Label1->Caption = "";
        return;
    }

    // в каталоге есть файл с расширением mp3
    // добавим имя этого файла в список
    ListBox1->Items->Add(SearchRec.Name);
    // пока в каталоге есть другие файлы с расширением WAV
    while (FindNext(SearchRec) == 0)
              ListBox1->Items->Add(SearchRec.Name);

    ListBox1->ItemIndex  =  0;
    Label1->Caption = ListBox1->Items->Strings [ListBox1->ItemIndex];
    SpeedButton2->Enabled = false;
    if (ListBox1->Count == 1)
        SpeedButton4->Enabled = false;
    else
        SpeedButton4->Enabled = true;
     SpeedButton3->Glyph->LoadFromResourceID((int)HInstance,101);    
}

// активизировать воспроизведение MP3 файла, имя которого
// выделено в списке ListBox
void __fastcall TForm1::Play()
{
    Label1->Caption = ListBox1->Items->Strings [ListBox1->ItemIndex];
    MediaPlayer1->FileName = SoundPath +
                               ListBox1->Items->Strings [ListBox1->ItemIndex];

    MediaPlayer1->Open();
    MediaPlayer1->Play();
    min = 0;
    sec = 0;
    Timer1->Enabled = true;
}

// остановить воспроизведение
void __fastcall TForm1::Stop()
{
    MediaPlayer1->Stop();
    Timer1->Enabled = false;
    Label2->Caption = "0";
    Label4->Caption = "00";
}

// щелчок на кнопке Play/Stop
// ( картинки для кнопок лучше загружать из ресурса )
void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
    if ( mode == 1 )
    {
        //SpeedButton3->Glyph->LoadFromFile("play_blue16.bmp");
        SpeedButton3->Glyph->LoadFromResourceID((int)HInstance, 101);
        SpeedButton3->Hint = "Воспроизведение";
        Stop();
        mode = 0;
    }
    else {
        //SpeedButton3->Glyph->LoadFromFile("stop_blue16.bmp");
        SpeedButton3->Glyph->LoadFromResourceID((int)HInstance, 102);
        SpeedButton3->Hint = "Стоп";
        Play();
        mode = 1;
    }
}

// сигнал от таймера
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    // индикация времени воспроизведения
    if ( sec < 59 )
    {
        sec++;
        if ( sec < 10)
            Label4->Caption = "0" + IntToStr(sec);
        else
            Label4->Caption = IntToStr(sec);
    }
    else
    {
        sec = 0;
        min++;
        Label2->Caption = IntToStr(min);
        Label4->Caption = "00";
    }

    // заваршено воспроизведение текущего файла?
    if ( MediaPlayer1->Position < MediaPlayer1->Length )
        // воспроизведение текущей композиции не завершено
        return;

    // воспроизведение текущей композиции завершено
    Stop();

    if ( ListBox1->ItemIndex < ListBox1->Count - 1 )
    {
         ListBox1->ItemIndex += 1;
         Play(); // активизировать воспроизведение следующего MP3 файла
         if ( ListBox1->ItemIndex == ListBox1->Count - 1 )
             SpeedButton4->Enabled = false;
    }
    else {
        // закончено воспроизведение последнего MP3 файла
        //SpeedButton3->Glyph->LoadFromFile("play_blue16.bmp");
        SpeedButton3->Glyph->LoadFromResourceID((int)HInstance, 101);
        SpeedButton3->Hint = "Воспроизведение";
        mode = 0;
    }
}

// щелчок на кнопке "К следующему файлу"
void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
    if ( mode == 1 )
        Stop();  // остановить воспроизведение текущей композиции

    ListBox1->ItemIndex += 1;
    Label1->Caption = ListBox1->Items->Strings [ListBox1->ItemIndex];

    // проверить и, если надо, изменить состояние
    // кнопок перехода к следующему и предыдущему файлу
    if ( ListBox1->ItemIndex == ListBox1->Count - 1)
        SpeedButton4->Enabled = false;

    if ( ! SpeedButton2->Enabled  )
        SpeedButton2->Enabled = true;

    if ( mode == 1)
        Play(); // активизировать воспроизведение следующей композиции
}

// щелчок на кнопке "К предыдущему файлу"
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
     if ( mode == 1 )
        Stop();  // остановить воспроизведение текущей композиции

     ListBox1->ItemIndex -= 1;
     Label1->Caption = ListBox1->Items->Strings [ListBox1->ItemIndex];

     // проверить и, если надо, изменить состояние
     // кнопок перехода к следующему и предыдущему файлу
     if ( ! SpeedButton4->Enabled )
        SpeedButton4->Enabled = true;

     if ( ListBox1->ItemIndex == 0 )
        SpeedButton2->Enabled = false;


     if (mode == 1 )
        Play(); // активизировать воспроизведение предыдущей композиции
}

#include "FileCtrl.hpp"

// щелчок на кнопке Eject - выбор каталога
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
    AnsiString dir;
    if ( SelectDirectory("Выберите каталог","",dir) )
    {
        if ( mode == 1) // режим "Воспроизведение"
        {
            Stop();
            //SpeedButton3->Glyph->LoadFromFile("play_blue16.bmp");
            SpeedButton3->Glyph->LoadFromResourceID((int)HInstance, 101);
            SpeedButton3->Hint = "Воспроизведение";
            Stop();
            mode = 0;
        }
        SoundPath = dir + "\\";
        PlayList(SoundPath);
    }
}

// щелчок на имени файла (композиции)
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
    if ( MediaPlayer1->Mode == 2) // плеер в режиме воспроизведения
    {
        Stop(); // остановить воспроизведение текущей композиции
        Play(); // активизировать воспроизведение выбранной композиции
    }

    // изменить, если надо, состояние кнопок
    // перехода к предыдущей и следующей композиции
    if (ListBox1->ItemIndex == 0 )
        SpeedButton2->Enabled = false;
    else
        SpeedButton2->Enabled = true;

    if (ListBox1->ItemIndex == ListBox1->Count -1  )
        SpeedButton4->Enabled = false;
    else
        SpeedButton4->Enabled = true;
}

#include "mmsystem.hpp"
// пользователь изменил положение регулятора громкости
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
    volume.Left = - TrackBar1->Position;
    volume.Right = - TrackBar1->Position;
    waveOutSetVolume(0,volume.Volume);
}

