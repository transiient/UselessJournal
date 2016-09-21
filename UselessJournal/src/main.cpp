#include <iostream>
#include <string>

#include "NoteManager.h"
#include "ModeSelector.h"
#include "Settings.h"

int main() {
	int selected = 0;
	ModeSelector mainMenu;
	
	mainMenu.setType("Main Menu");
	mainMenu.updateChoices({
		"Create a note",
		"Manage my notes",
		"Save my notes",
		"Load my notes",
		"Exit"
	});

	// Load on startup, if enabled
	if (Settings::getLoadOnStart()) {
		NoteAPI::loadNotes();
	}

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
		case 3: // Load Notes
			NoteAPI::loadNotes();
			selected = 0;
			break;
		case 4: // Exit
			if (Settings::getSaveOnExit()) {
				NoteAPI::saveNotes();
				std::cout << "Saved your notes. ";
			}
			std::cout << "Now exiting..." << std::endl;
			return 0;
		}
	}

	system("PAUSE"); // temp
	return 0;
}