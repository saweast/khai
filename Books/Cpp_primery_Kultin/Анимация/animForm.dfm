object Form1: TForm1
  Left = 219
  Top = 184
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1040#1085#1080#1084#1072#1094#1080#1103
  ClientHeight = 151
  ClientWidth = 320
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 16
    Top = 80
    Width = 37
    Height = 16
    Caption = 'Label1'
  end
  object Animate1: TAnimate
    Left = 16
    Top = 16
    Width = 90
    Height = 45
    Active = False
    StopFrame = 8
    Timers = True
  end
  object Button1: TButton
    Left = 16
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Play'
    TabOrder = 1
    OnClick = Button1Click
  end
end
