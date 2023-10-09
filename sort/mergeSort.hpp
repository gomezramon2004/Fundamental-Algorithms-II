#pragma once
#include <vector>
#include "../parse/parse.hpp"

// Compare the vectors based on their UBIs and Dates
bool compareInfo(const Info& info1, const Info& info2, int option);
// Merge sort algorithm: merge section
LinkedList mergeLists(LinkedList& left, LinkedList& right, int option);

LinkedList mergeSort(LinkedList& list, int option);
