#pragma once
#include "../linkedList/linkedList.hpp"

// Search if the same value exists to the left side
void searchByLeft(const std::string& input, Node* node, LinkedList& output);
// Search if the same value exists to the right side
void searchByRight(const std::string& input, Node* node, LinkedList& output);
// Binary Search algorithm to find the data structs that they have the same value as the comparison input
LinkedList binarySearch(const LinkedList& list, const std::string& input);
