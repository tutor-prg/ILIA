//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TListBox *ListBox1;
	TLabel *Label2;
	TButton *Button_Add;
	TButton *Button_Edit;
	TButton *Button_Delete;
	TButton *Button1;
	TEdit *Edit_Last_Name;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit_Name;
	TLabel *Label5;
	TComboBox *ComboBox_Year;
	TLabel *Label6;
	TEdit *Edit_Address;
	TLabel *Телефон;
	TEdit *Edit_Phone;
	TLabel *Відділ;
	TEdit *Edit_Department;
	TLabel *Label7;
	TComboBox *ComboBox_Profession;
	TLabel *Label8;
	TEdit *Edit_Num_Autor;
	void __fastcall Button_AddClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
