object Form1: TForm1
  Left = 538
  Top = 374
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1050#1086#1085#1074#1077#1088#1090#1086#1088
  ClientHeight = 194
  ClientWidth = 218
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
    Left = 8
    Top = 8
    Width = 201
    Height = 33
    AutoSize = False
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1094#1077#1085#1091' '#1074' '#1076#1086#1083#1083#1072#1088#1072#1093', '#1082#1091#1088#1089' '#1080' '#1097#1077#1083#1082#1085#1080#1090#1077' '#1085#1072' '#1082#1085#1086#1087#1082#1077' '#1055#1077#1088#1077#1089#1095#1077#1090
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object Label2: TLabel
    Left = 8
    Top = 56
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
    Top = 88
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
    Top = 120
    Width = 201
    Height = 25
    AutoSize = False
    WordWrap = True
  end
  object Edit1: TEdit
    Left = 88
    Top = 56
    Width = 121
    Height = 22
    MaxLength = 9
    TabOrder = 0
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 88
    Top = 88
    Width = 73
    Height = 22
    TabOrder = 1
    OnKeyPress = Edit2KeyPress
  end
  object Button1: TButton
    Left = 8
    Top = 160
    Width = 89
    Height = 25
    Caption = #1055#1077#1088#1077#1089#1095#1077#1090
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 128
    Top = 160
    Width = 81
    Height = 25
    Caption = #1047#1072#1074#1077#1088#1096#1080#1090#1100
    TabOrder = 3
    OnClick = Button2Click
  end
end
