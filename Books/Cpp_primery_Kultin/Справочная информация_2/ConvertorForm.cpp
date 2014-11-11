/*
    ��������� ������������� ���� �� �������� � �����.
    ������������� ����� ���������� ���������� � ������� HTML Help 1.0.

    ����������� ���������� ���������� � ������� HTML Help 1.0
    ������������ ��������� ������� hh.exe

    ���� ���������� ���������� ������ ��������� � ��� �� �������� ��� � ���������,
    ��� � ��������� �������� Help.
*/

#include <vcl.h>
#pragma hdrstop

#include "ConvertorForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

/* ������� ������� � ���� "����". ���������
   ��������� ������� KeyDown ��������� ������������
   ������� ���� ������, � ��� ����� � ��������������
   (��� ������� �������������� ������� ������� KeyPress
   �� ���������) */
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_F1 )
     /* ����������� ���������� ����������
       ������������ ������� hh.exe, ��������
       � ������ Windows. ���� mappid ������
       ������������ ������ ���������� ����������. */
        WinExec("hh.exe -mapid 3 convertor.chm", SW_RESTORE);
}

// ������� ������� � ���� "����"
void __fastcall TForm1::Edit2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_F1 )
        WinExec("hh.exe -mapid 4 convertor.chm", SW_RESTORE);
}

// ������ �� ������ "�������"
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    WinExec("hh.exe -mapid 1 convertor.chm", SW_RESTORE);
}


// ������ �� ������ ��������
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	float usd; // ���� � ��������
    float k;   // ����
    float rub; // ���� � ������


    // ��������, ������� �� ������ � ���� ���� � ����
    if (((Edit1->Text).Length() == 0) || ((Edit2->Text).Length() == 0))
    {
    	MessageDlg("���� ������ ���� � ����",
        	mtInformation, TMsgDlgButtons() << mbOK, 0);
        if ((Edit1->Text).Length() == 0)
        	Edit1->SetFocus(); // ������ ����� ����
        else
        	Edit2->SetFocus(); // ������ ����� ����
        return;
    }

    // ���� �������� ������
    usd = StrToFloat(Edit1->Text);
    k = StrToFloat(Edit2->Text);

    // ����������
    rub = usd * k;

    // ����� ����������
    Label4->Caption = FloatToStrF(usd,ffGeneral,7,2) + "$ = " +
    			FloatToStrF(rub,ffGeneral,7,2) + " ���." ;

}

// ������� ������� � ���� ����
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
	// ��� ������������ ������� ������� �����, � ����������
    // ������ � ���� �������������� �� ��������

    // Key - ��� ������� �������
    // ��������, �������� �� ������ ����������
    if ((Key >= '0') && (Key <= '9')) //�����
    	return;

    // ���������� ���������� DecimalSeparator
    // �������� ������, ������������ � �������� �����������
    // ��� ������ ������� �����
    if (Key == DecimalSeparator)
    {
    	if ((Edit1->Text).Pos(DecimalSeparator) != 0)
        {
        	Key = 0; // ����������� ��� ������
        	return;
    	}
    }

    if (Key == VK_BACK) // ������� <Backspace>
    	return;

    if (Key == VK_RETURN) // ������� <Enter>
    {
    	Edit2->SetFocus();
        return;
    }

    // ��������� ������� ���������
    Key = 0; // �� ���������� ������
}

// ������� ������� � ���� ����
void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
	if ((Key >= '0') && (Key <= '9')) //�����
    	return;

    if (Key == DecimalSeparator)
    {
    	if ((Edit2->Text).Pos(DecimalSeparator) != 0)
        	Key = 0; // ����������� ��� ������
        return;
    }

    if (Key == VK_BACK) // ������� <Backspace>
    	return;

    if (Key == VK_RETURN) // ������� <Enter>
    {
    	Button1->SetFocus();// ������� � ������ ���������
        					// ��������� ������� ������� <Enter>
        					// ������������ ������� ���������� �����
        return;
    }

    // ��������� ������� ���������
    Key = 0; // �� ���������� ������
}

//������ �� ������ ���������
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Form1->Close(); // ������� ����� ����������
}




