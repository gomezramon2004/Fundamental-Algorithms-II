#include "./parse/parse.cpp"
#include "./sort/mergeSort.cpp"
#include "./search/binarySearch.cpp"
#include "./print/print.cpp"
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
        std::string inputTest1 = "4TL";
        // std::string inputTest2 = "1SV";
        // std::string inputTest3 = "0KI";
        // std::string inputTest4 = "AAA";
        LinkedList bitacora, listaMed, listaRojo;
        //bitacora = bitacora.parse("bitacora.txt");
        bitacora.parse("bitacora.txt");
        //mergeSort(bitacora, 0, bitacora.size() - 1);
        //std::vector<Info> output = binarySearch(inputTest1, bitacora)
        isEmpty(bitacora);
        bitacora = mergeSort(bitacora);
        listaMed = listaRojo.divideList(bitacora, 'M');
        print(listaMed);
        print(listaRojo);
        //print(bitacora);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    //divide a list into two lists

    return 0;
}