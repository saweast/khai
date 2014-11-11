/*
    ��������� ������������� ���� �� �������� � �����.
    ������������� ����� ���������� ���������� � ������� WinHelp.

    ����������� ���������� ���������� � ������� WinHelp
    ������������ ��������� ������� winhlp32.exe

    ���� ���������� ���������� (conv.hlp) ������ ��������� � ��� �� �������� ��� � ���������,
    ��� � ��������� �������� Help.
*/

#include <vcl.h>
#pragma hdrstop

#include "ConvForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

// ������ �� ������ "�������"
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    WinExec("winhlp32.exe conv.hlp", SW_RESTORE);
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




