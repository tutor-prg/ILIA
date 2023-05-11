//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <string.h>
#include "linkedlist.h"
#include "person.h"
LinkedList<Person> persones;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Edit1->Text = s;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	AnsiString S = Edit1->Text;
	strcpy(s, S.c_str());
    Edit1->Text = "";
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Staff1Click(TObject *Sender)
{
	TForm2 *fm = new TForm2(this);
	fm->ShowModal();
}
//---------------------------------------------------------------------------

