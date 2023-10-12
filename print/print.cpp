#include "print.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <map>

// Function to get the name of a month based on its index.
std::string get_month_name(int index) {
    // Create a map that associates month indices with month names.
   std::map<int, std::string> monthNames {
        {1, "jan"},
        {2, "feb"},
        {3, "mar"},
        {4, "apr"},
        {5, "may"},
        {6, "jun"},
        {7, "jul"},
        {8, "aug"},
        {9, "sep"},
        {10, "oct"},
        {11, "nov"},
        {12, "dec"}
    };
    // Attempt to find the month name for the given index in the map
    const auto iter = monthNames.find(index);
    if (iter != monthNames.cend())
        return iter->second;
    return "Invalid Month"; // Return "Invalid Month" if the index is not found in the map.
}

void print(const LinkedList& list1, const LinkedList& list2) {
    Node* temp1 = list1.head; // Initialize a pointer for the first linked list.
    Node* temp2 = list2.head; // Initialize a pointer for the second linked list.
    size_t i = 0, year = 0, counter1 = 0, counter2 = 0;// Initialize counters for months, years, and each list.

    // Determine the starting month and year by comparing the first entries from both lists.
    temp1->info.dateTime.tm_mon < temp2->info.dateTime.tm_mon ? i = temp1->info.dateTime.tm_mon : i = temp2->info.dateTime.tm_mon;
    temp1->info.dateTime.tm_year < temp2->info.dateTime.tm_year ? year = temp1->info.dateTime.tm_year : year = temp2->info.dateTime.tm_year;

    while (temp1 || temp2) { // Continue looping as long as there are elements in either list.


        // Count the entries for the current month in the first list.
        while (temp1 && temp1->info.dateTime.tm_mon == i) {
            ++counter1;
            temp1 = temp1->next;
        }

        // Count the entries for the current month in the second list.
        while (temp2 && temp2->info.dateTime.tm_mon == i) {
            ++counter2; 
            temp2 = temp2->next;
        }

        // Print the month, year, and the counts of entries from both lists.
        std::cout << get_month_name(i + 1) << " " << year - 100  << " " << counter1 << " " << counter2 << "\n";

        // Move to the next month and update the year if necessary.
        i + 1 == 12 ? ++year, i = 0 : ++i;

        // Restart counters for each list.
        counter1 = 0, counter2 = 0;
    }
}
