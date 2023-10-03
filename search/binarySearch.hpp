#pragma once
#include <vector>
#include "../parse/parse.hpp"

// Search if the same value exists to the left side
void searchByLeft(const std::string& input, const std::vector<Info>& vec, const int mid, std::vector<Info>& output);
// Search if the same value exists to the right side
void searchByRight(const std::string& input, const std::vector<Info>& vec, const int mid, std::vector<Info>& output);
// Binary Search algorithm to find the data structs that they have the same value as the comparison input
std::vector<Info> binarySearch(const std::string& input, const std::vector<Info>& vec);