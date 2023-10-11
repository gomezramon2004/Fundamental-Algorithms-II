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
        LinkedList bitacora = parse("bitacora.txt");
        bitacora = mergeSort(bitacora, false);
        LinkedList listaMed = bitacora.divideList('M');
        LinkedList listaRed = bitacora.divideList('R');
        LinkedList outputMed = binarySearch(listaMed, inputTest1);
        LinkedList outputRed = binarySearch(listaRed, inputTest1);
        outputMed = mergeSort(outputMed, true);
        outputRed = mergeSort(outputRed, true);
        print(outputMed, outputRed);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}