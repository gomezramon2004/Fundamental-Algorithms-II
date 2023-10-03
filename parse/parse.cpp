#include "parse.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <iomanip>

std::vector<Info> parse(std::string fileName) {
    std::ifstream inputFile(fileName);  // RAII is responsible for destruct the file-handling object out of scope. It will handle file closing automatically
    if (!inputFile.is_open()) {
        throw std::runtime_error("Error - Unable to open the file.");
    }
    
    const size_t LINE_COUNT = std::count_if(std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>(), [](char c) { return c == '\n'; }); // Count the number of '\n' from the input stream (number of lines)
    inputFile.seekg(0); // Sets the position from the input stream to the start
    std::vector<Info> parsedVec(LINE_COUNT); // Initialize the size of the vector

    for (size_t i = 0; i < LINE_COUNT; ++i) {
        std::string line;
        std::getline(inputFile, line);
        std::string dateTime = line.substr(0, 16); // Substract the datetime characters
        struct tm timeStruct;
        std::time_t time = mktime(&timeStruct); 

        std::istringstream ss(dateTime);
        ss >> std::get_time(&timeStruct, "%d/%m/%Y %H:%M");
        
        parsedVec[i] = {time, timeStruct, line[17], line.substr(19, 24)};
    }

    return parsedVec;
}

// strptime(dateTime,"%d/%m/%Y %H:%M", &timeStruct); We can't use strptime because Windows isn't POSIX Compliant
// https://stackoverflow.com/questions/321849/strptime-equivalent-on-windows
// https://www.quora.com/Why-doesnt-Microsoft-make-Windows-POSIX-compliant 