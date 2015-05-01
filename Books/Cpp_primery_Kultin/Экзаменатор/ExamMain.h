#ifndef ExamMainH
#define ExamMainH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Graphics.hpp>

// ������
struct TVopros {
    AnsiString Vopr;   // ������
    AnsiString Img;    // ����������� (��� BMP-�����)
    AnsiString Otv[4]; // �������� ������
    int        nOtv;   // ���-�� ��������� ������
    int        rOtv;   // ����� ����������� ������
};

// �����
class TForm1 : public TForm
{
__published:  // IDE-managed Components
    TLabel *Label1;   // �������������� ���������, ������
    TImage *Image1;   // ����������� � �������
    TButton *Button1; // ������ OK / ������
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);

private:
    TRadioButton *RadioButton[4];  // �������� ������ - ����������� ������
    void __fastcall RadioButtonClick(TObject *Sender); // ������ ������ ������ ������
    void __fastcall ShowVopros(TVopros v);  // ������� ������
    void __fastcall EraseVopros(void);      // ������� ������

public:
    __fastcall TForm1(TComponent* Owner);
};

extern PACKAGE TForm1 *Form1;



#endif
