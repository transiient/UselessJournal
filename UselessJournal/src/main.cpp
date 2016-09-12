#include <iostream>
#include <string>

//#include "io.h"
#include "NoteManager.h"
#include "ModeSelector.h"

int main() {
	std::cout << "Welcome to UselessJournal - The journal application that doesn't save your notes after closing!" << std::endl;

	int selected = 0;
	ModeSelector mainMenu;

	while (!selected) {
		mainMenu.selector(selected);

		switch (selected) {
		case 0: // New Note
			NoteAPI::newNoteWizard();
			selected = 0;
		case 1: // Manage Notes
			NoteAPI::manageNotes();
			selected = 0;
		case 2: // Exit
			std::cout << "Bye!" << std::endl;
			break;
		}
	}

	return 0;
}