object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Notebook'
  ClientHeight = 572
  ClientWidth = 894
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
  object Grid: TStringGrid
    Left = 8
    Top = 8
    Width = 882
    Height = 555
    ColCount = 7
    DefaultColWidth = 120
    TabOrder = 0
    OnDrawCell = DrawCell
    OnSelectCell = SelectCell
  end
  object MainMenu1: TMainMenu
    Left = 544
    Top = 392
    object File1: TMenuItem
      Caption = #1060#1072#1081#1083
      object New1: TMenuItem
        Caption = #1057#1086#1079#1076#1072#1090#1100
        OnClick = New1Click
      end
      object Save1: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        OnClick = Save1Click
      end
      object Open1: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        OnClick = Open1Click
      end
      object Print: TMenuItem
        Caption = #1055#1077#1095#1072#1090#1100
        OnClick = PrintClick
      end
    end
    object Notes: TMenuItem
      Caption = #1047#1072#1087#1080#1089#1100
      object Addnote1: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100
        OnClick = Addnote1Click
      end
    end
    object N1: TMenuItem
      Caption = #1058#1072#1073#1083#1080#1094#1072
      object Clear: TMenuItem
        Caption = #1057#1073#1088#1086#1089#1080#1090#1100' '#1092#1080#1083#1100#1090#1088#1099
        OnClick = ClearClick
      end
      object Search: TMenuItem
        Caption = #1053#1072#1081#1090#1080
        OnClick = SearchClick
      end
    end
  end
  object SaveDialog1: TSaveDialog
    Filter = 'Note | *.note'
    Left = 608
    Top = 392
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Note | *.note'
    Left = 720
    Top = 392
  end
  object PrintDialog1: TPrintDialog
    Left = 664
    Top = 392
  end
end
