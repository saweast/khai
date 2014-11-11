object Form1: TForm1
  Left = 485
  Top = 314
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1057#1088#1077#1076#1085#1077#1084#1077#1089#1103#1095#1085#1072#1103' '#1090#1077#1084#1087#1077#1088#1072#1090#1091#1088#1072
  ClientHeight = 251
  ClientWidth = 297
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
    Left = 8
    Top = 176
    Width = 281
    Height = 17
    AutoSize = False
    WordWrap = True
  end
  object Memo1: TMemo
    Left = 8
    Top = 16
    Width = 281
    Height = 105
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Button1: TButton
    Left = 8
    Top = 216
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 136
    Width = 145
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 2
    OnChange = ComboBox1Change
  end
end
