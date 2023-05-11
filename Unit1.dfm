object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1030#1085#1092#1086#1088#1084#1072#1094#1110#1081#1085#1072' '#1089#1080#1089#1090#1077#1084#1072
  ClientHeight = 438
  ClientWidth = 744
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 8
    Top = 88
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object Button1: TButton
    Left = 135
    Top = 86
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 232
    Top = 86
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 2
    OnClick = Button2Click
  end
  object StringGrid1: TStringGrid
    Left = 313
    Top = 88
    Width = 337
    Height = 145
    TabOrder = 3
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 392
    object File1: TMenuItem
      Caption = 'File'
      object Open1: TMenuItem
        Caption = 'Open'
      end
      object Open2: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
      end
    end
    object File2: TMenuItem
      Caption = 'Tables'
      object Staff1: TMenuItem
        Caption = 'Staff (Persones)'
        OnClick = Staff1Click
      end
      object Departments1: TMenuItem
        Caption = 'Departments'
      end
      object Departments2: TMenuItem
        Caption = 'Projects'
      end
      object Contracts1: TMenuItem
        Caption = 'Contracts'
      end
      object Equipment1: TMenuItem
        Caption = 'Equipment'
      end
    end
    object Contracts2: TMenuItem
      Caption = 'Requests'
      object Request11: TMenuItem
        Caption = 'Request_1'
      end
      object Request21: TMenuItem
        Caption = 'Request_2'
      end
      object Request31: TMenuItem
        Caption = 'Request_3'
      end
      object Request41: TMenuItem
        Caption = 'Request_4'
      end
      object Request51: TMenuItem
        Caption = 'Request_5'
      end
      object Request61: TMenuItem
        Caption = 'Request_6'
      end
      object Request71: TMenuItem
        Caption = 'Request_7'
      end
      object Request81: TMenuItem
        Caption = 'Request_8'
      end
      object Request91: TMenuItem
        Caption = 'Request_9'
      end
      object Request101: TMenuItem
        Caption = 'Request_10'
      end
      object Request111: TMenuItem
        Caption = 'Request_11'
      end
      object Request121: TMenuItem
        Caption = 'Request_12'
      end
      object Request131: TMenuItem
        Caption = 'Request_13'
      end
      object Request141: TMenuItem
        Caption = 'Request_14'
      end
    end
    object Request142: TMenuItem
      Caption = 'Help'
    end
  end
end
