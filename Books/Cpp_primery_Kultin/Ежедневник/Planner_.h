//---------------------------------------------------------------------------

#ifndef Planner_H
#define Planner_H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <DBClient.hpp>
#include <ADODB.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TDataSource *DataSource1;
    TDBGrid *DBGrid1;
    TDBNavigator *DBNavigator1;
    TButton *Button1;
    TButton *Button2;
    TButton *Button3;
    TButton *Button4;
    TLabel *Label1;
    TLabel *Label2;
    TCheckBox *CheckBox1;
    TADOConnection *ADOConnection1;
    TADODataSet *ADODataSet1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall ShowSQL(void);
    void __fastcall FormShow(TObject *Sender);
  
private:	// User declarations

public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
