object Form1: TForm1
  Left = 311
  Top = 343
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1045#1078#1077#1076#1085#1077#1074#1085#1080#1082
  ClientHeight = 329
  ClientWidth = 551
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000F000000000000000000000000000000FF00F0000000000
    0000000000000000FFF08F0000000BB3333333333333330FFFF08F0333300B70
    00000000000000FFF7F08F0000300B7FF6FFFFFFFFF807FF77F08F0880300B7F
    F6FFFFFFFFF0B0F7D7F08F0880300B7666666666666807FD7DF08F0280300B7F
    F6FFFFFFFFF807F7D7F08F0280300B7FF6FFFFFFFFF0B0FD7DF08F0280300B76
    66666666666807F7DFF08F0280300B7FF6FFFFFFFFF807FDFFF08F0280300B7F
    F6FFFFFFFFF0B0FFAFF04F0280300B7666666666666807FA2FF04F0880300B7F
    F6FFFFFFFFF807F2AFF04F0880300B7FF6FFFFFFFFF0B0FA2FF04F0880300B76
    66666666666807F2AFF08F0180300B7FF6FFFFFFFFF807FAFFF08F0180300B7F
    F6FFFFFFFFF0B0FFFFF08F0880300B7666666666666807FFFF078F0880300B7F
    F6FFFFFFFFF807FFF078F00880300B7FF6FFFFFFFFF0B0FF07800788F0300B7F
    F6888888888807F0700788FFF0300B7F00000000007807000888FFFFF0300B77
    0FF88887700000000000000000B00BBBB0FF88770BB303BBBBBBBBBBBBB00000
    000FF870000B3B00000000000000000000FF8887000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000FFFF
    FEFFFFFFFCFFFFFFF89FFFFFF01F800000010000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000080000001F8063FFFFC0FFFFFFFFFFFFF}
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 41
    Height = 18
    Caption = 'Label1'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 40
    Width = 51
    Height = 18
    Caption = 'Label2'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 64
    Width = 537
    Height = 217
    DataSource = DataSource1
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'aDate'
        Title.Caption = #1050#1086#1075#1076#1072
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = []
        Width = 88
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'aTask'
        Title.Caption = #1063#1090#1086
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = []
        Width = 403
        Visible = True
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 304
    Top = 32
    Width = 240
    Height = 25
    DataSource = DataSource1
    Flat = True
    TabOrder = 1
  end
  object Button1: TButton
    Left = 8
    Top = 296
    Width = 75
    Height = 25
    Caption = #1057#1077#1075#1086#1076#1085#1103
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 96
    Top = 296
    Width = 75
    Height = 25
    Caption = #1047#1072#1074#1090#1088#1072
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 184
    Top = 296
    Width = 75
    Height = 25
    Caption = #1069#1090#1072' '#1085#1077#1076#1077#1083#1103
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 272
    Top = 296
    Width = 75
    Height = 25
    Caption = #1042#1089#1077
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button4Click
  end
  object CheckBox1: TCheckBox
    Left = 480
    Top = 304
    Width = 49
    Height = 17
    Caption = 'SQL '
    TabOrder = 6
  end
  object DataSource1: TDataSource
    DataSet = ADODataSet1
    Left = 24
    Top = 232
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source=DPlan' +
      'ner'
    LoginPrompt = False
    Left = 24
    Top = 152
  end
  object ADODataSet1: TADODataSet
    Connection = ADOConnection1
    CursorType = ctStatic
    CommandText = 'SELECT * FOM schedule ORDER BY aDate'
    Parameters = <>
    Left = 24
    Top = 192
  end
end
