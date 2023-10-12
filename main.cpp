#include "./linkedList/linkedList.hpp"
#include "./parse/parse.hpp"
#include "./sort/mergeSort.hpp"
#include "./search/binarySearch.hpp"
#include "./print/print.hpp"
#include <iostream>
#include <string>

// Description: Sort a log info in descending order using merge sort and display all of the entries matched with the user input

// Francisco Rochín Gómez - A01252974
// Andrés Sandoval Ibarra - A01253138
// Daniel Fernández Clausen - A01254659
// Ramón Alberto Gómez Urquídez - A01254784
// October 11th, 2023

int main() {
    try {
        std::string inputTest1 = "4TL";
        // std::string inputTest2 = "1SV";
        // std::string inputTest3 = "0KI";
        // std::string inputTest4 = "AAA";
         // Parse the "bitacora.txt" file to create a linked list of ship entries.
        LinkedList log = parse("bitacora.txt");

        // Sort the linked list in descending order using merge sort.
        log = mergeSort(log, false);

        // Divide the sorted list into two based on the entry point (Mar Mediterráneo and Mar Rojo).
        LinkedList medList = log.divideList('M');
        LinkedList redList = log.divideList('R');

        // Perform a binary search on both lists to find entries matching the specified input.
        LinkedList outputMed = binarySearch(medList, inputTest1);
        LinkedList outputRed = binarySearch(redList, inputTest1);

        // Sort the search results by time.
        outputMed = mergeSort(outputMed, true);
        outputRed = mergeSort(outputRed, true);

        // Print the search results for both entry points.
        print(outputMed, outputRed);
    } catch (const std::exception& e) {
        // Handle and display any exceptions that may occur.
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}