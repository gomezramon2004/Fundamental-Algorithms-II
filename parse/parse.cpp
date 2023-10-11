#include "parse.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <iostream>

// Function to parse data from a file and create a linked list of Info objects.
LinkedList parse(std::string fileName) {
    std::ifstream inputFile(fileName);  // RAII is responsible for destruct the file-handling object out of scope. It will handle file closing automatically
    if (!inputFile.is_open()) {
        throw std::runtime_error("Error - Unable to open the file.");
    }
    
    // Count the number of lines in the file to determine the number of records.
    const size_t LINE_COUNT = std::count_if(std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>(), [](char c) { return c == '\n'; }); 
    inputFile.seekg(0); // Sets the position from the input stream to the start
    Info parsedNode; 
    LinkedList list;

    for (size_t i = 0; i < LINE_COUNT; ++i) {
        std::string line;
        std::getline(inputFile, line); // Read a line from the file.

        std::string dateTime = line.substr(0, 16); // Extract the date and time from the line.
        struct tm timeStruct;
        std::time_t time = mktime(&timeStruct); // Convert the date and time to a time_t object.

        std::istringstream ss(dateTime);
        ss >> std::get_time(&timeStruct, "%d/%m/%Y %H:%M"); // Parse the date and time into a tm structure.

        parsedNode = {time, timeStruct, line[17], line.substr(19, 24)}; // Create an Info object with parsed data.
        list.insertNode(parsedNode); // Insert the Info object into the linked list.
    }
    
    return list; // Return the linked list containing the parsed records.
}

// strptime(dateTime,"%d/%m/%Y %H:%M", &timeStruct); We can't use strptime because Windows isn't POSIX Compliant
// https://stackoverflow.com/questions/321849/strptime-equivalent-on-windows
// https://www.quora.com/Why-doesnt-Microsoft-make-Windows-POSIX-compliant 
