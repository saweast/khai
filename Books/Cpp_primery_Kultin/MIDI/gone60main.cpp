/*
   ѕрограмма демонстрирует использование компонента MediaPlayer
   дл€ воспроизведени€ MIDI-файла. ћелоди€ воспроизводитс€ "по кругу",
   до тех пор, пока пользователь не угадает число или не истечет врем€,
   отведенное на решение задачи.
*/

#include <vcl.h>
#pragma hdrstop

#include "gone60main.h"
#include "Math.hpp"

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;



__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

int pw;       // "секретное" число
int rem = 60; // остаток времени на выполнени€ задани€

// начало работы программы
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    TSearchRec sr;

    if ( FindFirst("*.mid",faAnyFile, sr) == 0)
    {
        MediaPlayer1->FileName = sr.Name;
        MediaPlayer1->Open();
        MediaPlayer1->Play();
    }

    Randomize();
    pw = RandomRange(100,999); // "секретное" число
}

// провер€ет, правильное ли число ввел игрок
void __fastcall TForm1::isRight(void)
{
    if ( StrToInt(Edit1->Text) == pw )
        {
            Timer1->Enabled = false;
            Button1->Enabled = false;
            Edit1->Enabled = false;
            MediaPlayer1->Stop();
            MediaPlayer1->Close();
            // аплодисменты!
            //PlaySound("Applause.wav",0, SND_ASYNC);
            ShowMessage("ѕоздравл€ю!\n¬ы угадали число за " +
                        IntToStr(60 - rem)+ " сек");
        }
}

// Ќажатие клавиши в поле редактировани€
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
    if ( ( Edit1->Text.Length() < 3) && ((Key >= '0') && (Key <= '9')))
        return;

    if ( Key == VK_RETURN)
    {
        isRight(); // проверить, правильное ли число ввел пользователь
        return;
    }

    if ( Key == VK_BACK) return;

    // остальные символы запрещены
    Key = 0;
}

// —одержимое пол€ редактировани€ изменилось
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
    // кнопка OK доступна только в том случае,
    // если в поле редактировани€ три символа (цифры)
    if ( Edit1->Text.Length() == 3)
        Button1->Enabled = true;
    else
        Button1->Enabled = false;
}

// щелчок на кнопке OK
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    isRight();  // проверить, правильное ли число ввел пользователь
}

// сигнал от таймера
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    rem--;
    Label4->Caption = IntToStr(rem);
    if (rem == 0 )
    {
        // врем€, отведенное на решение задачи истекло
        Timer1->Enabled = false;
        Edit1->Enabled = false;
        Button1->Enabled = false;

        MediaPlayer1->Stop();

        ShowMessage("  сожалению, ¬ы не справились с поставленной задачей\n"
                    "\"—екретное\" число - " + IntToStr(pw) );
    }
}

// состо€ние плеера изменилось
void __fastcall TForm1::MediaPlayer1Notify(TObject *Sender)
{
    /* ≈сли плеер воспроизводит файл и значение свойства Notify равно true
       (метод Play по умолчанию присваивает свойству Notify значение true),
       то в момент окончани€ воспроизведени€ возникает событие Notyfy */

    //ShowMessage("Notify" + IntToStr(MediaPlayer1->Mode) );
    if (Timer1->Enabled)
        /* ƒлительность мелодии меньше времени, отведенного
           на решение задачи. ѕроиграть еще раз. */
        MediaPlayer1->Play();
}

// завершение работы программы
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    Timer1->Enabled = false;
    MediaPlayer1->Stop();
    MediaPlayer1->Close();
}


