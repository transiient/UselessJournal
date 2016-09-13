#include <iostream>
#include <string>

#include "NoteManager.h"
#include "ModeSelector.h"

int main() {
	int selected = 0;
	ModeSelector mainMenu;

	mainMenu.setType("Main Menu");

	while (!selected) {
		mainMenu.selector(selected);

		switch (selected) {
		case 0: // New Note
			NoteAPI::newNoteWizard();
			selected = 0;
			break;
		case 1: // Manage Notes
			NoteAPI::manageNotes();
			selected = 0;
			break;
		case 2: // Save Notes
			NoteAPI::saveNotes();
			selected = 0;
			break;
		case 3: // Save Notes
			NoteAPI::loadNotes();
			selected = 0;
			break;
		case 4:
			std::cout << "Bye!" << std::endl;
			return 0;
		}
	}

	system("PAUSE"); // temp
	return 0;
}