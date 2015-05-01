object Form1: TForm1
  Left = 474
  Top = 312
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1055#1086#1075#1086#1076#1072
  ClientHeight = 302
  ClientWidth = 229
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 16
    Top = 224
    Width = 77
    Height = 16
    Caption = #1058#1077#1084#1087#1077#1088#1072#1090#1091#1088#1072
  end
  object Button1: TButton
    Left = 16
    Top = 264
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Enabled = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object MonthCalendar1: TMonthCalendar
    Left = 16
    Top = 16
    Width = 197
    Height = 183
    Date = 38404.3939176736
    ShowTodayCircle = False
    TabOrder = 1
    OnClick = MonthCalendar1Click
  end
  object Edit1: TEdit
    Left = 104
    Top = 216
    Width = 57
    Height = 24
    TabOrder = 2
    OnChange = Edit1Change
    OnKeyPress = Edit1KeyPress
  end
end
