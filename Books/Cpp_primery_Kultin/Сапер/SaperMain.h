#ifndef SaperMainH
#define SaperMainH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>

class TMain : public TForm
{
__published:
    TMainMenu *MainMenu1;
    // ������� �������� ����
    TMenuItem *N1; // ����� ����
    TMenuItem *N2; // ������� "?"
    // ������� ���� "?"
    TMenuItem *N3; //  �������
    TMenuItem *N4; //  � ���������

    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);

    // ����� ������� � ����
    void __fastcall N1Click(TObject *Sender); // ����� ����
    void __fastcall N3Click(TObject *Sender); // �������
    void __fastcall N4Click(TObject *Sender); // � ���������

private:
    void __fastcall ShowPole(int status); // ���������� ����
    void __fastcall Kletka (int row, int col, int status); // ���������� ���������� ������
    void __fastcall Mina (int x, int y);   // ������ ����
    void __fastcall Flag( int x, int y);   // ������ ����

public:
    __fastcall TMain(TComponent* Owner);
};

extern PACKAGE TMain *Main;

#endif
