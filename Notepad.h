//---------------------------------------------------------------------------

#ifndef NotepadH
#define NotepadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------

#include <vector>
#include "Note.h"

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *Grid;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *New1;
	TMenuItem *Save1;
	TMenuItem *Open1;
	TMenuItem *Notes;
	TMenuItem *Addnote1;
	TSaveDialog *SaveDialog1;
	TOpenDialog *OpenDialog1;
	TMenuItem *Search;
	TMenuItem *Print;
	TMenuItem *N1;
	TMenuItem *Clear;
	TPrintDialog *PrintDialog1;
	void __fastcall SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall Addnote1Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall Save1Click(TObject *Sender);
	void __fastcall New1Click(TObject *Sender);
	void __fastcall DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall PrintClick(TObject *Sender);
	void __fastcall SearchClick(TObject *Sender);

private:	// User declarations
	std::vector<Note> notes;
    std::vector<Note> clrNotes;

	bool firstNameComp(Note& n1, Note& n2);
	bool middleNameComp(Note& n1, Note& n2);
	bool lastNameComp(Note& n1, Note& n2);
	bool adressComp(Note& n1, Note& n2);
	bool numberComp(Note& n1, Note& n2);

    int lastRow = -1;

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
    void updateGrid();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
