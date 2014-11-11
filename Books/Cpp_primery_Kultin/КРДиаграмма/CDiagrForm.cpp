#include <vcl.h>
#pragma hdrstop

#include "CDiagrForm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

#include "Math.h" // ��� ������� � sin � cos

TForm1 *Form1;


#undef MOBY      // ��������� "����� ��������� ���������"
#undef PEOPLE    // ��������� "��������� �����"

#define ENERGY      // ��������� "��������� �������"

#ifdef MOBI
#define HB 5
#define OBR /* ��������� ��������������� ���������
                    �������� ������ (��������� ���� ������ ���������
                    � ����� �����) */

                    // *** �������� ������ ***
AnsiString Title = "����� ��������� ���������";
float data[] = {38,55,30,20,25}; // �������� �� ������ ���������
float pr[];  // ���� ��������� � ����� ����� (�������)

// *** ������� ������� ***
AnsiString dTitle[] = {"Samsung","Nokia","LG","Sony Ericson","Motorola"};

// *** ���� ��� ������ ��������� ***
TColor cl[] = {clLime, clNavy, clMaroon, clGreen, clYellow};
#endif

#ifdef PEOPLE
#define HB 6
#define OBR /* ��������� ��������������� ���������
                    �������� ������ (��������� ���� ������ ���������
                    � ����� �����) */

// *** �������� ������ ***
AnsiString Title = "��������� �����";
float data[HB] = {1.25e9,1e9,274e6,216e6,172e6,146e6}; // �������� �� ������ ���������
float pr[HB];  // ���� ��������� � ����� ����� (�������)

// *** ������� ������� ***
AnsiString dTitle[HB] = {"�����","�����","���","���������","��������","������"};

// *** ���� ��� ������ ��������� ***
TColor cl[HB] = {clLime, clBlue, clMaroon, clGreen, clYellow, clTeal};

#endif

#ifdef ENERGY
#define HB 6
#undef OBR /* ��������������� ���������
             �������� ������ ��������� �� ���� - ����� ���������
             ������� data ������ ���� ����� 100 */

// *** �������� ������ ***
AnsiString Title = "������������� �������";
float data[HB] = {0.5,2.5,7,23,24,40}; // �������� �� ������ ���������
float pr[HB];  // ���� ��������� � ����� ����� (�������)

// *** ������� ������� ***
AnsiString dTitle[HB] = {"������","����� ��������������","������� ��������������",
                         "���","�����","�����"};

// *** ���� ��� ������ ��������� ***
TColor cl[HB] = {clLime, clBlue, clPurple, clSkyBlue, clYellow, clTeal};

#endif

#define R 80  // ������ ���������
#define D 160 // ������� ���������

#define TORAD 0.0174532 // ���� ��������� ���� �� �������� � �������
/* ��� ��������� �������� ���� �� �������� � �������,
   �������� � �������� ���� �������� �� Pi/180 */

// ����������� �����
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    int i,j;
    // ���������� �������� ������ ������� "��������"
    float bd;
    AnsiString bt;
    TColor bc;
    for (i = 0; i < HB; i ++)
        for (j = 0; j < HB-1; j++)
            if (data[j+1] < data[j])
            {
                // �������� ������� i-�� � i+1-�� �������� �������

                bd = data[j];
                data[j] = data[j+1];
                data[j+1] = bd;

                bt = dTitle[j];
                dTitle[j] = dTitle[j+1];
                dTitle[j+1] = bt;

                bc = cl[j];
                cl[j] = cl[j+1];
                cl[j+1] = bc;
            }

    #ifdef OBR
    // ��������� ������ - ���������� ����
    // ������ ��������� � ����� �����
    float sum = 0;
    for (i = 0; i < HB; i++)
        sum += data[i];

    for (i = 0; i < HB; i++)
        pr[i] = ( data[i] / sum) * 100;
    #else
        // �������� ������ ������������ � ���� ���������
        for ( i = 0; i < HB; i++)
            pr[i] = data[i];

    #endif

}


// ��������� ��������� ������� Paint ������ ���������
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    int x,y;
    int i;

    // *** ��������� ***
    Canvas->Font->Name = "Tahoma";
    Canvas->Font->Size = 12;
    x = (ClientWidth - Canvas->TextWidth(Title)) /2;
    Canvas->Brush->Style = bsClear;
    Canvas->TextOutA(x,15,Title);


    // *** �������� ��������� ***

    // ����� x,y - ���������� ������ �������� ����
    // ��������������, � ������� ������ ����, �� ��������
    // ���������� ������
    x = (ClientWidth - D) /2 - R;
    y = 15 + Canvas->TextHeight(Title) + 20;


    int x0,y0; // ����� ������� (�����)
    int x1,y1; // ���������� ����� ������ ����
    int x2,y2; // ���������� ����� ����� ����
    int a1,a2; // ���� ����� ���� OX � �������, ��������������� ������

//    int n;     // ���������� ��������� (��������)
//    n = sizeof(data) / sizeof(float);

    x0 = x + R;
    y0 = y + R;

    a1 = 0; // ������ ������ ����������� �� ��� OX

    //Canvas->Pen->Style = psClear;
    for (int i = 0; i < HB; i++ )
    {
        /* ��-�� ������ ���������� ��������
           ��������, ����� ����� ������ � ���������
           ��������� ����� ��������� ���������� ���
           ��������� ������ ��������� ������.
           ����� ����� �� ����, ������� ��� �������
           ���������� ������� ��������� � ������ OX */
        if (i != HB-1)
            a2 = ( a1 + 3.6 * pr[i]);
        else
            a2 = 359;

        // ���������� ����� ������ ����
        x1 = x0 + R * cos (a2 * TORAD);
        y1 = y0 + R * sin (a2 * TORAD);

        // ���������� ����� ����� ����
        x2 = x0 + R * cos (a1 * TORAD);
        y2 = y0 + R * sin (a1 * TORAD);

        if ( abs(a1-a2) <= 6 )
            Canvas->Pen->Style = psClear;
        else
            Canvas->Pen->Style = psSolid;

        Canvas->Brush->Color = cl[i];
        Canvas->Pie(x,y,x+D,y+D,x1,y1,x2,y2);

        a1 =a2; // ��������� ������ ������ �� ������ ��������
    }

    // �������
    Canvas->Font->Size -= 2;
    int dy = Canvas->TextHeight("a");
    x = x + D + 40;
    y = y + 20;
    for (i =HB-1; i >=0; i--)
    {
        Canvas->Brush->Color = cl[i];
        Canvas->Rectangle(x,y,x+40,y+dy);

        Canvas->Brush->Style = bsClear;
        Canvas->TextOutA(x+50,y,dTitle[i]+
                 ", " + FloatToStrF(pr[i],ffGeneral,2,2) + "%");
        y = y + dy +10;
    }
}

void __fastcall TForm1::FormResize(TObject *Sender)
{
    Form1->Refresh();
}

