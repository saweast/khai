object Form1: TForm1
  Left = 308
  Top = 241
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1050#1086#1092#1077' '#1080' '#1087#1080#1088#1086#1078#1085#1086#1077
  ClientHeight = 200
  ClientWidth = 402
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
    Left = 16
    Top = 16
    Width = 164
    Height = 14
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1082#1086#1092#1077' '#1080' '#1087#1080#1088#1086#1078#1085#1086#1077
  end
  object RadioGroup1: TRadioGroup
    Left = 208
    Top = 40
    Width = 185
    Height = 105
    Caption = #1050#1086#1092#1077
    Items.Strings = (
      #1095#1077#1088#1085#1099#1081
      #1089#1086' '#1089#1083#1080#1074#1082#1072#1084#1080
      #1087#1086'-'#1080#1090#1072#1083#1100#1103#1085#1089#1082#1080)
    TabOrder = 0
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 40
    Width = 185
    Height = 105
    Caption = #1055#1080#1088#1086#1078#1085#1086#1077
    TabOrder = 1
    object RadioButton1: TRadioButton
      Left = 8
      Top = 23
      Width = 113
      Height = 17
      Caption = #1101#1082#1083#1077#1088
      TabOrder = 0
    end
    object RadioButton2: TRadioButton
      Left = 8
      Top = 50
      Width = 153
      Height = 17
      Caption = #1073#1091#1083#1086#1095#1082#1072' '#1089#1086' '#1089#1083#1080#1074#1082#1072#1084#1080
      TabOrder = 1
    end
    object RadioButton3: TRadioButton
      Left = 8
      Top = 78
      Width = 113
      Height = 17
      Caption = #1082#1086#1088#1079#1080#1085#1086#1095#1082#1072
      TabOrder = 2
    end
  end
  object Button1: TButton
    Left = 16
    Top = 168
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
  end
end
