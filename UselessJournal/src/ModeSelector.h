#pragma once
//TODO: Rewrite this, it's disgusting.

#include <iostream>
#include <string>
#include <vector>
#include "util/Clearwindow.h"

// MODE SELECTOR
class ModeSelector {
	// Current selection
	int currentSelection = 0;

	// Change id's state to selected
	void makeSelected(int id) {
		currentSelection = id;
		refreshMenu();
	}
	// Get id's state
	std::string isSelected(int id) {
		if (currentSelection == id) {
			return "[>]";
		}
		else {
			return "[ ]";
		}
	}

	std::vector<std::string> m_Choices = { // Make use of this instead of the current implementation
		"Create a note",
		"Manage my notes",
		"Exit (and delete notes)"
	};

public:
	// Select a mode using raw console input
	void refreshMenu() {
		for (int i = 0; i < 30; i++) std::cout << std::endl; // Clear window

		std::cout << "Select an operation (use W, S and Enter to select):" << std::endl << std::endl;

		std::cout << isSelected(0) << " New entry" << std::endl;
		std::cout << isSelected(1) << " Modify entry" << std::endl;
		std::cout << isSelected(2) << " Exit (and delete notes)" << std::endl;
	}

	int selector(int &variable) {
		bool selected = 0;

		refreshMenu();

		int inputchar, inputchartest;

		while (selected == 0) {
			//if (GetAsyncKeyState(VK_RETURN) & 0x8000) { ... }

			// works for Enter, not for anything else.
			inputchartest = _getch();
			//clog << "got key press - " << inputchartest;
			if (inputchartest == 0 || inputchartest == 0xE0) {
				inputchar = _getch();
				//clog << "0, " << inputchar << endl;
			}
			else {
				//clog << "not 0" << endl;
				inputchar = inputchartest;
			}

			if (inputchar == KEY_MENU_DOWN) {
				//clog << "was key arrow down" << endl;
				if (currentSelection == 2) {
					makeSelected(0);
				}
				else {
					makeSelected(currentSelection + 1);
				}
			}
			else if (inputchar == KEY_MENU_UP) {
				//clog << "was key arrow up" << endl;
				if (currentSelection == 0) {
					makeSelected(2);
				}
				else {
					makeSelected(currentSelection - 1);
				}
			}
			else if (inputchar == KEY_ENTER) {
				//clog << "was key enter" << endl;
				selected = 1;
				variable = currentSelection;
				return currentSelection;
			}
		}
	}
};
