#include <iostream>

#include "Notes.h"

// Note class
note::note(string noteTitle, string noteBody) {
	this->noteTitle = noteTitle;
	this->noteTitle = noteBody;
}
note::~note() {
	delete this;
}
void note::Modify(string newTitle, string newBody) {
	this->noteBody = newBody;
	this->noteTitle = newTitle;
}