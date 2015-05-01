//---------------------------------------------------------------------------

#ifndef ShowAVI_1H
#define ShowAVI_1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
        // ����������
        TAnimate *Animate1;          // ������������ ����������� ��������
        TRadioButton *RadioButton1;  // �������� ���� ��������
        TRadioButton *RadioButton2;  // ���������� ��������
        TButton *Button1;            // ������ ����/����
        TButton *Button2;            // ������ ��������� ����
        TButton *Button3;            // ������ ���������� ����
        TLabel *Label1;
        TEdit *Edit1;                // ��� AVI-����
        TButton *Button4;            //������ ����� (��������� ������ Open File)
        TOpenDialog *OpenDialog1;    //������ Open File

    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall RadioButton1Click(TObject *Sender);
    void __fastcall RadioButton2Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
private:
        int CFrame; // ����� �����, ������������� � ������
                    // ����������� ��������� 
public:
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
