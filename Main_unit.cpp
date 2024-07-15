﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main_unit.h"
//---------------------------------------------------------------------------
#include <tchar.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain_Form *Main_Form;
//---------------------------------------------------------------------------
//global var
AnsiString temperature;
int val;
double C,F,K;
//---------------------------------------------------------------------------
__fastcall TMain_Form::TMain_Form(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TMain_Form::prompt()
{
    temperature = InputBox(L"Required!!!",L"Enter the temperature with its unit\n like 25C for degrees Celcius\n25K for degrees Kalvin\n25F for degrees Fahrenheit!",L"");
	//validating
	while(temperature.IsEmpty())
	{
		if(temperature.IsEmpty())
		{
			ShowMessage("You didn't provide the temperature!!!\nPlease, provide it!");
			temperature = InputBox(L"Required!!!",L"Enter the temperature with its unit\n like 25C for degrees Celcius\n25K for degrees Kalvin\n25F for degrees Fahrenheit!",L"");
		}else
		{
			ShowMessage("Let's dive in!");
		}
	}
	dis_panel->Caption = "Given Temperature : " + temperature.SubString(0,temperature.Length()-1) + "⁰" + temperature.SubString(temperature.Length(),1);
}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::FormShow(TObject *Sender)
{
    prompt();
    reset_btn->Enabled = false;

}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::convert_btnClick(TObject *Sender)
{
	//ShowMessage("This is the length of the string : " + IntToStr(temperature.Length()));
	//getting the actual value
	AnsiString actualTem = temperature.SubString(0,temperature.Length()-1);
	//ShowMessage("This is the actual value in string : " + actualTem);
	//converting into int
	val = StrToInt(actualTem);
	//ShowMessage("This is the actual value in int : " + IntToStr(val));
	//decision
	AnsiString unit_ = temperature.SubString(temperature.Length(),1);
	//ShowMessage("This is the Unit : " + unit_);
	if(unit_== 'C' || unit_== 'c')
	{
		//ShowMessage("This is the Unit : " + unit_);
		F = (val * (9 / 5)) + 32;
		K = val + 273.15;
		//ShowMessage("The " + IntToStr(val) + " degrees celcius converted in Fahrenheit is " + FloatToStr(F) + " degrees Fahrenheit!\n");
		//ShowMessage("The " + IntToStr(val) + " degrees celcius converted in Kalvin is " + FloatToStr(K) + " degrees Kalvin!\n");
		dis_final_res_pnl->Caption = IntToStr(val) + "⁰C in Fahrenheit is " + FloatToStr(F) + "⁰F" + " and in Kalvin is " + FloatToStr(K) + "⁰K";
	}else if(unit_== 'F' || unit_== 'f')
	{
		//ShowMessage("This is the Unit : " + unit_);
		C = (val - 32) * 9 / 5;
		K = (val - 32) * (5 / 9) + 273.15;
		//ShowMessage("The " + IntToStr(val) + " degrees Fahrenheit converted in celcius is " + FloatToStr(C) + " degrees celcius!\n");
		//ShowMessage("The " + IntToStr(val) + " degrees Fahrenheit converted in Kalvin is " + FloatToStr(K) + " degrees Kalvin!\n");
		dis_final_res_pnl->Caption = IntToStr(val) + "⁰F in Celsius is " + FloatToStr(C) + "⁰C" + " and in Kalvin is " + FloatToStr(K) + "⁰K";
	}else if(unit_== 'K' || unit_== 'k')
	{
		//ShowMessage("This is the Unit : " + unit_);
		C = val - 273.15;
		F = (val - 273.15) * (9 / 5) + 32;
		//ShowMessage("The " + IntToStr(val) + " degrees Kalvin converted in celcius is " + FloatToStr(C) + " degrees celcius!\n");
		//ShowMessage("The " + IntToStr(val) + " degrees Kalvin converted in Fahrenheit is " + FloatToStr(F) + " degrees Fahrenheit!\n");
		dis_final_res_pnl->Caption = IntToStr(val) + "⁰K in Celsius is " + FloatToStr(C) + "⁰C" + " and in Fahrenheit is " + FloatToStr(F) + "⁰F";
	}else
	{
		//ShowMessage("Invalid Unit!!!");
		dis_final_res_pnl->Caption = "Invalid Unit!!!";
	}
	reset_btn->Enabled = true;
    convert_btn->Enabled = false;

}
//---------------------------------------------------------------------------
void __fastcall TMain_Form::reset_btnClick(TObject *Sender)
{
	dis_panel->Caption = "Given Temperature : ";
	dis_final_res_pnl->Caption = "Converted Temperature...";
	prompt();
	convert_btn->Enabled = true;
    reset_btn->Enabled = false;

}
//---------------------------------------------------------------------------
