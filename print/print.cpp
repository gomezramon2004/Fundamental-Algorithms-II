#include "print.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <map>

/*
    To replicate the same format as the input, std::setfill and std::setw will reserve the 
    field width (in this case, two zeros) and place the date value to the right. tm_mon has 
    a range of 0 to 11, and tm_year starts counting from the year 1900.
*/

// void print(const LinkedList& list) {
//     for (auto &&i : list) {
//         std::cout << std::setfill('0') << std::setw(2) << i.dateTime.tm_mday << '/' << 
//         std::setfill('0') << std::setw(2) << i.dateTime.tm_mon + 1 << '/' << 
//         i.dateTime.tm_year + 1900 << ' ' << 
//         std::setfill('0') << std::setw(2) << i.dateTime.tm_hour << ":" << 
//         std::setfill('0') << std::setw(2) << i.dateTime.tm_min << " " << 
//         i.enterPoint << " " << 
//         i.ubi << "\n";
//     }
// }

std::string get_month_name(int index) {
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

    const auto iter = monthNames.find(index);
    if (iter != monthNames.cend())
        return iter->second;
    return "Invalid Month";
}

void print(const LinkedList& list1, const LinkedList& list2) {
    Node* temp1 = list1.head;
    Node* temp2 = list2.head;

    for (size_t i = 0; i < 12; i++) {
        int counter1 = 0;
        int counter2 = 0;

        while (temp1 && temp1->info.dateTime.tm_mon == i) {
            ++counter1;
            temp1 = temp1->next;
        }

        while (temp2 && temp2->info.dateTime.tm_mon == i) {
            ++counter2;
            temp2 = temp2->next;
        }

        std::cout << get_month_name(i + 1) << " " << temp1->info.dateTime.tm_year - 100 << " " << counter1 << " " << counter2 << "\n";
    }
}

