object Form1: TForm1
  Left = 239
  Top = 173
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1080#1083#1083#1102#1089#1090#1088#1072#1094#1080#1081
  ClientHeight = 343
  ClientWidth = 487
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 32
    Width = 473
    Height = 265
    Center = True
    Proportional = True
  end
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object Button1: TButton
    Left = 8
    Top = 312
    Width = 75
    Height = 25
    Caption = #1050#1072#1090#1072#1083#1086#1075
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 96
    Top = 312
    Width = 75
    Height = 25
    Caption = #1044#1072#1083#1100#1096#1077
    Enabled = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object CheckBox1: TCheckBox
    Left = 192
    Top = 317
    Width = 97
    Height = 17
    Caption = #1085#1077#1087#1088#1077#1088#1099#1074#1085#1086
    Enabled = False
    TabOrder = 2
    OnClick = CheckBox1Click
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 2000
    OnTimer = Timer1Timer
    Left = 312
    Top = 312
  end
end
