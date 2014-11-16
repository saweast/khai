object Form1: TForm1
  Left = 318
  Top = 314
  HelpContext = 1
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1050#1086#1085#1074#1077#1088#1090#1086#1088
  ClientHeight = 130
  ClientWidth = 348
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  HelpFile = 'conv.hlp'
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object Label2: TLabel
    Left = 8
    Top = 16
    Width = 49
    Height = 14
    Caption = #1062#1077#1085#1072' ($)'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 48
    Width = 72
    Height = 14
    Caption = #1050#1091#1088#1089' ('#1088#1091#1073'/$)'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 88
    Width = 201
    Height = 25
    AutoSize = False
    WordWrap = True
  end
  object Label5: TLabel
    Left = 8
    Top = 112
    Width = 63
    Height = 13
    Caption = 'F1 - '#1089#1087#1088#1072#1074#1082#1072
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 88
    Top = 16
    Width = 105
    Height = 24
    HelpContext = 3
    MaxLength = 9
    TabOrder = 0
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 88
    Top = 48
    Width = 105
    Height = 24
    TabOrder = 1
    OnKeyPress = Edit2KeyPress
  end
  object Button1: TButton
    Left = 240
    Top = 16
    Width = 89
    Height = 25
    Caption = #1055#1077#1088#1077#1089#1095#1077#1090
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 240
    Top = 96
    Width = 89
    Height = 25
    Caption = #1047#1072#1074#1077#1088#1096#1080#1090#1100
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 240
    Top = 48
    Width = 89
    Height = 25
    Caption = #1057#1087#1088#1072#1074#1082#1072
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button3Click
  end
end
