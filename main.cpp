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
        std::string months[12]= {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
        std::string inputTest1 = "4HU";
        // std::string inputTest2 = "1SV";
        // std::string inputTest3 = "0KI";
        // std::string inputTest4 = "AAA";
         // Parse the "bitacora.txt" file to create a linked list of ship entries.
        LinkedList bitacora = parse("bitacora.txt");

        // Sort the linked list in descending order using merge sort.
        bitacora = mergeSort(bitacora, false);

        // Divide the sorted list into two based on the entry point (Mar Mediterráneo and Mar Rojo).
        LinkedList listaMed = bitacora.divideList('M');
        LinkedList listaRed = bitacora.divideList('R');

        // Perform a binary search on both lists to find entries matching the specified input.
        LinkedList outputMed = binarySearch(listaMed, inputTest1);
        LinkedList outputRed = binarySearch(listaRed, inputTest1);

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