#ifndef STRING_READ_H
#define STRING_READ_H

#include <string>
// For std::string;
#include <sstream>
// for std::ostringstream;
#include <map>
// For std::map;
#include <cstddef>

// cleanWords
// Reads file line and adds strings (as a key) to a map on token at a time.
// The associated value is the frequency which the word appears in the file.
// Before adding to a strings map, words are set to lowercase and lose special characters
// If the string is already in the map, add associated count value by 1.
// Pre:
//     value in map must be modifiable
//     string line and map key cannot be modified
// Requirements on Types:
//     map must have key value of type string
// Exception safety guarantee:
//     No-Throw Guarantee
//     Exception neutral
void cleanWords(std::map<std::string, std::size_t> & words, const std::string & line);

// readFile
// Opens file for reading line by line. Closes when done.
// Pre:
//     Map must empty.
// Post:
//      File must be closed.
// Requirements on Types:
//     Map must be modifiable.
//     getfileName must not be modified.
// Exception safety guarantee:
//     Strong Guarantee
//     Exception neutral
bool readFile(std::map<std::string, std::size_t> & words, const std::string & getFileName);

// printMap
// Puts contents of a map into a string-stream for printing.
// Post:
//      Map must be in the same condition as it was before the function ran.
// Requirements on Types:
//     Map must not be modifiable.
// Exception safety guarantee:
//     No-Throw Guarantee
//     Exception neutral
std::ostringstream printMap(const std::map<std::string, std::size_t> & words);

#endif


