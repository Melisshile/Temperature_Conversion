object Main_Form: TMain_Form
  Left = 0
  Top = 0
  Caption = 'Temperature_Conversion_App'
  ClientHeight = 441
  ClientWidth = 624
  Color = clAquamarine
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Arial Narrow'
  Font.Style = [fsBold]
  Icon.Data = {
    0000010001001010100001000400280100001600000028000000100000002000
    0000010004000000000080000000000000000000000010000000000000000000
    0000FF8400000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000110000101000010011000010100001001100001010000100110
    0011011001100110011001100110011111000110011001100111011111100110
    0001011001100110000101100110011000010110011001100001011001100110
    001101000010001001100100001000111100010000100000000000000000FFFF
    00009EBD00009EBD00009EBD00009C9900009999000083990000988100009E99
    00009E9900009E9900009E9900009CBD0000D9BD0000C3BD0000FFFF0000}
  OnShow = FormShow
  TextHeight = 20
  object title_panel: TPanel
    Left = 88
    Top = 24
    Width = 441
    Height = 81
    Caption = 'Temperature Conversion Program'
    TabOrder = 0
  end
  object convert_btn: TButton
    Left = 248
    Top = 192
    Width = 121
    Height = 65
    Caption = 'Convert Now'
    TabOrder = 1
    OnClick = convert_btnClick
  end
  object dis_panel: TPanel
    Left = 184
    Top = 128
    Width = 241
    Height = 41
    Caption = 'Given Temperature : '
    TabOrder = 2
  end
  object dis_final_res_pnl: TPanel
    Left = 88
    Top = 280
    Width = 441
    Height = 105
    Caption = 'Converted Temperature...'
    TabOrder = 3
  end
  object reset_btn: TButton
    Left = 392
    Top = 192
    Width = 105
    Height = 65
    Caption = 'Reset'
    TabOrder = 4
    OnClick = reset_btnClick
  end
end
