#include "parse.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <iostream>
LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

void LinkedList::insertNode(Info info) {
    Node* newNode = new Node;
    newNode->info = info;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
//empty list fucntion
void isEmpty(LinkedList list){
    if(list.head == nullptr){
        std::cout << "The list is empty" << std::endl;
    }
    else{
        std::cout << "The list is not empty" << std::endl;
    }
}

LinkedList LinkedList::parse(std::string fileName) {
    std::ifstream inputFile(fileName);  // RAII is responsible for destruct the file-handling object out of scope. It will handle file closing automatically
    if (!inputFile.is_open()) {
        throw std::runtime_error("Error - Unable to open the file.");
    }
    
    const size_t LINE_COUNT = std::count_if(std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>(), [](char c) { return c == '\n'; }); // Count the number of '\n' from the input stream (number of lines)
    inputFile.seekg(0); // Sets the position from the input stream to the start
    Info parsedNode; 
    LinkedList list;

    for (size_t i = 0; i < LINE_COUNT; ++i) {
        std::string line;
        std::getline(inputFile, line);
        std::string dateTime = line.substr(0, 16); // Substract the datetime characters
        struct tm timeStruct;
        std::time_t time = mktime(&timeStruct); 
        std::istringstream ss(dateTime);
        ss >> std::get_time(&timeStruct, "%d/%m/%Y %H:%M");
        parsedNode = {time, timeStruct, stoi(line.substr(3, 4)), line[17], line.substr(19, 24)};
        this->insertNode(parsedNode);
    }
    return *this;
}

int LinkedList::sizeList(LinkedList list){
    int size = 0;
    Node* temp = list.head;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}

LinkedList LinkedList::divideList(LinkedList list, char puerto_com){
    LinkedList list2;
    *this = LinkedList();
    Node* temp = list.head;
    int i = 0;
    while (temp != nullptr) {
        if(temp->info.enterPoint == puerto_com){
            list2.insertNode(temp->info);
        }
        else{
            this->insertNode(temp->info);
        }
        temp = temp->next;
    }
    return list2;
}

// strptime(dateTime,"%d/%m/%Y %H:%M", &timeStruct); We can't use strptime because Windows isn't POSIX Compliant
// https://stackoverflow.com/questions/321849/strptime-equivalent-on-windows
// https://www.quora.com/Why-doesnt-Microsoft-make-Windows-POSIX-compliant 