#include "NoteManager.h"

/*
Note Manager
*/

// Journal
std::vector<note> NoteAPI::m_Journal;

// Find a note and return its ID. Returns -1 if not found.
int NoteAPI::getNoteID(note findThis) {
	for (unsigned int i = 0; i < m_Journal.size(); i++) {
		if (findThis == m_Journal[i]) {
			return i;
		}
	}
	return -1;
}

int NoteAPI::addNoteToJournal(note newNote) {
	m_Journal.push_back(newNote);

	return getNoteID(newNote);
}

std::vector<note> NoteAPI::getJournal() {
	return m_Journal;
}

// --------------------------
// Methods for managing notes
// --------------------------

note NoteAPI::newNoteWizard() {
	std::string newNoteTitle, newNoteBody;

	std::cout << "New note" << std::endl << std::endl;
	std::cout << "  Title: ";
	getline(std::cin, newNoteTitle);

	std::cout << std::endl << std::endl << "  Text: ";
	getline(std::cin, newNoteBody);

	note newnote = note(newNoteTitle, newNoteBody); // Create and...
	addNoteToJournal(newnote);						// save!

	std::cout << std::endl << std::endl << "Note saved with ID " << NoteAPI::getNoteID(newnote) << "!";

	return newnote;
}

void NoteAPI::manageNotes() {
	std::cout << "Your notes" << std::endl << std::endl;
	
	if (m_Journal.size() == 0) {
		std::cout << "  " << "There's nothing here, create a note first." << std::endl;
		std::cin.clear(); std::cin.ignore();
		return;
	}
	else {
		ModeSelector manageMenu;
		int option;
		std::vector<std::string> newChoices;

		for (int i = 0; m_Journal.size() > i; i++) {
			//std::cout << "  " << i << ": " << m_Journal[i].getNoteTitle() << std::endl;
			newChoices.push_back(m_Journal[i].getNoteTitle());
		}

		manageMenu.updateChoices(newChoices);
		manageMenu.selector(option);

		system("PAUSE"); // temp. debug
	}
}