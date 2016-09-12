#include "ModeSelector.h"

// Change id's state to selected
void ModeSelector::makeSelected(int id) {
	currentSelection = id;
	refreshMenu();
}

// Get id's state
std::string ModeSelector::isSelected(int id) {
	if (currentSelection == id) {
		return ">";
	}
	else {
		return " ";
	}
}

void ModeSelector::setDefaultChoices() { m_CurrentChoices = m_DefaultChoices; }

void ModeSelector::updateChoices(std::vector<std::string> newChoices) {
	m_CurrentChoices = newChoices;
	refreshMenu();
}

// ------------
// Refresh menu
// ------------

void ModeSelector::refreshMenu() {
	for (int i = 0; i < 30; i++) std::cout << std::endl;

	std::cout << "Select an operation (use W, S and Enter to select):" << std::endl << std::endl;

	// Generate menu
	for (int i = 0; i < m_DefaultChoices.size(); i++) {
		std::cout << isSelected(i) << " " << m_DefaultChoices[i] << std::endl;
	}
}

void ModeSelector::selector(int &variable) {
	setDefaultChoices();

	bool selected = 0;

	refreshMenu();

	int inputchar, inputchartest;

	while (selected == 0) {
		inputchartest = _getch();
		if (inputchartest == 0 || inputchartest == 0xE0) inputchar = _getch(); // Arrow keys input blank first, then the actual value. Annoying, huh?
		else inputchar = inputchartest;

		if (inputchar == KEY_MENU_DOWN) {
			if (currentSelection == 2)
				makeSelected(0);
			else
				makeSelected(currentSelection + 1);
		}
		else if (inputchar == KEY_MENU_UP) {
			if (currentSelection == 0)
				makeSelected(2);
			else
				makeSelected(currentSelection - 1);
		}
		else if (inputchar == KEY_ENTER) {
			selected = 1;
			variable = currentSelection;
			return;
		}
	}
}