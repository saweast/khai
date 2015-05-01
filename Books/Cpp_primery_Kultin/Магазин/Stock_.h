//---------------------------------------------------------------------------

#ifndef Stock_H
#define Stock_H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TTable *Table1;
    TDBGrid *DBGrid1;
    TDataSource *DataSource1;
    TDBEdit *DBEdit1;
    TDBEdit *DBEdit2;
    TDBMemo *DBMemo1;
    TImage *Image1;
    TStatusBar *StatusBar1;
    void __fastcall DataSource1StateChange(TObject *Sender);
    void __fastcall Table1AfterScroll(TDataSet *DataSet);
    void __fastcall ShowPhoto(AnsiString Photo);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);

private:

public:
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
