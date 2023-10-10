#include "./parse/parse.hpp"
#include "./sort/mergeSort.hpp"
#include "./search/binarySearch.hpp"
#include "./print/print.hpp"
#include <iostream>
#include <string>
#include <vector>

// Description: Sort a log info in descending order using merge sort and display all of the entries matched with the user input

// Francisco Rochín Gómez - A01252974
// Andrés Sandoval Ibarra - A01253138
// Daniel Fernández Clausen - A01254659
// Ramón Alberto Gómez Urquídez - A01254784
// October 4th, 2023

int main() {
    try {
        std::string months[12]= {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
        std::string inputTest1 = "4TL";
        // std::string inputTest2 = "1SV";
        // std::string inputTest3 = "0KI";
        // std::string inputTest4 = "AAA";
        LinkedList bitacora, listaMed, listaRojo;
        //bitacora = bitacora.parse("bitacora.txt");
        bitacora.parse("bitacora.txt");
        //mergeSort(bitacora, 0, bitacora.size() - 1);
        //std::vector<Info> output = binarySearch(inputTest1, bitacora)
        bitacora.isEmpty();
        bitacora = mergeSort(bitacora, 1);
        listaMed = listaRojo.divideList(bitacora, 'M');
        print(listaMed);
        print(listaRojo);
        for (int i = 0; i < 12; ++i) {
            std::cout << months[i] << ": " << countMonth(listaRojo, i + 1) << std::endl;
        }
        //print(bitacora);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    //divide a list into two lists

    return 0;
}