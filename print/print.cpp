#include "print.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <map>

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
    size_t i = 0, year = 0;

    temp1->info.dateTime.tm_mon < temp2->info.dateTime.tm_mon ? i = temp1->info.dateTime.tm_mon : i = temp1->info.dateTime.tm_mon;
    temp1->info.dateTime.tm_year < temp2->info.dateTime.tm_year ? year = temp1->info.dateTime.tm_year : year = temp1->info.dateTime.tm_year;

    while (temp1 || temp2) {
        int counter1 = 0, counter2 = 0;

        while (temp1 && temp1->info.dateTime.tm_mon == i) {
            ++counter1;
            temp1 = temp1->next;
        }

        while (temp2 && temp2->info.dateTime.tm_mon == i) {
            ++counter2; 
            temp2 = temp2->next;
        }


        std::cout << get_month_name(i + 1) << " " << year - 100  << " " << counter1 << " " << counter2 << "\n";
        i + 1 == 12 ? ++year, i = 0 : ++i;
    }
}