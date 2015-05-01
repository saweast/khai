object Form1: TForm1
  Left = 249
  Top = 294
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1059#1089#1087#1077#1090#1100' '#1079#1072' 60 '#1089#1077#1082#1091#1085#1076
  ClientHeight = 173
  ClientWidth = 347
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 314
    Height = 16
    Caption = #1042#1099' '#1076#1086#1083#1078#1085#1099' '#1091#1075#1072#1076#1072#1090#1100' '#1090#1088#1077#1093#1079#1085#1072#1095#1085#1086#1077' '#1095#1080#1089#1083#1086' '#1079#1072' 60 '#1089#1077#1082#1091#1085#1076'.'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 32
    Width = 245
    Height = 32
    Caption = 
      #1042#1074#1077#1076#1080#1090#1077' '#1095#1080#1089#1083#1086' '#1080' '#1097#1077#1083#1082#1085#1080#1090#1077' '#1085#1072' '#1082#1085#1086#1087#1082#1077' OK '#1080#1083#1080' '#1085#1072#1078#1084#1080#1090#1077' '#1082#1083#1072#1074#1080#1096#1091' <Enter' +
      '>'
    WordWrap = True
  end
  object Label3: TLabel
    Left = 8
    Top = 120
    Width = 55
    Height = 16
    Caption = #1054#1089#1090#1072#1083#1086#1089#1100
  end
  object Label4: TLabel
    Left = 72
    Top = 120
    Width = 14
    Height = 16
    Caption = '60'
  end
  object Label5: TLabel
    Left = 96
    Top = 120
    Width = 19
    Height = 16
    Caption = #1089#1077#1082
  end
  object MediaPlayer1: TMediaPlayer
    Left = 88
    Top = 144
    Width = 253
    Height = 25
    ColoredButtons = []
    Visible = False
    TabOrder = 0
    OnNotify = MediaPlayer1Notify
  end
  object Edit1: TEdit
    Left = 8
    Top = 80
    Width = 121
    Height = 24
    TabOrder = 1
    OnChange = Edit1Change
    OnKeyPress = Edit1KeyPress
  end
  object Button1: TButton
    Left = 152
    Top = 80
    Width = 75
    Height = 25
    Caption = 'OK'
    Enabled = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 8
    Top = 144
  end
end
