//---------------------------------------------------------------------------

#ifndef Main_unitH
#define Main_unitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMain_Form : public TForm
{
__published:	// IDE-managed Components
	TPanel *title_panel;
	TButton *convert_btn;
	TPanel *dis_panel;
	TPanel *dis_final_res_pnl;
	TButton *reset_btn;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall convert_btnClick(TObject *Sender);
	void __fastcall reset_btnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMain_Form(TComponent* Owner);
	//prompt method
    void prompt();
};
//---------------------------------------------------------------------------
extern PACKAGE TMain_Form *Main_Form;
//---------------------------------------------------------------------------
#endif
