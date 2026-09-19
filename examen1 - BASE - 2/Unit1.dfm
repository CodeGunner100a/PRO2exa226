object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 617
  ClientWidth = 811
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 15
  object Edit1: TEdit
    Left = 40
    Top = 128
    Width = 225
    Height = 23
    TabOrder = 0
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 271
    Top = 128
    Width = 225
    Height = 23
    TabOrder = 1
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 520
    Top = 128
    Width = 225
    Height = 23
    TabOrder = 2
    Text = 'Edit3'
  end
  object Button1: TButton
    Left = 670
    Top = 48
    Width = 75
    Height = 25
    Caption = 'DIM'
    TabOrder = 3
  end
  object StringGrid1: TStringGrid
    Left = 40
    Top = 240
    Width = 705
    Height = 273
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 4
  end
  object Button2: TButton
    Left = 40
    Top = 48
    Width = 75
    Height = 25
    Caption = 'EJERCICIO 1'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 142
    Top = 48
    Width = 75
    Height = 25
    Caption = 'EJERCICIO 2'
    TabOrder = 6
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 248
    Top = 48
    Width = 75
    Height = 25
    Caption = 'EJERCICIO 3'
    TabOrder = 7
    OnClick = Button4Click
  end
end
