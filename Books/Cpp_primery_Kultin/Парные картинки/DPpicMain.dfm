object Form1: TForm1
  Left = 277
  Top = 346
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1055#1072#1088#1085#1099#1077' '#1082#1072#1088#1090#1080#1085#1082#1080
  ClientHeight = 103
  ClientWidth = 390
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnMouseDown = FormMouseDown
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 48
    Top = 64
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 64
    object N1: TMenuItem
      Caption = #1053#1086#1074#1072#1103' '#1080#1075#1088#1072
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N3: TMenuItem
        Caption = #1057#1087#1088#1072#1074#1082#1072
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = N4Click
      end
    end
  end
end
