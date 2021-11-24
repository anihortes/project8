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
    //string txt = ".txt";
    //return std::equal(filename.end()-4, filename.end(), txt.begin());
    return true;
}

/*
 * Takes user input to read a file
 * If user wants to exit program, hit ENTER until
 * "Program complete." message appears.
 */
int main() {
	map<string, size_t> words;
	string getFileName;
	cout << "Enter a file or hit ENTER to quit: ";
	getline(cin, getFileName);
	//keeps running until user hits ENTER key
	while (checkUserInput(getFileName)) {
		if (readFile(words, getFileName)) {
			string print = printMap(words).str();
			cout << print << endl;
		}
		cout << "Enter file or hit ENTER twice to quit: ";
		getline(cin, getFileName);
		words.clear();
	}
	cout << "\nProgram complete. Have an absolutely wonderful day :))" << endl;
}
