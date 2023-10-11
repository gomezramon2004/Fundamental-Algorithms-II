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
        LinkedList bitacora, listaMed, listaRed, outputMed, outputRed;
        bitacora.parse("bitacora.txt");
        bitacora = mergeSort(bitacora, false);
        listaMed = bitacora.divideList('M');
        listaRed = bitacora.divideList('R');
        outputMed = binarySearch(listaMed, inputTest1);
        outputRed = binarySearch(listaRed, inputTest1);
        outputMed = mergeSort(outputMed, true);
        outputRed = mergeSort(outputRed, true);
        print(outputMed, outputRed);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}