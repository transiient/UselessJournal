#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "../Notes.h"

/* Common file IO operations */

class IO {
private:
	static const std::string defaultJournalPath; // Default path to save to
	static const int retryCount = 5; // Maximum number of load/save retries before failing
	static const int retryDelay = 2000; // Delay between retries
public:
	// Open journal from a specified file
	static bool openJournalFromFile(std::vector<note> &notes, std::string path);
	// Open from default path (folder root)
	static bool openJournalFromFile(std::vector<note> &notes);

	// Save to specified file
	static bool saveJournalToFile(std::vector<note> notes, std::string path);
	// Save to default path (folder root)
	static bool saveJournalToFile(std::vector<note> notes);

	// Export as .txt
	static bool exportJournalToTxt(std::string inPath, std::string outPath);
	// Export as .xml
	static bool exportJournalToXml(std::string inPath, std::string outPath);
};