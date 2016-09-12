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

// ------------
// Public
// ------------

void ModeSelector::setType(std::string newType) {
	m_MenuType = newType;
}

std::string ModeSelector::getType() {
	return m_MenuType;
}

void ModeSelector::setDefaultChoices() {
	m_CurrentChoices = m_DefaultChoices;
}

void ModeSelector::updateChoices(std::vector<std::string> newChoices) {
	m_CurrentChoices = newChoices;
	refreshMenu();
}

void ModeSelector::refreshMenu() {
	// Clear screen to redraw
	for (int i = 0; i < 60; i++) std::cout << std::endl;

	std::cout << "Useless Journal :: " << m_MenuType << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << "Select an option (use the Up and Down arrows, Enter to select):" << std::endl << std::endl;

	// Generate menu from m_CurrentChoices
	for (int i = 0; i < m_CurrentChoices.size(); i++) {
		std::cout << isSelected(i) << " " << m_CurrentChoices[i] << std::endl;
	}
}

void ModeSelector::selector(int &variable) {
	if (m_CurrentChoices.size() == 0) {
		setDefaultChoices();
	}

	bool selected = 0;

	refreshMenu();

	int inputchar, inputchartest;

	while (selected == 0) {
		inputchartest = _getch();
		if (inputchartest == 0 || inputchartest == 0xE0) inputchar = _getch(); // Arrow keys input blank first, then the actual value. Annoying, huh?
		else inputchar = inputchartest;

		if (inputchar == KEY_MENU_DOWN) {
			if (currentSelection == m_CurrentChoices.size() - 1) // If the current selection is the last index
				makeSelected(0);
			else
				makeSelected(currentSelection + 1);
		}
		else if (inputchar == KEY_MENU_UP) {
			if (currentSelection == 0)
				makeSelected(m_CurrentChoices.size() - 1);
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