#pragma once

#include <vector>
#include "Notes.h"

/*
	Note Manager
*/

std::vector<note> m_Notes; // TODO: Get this working inside the NoteAPI class

class NoteAPI {
public:
	// Find a note and return its ID. Returns -1 if not found.
	static int getNoteID(note findThis) {
		for (unsigned int i = 0; i < m_Notes.size(); i++) {
			if (findThis == m_Notes[i]) {
				return i;
			}
		}
		return -1;
	}

	static int addNoteToJournal(note newNote) {
		m_Notes.push_back(newNote);
		
		return getNoteID(newNote);
	}

	static std::vector<note> getJournal() {
		return m_Notes;
	}

	// --------------------------
	// Methods for managing notes
	// --------------------------

	static note newNoteWizard() {
		std::string newNoteTitle, newNoteBody;

		std::cout << "New note" << std::endl;
		std::cout << "  Title: ";
		std::cin >> newNoteTitle;

		std::cout << std::endl << std::endl << "  Text: ";
		std::cin >> newNoteBody;

		note newnote = note(newNoteTitle, newNoteBody);

		std::cout << std::endl << std::endl << "Note saved with ID " << NoteAPI::getNoteID(newnote) << "!";

		return newnote;
	}
};