#pragma once

#include <string>
#include <vector>

// Single Note
class note {
	std::string noteTitle, noteBody;
public:
	note(std::string noteTitle, std::string noteBody);
	~note();

	std::string getNoteBody(); // returns: current body
	std::string changeNoteBody(std::string newNoteBody); // returns: new body

	friend bool operator==(const note &l, const note &r) {
		return (l.noteTitle == r.noteTitle && l.noteBody == r.noteBody);
	}
};