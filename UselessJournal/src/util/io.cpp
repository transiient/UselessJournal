#include "io.h"

// Keep these as they are for now, TODO: Make these editable by changing the way openJournalFromFile works
#define NOTE_TITLE_PREFIX "##T"
#define NOTE_BODY_PREFIX  "##B"
#define NOTE_LINE_AFTER   "##D"

#define LOG(st) std::cout << st << std::endl

// Default path to save to
const std::string IO::defaultJournalPath = "journal.uj";

// Open journal from a specified file
bool IO::openJournalFromFile(std::vector<note> &notes, std::string path) {
	std::ifstream journalFileStream(path);
	std::vector<std::string> LINES;
	int iterator = 1;

	if (journalFileStream.good()) {
		while (!journalFileStream.eof()) {
			LOG("Getting line");
			LOG(iterator);

			std::string lineTmp;
			std::getline(journalFileStream, lineTmp); // this failed when it used LINES[iterator] because you need to use push_back instead!
			LINES.push_back(lineTmp);

			LOG("    Got line");
			++iterator;
		}
	}
	else {
		LOG("Couldn't open file.");
	}

	// For each line, check what it is by the prefixes at the top and set up notes
	for (int i = 0; i < LINES.size(); i++) {
		std::string curLn = LINES[i]; // current line
		std::string title, body;

		if (curLn[0] == '#' && curLn[1] == '#') { // If it's made by this script
			if (curLn[2] == 'T') { // Title field
				title = LINES[i];
				title.erase(0, 2);
			}
			else if (curLn[2] == 'B') { // Body field
				body = LINES[i + 1];
				body.erase(0, 2);
			}

			notes.push_back(note(title, body));
		}
	}

	journalFileStream.close();
	LOG("Loaded");
	return 1;
}
// Open from default path (folder root)
bool IO::openJournalFromFile(std::vector<note> &notes) {
	return openJournalFromFile(notes, defaultJournalPath);
}

/*
  Save to specified file

  Params: notes (vector) - The vector to be saved
		  path           - The full path to save to, including filename and extension
*/
bool IO::saveJournalToFile(std::vector<note> notes, std::string path) {
	std::ofstream journalFileStream(path);

	if (journalFileStream.good()) {
		LOG("Successfully opened file");

		for (int i = 0; i < notes.size(); i++) {
			journalFileStream << NOTE_TITLE_PREFIX << " " << notes[i].getNoteTitle() << std::endl;
			journalFileStream << NOTE_BODY_PREFIX  << " " << notes[i].getNoteBody()  << std::endl;
			journalFileStream << NOTE_LINE_AFTER   << std::endl;
		}
	}
	else {
		LOG("Couldn't open file.");
	}
	
	journalFileStream.close();
	LOG("Saved");
	return 1;
}
// Save to default path (folder root)
bool IO::saveJournalToFile(std::vector<note> notes) {
	return saveJournalToFile(notes, defaultJournalPath);
}

// Export as .txt
bool IO::exportJournalToTxt(std::string inPath, std::string outPath) {
	return 0;
}
// Export as .xml
bool IO::exportJournalToXml(std::string inPath, std::string outPath) {
	return 0;
}