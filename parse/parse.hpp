#pragma once
#include <string>
#include <vector>

struct Info {
    time_t timeValue; // Value that counts in seconds from 01/01/1970 to the corresponding date
    struct tm dateTime; // Struct that holds the data of our date
    int monthValue;
    char enterPoint;
    std::string ubi;
};

class Node {
    public: 
        Info info;
        Node* next;
};

class LinkedList {
    public:
        Node* head;
        Node* tail;
        int size;

        LinkedList();
        void insertNode(Info info);
        LinkedList parse(std::string fileName);    
        void isEmpty();
        LinkedList divideList(LinkedList list, char puerto_com);
        int sizeList(LinkedList list);
};
// Parse the info into a struct named Info
//std::vector<Info> parse(std::string fileName);
