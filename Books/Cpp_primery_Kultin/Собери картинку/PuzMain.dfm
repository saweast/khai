object Form1: TForm1
  Left = 351
  Top = 395
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1057#1086#1073#1077#1088#1080' '#1082#1072#1088#1090#1085#1082#1091
  ClientHeight = 105
  ClientWidth = 315
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnMouseDown = FormMouseDown
  OnPaint = FormPaint
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 8
    Top = 56
    object N1: TMenuItem
      Caption = #1053#1086#1074#1072#1103' '#1080#1075#1088#1072
      OnClick = N1Click
    end
    object N5: TMenuItem
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
      object N6: TMenuItem
        Caption = #1053#1086#1084#1077#1088' '#1092#1080#1096#1082#1080
        OnClick = N6Click
      end
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
