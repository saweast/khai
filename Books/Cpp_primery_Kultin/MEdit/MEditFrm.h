//---------------------------------------------------------------------------

#ifndef MEditFrmH
#define MEditFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TToolBar *ToolBar1;
    TSpeedButton *SpeedButton1;
    TSpeedButton *SpeedButton2;
    TMainMenu *MainMenu1;
    TMenuItem *mFile;
    TMenuItem *mHelp;
    TMenuItem *imAbout;
    TMenuItem *imOpen;
    TMenuItem *imSave;
    TMenuItem *imExit;
    TMenuItem *mParam;
    TMenuItem *imToolBar;
    TRichEdit *RichEdit1;
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
    void __fastcall imToolBarClick(TObject *Sender);
    void __fastcall imOpenClick(TObject *Sender);

    void __fastcall imSaveClick(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall imExitClick(TObject *Sender);
    void __fastcall imAboutClick(TObject *Sender);

private:
    bool __fastcall SaveText();

public:
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
