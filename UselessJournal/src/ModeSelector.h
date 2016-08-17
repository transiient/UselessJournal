#pragma once

#include <iostream>
#include <string>
#include "util/Clearwindow.h"
using namespace std;

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
	string isSelected(int id) {
		if (currentSelection == id) {
			return "[>]";
		}
		else {
			return "[ ]";
		}
	}

public:
	// Select a mode using raw console input
	void refreshMenu() {
		for (int i = 0; i < 30; i++) cout << endl; // Clear window

		cout << "Select an operation (use W, S and Enter to select):" << endl << endl;

		cout << isSelected(0) << " New entry" << endl;
		cout << isSelected(1) << " Modify entry" << endl;
		cout << isSelected(2) << " Exit (and delete notes)" << endl;
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
