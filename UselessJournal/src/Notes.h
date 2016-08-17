#pragma once

#include <string>
#include <vector>
using namespace std; // sorry c++ gods

// Single Note
class Note {
private:
	int noteId;
	string mNoteTitle, mNoteBody;
public:
	Note(string noteTitle, string noteBody);
	~Note();

	void Modify();
};

// Managing Notes
class NotesManager {
private:
	vector<string> notes;
public:
	void newNoteWizard();
	void modNoteWizard(int noteId);
	void modNoteWizard(string noteTitle);
};