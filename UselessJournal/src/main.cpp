#include <iostream>
#include <string>
/*
#include "NoteManager.h"
#include "ModeSelector.h"
#include "Settings.h"
*/
#include "awe/interface.h"
/*
int main() {
	int selected = 0;
	ModeSelector mainMenu;
	
	mainMenu.setType("Main Menu");
	mainMenu.updateChoices({
		"Create a note",
		"Manage my notes",
		"Save my notes",
		"Load my notes",
		"Edit settings",
		"Exit"
	});

	// Load settings
	Settings::loadAll();

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
		case 4: // Edit settings
			Settings::editWizard();
			selected = 0;
			break;
		case 5: // Exit
			if (Settings::getSaveOnExit()) {
				NoteAPI::saveNotes();
				std::cout << "Saved your notes. ";
			}
			Settings::saveAll();
			std::cout << "Now exiting..." << std::endl;
			return 0;
		}
	}

	system("PAUSE"); // temp
	return 0;
	

	return UJUI::Interface();
}*/

#ifdef _WIN32
int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE, wchar_t*, int nCmdShow) {
#else
int main() {
#endif

	UJApp app;
	app.Run();

	return 0;
}