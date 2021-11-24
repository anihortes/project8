#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
using std::to_string;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ifstream;
#include <map>
using std::map;
#include <iomanip>
using std::setw;
#include <algorithm>
using std::transform;
#include <cstddef>
using std::size_t;

// See header file for implementation
void cleanWords(map <string, size_t> & words, const string & line) {
    // take a line of a file and put it on the stringstream for parsing
	istringstream iStringStreamOnLine(line);
	string str; // dummy string used to look in stringstream
	// str will point to each word on the line of the file until reaching '\n'
	while (iStringStreamOnLine >> str) {
		// Turn all words to lower case for consistency
		transform(str.begin(), str.end(),
			str.begin(), ::tolower);

		// Remove characters that aren't in the alphabet
		str.erase(std::remove_if(str.begin(), str.end(),
			[](char c) {
			return  (c <= -1 || c >= 255)
				|| std::isspace(c) || !std::isalpha(c);
            }),
        str.end());

		// If word is found add to value
		if (words.count(str) != 0) {
			words[str] ++;
		}

		// removes empty strings
		else if (str.empty()) {
			str = "";
			words.erase("");
		}

		// if word is not found set value to 1
		else {
			words[str] = 1;
		}
	}
}

// See header file for implementation
bool readFile(map <string, size_t> & words, const string & getFileName) {
	ifstream fin(getFileName);
	while (!fin) {
		cout << "Error finding file." << endl;
		return false;
	}
	while (true) {
		string line;
		getline(fin, line);
		if (!fin) {
			if (fin.eof()) {
				cout << "Finished reading file." << endl;
			}
			else {
				cout << "Error during transmit." << endl;
			}
			return true;
		}
		cleanWords(words, line);
	}
	return true;
}

// Iterate through map and find largest word
size_t maxElement(const map<string, size_t> & words) {
	size_t largeWord = 0;
	for (const auto & p : words) {
		if (p.first.size() > largeWord) {
            largeWord = p.first.size();
		}
	}
	return largeWord;
}

// See header file for implementation
std::ostringstream printMap(const map<string, size_t> & words) {
	std::ostringstream ss1;
	// sets distance between keys and values to a constant distance for ease of reading
	ss1 << "WORD" << std::setw(maxElement(words) + 2) << "COUNT" << endl;
	for (const auto & p : words) {
		size_t set = p.first.size() - to_string(p.second).size();
		ss1 << p.first << std::setw(maxElement(words) + 1 - set) << p.second << endl;
	}
	return ss1;
}
