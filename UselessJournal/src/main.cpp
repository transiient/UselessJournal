#define KEY_MENU_DOWN   80
#define KEY_MENU_UP     72
#define KEY_ENTER       13

#include <iostream>
#include <conio.h>
#include <string>

#include "io.h"
#include "ModeSelector.h"
#include "Notes.h"

using namespace std;

// Runs on launch (yay)
int main() {
	cout << "Welcome to UselessJournal - The journal application that doesn't save your notes!" << endl;

	int selected;
	ModeSelector ms;
	ms.selector(selected);

	switch (selected) {
	case 0:
		// 0 is New Note
		NotesManager.newNote();
	case 1:
		// 1 is Modify Note
	case 2:
		// 2 is Exit
		cout << "Bye!" << endl;
		exit(0);
	}
}