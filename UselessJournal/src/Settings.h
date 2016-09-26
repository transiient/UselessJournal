#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream> // TODO: Maybe this should be inside IO.h instead?
#include "ModeSelector.h"

class Settings {
private:
	static std::vector<std::string> flagDefinitionsForEditWizard;
	static std::vector<bool> defaultFlags; // Default settings
	static std::vector<bool> currentFlags; // Current settings
	static std::string settingsPath;
public:
	// Set settings back to default values
	static void setDefault();
	// Get the current settings -- TODO: Maybe make this private?
	static std::vector<bool> get();
	// Set new settings -- TODO: Maybe make this private?
	static void set(std::vector<bool> newFlags);

	/////////////////////
	//  Save settings  //
	/////////////////////
	static bool saveAll();
	static bool loadAll();

	/////////////////////
	//  Get settings   //
	/////////////////////
	static bool Settings::getSaveOnExit();
	static bool Settings::getLoadOnStart();

	/////////////////////
	// Manage settings //
	/////////////////////
	static void editWizard();
	static void setEnableSaveOnExit(bool b);
	static void setEnableLoadOnStart(bool b);
};