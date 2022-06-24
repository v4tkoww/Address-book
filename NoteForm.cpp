//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NoteForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <Vcl.Imaging.pngimage.hpp>

TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner, const Note& note_)
	: TForm(Owner)
{
	success = false;
    isDelete = false;
    note = note_;
	if(note.firstName.Length() == 0)
	{
		Photo->Canvas->Brush->Color = clWhite;
		Photo->Canvas->FillRect(TRect(0, 0, 128, 160));
		AddButton->Caption = L"Добавить";
        AddButton->Width = 254;
		DeleteButton->Visible = false;

        TResourceStream* stream
			= new TResourceStream((int)HInstance, "PngImage_1", RT_RCDATA);
		TPngImage* img = new TPngImage();
        img->LoadFromStream(stream);
		auto* bitmap = new Graphics::TBitmap();
		bitmap->Width = 128;
		bitmap->Height = 160;

		TRect rect = TRect(0, 0, bitmap->Width, bitmap->Height);
		bitmap->Canvas->StretchDraw(rect, img);
		img->Assign(bitmap);
		Photo->Picture->Assign(img);
	}
	else
	{
		LastNameEdit->Text = note.lastName;
		FirstNameEdit->Text = note.firstName;
		MiddleNameEdit->Text = note.middleName;
		AdressEdit->Text = note.adress;
		NumberEdit->Text = note.number;

		photoPath = note.photoPath;
		TPngImage* img = new TPngImage();
		auto* bitmap = new Graphics::TBitmap();
		bitmap->Width = 128;
		bitmap->Height = 160;

		img->LoadFromFile(photoPath);
		TRect rect = TRect(0, 0, bitmap->Width, bitmap->Height);
		bitmap->Canvas->StretchDraw(rect, img);
		img->Assign(bitmap);
		Photo->Picture->Assign(img);

		delete img;
		delete bitmap;

		AddButton->Caption = L"Изменить";
		AddButton->Width = 121;
		DeleteButton->Visible = true;
	}
}
//---------------------------------------------------------------------------

Note TForm2::getNote()
{
	return note;
}

void __fastcall TForm2::AddButtonClick(TObject *Sender)
{
	note.lastName = LastNameEdit->Text;
	if(note.lastName.Length() == 0)
	{
		Application->MessageBox(L"Введите фамилию!", L"Ошибка", MB_OK);
		return;
	}
	note.firstName = FirstNameEdit->Text;
	if(note.firstName.Length() == 0)
	{
		Application->MessageBox(L"Введите имя!", L"Ошибка", MB_OK);
		return;
	}
	note.middleName = MiddleNameEdit->Text;
	if(note.middleName.Length() == 0)
	{
		Application->MessageBox(L"Введите отчество!", L"Ошибка", MB_OK);
		return;
	}
	note.number = NumberEdit->Text;
	if(note.number.Length() == 0)
	{
		Application->MessageBox(L"Введите номер!", L"Ошибка", MB_OK);
		return;
	}
	note.adress = AdressEdit->Text;
	if(note.adress.Length() == 0)
	{
		Application->MessageBox(L"Введите адрес!", L"Ошибка", MB_OK);
		return;
	}
    note.photoPath = photoPath;
	if(note.photoPath.Length() == 0)
	{
        note.photoPath = L"user-male.png";
	}
	success = true;
    isDelete = false;
    Close();
}

bool TForm2::isSuccess()
{
	return success;
}

void __fastcall TForm2::GetPhotoButtonClick(TObject *Sender)
{
	if(OpenPhotoDialog->Execute())
	{
		photoPath = OpenPhotoDialog->FileName;
		TPngImage* img = new TPngImage();
		auto* bitmap = new Graphics::TBitmap();
		bitmap->Width = 128;
		bitmap->Height = 160;

        img->LoadFromFile(photoPath);
		TRect rect = TRect(0, 0, bitmap->Width, bitmap->Height);
		bitmap->Canvas->StretchDraw(rect, img);
        img->Assign(bitmap);
		Photo->Picture->Assign(img);

		delete img;
        delete bitmap;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DeleteButtonClick(TObject *Sender)
{
    isDelete = true;
	success = true;
    Close();
}
//---------------------------------------------------------------------------
bool TForm2::toDelete()
{
    return isDelete;
}
