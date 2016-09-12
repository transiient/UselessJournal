#define KEY_MENU_DOWN   80
#define KEY_MENU_UP     72
#define KEY_ENTER       13

#include <iostream>
#include <conio.h>
#include <string>

//#include "io.h"
#include "NoteManager.h"
#include "ModeSelector.h"

int main() {
	std::cout << "Welcome to UselessJournal - The journal application that doesn't save your notes after closing!" << std::endl;

	int selected;
	ModeSelector selector;
	selector.selector(selected);

	switch (selected) {
	case 0:
		// 0, New Note
		NoteAPI::newNoteWizard();
	case 1:
		// 1, Modify Note // Will become "Manage notes" (print list of notes with options below)
		
	case 2:
		// 2, Exit
		std::cout << "Bye!" << std::endl;
		return 0;
	}
}