//---------------------------------------------------------------------------

#pragma hdrstop

#include "Note.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Note::Note() :
	firstName(""),
	middleName(""),
	lastName(""),
	number(""),
	adress(""),
	photoPath("")
{

}

Note::Note(
	UnicodeString firstName_,
	UnicodeString middleName_,
	UnicodeString lastName_,
	UnicodeString number_,
	UnicodeString adress_,
	UnicodeString photoPath_) :
	firstName(firstName_),
	middleName(middleName_),
	lastName(lastName_),
	number(number_),
	adress(adress_),
	photoPath(photoPath_)
{

}
