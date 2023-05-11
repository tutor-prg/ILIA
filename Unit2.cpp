//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "linkedlist.h"
#include "person.h"
extern LinkedList<Person> persones;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button_AddClick(TObject *Sender)
{
	AnsiString lastname = Edit_Last_Name->Text;
    AnsiString name = Edit_Name->Text;
}
//---------------------------------------------------------------------------

