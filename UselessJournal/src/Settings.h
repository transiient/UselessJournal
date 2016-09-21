#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream> // TODO: Maybe this should be inside IO.h instead?

class Settings {
private:
	static std::vector<int> defaultFlags; // Default settings
	static std::vector<int> currentFlags; // Current settings
	static std::string settingsPath;
public:
	// Set settings back to default values
	static void setDefault();
	// Get the current settings -- TODO: Maybe make this private?
	static std::vector<int> get();
	// Set new settings -- TODO: Maybe make this private?
	static void set(std::vector<int> newFlags);

	/////////////////////
	//  Save settings  //
	/////////////////////
	static bool saveSettings();
	static bool loadSettings();

	/////////////////////
	//  Get settings   //
	/////////////////////
	static bool Settings::getSaveOnExit();
	static bool Settings::getLoadOnStart();

	/////////////////////
	// Manage settings //
	/////////////////////
	static void setEnableSaveOnExit(bool b);
	static void setEnableLoadOnStart(bool b);
};