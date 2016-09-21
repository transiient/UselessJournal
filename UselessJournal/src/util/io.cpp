#include "io.h"

// Keep these as they are for now, TODO: Make these editable by changing the way openJournalFromFile works
#define NOTE_TITLE_PREFIX "##T"
#define NOTE_BODY_PREFIX  "##B"

#define LOG(st) std::cout << st << std::endl

// Default path to save to
const std::string IO::defaultJournalPath = "journal.uj";

// Open journal from a specified file
bool IO::openJournalFromFile(std::vector<note> &notes, std::string path) { /*! *** MEMORY LEAK *** !*/
	std::ifstream journalFileStream(path); // File stream
	std::vector<std::string> LINES; // Vector to store every line of the file in

	if (journalFileStream.good()) {
		notes = {};

		while (!journalFileStream.eof()) {
			std::string line; std::getline(journalFileStream, line);	 // Get line
			LINES.push_back(line);										 // and push it to the back
		}
	}
	else { LOG("Couldn't open file."); }

	for (int i = 0; i < LINES.size(); i += 2) { // For each 2 lines, check what they are by the prefixes and set up notes
		if (LINES[i][0] == '#' && LINES[i][1] == '#') { // If it's prefixed
			std::string xtitle, xbody; // Create variables

			if (LINES[i][2] == 'T' && LINES[i + 1][2] == 'B') { // Check the next characters
				xtitle = LINES[i];
				xbody  = LINES[i + 1];
			}

			xtitle.erase(0, 4);
			xbody.erase(0, 4);

			notes.push_back(note(xtitle, xbody)); // Create a note and push it into the notes vector
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
	if (!remove(path.c_str())) { LOG("Deleted old file"); }

	std::ofstream journalFileStream(path);

	if (journalFileStream.good()) {
		LOG("Successfully opened new file");

		for (int i = 0; i < notes.size(); i++) {
			journalFileStream << NOTE_TITLE_PREFIX << " " << notes[i].getNoteTitle() << std::endl;
			journalFileStream << NOTE_BODY_PREFIX  << " " << notes[i].getNoteBody()  << std::endl;
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
bool IO::saveJournalToFile(std::vector<note> notes) { // not tested
	return saveJournalToFile(notes, defaultJournalPath);
}

// Export as .txt
bool IO::exportJournalToTxt(std::string inPath, std::string outPath) {
	std::vector<note> notes;
	openJournalFromFile(notes, inPath);
	std::ofstream exportFileStream(outPath);

	if (exportFileStream.good()) {
		LOG("Opened output file");

		exportFileStream << "Useless Journal exported notes\n\n" << std::endl;

		for (int i = 0; i < notes.size(); i++) {
			exportFileStream << notes[i].getNoteTitle() << std::endl;
			exportFileStream << "    " << notes[i].getNoteBody() << std::endl;
		}
	}
	else {
		LOG("Couldn't open file.");
	}

	exportFileStream.close();
	LOG("Saved");
	return 0;
}
// Export as .xml
bool IO::exportJournalToXml(std::string inPath, std::string outPath) {
	return 0;
}
// Export as .html
bool IO::exportJournalToHtml(std::string inPath, std::string outPath) { // not tested
	std::vector<note> notes;
	openJournalFromFile(notes, inPath);
	std::ofstream exportFileStream(outPath);

	if (exportFileStream.good()) {
		LOG("Opened output file");

		exportFileStream << "<html><head><title>Useless Journal - Exported notes</title></head><body>" << std::endl;

		for (int i = 0; i < notes.size(); i++) {
			exportFileStream << "<div class='note'>\n";
			exportFileStream << "<h1>" << notes[i].getNoteTitle() << "</h1>\n";
			exportFileStream << "<p>" << notes[i].getNoteBody() << "</p>\n";
			exportFileStream << "</div>" << std::endl;
		}

		exportFileStream << "</body></html>" << std::endl;
	}
	else {
		LOG("Couldn't open file.");
	}

	exportFileStream.close();
	LOG("Saved");
	return 0;
}