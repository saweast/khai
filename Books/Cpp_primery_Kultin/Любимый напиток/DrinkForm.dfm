object Form1: TForm1
  Left = 282
  Top = 469
  BorderIcons = [biSystemMenu, biMaximize]
  BorderStyle = bsSingle
  Caption = #1051#1102#1073#1080#1084#1099#1081' '#1085#1072#1087#1080#1090#1086#1082
  ClientHeight = 193
  ClientWidth = 492
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object Label7: TLabel
    Left = 8
    Top = 16
    Width = 481
    Height = 17
    AutoSize = False
    Caption = 
      #1042#1099#1073#1077#1088#1080#1090#1077' '#1074' '#1089#1087#1080#1089#1082#1077' '#1080#1083#1080' '#1074#1074#1077#1076#1080#1090#1077' '#1074' '#1087#1086#1083#1077' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103' '#1089#1074#1086#1081' '#1083#1102#1073#1080#1084#1099#1081 +
      ' '#1085#1072#1087#1080#1090#1086#1082
    WordWrap = True
  end
  object Label1: TLabel
    Left = 8
    Top = 48
    Width = 37
    Height = 16
    Caption = 'Label1'
  end
  object Label3: TLabel
    Left = 336
    Top = 48
    Width = 37
    Height = 16
    Caption = 'Label3'
  end
  object Label2: TLabel
    Left = 176
    Top = 48
    Width = 37
    Height = 16
    Caption = 'Label2'
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 72
    Width = 145
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 0
    OnClick = ComboBox1Click
    Items.Strings = (
      #1050#1086#1082#1072'-'#1050#1086#1083#1072
      #1052#1077#1088#1080#1085#1076#1072
      #1055#1077#1087#1089#1080'-'#1050#1086#1083#1072
      #1057#1087#1088#1072#1081#1090
      #1060#1072#1085#1090#1072
      #1063#1072#1081
      #1050#1086#1092#1077
      #1050#1086#1092#1077' '#1095#1077#1088#1085#1099#1081
      #1050#1086#1092#1077' '#1089#1086' '#1089#1083#1080#1074#1082#1072#1084#1080
      #1050#1072#1082#1072#1086
      #1063#1072#1081' '#1089' '#1083#1080#1084#1086#1085#1086#1084)
  end
  object ComboBox3: TComboBox
    Left = 328
    Top = 72
    Width = 145
    Height = 113
    Style = csSimple
    ItemHeight = 16
    TabOrder = 1
    OnKeyPress = ComboBox3KeyPress
  end
  object ComboBox2: TComboBox
    Left = 168
    Top = 72
    Width = 145
    Height = 24
    ItemHeight = 16
    TabOrder = 2
    OnClick = ComboBox2Click
    OnKeyPress = ComboBox2KeyPress
  end
end
