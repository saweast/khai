/*
    ��������� �������������, ��� ��������� ������
    �� ����� � ��������� StringGrid � ���
    �������� ������ �� ��������� � ����.
    
*/

#include <vcl.h>
#pragma hdrstop

#include "spendingFrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    // *** ��������� ������� ***

    StringGrid1->Options
            << goEditing            // ��������� �������������
            << goTabs;              // <Tab> - ������� � ��������� ������

    // ��������� ��������
    StringGrid1->Cells[0][0] = "����";
    StringGrid1->Cells[1][0] = "�����";
    StringGrid1->Cells[2][0] = "�����������";

    // ������ ��������
    StringGrid1->ColWidths[0] = 70;
    StringGrid1->ColWidths[1] = 70;
    StringGrid1->ColWidths[2] = 200;

}

// ������� ������� � ������ �������
void __fastcall TForm1::StringGrid1KeyPress(TObject *Sender, char &Key)
{
    int cRow, cCol;
    if ( Key == VK_RETURN )
    {
        // ����������� ������ � ��������� ������
        cRow = StringGrid1->Row;
        cCol = StringGrid1->Col;
        if ( cCol < StringGrid1->ColCount - 1 )
            StringGrid1->Col = StringGrid1->Col + 1;
        else
            if ( cRow < StringGrid1->RowCount - 1 )
            {
                StringGrid1->Row = StringGrid1->Row + 1;
                StringGrid1->Col = 1;
            }
    }
}

// �������� ������
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    // �������� ������ � �������
    StringGrid1->Row = StringGrid1->RowCount-1;  // ������� � ��������� ������
    StringGrid1->RowCount++;                     // �������� ������
    StringGrid1->Row = StringGrid1->RowCount-1;  // ������� � ��������� ������
}


// ���������� ������ ���������
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    int f; // ���������� �����

      /* ���� ����� ������� � ������ fmCreate, �����, ����
       ���� ����������, �� ����� ������ ��� ������,
       ���� ����� ���, �� �� ����� ������ */

    if ( FileExists("tabl.grd") )
        f = FileOpen("tabl.grd",fmOpenWrite);
    else
       f = FileCreate("tabl.grd");

    if ( f != -1 )
    {
        // ��������� ������� � �����
        for (int i = 1; i < StringGrid1->RowCount; i++)
        {
             AnsiString st = StringGrid1->Rows[i]->DelimitedText +"\r\n";
             FileWrite(f,st.c_str(), st.Length());
        }
        FileClose(f);
    }

    else
        // ������ ������� � �����
        ShowMessage("O����� ������� � �����");
}



int GetLine(int f, AnsiString *st); // ������ ������ �� �����

// ��������� ������� �� �����
void __fastcall TForm1::FormActivate(TObject *Sender)
{
    int f;          // ���������� �����
    AnsiString st;  // ����������� ������
    bool fl = true; // true - ������ ������ ������

    if (( f = FileOpen("tabl.grd",fmOpenRead)) == -1 )
        return;

    // ���� ������

    // ��������� �������
    while ( GetLine(f, &st) != 0)
    {
        // �������� ������ � �������
        if ( fl )
        {
            StringGrid1->Rows[StringGrid1->Row]->DelimitedText = st;
            fl = false;
        }    
        else
        {
            StringGrid1->RowCount++;
            StringGrid1->Row = StringGrid1->RowCount-1;
            StringGrid1->Rows[StringGrid1->Row]->DelimitedText = st;
        }    
    }
    FileClose(f);
}

// ������ �� ����� ������ ��������
// �� ������� ������� �� ������� "����� ������"
// �������� ������� - ���-�� ����������� ��������
int GetLine(int f, AnsiString *st)
{
    unsigned char buf[256]; // ������ (�����)
    unsigned char *p = buf;  // ��������� �� ������

    int n;       // ���-�� ����������� ���� (�������� �-� FileRead)
    int len = 0; // ����� ������

    n = FileRead(f, p, 1);
    while ( n != 0 )
    {
        if ( *p == '\r')
        {
            n = FileRead(f, p, 1); // ��������� '\n'
            break;
        }
        len++;
        p++;
        n = FileRead(f, p, 1);
    }

    *p = '\0';
    if ( len !=0)
        st->printf("%s", buf);
    return len;
}



