object Form1: TForm1
  Left = 501
  Top = 309
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1050#1072#1092#1077
  ClientHeight = 193
  ClientWidth = 361
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 14
  object Label1: TLabel
    Left = 144
    Top = 16
    Width = 41
    Height = 18
    AutoSize = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 16
    Width = 102
    Height = 14
    Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100' '#1079#1072#1082#1072#1079#1072':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object CheckBox1: TCheckBox
    Left = 24
    Top = 48
    Width = 97
    Height = 17
    Caption = #1041#1080#1075'-'#1052#1072#1082
    TabOrder = 0
    OnClick = CheckBox1Click
  end
  object CheckBox2: TCheckBox
    Left = 24
    Top = 72
    Width = 97
    Height = 17
    Caption = #1089#1086#1091#1089
    TabOrder = 1
    OnClick = CheckBox2Click
  end
  object CheckBox3: TCheckBox
    Left = 24
    Top = 96
    Width = 97
    Height = 17
    Caption = #1082#1072#1088#1090#1086#1096#1082#1072
    TabOrder = 2
    OnClick = CheckBox3Click
  end
  object CheckBox4: TCheckBox
    Left = 24
    Top = 120
    Width = 97
    Height = 17
    Caption = #1050#1086#1082#1072'-'#1050#1086#1083#1072
    TabOrder = 3
    OnClick = CheckBox4Click
  end
  object Button1: TButton
    Left = 16
    Top = 160
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 4
    OnClick = Button1Click
  end
end
