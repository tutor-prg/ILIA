//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Samples.Spin.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TButton *Button1;
	TButton *Button2;
	TStringGrid *StringGrid1;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *File2;
	TMenuItem *Staff1;
	TMenuItem *Open1;
	TMenuItem *Open2;
	TMenuItem *Exit1;
	TMenuItem *Departments1;
	TMenuItem *Departments2;
	TMenuItem *Contracts1;
	TMenuItem *Contracts2;
	TMenuItem *Request11;
	TMenuItem *Request21;
	TMenuItem *Request31;
	TMenuItem *Request41;
	TMenuItem *Request51;
	TMenuItem *Request61;
	TMenuItem *Request71;
	TMenuItem *Request81;
	TMenuItem *Request91;
	TMenuItem *Request101;
	TMenuItem *Request111;
	TMenuItem *Request121;
	TMenuItem *Request131;
	TMenuItem *Request141;
	TMenuItem *Request142;
	TMenuItem *Equipment1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Staff1Click(TObject *Sender);
private:	// User declarations
	char s[200] = "";
	//AnsiString s = "";
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
