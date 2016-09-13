#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

#include "ModeSelector.h"
#include "Notes.h"
#include "util/io.h"

/*
	Note Manager
*/

class NoteAPI {
private:
	static std::vector<note> m_Journal; // TODO: Make it work.
public:
	// Find a note at an index and return it
	static note getNoteAtIndex(int id);
	// Find a note and return its ID. Returns -1 if not found.
	static int getNoteID(note findThis);
	// Add a note to the journal
	static int addNoteToJournal(note newNote);
	// Get the current journal
	static std::vector<note> getJournal();

	// --------------------------
	// Methods for managing notes
	// --------------------------

	// Create a note and add it to the journal
	static note newNoteWizard();
	// Manage notes in the journal
	static void manageNotes();
	// Save the journal
	static void saveNotes();
	// Load the journal
	static void loadNotes();
};