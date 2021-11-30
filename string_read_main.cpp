// string_read_main.cpp
// A. Harrison Owen
// 2021-11-29
//
// For CS 311 Fall 2021
// Required files to run: string_read.cpp, string_read.hpp
//
// Description: Program reads a user specified file and
//              prints each unique word in the file as well as
//              the frequency it appears in the file.
//
// Invariants: Program looks for (or opens) file in the debug folder for the .cpp files.
//
#include "string_read.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <map>
using std::map;
#include <algorithm>
using std::equal;
#include <cstddef>
using std::size_t;

// returns bool
// checks if user specified a .txt file
bool checkUserInput(const string & filename){
    if(filename.size() <= 4) {
        cout << "User did not specify a filename with ";
        cout << "a file format extension\n...how sad :(\n";
        cout << "Exiting code.\n";
        return false;
    }
    return true;
}


// Takes user input to read a file
// If user wants to exit program, hit ENTER until the
// "Program complete." message appears.
//
int main() {
	map<string, size_t> wordsInFile;
	string getFileName;
	cout << "Enter a file or hit ENTER to quit: ";
	getline(cin, getFileName);
	//keeps running until user hits ENTER key
	while (checkUserInput(getFileName)) {
		if (readFile(wordsInFile, getFileName)) {
			string print = printMap(wordsInFile).str();
			cout << print << endl;
		}
		cout << "Enter file or hit ENTER to quit: ";
		getline(cin, getFileName);
		wordsInFile.clear();
	}
	cout << "\nProgram complete. Have an absolutely wonderful day :))" << endl;
}
