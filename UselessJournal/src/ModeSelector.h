#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#define KEY_MENU_DOWN   80
#define KEY_MENU_UP     72
#define KEY_ENTER       13

// MODE SELECTOR
class ModeSelector {
	// Current selection
	int currentSelection = 0;

	// Change id's state to selected
	void makeSelected(int id);

	// Get id's state
	std::string isSelected(int id);

	// The default menu options
	std::vector<std::string> m_DefaultChoices = {
		"Create a note",
		"Manage my notes",
		"Exit (and delete notes)"
	};
	// This can be edited using UpdateChoices() to add different options
	std::vector<std::string> m_CurrentChoices;

public:
	void setDefaultChoices();
	void updateChoices(std::vector<std::string> newChoices);
	
	void refreshMenu();

	void selector(int &variable);
};
