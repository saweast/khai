/*
   Простой редактор текста.
   Демонстрирует использование компонентов RichEdit, MainMenu,
   ToolBar, SpeedButton, OpenDialog, SaveDialog.

   */

#include <vcl.h>
#pragma hdrstop

#include "MEditFrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

// ссылка на модуль формы "О программе" вставлене вручную
#include "about.h"

TForm1 *Form1;
AnsiString aFileName; // имя редактируемого файла


// конструктор формы
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    aFileName = "";

    /* Задать функцию обработки события Click для
       кнопок панели инструментов
       Внимание! Сначала надо создать функции обработки
       события Click для команд Файл/Открыть и Файл/Сохранить,
       затем - вставить в текст следующие две инструкции. */
    SpeedButton1->OnClick = imOpenClick;
    SpeedButton2->OnClick = imSaveClick;
}

// сохранить текст в файле
bool __fastcall TForm1::SaveText()
{
    // значение функции SaveText равно false, если
    // в окне Сохранить пользовательсделал щелчок на кнопке Отменить
    if ( aFileName == "" )
    {
        // получить у пользователя имя файла
        //SaveDialog1->FileName = "Text.txt";
        SaveDialog1->Options << ofPathMustExist << ofOverwritePrompt;
        if ( SaveDialog1->Execute() )
             aFileName = SaveDialog1->FileName;
        else
           return false; // пользователь закрыл окно щелчком на кнопке "Отменить"
    }

    RichEdit1->Lines->SaveToFile(aFileName); // записать текст в файл
    return true;
}

// команда Файл/Открыть
void __fastcall TForm1::imOpenClick(TObject *Sender)
{
    int r;

    // если текст изменен, то его надо сохранить
    if ( RichEdit1->Modified )
    {
        // текст изменен
        r = MessageDlg("Текст был изменен.\nСохранить изменения?",
                    mtWarning, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);

        if ( r == mrCancel )
            // в окне сообщения пользователь щелкнул на кнопке Cancel
            return;

        // здесь пользователь выбрал Yes
        if ( ( r == mrYes ) && ( ! SaveText() ))
              return;
    }

    // открыть файл
    OpenDialog1->FileName = "*.txt";
    OpenDialog1->Options << ofPathMustExist << ofFileMustExist;

    if ( OpenDialog1->Execute() )
    {
        RichEdit1->Lines->LoadFromFile(OpenDialog1->FileName);
        RichEdit1->Modified = false;
        Form1->Caption = "MEdit - " +  OpenDialog1->FileName;
        aFileName = OpenDialog1->FileName;
    }
}

// команда Файл/Сохранить
void __fastcall TForm1::imSaveClick(TObject *Sender)
{
    // записать текст в файл
    if ( SaveText() )
    {
        RichEdit1->Modified = false;
        Form1->Caption = "MEdit - " + aFileName;
    }
}

// команда Файл/Выход
void __fastcall TForm1::imExitClick(TObject *Sender)
{
     Form1->Close();
     /* возникает событие FormCloseQuery,
        функция которого проверяет, внесены ли
        изменеия в текст */
}

// пользователь сделал щелчок на кнопке "Закрыть окно"
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    int r;
    if ( RichEdit1->Modified ) // текст изменен
    {
        r = MessageDlg("Текст был изменен.\nСохранить изменения?",
                    mtWarning, TMsgDlgButtons() << mbYes << mbNo << mbCancel, 0);

        switch ( r )
        {
            case mrYes : // пользователь щелкнул на кнопке Yes
                if ( ! SaveText() )
                    CanClose = false;  // окно не закрывать
                break;

            case mrCancel : // пользователь щелкнул на кнопке Cancel
                    CanClose = false; // продолжить работу с текстом
        }
     }
}

// команда Параметры/Панель инструментов
void __fastcall TForm1::imToolBarClick(TObject *Sender)
{
    // скрыть/отобразить панель инструментов
    ToolBar1->Visible = ! ToolBar1->Visible;

    // поставить/убрать "галочку" в меню Параметры/Панель инструментов
    imToolBar->Checked = ! imToolBar->Checked;
}

// команда Справка/О программе
void __fastcall TForm1::imAboutClick(TObject *Sender)
{
    TAboutForm *AboutForm;
     // свойству Position формы AboutForm надо присвоить значение poOwnerForm
    AboutForm = new TAboutForm (this);
    AboutForm->ShowModal();
    delete AboutForm;
}

