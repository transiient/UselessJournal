#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#define KEY_MENU_DOWN   80
#define KEY_MENU_UP     72
#define KEY_ENTER       13

// Menu framework
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

	std::string m_MenuType = "Menu";

public:
	// Set the menu type
	void setType(std::string newType);
	// Get the current menu type (default: "Menu")
	std::string getType();
	
	// Set the menu choices back to default
	void setDefaultChoices();
	// Update the list of menu choices with new ones!
	void updateChoices(std::vector<std::string> newChoices);
	
	// Refresh and redraw the menu
	void refreshMenu();

	// Show the menu
	void selector(int &variable);
};
