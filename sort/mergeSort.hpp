#pragma once
#include <vector>
#include "../parse/parse.hpp"

// Compare the vectors based on their UBIs and Dates
bool compareInfo(const Info& info1, const Info& info2);
// Merge sort algorithm: merge section
void merge(LinkedList& vec, int left, int mid, int right);
// Merge sort algorithm: recursive section
void mergeSort(LinkedList& vec, int left, int right);