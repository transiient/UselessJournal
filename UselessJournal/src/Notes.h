#pragma once

#include <string>
#include <vector>
using namespace std;

// Single Note
class note {
	int noteId;
	string noteTitle, noteBody;
public:
	note(string noteTitle, string noteBody);
	~note();

	string getNoteBody();
	string getNoteBody(); // returns: current body
	string changeNoteBody(); // returns: new body
};