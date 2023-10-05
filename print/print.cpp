#include "print.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

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

void print(const LinkedList& list) {
    Node* temp = list.head;
    while (temp != nullptr) {
        std::cout << std::setfill('0') << std::setw(2) << temp->info.dateTime.tm_mday << '/' << 
        std::setfill('0') << std::setw(2) << temp->info.dateTime.tm_mon + 1 << '/' << 
        temp->info.dateTime.tm_year + 1900 << ' ' << 
        std::setfill('0') << std::setw(2) << temp->info.dateTime.tm_hour << ":" << 
        std::setfill('0') << std::setw(2) << temp->info.dateTime.tm_min << " " << 
        temp->info.enterPoint << " " << 
        temp->info.ubi << "\n";
        temp = temp->next;
    }
}



