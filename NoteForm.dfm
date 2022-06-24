object Form2: TForm2
  Left = 0
  Top = 0
  Caption = #1047#1072#1087#1080#1089#1100
  ClientHeight = 420
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
  object Photo: TImage
    Left = 8
    Top = 219
    Width = 128
    Height = 160
  end
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
  object GetPhotoButton: TButton
    Left = 142
    Top = 219
    Width = 121
    Height = 25
    Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1092#1086#1090#1086'...'
    TabOrder = 5
    OnClick = GetPhotoButtonClick
  end
  object AddButton: TButton
    Left = 8
    Top = 387
    Width = 121
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 6
    OnClick = AddButtonClick
  end
  object DeleteButton: TButton
    Left = 142
    Top = 387
    Width = 121
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 7
    OnClick = DeleteButtonClick
  end
  object OpenPhotoDialog: TOpenPictureDialog
    Filter = 
      'All (*.gif;*.png;*.jpg;*.jpeg;*.bmp;*.ico;*.emf;*.wmf;*.tif;*.ti' +
      'ff)|*.gif;*.png;*.jpg;*.jpeg;*.bmp;*.ico;*.emf;*.wmf;*.tif;*.tif' +
      'f|GIF Image (*.gif)|*.gif|Portable Network Graphics (*.png)|*.pn' +
      'g|JPEG Image File (*.jpg)|*.jpg|JPEG Image File (*.jpeg)|*.jpeg|' +
      'Bitmaps (*.bmp)|*.bmp|Icons (*.ico)|*.ico|Enhanced Metafiles (*.' +
      'emf)|*.emf|Metafiles (*.wmf)|*.wmf|TIFF Images (*.tif)|*.tif|TIF' +
      'F Images (*.tiff)|*.tiff|PNG Images (*.png)| *.png'
    Left = 192
    Top = 280
  end
end
