//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NoteSearch.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <Vcl.Imaging.pngimage.hpp>

TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner, std::vector<Note>& notes_)
	: TForm(Owner)
{
	success = false;
	notes = notes_;
}
//---------------------------------------------------------------------------

std::vector<Note> TForm3::getNotes()
{
	return notes;
}

void __fastcall TForm3::FindButtonClick(TObject *Sender)
{
	auto lastName = LastNameEdit->Text;
	if(lastName.Length() > 0)
	{
		std::vector<Note> newNotes;
		for(auto item : notes)
		{
			if(item.lastName == lastName)
			{
                newNotes.push_back(item);
            }
		}
        notes = newNotes;
	}
	auto firstName = FirstNameEdit->Text;
	if(firstName.Length() > 0)
	{
		std::vector<Note> newNotes;
		for(auto item : notes)
		{
			if(item.firstName == firstName)
			{
                newNotes.push_back(item);
            }
		}
        notes = newNotes;
	}
	auto middleName = MiddleNameEdit->Text;
	if(middleName.Length() > 0)
	{
		std::vector<Note> newNotes;
		for(auto item : notes)
		{
			if(item.middleName == middleName)
			{
                newNotes.push_back(item);
            }
		}
        notes = newNotes;
	}
	auto number = NumberEdit->Text;
	if(number.Length() > 0)
	{
		std::vector<Note> newNotes;
		for(auto item : notes)
		{
			if(item.number == number)
			{
                newNotes.push_back(item);
            }
		}
        notes = newNotes;
	}
	auto adress = AdressEdit->Text;
	if(adress.Length() > 0)
	{
		std::vector<Note> newNotes;
		for(auto item : notes)
		{
			if(item.adress == adress)
			{
                newNotes.push_back(item);
            }
		}
        notes = newNotes;
	}

	success = true;
    Close();
}

bool TForm3::isSuccess()
{
	return success;
}
