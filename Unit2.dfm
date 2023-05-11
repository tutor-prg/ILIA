object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Staff (Persones)'
  ClientHeight = 464
  ClientWidth = 602
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 236
    Top = 8
    Width = 127
    Height = 25
    Caption = #1042#1110#1076#1076#1110#1083' '#1082#1072#1076#1088#1110#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsUnderline]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 64
    Top = 31
    Width = 142
    Height = 19
    Caption = #1057#1087#1080#1089#1086#1082' '#1087#1088#1072#1094#1110#1074#1085#1080#1082#1110#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 304
    Top = 53
    Width = 47
    Height = 13
    Caption = #1055#1088#1110#1079#1074#1080#1097#1077
  end
  object Label4: TLabel
    Left = 472
    Top = 53
    Width = 18
    Height = 13
    Caption = #1030#1084#39#1103
  end
  object Label5: TLabel
    Left = 304
    Top = 112
    Width = 80
    Height = 13
    Caption = #1056#1110#1082' '#1085#1072#1088#1086#1076#1078#1077#1085#1085#1103
  end
  object Label6: TLabel
    Left = 305
    Top = 136
    Width = 37
    Height = 13
    Caption = #1040#1076#1088#1077#1089#1072
  end
  object Телефон: TLabel
    Left = 304
    Top = 184
    Width = 44
    Height = 13
    Caption = #1058#1077#1083#1077#1092#1086#1085
  end
  object Відділ: TLabel
    Left = 472
    Top = 184
    Width = 30
    Height = 13
    Caption = #1042#1110#1076#1076#1110#1083
  end
  object Label7: TLabel
    Left = 304
    Top = 232
    Width = 46
    Height = 13
    Caption = #1055#1088#1086#1092#1077#1089#1110#1103
  end
  object Label8: TLabel
    Left = 305
    Top = 296
    Width = 155
    Height = 13
    Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1072#1074#1090#1086#1088#1089#1100#1082#1080#1093' '#1089#1074#1110#1076#1086#1094#1090#1074
  end
  object ListBox1: TListBox
    Left = 8
    Top = 56
    Width = 273
    Height = 369
    ItemHeight = 13
    TabOrder = 0
  end
  object Button_Add: TButton
    Left = 8
    Top = 431
    Width = 75
    Height = 25
    Caption = #1044#1086#1076#1072#1090#1080
    TabOrder = 1
    OnClick = Button_AddClick
  end
  object Button_Edit: TButton
    Left = 104
    Top = 431
    Width = 81
    Height = 25
    Caption = #1056#1077#1076#1072#1075#1091#1074#1072#1085#1085#1103
    TabOrder = 2
  end
  object Button_Delete: TButton
    Left = 206
    Top = 431
    Width = 75
    Height = 25
    Caption = #1055#1088#1080#1073#1088#1072#1090#1080
    TabOrder = 3
  end
  object Button1: TButton
    Left = 518
    Top = 431
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1080#1090#1080
    ModalResult = 8
    TabOrder = 4
  end
  object Edit_Last_Name: TEdit
    Left = 304
    Top = 72
    Width = 153
    Height = 21
    TabOrder = 5
  end
  object Edit_Name: TEdit
    Left = 472
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object ComboBox_Year: TComboBox
    Left = 400
    Top = 109
    Width = 145
    Height = 21
    ItemIndex = 0
    TabOrder = 7
    Text = '1980'
    Items.Strings = (
      '1980'
      '1981'
      '1982'
      '1983')
  end
  object Edit_Address: TEdit
    Left = 305
    Top = 155
    Width = 289
    Height = 21
    TabOrder = 8
  end
  object Edit_Phone: TEdit
    Left = 304
    Top = 203
    Width = 121
    Height = 21
    TabOrder = 9
  end
  object Edit_Department: TEdit
    Left = 473
    Top = 203
    Width = 121
    Height = 21
    TabOrder = 10
  end
  object ComboBox_Profession: TComboBox
    Left = 304
    Top = 251
    Width = 290
    Height = 21
    ItemIndex = 0
    TabOrder = 11
    Text = #1050#1086#1085#1089#1090#1088#1091#1082#1090#1086#1088
    Items.Strings = (
      #1050#1086#1085#1089#1090#1088#1091#1082#1090#1086#1088
      #1030#1085#1078#1077#1085#1077#1088
      #1058#1077#1093#1085#1110#1082
      #1051#1072#1073#1086#1088#1072#1085#1090)
  end
  object Edit_Num_Autor: TEdit
    Left = 466
    Top = 293
    Width = 128
    Height = 21
    TabOrder = 12
  end
end
