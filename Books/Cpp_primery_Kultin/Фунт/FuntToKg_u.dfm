object Form1: TForm1
  Left = 465
  Top = 266
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1060#1091#1085#1090#1099'-'#1082#1080#1083#1086#1075#1088#1072#1084#1084#1099
  ClientHeight = 150
  ClientWidth = 266
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 249
    Height = 41
    AutoSize = False
    Caption = 
      #1042#1074#1077#1076#1080#1090#1077' '#1074#1077#1089' '#1074' '#1092#1091#1085#1090#1072#1093' '#1080' '#1097#1077#1083#1082#1085#1080#1090#1077' '#1085#1072' '#1082#1085#1086#1087#1082#1077' '#1055#1077#1088#1077#1089#1095#1077#1090'. '#1044#1083#1103' '#1086#1090#1076#1077#1083#1077#1085#1080 +
      #1103' '#1076#1088#1086#1073#1085#1086#1081' '#1095#1072#1089#1090#1080' '#1086#1090' '#1094#1077#1083#1086#1081' '#1080#1089#1087#1086#1083#1100#1079#1091#1081#1090#1077' '#1079#1072#1087#1103#1090#1091#1102
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
    Top = 104
    Width = 177
    Height = 33
    AutoSize = False
    WordWrap = True
  end
  object Edit1: TEdit
    Left = 8
    Top = 64
    Width = 129
    Height = 21
    TabOrder = 0
    OnChange = Edit1Change
    OnKeyPress = Edit1KeyPress
  end
  object Button1: TButton
    Left = 160
    Top = 64
    Width = 97
    Height = 25
    Caption = #1055#1077#1088#1077#1089#1095#1077#1090
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
end
