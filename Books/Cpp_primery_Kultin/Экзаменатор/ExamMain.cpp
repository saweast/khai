/* ������������� ��������� ������������. ���� �����������
   �� �����, ��� �������� ������ ���� ������� � ���������
   ������.
   ��������� ������������� �������� � ��������� �����������
   �� ����� ������ ���������.
*/

#include <vcl.h>
#pragma hdrstop

#include "ExamMain.h"
#include <stdio.h>     // ��� ������� � ������� sscanf
#include <jpeg.hpp>    // ������������ ������ � jpg-�������������

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1  *Form1;   // �����

int f;            // ���������� ����� �����
                  // ��� ����� ����� ����� �� ��������� ������

int level[4];     // ���-�� ���������� �������, ����������� ��� ���������� ������
AnsiString mes[4];// ��������� � ���������� ������

TVopros Vopros;   // ������
int otv;          // ����� ���������� ������

int right = 0;    // ���-�� ���������� �������

// �������, �������������� ������ ������� �� ����� �����
int GetInt(int f);                     // ������ �����
int GetString(int f, AnsiString *st);  // ������ ������


// �����������
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    int i;
    int left = 10;

    // �������� ����������� ��� ������
    // ����������� ������, �� ������� �� ����������
    for (i = 0; i < 4; i++ )
    {
        // �������� �����������
        RadioButton[i] = new TRadioButton(Form1);
        // ��������� �������� �������
        RadioButton[i]->Parent = Form1;
        RadioButton[i]->Left = left;
        RadioButton[i]->Width = Form1->ClientWidth - left - 20;
        RadioButton[i]->Visible = false;
        RadioButton[i]->Checked = false;

        // ������� ������� ��������� ������� Click
        RadioButton[i]->OnClick = RadioButtonClick;
    }
}

void __fastcall TForm1::FormActivate(TObject *Sender)
{
    AnsiString st;

    // ��� ����� ����� ������ ���� ������� � ��������� ������
    int n = ParamCount();
    if (  n < 1 )
    {
        Label1->Font->Style = TFontStyles()<< fsBold;
        Label1->Caption = "� ��������� ������ ������� ��������� ���� ������ ��� ����� �����";
        Button1->Tag = 2;
        return;
    }

    // ������� ���� �����
    f = FileOpen(ParamStr(1), fmOpenRead);
    if ( f == -1 )
    {
            Label1->Font->Style = TFontStyles()<< fsBold;
            Label1->Caption =
               "������ ������� � ����� ����� " + ParamStr(1);
            Button1->Tag = 2;
            return;
    }

    //  ������� ���������� � �����
    GetString(f, &st); // ��������� �������� �����
    Form1->Caption = st;

    GetString(f, &st); // ��������� ������� ����������
    Label1->Width = Form1->ClientWidth - Label1->Left -20;
    Label1->Caption = st;
    Label1->AutoSize = true;

    // ��������� ���������� �� ������� ������
    for (int i=0; i<4; i++)
    {
        level[i] = GetInt(f);
        GetString(f, &mes[i]);
    }
}

// ������ �� ����� ��������� ������
bool GetVopros(TVopros *v)
{
    AnsiString st;
    int p;   // ���� p=1, �� � ������� ���� �����������

    if ( GetString(f, &(v->Vopr)) != 0 )
    {
        // ��������� ���-�� ��������� ������, ����� ����������� ������
        // � ������� ������� �����������
        v->nOtv = GetInt(f);
        v->rOtv = GetInt(f);
        p       = GetInt(f);

        if (p) // � ������� ���� �����������
            GetString(f,&(v->Img) );
        else v->Img = "";

        // ������ �������� ������
        for (int i = 0; i < v->nOtv; i++)
        {
            GetString(f,&(v->Otv[i]));
        }
        return true;
    }
    else return false;
}

// ������� ������
void __fastcall TForm1::ShowVopros(TVopros v)
{
    int top;
    int i;

    // ������
    Label1->Width = ClientWidth - Label1->Left -20;
    Label1->Caption = v.Vopr;
    Label1->AutoSize = true;

    if (v.Img != "") // � ������� ���� �����������
    {
       /* ��������� ������ �������, ������� �����
          ������������ ��� ������ ����������� */
       int RegHeight =  Button1->Top
           - (Label1->Top + Label1->Height +10) // ������� ������ �������
           - (RadioButton[1]->Height + 10) * v.nOtv;

        Image1->Top = Label1->Top + Label1->Height + 10;
        // �������� �������� � ��������� �� ������
        Image1->Visible = false;
        Image1->AutoSize = true;
        Image1->Picture->LoadFromFile(v.Img);
        if (Image1->Height > RegHeight) // �������� �� ����������
        {
            Image1->AutoSize = false;
            Image1->Height = RegHeight;
            Image1->Proportional = true;
        }
        Image1->Visible = true;
        // ��������� ����� ����������� �� �����������
         top = Image1->Top + Image1->Height + 10;
    }
    else // ��������� ����� ����������� �� �������
         top = Label1->Top + Label1->Height + 10;

    // �������� ������
    for (i = 0; i < v.nOtv; i++)
    {
        RadioButton[i]->Top = top;
        RadioButton[i]->Caption = v.Otv[i];
        RadioButton[i]->Visible = true;
        RadioButton[i]->Checked = false;
        top += 20;
    }
}

// ������ �� ������������ ������ ������
void __fastcall TForm1::RadioButtonClick(TObject *Sender)
{
    int i =0;
    while (  ! RadioButton[i]->Checked )
        i++;

    otv = i+1;
    // ����� ������, ������� ��������� ������ ������
    Button1->Enabled = true;
}

// ������� ������ � ������
void __fastcall TForm1::EraseVopros(void)
{
    Image1->Visible = false; // ������ ���� ������ �����������

    // ������ ���� ������ ������
    for (int i = 0; i <4; i++)
    {
        RadioButton[i]->Visible = false;
        RadioButton[i]->Checked = false;
    }
    Button1->Enabled = false; // ������� ����������� ������ ������
}

// ������ �� ������ OK/������/OK
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    bool ok; // ���-� ������ �� ����� ���������� �������

    switch (Button1->Tag) {
        case 0: // ������ �� ������ OK � ������ ������ ���������

                // ��������� � ������� ������ ������
                GetVopros(&Vopros);
                ShowVopros(Vopros);

                Button1->Caption = "������";
                Button1->Enabled = false;
                Button1->Tag = 1;
                break;

        case 1: // ������ �� ������ ������
                if (otv == Vopros.rOtv) // ������ ���������� �����
                    right++;
                EraseVopros();
                ok = GetVopros(&Vopros);
                if ( ok )
                    ShowVopros(Vopros);
                else
                // �������� ������ ���
                {
                    FileClose(f);
                    // ������� ���������
                    AnsiString st; // ���������
                    int i; // ����� ������������ ������

                    Form1->Caption = "��������� ������������";
                    st.printf("���������� �������: %i\n",right);

                    // ��������� ������
                    i = 0; // �����������, ��� ���������� ������� �� ��� ������
                    while (( right < level[i]) && (i < 3))
                        i++;

                    st = st + mes[i];
                    Label1->Caption = st;

                    Button1->Caption = "OK";
                    Button1->Enabled = true;
                    Button1->Tag = 2;
                }
                break;

        case 2: // ������ �� ������ OK � ����� ������ ���������
                Form1->Close(); // ��������� ������ ���������
    }
}

// ������� GetString ������ ������ �� �����
// �������� ������� - ���-�� ����������� ��������
int GetString(int f, AnsiString *st)
{
    unsigned char buf[300]; // ������ (�����)
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

// ������ �� ����� ����� �����
int GetInt(int f)
{
    char buf[20];   // ������ (�����)
    char *p = buf;  // ��������� �� ������

    int n;       // ���-�� ����������� ���� (�������� �-� FileRead)
    int a;       // �����, ����������� �� �����

    n = FileRead(f, p, 1) ;
    while ( (*p >= '0') && (*p <= '9') && (n > 0) )
    {
        p++;
        n = FileRead(f, p, 1) ;
    }

    if ( *p == '\r')
        n = FileRead(f, p, 1); // ��������� '\n'

    *p = '\0';

    // ����������� ����� � ������, ����������� � �����
    sscanf(buf,"%i", &a);
    return a;
}

