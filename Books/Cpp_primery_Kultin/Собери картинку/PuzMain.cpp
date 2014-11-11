/*
  ���� "������ ��������" - ���� "15" � �����������
  ����������� (������ ���� - ��������� ��������).
  �������� ����������� �� ����� pic_1.bmp,
  ������� ��������� � ��� �� ��������
  ��� � ����������� ���� ���������.
  (�) ������� �.�., 2005.
*/

#include <vcl.h>
#pragma hdrstop

#include "PuzMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


#include "math.hpp" // ��� ������� � Randomize � RandomRange

// ������ ���� WxH
#define W 4
#define H 4

int wc, hc; // ������ ������

byte pole[H][W]; // ������� ����
byte ex,ey;      // ���������� ������ ������

bool GameOver;

AnsiString fn; // ��� bmp-����� (��������)
TSearchRec SearchRec; // ��������� ������ �����

__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    pic = new Graphics::TBitmap();
}

// ������ ������ ���������
void __fastcall TForm1::FormShow(TObject *Sender)
{
    NewGame();
}

// ����� ����
void __fastcall TForm1::NewGame()
{
    static int Tag = 0;
       // ��������� ���� �����������
    if (( ParamCount() == 0 ) && (Tag == 0 )) Tag = 1;

    switch ( Tag )
    {
        case 0 :  // ��� ����� - �� ��������� ������
             fn = ParamStr(1);
             Tag = 1;
             break;

        case 1:  // ������� ������ �� ������� bmp-����
             { FindFirst("*.bmp",faAnyFile,SearchRec);
               fn = SearchRec.Name;
               Tag = 2;
             }
             break;

        case 2: // ������� ��������� bmp-����
             {
                if ( FindNext(SearchRec) != 0)
                    FindFirst("*.bmp",faAnyFile,SearchRec);
                fn = SearchRec.Name;
             }
             break;
    }

    // ��������� �����������
    try {
        pic->LoadFromFile(fn);
    }
    catch (EFOpenError &e)
    {
        MessageDlg("������ ������� � ����� �����������",
          mtWarning, TMsgDlgButtons()<< mbOK<<mbHelp,0);
        return;
    }

    // ���������� ������ ������
    wc = pic->Width / W;
    hc = pic->Height / H;

    // ���������� ������ �����
    ClientWidth = wc * W;
    ClientHeight = hc * H;

    // �������� (����������) ��������� �����
    int k = 1;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            pole[i][j] = k++;

    GameOver = false;
    Mixer();     // ���������� �����
    ShowPole();  // ���������� ������� ����
}

// ������������ �����
void __fastcall TForm1::Mixer()
{
    int x1,y1; // ������ ������
    int x2,y2; // ��� ����������� � ������
    int d;     // ����������� ������������ ������

    Randomize();

    x1 = 3; y1 = 3; // ��. �������� ������� stp
    for ( int i = 0; i < 150; i++)  // ���-�� ������������
    {
        do {
            x2 = x1;
            y2 = y1;
            // ������� �����, ����������� � ������ ������,
            //   ������� ���������� � ������ ������
            d = RandomRange(1,5);
            switch ( d ) {
                case 1: x2--; break;
                case 2: x2++; break;
                case 3: y2--; break;
                case 4: y2++; break;
            }
        } while ((x2 < 0) || (x2 >= W) || (y2 < 0) || (y2 >= H));

        /* ����� ���������� �����, �������
           ���� ����������� � ������ ������ */

        pole[y1][x1]  =  pole[y2][x2];
        pole[y2][x2]  =  16;
        x1 = x2;
        y1 = y2;
    };
    // �������� ���������� ������ ������
    ex =  x1;
    ey =  y1;
}

// ���������� �� ����������� ����� ������� ����
void __fastcall TForm1::ShowPole()
{
    TRect src, dst; /* ������� �������� � ������� ��
                       �� ����������� �� ����������� ����� */
    int sx,sy;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            /* ����������� ����� ��������� �������� � ����������
               ������ �������� ���� �������-��������� */
            sx = ((pole[i][j]-1) % W) * wc;
            sy = ((pole[i][j]-1) / H) * hc;

            src = Bounds(sx,sy,wc,hc);
            dst = Bounds(j*wc,i*hc,wc,hc);

            if ((  pole[i][j] != 16 ) || GameOver )
                // �������� ��������
                Canvas->CopyRect(dst,pic->Canvas,src);
            else
            {
                // ������ ������
                Canvas->Brush->Style = bsSolid;
                Canvas->Brush->Color = clBtnFace;
                Canvas->Rectangle(dst);
            }
        }
    if ( N6->Checked )
    {
        // ������� ����� �����
        Canvas->Brush->Style = bsClear;
        for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            Canvas->TextOutA(wc*j,hc*i, IntToStr(pole[i][j]));
    }
}

// ������ � ������
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    int cx,cy; // ���������� ������

    cx = X / wc;
    cy = Y / hc;

    Move(cx,cy); // ����������� ��������� ������ � �������� ���������
}

bool Finish(); // ���������, ��������� �� ��������� �����

// ���������� ����� �� ������, � ������� ������ ������
// � ��������� ������
void __fastcall TForm1::Move(int cx, int cy)
{
    if  ( ( abs(cx - ex) == 1  &&  cy-ey == 0  ) ||
          ( abs(cy - ey) == 1  &&  cx-ex == 0  ) )
    {
        // ����������� ����� �� (cx,cy) � (ex,ey)
        pole[ey][ex] = pole[cy][cx];
        pole[cy][cx] = 16;
        ex = cx;
        ey = cy;
        // ���������� ����
        ShowPole();
        if ( Finish () )
        {
            GameOver = true;
            ShowPole();
            int r = MessageDlg ("���� ����������! ��� ��� (������ ��������)?",
                                mtInformation, TMsgDlgButtons() << mbYes << mbNo, 0);
            if ( r == mrNo )
                Form1->Close(); // ��������� ������ ���������
            else
            {
                NewGame();
                ShowPole();
            }
        }
    }
}

/* ���������, ����������� ��
  ������ (��������� ��������) � ������ ������� */
bool Finish()
{
    bool result;
    int row, col;
    int k = 1;

    result  =  true; // ����� ����� � ������ �������
    for (row = 0; row < H; row++)
    {
        for (col = 0; col < W; col++)
            if ( pole[row][col] == k )
                k++;
            else {
                result = false;
                break;
            }
        if ( ! result ) break;
    }
     return (result);
};

// ��������� ������� Paint
void __fastcall TForm1::FormPaint(TObject *Sender)
{
    ShowPole();
}

// ����� � ������ ���� ������� ����� ����
void __fastcall TForm1::N1Click(TObject *Sender)
{
    NewGame();
}

// ����� � ���� ������� ������� �������
void __fastcall TForm1::N3Click(TObject *Sender)
{
    WinExec("hh.exe puzzle.chm", SW_RESTORE);
}

// ����� � ���� ������� ������� � ���������
void __fastcall TForm1::N4Click(TObject *Sender)
{
    WinExec("hh.exe -mapid 3 puzzle.chm", SW_RESTORE);

}

// ������� ���������/����� �����
void __fastcall TForm1::N6Click(TObject *Sender)
{
    N6->Checked = ! N6->Checked;
    ShowPole();
}

