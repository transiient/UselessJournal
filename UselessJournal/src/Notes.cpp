#include <iostream>

#include "Notes.h"
#include "NoteManager.h"

// Note class
note::note(std::string noteTitle, std::string noteBody) { // TODO: Add date parameter
	this->noteTitle = noteTitle;
	this->noteBody = noteBody;

	NoteAPI::addNoteToJournal(*this);
}
note::~note() {
	// should be garbage collected, right?
	this->noteTitle = "";
	this->noteBody  = "";
}

std::string note::getNoteBody() {
	// Return the body of the current note
	return this->noteBody;
}
std::string note::changeNoteBody(std::string newNoteBody) {
	if (newNoteBody.size() < 1) {
		return this->noteBody;
	}
	else {
		this->noteBody = newNoteBody;
		return this->noteBody;
	}
}