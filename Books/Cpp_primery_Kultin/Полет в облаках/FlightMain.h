//---------------------------------------------------------------------------

#ifndef FlightMainH
#define FlightMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
    TTimer *Timer1;
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);

    private:
     Graphics::TBitmap *back;   // ���
     Graphics::TBitmap *sprite; // �������� - �������
     Graphics::TBitmap *kadr;   // ���� - �������� ����, �� ������� �������� �����������
     int x,y; // ��������� ������� - ����� ������� ���� ��������

public:
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;

#endif
