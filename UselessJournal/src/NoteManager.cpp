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

// Find a note at an index and return it, returns a blank note if not found
note NoteAPI::getNoteAtIndex(int id) {
	//if (std::find(m_Journal.begin(), m_Journal.end(), id) != m_Journal.end()) {
		return m_Journal[id];
	//}
	//else {
	//	return note("", "");
	//}
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

	// Clear screen to draw
	for (int i = 0; i < 60; i++) std::cout << std::endl;

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
		ModeSelector journalMenu;
		journalMenu.setType("Journal");
		int option;
		std::vector<std::string> newChoices;

		for (unsigned int i = 0; m_Journal.size() > i; i++) {
			newChoices.push_back(m_Journal[i].getNoteTitle());
		}

		journalMenu.updateChoices(newChoices);
		journalMenu.selector(option);

		note returnedNote = getNoteAtIndex(option);

		// Clear screen to draw note detail
		for (int i = 0; i < 60; i++) std::cout << std::endl;

		std::cout << "** " << returnedNote.getNoteTitle() << " **" << std::endl << std::endl;
		std::cout << returnedNote.getNoteBody() << std::endl << std::endl;

		// Show editor controls
		std::cout << "Press any key to go back" << std::endl;

		std::cin.clear(); std::cin.ignore();

		return;
	}
}