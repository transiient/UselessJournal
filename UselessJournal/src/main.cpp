#include <iostream>
#include <string>

//#include "io.h"
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
		case 2: // Exit
			std::cout << "Bye!" << std::endl;
			break;
		}
	}

	return 0;
}