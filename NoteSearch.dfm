object Form3: TForm3
  Left = 0
  Top = 0
  Caption = #1047#1072#1087#1080#1089#1100
  ClientHeight = 260
  ClientWidth = 270
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LastNameEdit: TLabeledEdit
    Left = 8
    Top = 24
    Width = 255
    Height = 21
    EditLabel.Width = 44
    EditLabel.Height = 13
    EditLabel.Caption = #1060#1072#1084#1080#1083#1080#1103
    TabOrder = 0
  end
  object FirstNameEdit: TLabeledEdit
    Left = 8
    Top = 64
    Width = 255
    Height = 21
    EditLabel.Width = 19
    EditLabel.Height = 13
    EditLabel.Caption = #1048#1084#1103
    TabOrder = 1
  end
  object MiddleNameEdit: TLabeledEdit
    Left = 8
    Top = 104
    Width = 255
    Height = 21
    EditLabel.Width = 49
    EditLabel.Height = 13
    EditLabel.Caption = #1054#1090#1095#1077#1089#1090#1074#1086
    TabOrder = 2
  end
  object NumberEdit: TLabeledEdit
    Left = 8
    Top = 144
    Width = 255
    Height = 21
    EditLabel.Width = 31
    EditLabel.Height = 13
    EditLabel.Caption = #1053#1086#1084#1077#1088
    NumbersOnly = True
    TabOrder = 3
  end
  object AdressEdit: TLabeledEdit
    Left = 8
    Top = 184
    Width = 255
    Height = 21
    EditLabel.Width = 31
    EditLabel.Height = 13
    EditLabel.Caption = #1040#1076#1088#1077#1089
    TabOrder = 4
  end
  object FindButton: TButton
    Left = 9
    Top = 227
    Width = 254
    Height = 25
    Caption = #1053#1072#1081#1090#1080
    TabOrder = 5
    OnClick = FindButtonClick
  end
end
