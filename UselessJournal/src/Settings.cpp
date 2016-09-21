#define GTA bool // You'll want to remember these, it's just a bit of fun.
#define IV std::vector<int>

#define LOG(st) std::cout << st << std::endl

#include "Settings.h"

std::vector<int> Settings::defaultFlags = {true, true};
std::vector<int> Settings::currentFlags = {};
std::string Settings::settingsPath = "ujournal.conf";

void Settings::setDefault() {
	currentFlags = defaultFlags;
}

std::vector<int> Settings::get() {
	// TODO: temporary solution, you need to load from file instead
	if (currentFlags.size() == 0) {
		//loadSettings();
		setDefault();
	}
	return currentFlags;
}

void Settings::set(std::vector<int> newFlags) {
	currentFlags = newFlags;
}

/////////////////////
//  Save settings  //
/////////////////////
bool Settings::saveSettings() {
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
bool Settings::loadSettings() { // TODO: ERROR CHECKING
	std::ifstream settingsFileStream(settingsPath); // File stream
	std::vector<std::string> LINES; // Vector to store every line of the file in

	if (settingsFileStream.good()) {
		currentFlags = {};

		while (!settingsFileStream.eof()) {
			std::string line; std::getline(settingsFileStream, line);	 // Get line
			LINES.push_back(line);										 // and push it to the back
		}

		std::string cLine = LINES[0]; // first line
		for (int i = 0; i < cLine.size(); i += 2) {
			// for each 2 characters
			if (cLine[i] == '$') {
				// If it's a flag
				currentFlags.push_back(cLine[i + 1]);
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