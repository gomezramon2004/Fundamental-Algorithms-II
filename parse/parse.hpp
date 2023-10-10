#pragma once
#include <string>
#include <vector>
#include "../linkedList/linkedList.hpp"

struct Info {
    time_t timeValue; // Value that counts in seconds from 01/01/1970 to the corresponding date
    struct tm dateTime; // Struct that holds the data of our date
    char enterPoint;
    std::string ubi;
};

// Parse the info into a struct named Info
std::vector<Info> parse(std::string fileName);