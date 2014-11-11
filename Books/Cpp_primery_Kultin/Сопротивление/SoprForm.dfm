object Form1: TForm1
  Left = 475
  Top = 284
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1057#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1077
  ClientHeight = 270
  ClientWidth = 242
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
    Width = 225
    Height = 42
    Caption = 
      #1055#1088#1086#1075#1088#1072#1084#1084#1072' '#1074#1099#1095#1080#1089#1083#1080#1090' '#1089#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1077' '#1101#1083#1077#1082#1090#1088#1080#1095#1077#1089#1082#1086#1081' '#1094#1077#1087#1080', '#1082#1086#1090#1086#1088#1072#1103' '#1089#1086#1089 +
      #1090#1086#1080#1090' '#1080#1079' '#1076#1074#1091#1093' '#1089#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1081
    WordWrap = True
  end
  object Label2: TLabel
    Left = 16
    Top = 164
    Width = 45
    Height = 14
    Caption = 'R1 ('#1054#1084')'
  end
  object Label3: TLabel
    Left = 16
    Top = 191
    Width = 45
    Height = 14
    Caption = 'R1 ('#1054#1084')'
  end
  object Label4: TLabel
    Left = 16
    Top = 224
    Width = 217
    Height = 33
    AutoSize = False
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 64
    Width = 225
    Height = 81
    Caption = #1057#1086#1087#1088#1086#1090#1080#1074#1083#1077#1085#1080#1103' '#1089#1086#1077#1076#1080#1085#1077#1085#1099
    TabOrder = 0
  end
  object RadioButton1: TRadioButton
    Left = 32
    Top = 88
    Width = 129
    Height = 17
    Caption = #1087#1086#1089#1083#1077#1076#1086#1074#1072#1090#1077#1083#1100#1085#1086
    Checked = True
    TabOrder = 1
    TabStop = True
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 32
    Top = 112
    Width = 113
    Height = 17
    Caption = #1087#1072#1088#1072#1083#1083#1077#1083#1100#1085#1086
    TabOrder = 2
    OnClick = RadioButton2Click
  end
  object Edit1: TEdit
    Left = 72
    Top = 160
    Width = 57
    Height = 22
    TabOrder = 3
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 72
    Top = 184
    Width = 57
    Height = 22
    TabOrder = 4
    OnKeyPress = Edit2KeyPress
  end
  object Button1: TButton
    Left = 152
    Top = 160
    Width = 75
    Height = 25
    Caption = #1042#1099#1095#1080#1089#1083#1080#1090#1100
    TabOrder = 5
    OnClick = Button1Click
  end
end
