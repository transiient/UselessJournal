#define GTA bool // You'll want to remember these, it's just a bit of fun.
#define IV std::vector<bool>

#define LOG(st) std::cout << st << std::endl

#include "Settings.h"

std::vector<std::string> Settings::flagDefinitionsForEditWizard = {
	"Save on exit",
	"Load on start",
	"* Load default settings",
	"* Back to main menu"
};
std::vector<bool> Settings::defaultFlags = {true, true};
std::vector<bool> Settings::currentFlags = {};
std::string Settings::settingsPath = "ujournal.conf";

void Settings::setDefault() {
	currentFlags = defaultFlags;
}

IV Settings::get() {
	// TODO: temporary solution, you need to load from file instead
	if (currentFlags.size() == 0) {
		//loadSettings();
		setDefault();
	}
	return currentFlags;
}

void Settings::set(std::vector<bool> newFlags) {
	currentFlags = newFlags;
}

/////////////////////
//  Save settings  //
/////////////////////
bool Settings::saveAll() {
	if (!remove(settingsPath.c_str())) { LOG("Deleted old settings file"); }

	std::ofstream settingsFileStream(settingsPath);

	if (settingsFileStream.good()) {
		LOG("Successfully opened settings file");

		for (int i = 0; i < currentFlags.size(); i++) {
			settingsFileStream << "$" << currentFlags[i];
		}
	}
	else {
		LOG("Couldn't open settings file.");
		return 0;
	}

	settingsFileStream.close();
	LOG("Saved settings");
	return 1;
}
bool Settings::loadAll() { // TODO: ERROR CHECKING
	std::ifstream settingsFileStream(settingsPath); // File stream
	std::vector<std::string> LINES; // Vector to store every line of the file in

	if (settingsFileStream.good()) {
		currentFlags = {};

		while (!settingsFileStream.eof()) {
			std::string line; std::getline(settingsFileStream, line);	 // Get line
			LINES.push_back(line);										 // and push it to the back
		}

		if (LINES.size() == 0) {
			LOG("Settings file empty or non-existent");
			return 0;
		}

		std::string cLine = LINES[0]; // first line
		for (int i = 0; i < cLine.size(); i += 2) {
			// for each 2 characters
			if (cLine[i] == '$') {
				// If it's a flag
				if (cLine[i + 1] == 1 || cLine[i + 1] == 0) {
					currentFlags.push_back(cLine[i + 1]);
				}
			}
		}
	}
	else {
		LOG("Couldn't open settings file.");
		return 0;
	}

	settingsFileStream.close();
	LOG("Loaded settings");
	return 1;
}

/////////////////////
//  Get settings   //
/////////////////////
GTA Settings::getSaveOnExit() {
	IV curf = get();
	if (curf[0] == 1)	return true;
	else				return false;
}
GTA Settings::getLoadOnStart() {
	IV curf = get();
	if (curf[1] == 1)	return true;
	else				return false;
}

/////////////////////
// Manage settings //
/////////////////////
// Edit settings with a wizard
void Settings::editWizard() {
	int selected = 0;
	ModeSelector es;
	es.setType("Settings");

	while (selected == 0) {
		std::vector<std::string> choices = {};
		std::string current = "";
		for (int i = 0; i < flagDefinitionsForEditWizard.size(); i++) {
			IV curf = get();
			if (i >= curf.size()) {
				current = "";
			}
			else {
				current = curf[i] ? "(true)" : "(false)";
			}
			choices.push_back(flagDefinitionsForEditWizard[i] + "  " + current);
		}

		es.updateChoices(choices);

		es.selector(selected);
		IV curf;

		switch (selected) {
		case 0:
			curf = get();
			if (curf[0] == true)
				setEnableSaveOnExit(false);
			else
				setEnableSaveOnExit(true);
			selected = 0;
			curf.empty();
			break;
		case 1:
			curf = get();
			if (curf[1] == true)
				setEnableLoadOnStart(false);
			else
				setEnableLoadOnStart(true);
			selected = 0;
			curf.empty();
			break;
		case 2:
			setDefault();
			selected = 0;
			curf.empty();
			break;
		case 3:
			saveAll();
			break;
		}
	}
}
// Enable or disable "Save on exit"
void Settings::setEnableSaveOnExit(bool b) {
	IV curf = get();
	currentFlags = { b, curf[1] };
}
// Enable or disable "Load on startup"
void Settings::setEnableLoadOnStart(bool b) {
	IV curf = get();
	currentFlags = { curf[0], b };
}