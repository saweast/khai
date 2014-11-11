object Form1: TForm1
  Left = 382
  Top = 152
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1069#1083#1077#1082#1090#1088#1086#1101#1085#1077#1088#1075#1080#1103
  ClientHeight = 233
  ClientWidth = 389
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 14
  object Label3: TLabel
    Left = 24
    Top = 128
    Width = 89
    Height = 14
    Caption = #1062#1077#1085#1072' ('#1088#1091#1073'./'#1082#1042#1090')'
  end
  object Label4: TLabel
    Left = 24
    Top = 168
    Width = 257
    Height = 14
    AutoSize = False
  end
  object GroupBox1: TGroupBox
    Left = 24
    Top = 16
    Width = 249
    Height = 89
    Caption = #1055#1086#1082#1072#1079#1072#1085#1080#1103' '#1089#1095#1077#1090#1095#1080#1082#1072
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 32
      Width = 69
      Height = 14
      Caption = #1087#1088#1077#1076#1099#1076#1091#1097#1077#1077
    end
    object Label2: TLabel
      Left = 16
      Top = 56
      Width = 45
      Height = 14
      Caption = #1090#1077#1082#1091#1097#1077#1077
    end
    object Edit1: TEdit
      Left = 96
      Top = 24
      Width = 113
      Height = 22
      TabOrder = 0
      OnKeyPress = EditKeyPress
    end
    object Edit2: TEdit
      Left = 96
      Top = 48
      Width = 113
      Height = 22
      TabOrder = 1
    end
  end
  object Edit3: TEdit
    Left = 128
    Top = 120
    Width = 105
    Height = 22
    TabOrder = 1
  end
  object Button1: TButton
    Left = 24
    Top = 200
    Width = 75
    Height = 25
    Caption = #1042#1099#1095#1080#1089#1083#1080#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
end
