//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Notepad.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "Note.h"
#include "NoteForm.h"  
#include "NoteSearch.h"

#include <fstream>
#include <Vcl.Imaging.pngimage.hpp>
#include <algorithm>
#include <System.SysUtils.hpp>

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Grid->ColWidths[0] = 32;
    Grid->ColWidths[4] = 128;
	Grid->ColWidths[6] = 200;
	Grid->RowCount = 1;
	Grid->Cells[1][0] = "Фамилия";
	Grid->Cells[2][0] = "Имя";
	Grid->Cells[3][0] = "Отчество";
	Grid->Cells[4][0] = "Фото";
	Grid->Cells[5][0] = "Телефон";
	Grid->Cells[6][0] = "Адрес";
}
//---------------------------------------------------------------------------

bool TForm1::firstNameComp(Note& n1, Note& n2)
{
	return n1.firstName < n2.firstName;
}
bool TForm1::middleNameComp(Note& n1, Note& n2)
{
	return n1.middleName < n2.middleName;
}
bool TForm1::lastNameComp(Note& n1, Note& n2)
{
	return n1.lastName < n2.lastName;
}
bool TForm1::adressComp(Note& n1, Note& n2)
{
	return n1.adress < n2.adress;
}
bool TForm1::numberComp(Note& n1, Note& n2)
{
	return n1.number < n2.number;
}

void __fastcall TForm1::SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)
{
	if (ARow == lastRow) {
        if(ARow > 0)
		{
			Note note = notes.at(ARow - 1);
			TForm2* form = new TForm2(this, note);
			form->ShowModal();
			if(form->isSuccess())
			{
				if(form->toDelete())
				{
					auto number = notes[ARow - 1].number;
					Note note = form->getNote();
					notes.erase(notes.begin() + ARow - 1);
					for(int i = 0; i < clrNotes.size(); ++i)
					{
						if(clrNotes.at(i).number == number)
						{
							clrNotes.erase(clrNotes.begin() + i);
							break;
						}
					}
				}
				else
				{
					auto number = notes[ARow - 1].number;
					Note note = form->getNote();
					notes[ARow - 1] = note;
					for(int i = 0; i < clrNotes.size(); ++i)
					{
						if(clrNotes.at(i).number == number)
						{
							clrNotes[i] = note;
							break;
						}
					}
				}
                updateGrid();
			}
		}
		else
		{
			switch(ACol)
			{
				case 1:
					std::sort(notes.begin(), notes.end(), lastNameComp);
					break;
				case 2:
					std::sort(notes.begin(), notes.end(), firstNameComp);
					break;
				case 3:
					std::sort(notes.begin(), notes.end(), middleNameComp);
					break;
				case 5:
					std::sort(notes.begin(), notes.end(), numberComp);
					break;
				case 6:
					std::sort(notes.begin(), notes.end(), adressComp);
					break;
			}
			updateGrid();
		}
	}
	else
	{
        lastRow = ARow;
    }
}
//---------------------------------------------------------------------------

void TForm1::updateGrid()
{
	Grid->RowCount = notes.size() + 1;
	for(int i = 0; i < notes.size(); ++i)
	{
		auto note = notes.at(i);
		Grid->Cells[0][i + 1] = i + 1;
		Grid->Cells[1][i + 1] = note.lastName;
		Grid->Cells[2][i + 1] = note.firstName;
		Grid->Cells[3][i + 1] = note.middleName;
        Grid->Cells[4][i + 1] = "";
		Grid->Cells[5][i + 1] = note.number;
		Grid->Cells[6][i + 1] = note.adress;
		Grid->RowHeights[i + 1] = 160;
    }
}

void __fastcall TForm1::Addnote1Click(TObject *Sender)
{
	Note note;
	TForm2* form = new TForm2(this, note);
	form->ShowModal();
	if(form->isSuccess())
	{
		auto note = form->getNote();
		notes.push_back(note);
		clrNotes.push_back(note);
		updateGrid();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Open1Click(TObject *Sender)
{
	if(OpenDialog1->Execute())
	{
		auto fileName = OpenDialog1->FileName;
		std::fstream file(fileName.t_str(), ios::in);
		if(file.is_open())
		{
            if(!notes.empty())
			{
				notes.erase(notes.begin(), notes.end());
				Grid->RowCount = 1;
            }
			std::string line;
			while(std::getline(file, line))
			{
                std::vector<std::string> strings;
                auto start = 0U;
				auto end = line.find("**");
				while (end != std::string::npos)
				{
					strings.push_back(line.substr(start, end - start));
					start = end + 2;
					end = line.find("**", start);
				}
                strings.push_back(line.substr(start, end - start));
				Note note;
				note.lastName = strings.at(0).c_str();
				note.firstName = strings.at(1).c_str();
				note.middleName = strings.at(2).c_str();
				note.photoPath = strings.at(3).c_str();
				note.number = strings.at(4).c_str();
				note.adress = strings.at(5).c_str();
				notes.push_back(note);
                clrNotes.push_back(note);
            }
			file.close();
            updateGrid();
		}
		else
		{
			Application->MessageBox(L"Невозможно открыть файл для чтения",
			L"Ошибка",
			MB_OK);
		}
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Save1Click(TObject *Sender)
{
	if(notes.empty())
	{
		Application->MessageBox(L"Для сохранения добавьте записи",
								L"Ошибка",
								MB_OK);
		return;
	}
	if(SaveDialog1->Execute())
	{
		auto fileName = SaveDialog1->FileName;
		if(fileName.Length() < 5 ||
		   fileName.SubString(fileName.Length() - 4, 5) != L".note")
        	fileName += L".note";
		std::ofstream file(fileName.t_str(), ios::out);
		if(file.is_open())
		{
			for(auto note : notes)
			{
				file << std::string(AnsiString(note.lastName).c_str()) << "**";
				file << std::string(AnsiString(note.firstName).c_str()) << "**";
				file << std::string(AnsiString(note.middleName).c_str()) << "**";
				file << std::string(AnsiString(note.photoPath).c_str()) << "**";
				file << std::string(AnsiString(note.number).c_str()) << "**";
				file << std::string(AnsiString(note.adress).c_str()) << "\n";
			}
            file.close();
		}
		else
		{
			Application->MessageBox(L"Невозможно открыть файл для записи",
			L"Ошибка",
			MB_OK);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::New1Click(TObject *Sender)
{
	if(notes.empty())
		return;
	notes.erase(notes.begin(), notes.end());
    clrNotes.erase(clrNotes.begin(), clrNotes.end());
    Grid->RowCount = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	if(ARow > 0 && ACol == 4)
	{
		auto photoPath = notes.at(ARow - 1).photoPath;
        TPngImage* img = new TPngImage();
		if(photoPath == L"NULL")
		{
			TResourceStream* stream
			= new TResourceStream((int)HInstance, "PngImage_1", RT_RCDATA);
            img->LoadFromStream(stream);
		}
		else
		{
            img->LoadFromFile(photoPath);
		}
		auto* bitmap = new Graphics::TBitmap();
		bitmap->Width = 128;
		bitmap->Height = 160;

		TRect rect = TRect(0, 0, bitmap->Width, bitmap->Height);
		bitmap->Canvas->StretchDraw(rect, img);
		Grid->Canvas->Draw(Rect.Left, Rect.Top, bitmap);

		delete img;
		delete bitmap;
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ClearClick(TObject *Sender)
{
	notes.assign(clrNotes.begin(), clrNotes.end());
    updateGrid();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PrintClick(TObject *Sender)
{
	if(notes.empty())
	{
        if(notes.empty())
		{
			Application->MessageBox(L"Для печати добавьте записи",
									L"Ошибка",
									MB_OK);
			return;
		}
	}
	const float SCALE = 5.5f;
	if(PrintDialog1->Execute())
	{
		TPrinter* printer = Printer();
		printer->BeginDoc();
		int y = 300;
		for(int i = 0; i < Grid->RowCount; ++i)
		{
			if(i != 1 && (i - 1) % 7 == 0)
			{
				printer->NewPage();
				y = 300;
            }
			int x = 150;
			int height = Grid->RowHeights[i] * SCALE;
			for(int u = 0; u < Grid->ColCount; ++u)
			{
				int width = Grid->ColWidths[u] * SCALE;
				TRect rect(x, y, x + width, y + height);
				String str = Grid->Cells[u][i];
				printer->Canvas->Pen->Width = 1;
				printer->Canvas->Pen->Color = clBlack;
				printer->Canvas->Rectangle(rect);
				
				if(u == 4 && i > 0)
				{
					auto photoPath = notes.at(i - 1).photoPath;
					TPngImage* img = new TPngImage();
					if(photoPath == L"NULL")
					{
						TResourceStream* stream
						= new TResourceStream((int)HInstance, "PngImage_1", RT_RCDATA);
						img->LoadFromStream(stream);
					}
					else
					{
						img->LoadFromFile(photoPath);
					}
					int pWidth = 128 * SCALE; 
					int pHeight = 160 * SCALE;

					TRect photoRect = TRect(x + 10, y + 10, x + pWidth - 10, y + pHeight - 10);
					printer->Canvas->StretchDraw(photoRect, img);

					delete img;
				}
				else
				{
					TRect textRect(x + 10, y + 10, x + width - 10, y + height - 10);
					printer->Canvas->TextRect(textRect, str);
                }

				x += width;
			}
			y += height;
        }
		printer->EndDoc();
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SearchClick(TObject *Sender)
{
	std::vector<Note> sNotes;
	TForm3* form = new TForm3(this, notes);
	form->ShowModal();
	if(form->isSuccess())
	{
		sNotes = form->getNotes(); 
		if(sNotes.size() > 0)
		{
			notes = sNotes;
			updateGrid();
		}
		else
		{
			Application->MessageBox(L"По вашему запросу ничего не найдено",
								   L"Поиск записи",
								   MB_OK);
        }
	}	
}
//---------------------------------------------------------------------------

