//---------------------------------------------------------------------------

#ifndef NoteFormH
#define NoteFormH
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
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *LastNameEdit;
	TLabeledEdit *FirstNameEdit;
	TLabeledEdit *MiddleNameEdit;
	TLabeledEdit *NumberEdit;
	TLabeledEdit *AdressEdit;
	TImage *Photo;
	TButton *GetPhotoButton;
	TButton *AddButton;
	TOpenPictureDialog *OpenPhotoDialog;
	TButton *DeleteButton;
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall GetPhotoButtonClick(TObject *Sender);
	void __fastcall DeleteButtonClick(TObject *Sender);
private:	// User declarations
	Note note;
	bool success = false;
    bool isDelete = false;
    AnsiString photoPath;
public:		// User declarations
	__fastcall TForm2(TComponent* Owner, const Note& note);

	Note getNote();
	bool isSuccess();
    bool toDelete();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
