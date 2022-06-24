//---------------------------------------------------------------------------

#ifndef NoteH
#define NoteH

#include <System.hpp>

class Note
{
public:
	Note();
	Note(UnicodeString firstName_,
		 UnicodeString middleName_,
		 UnicodeString lastName_,
		 UnicodeString number_,
		 UnicodeString adress_,
		 UnicodeString photoPath_);

	UnicodeString firstName;
	UnicodeString middleName;
	UnicodeString lastName;
	UnicodeString number;
	UnicodeString adress;
	UnicodeString photoPath;
};

#endif
