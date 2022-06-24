//---------------------------------------------------------------------------

#ifndef NoteSearchH
#define NoteSearchH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

#include "Note.h"
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *LastNameEdit;
	TLabeledEdit *FirstNameEdit;
	TLabeledEdit *MiddleNameEdit;
	TLabeledEdit *NumberEdit;
	TLabeledEdit *AdressEdit;
	TButton *FindButton;
	void __fastcall FindButtonClick(TObject *Sender);
private:	// User declarations
	std::vector<Note> notes;
	bool success = false;
    AnsiString photoPath;
public:		// User declarations
	__fastcall TForm3(TComponent* Owner, std::vector<Note>& notes);

	std::vector<Note> getNotes();
	bool isSuccess();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
